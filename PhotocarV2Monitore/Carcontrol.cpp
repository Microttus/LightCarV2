//
// Created by Martin Økter on 11/04/2024.
//

#include "Carcontrol.hh"

CarControl::CarControl()
: last_time_(millis())
{

}

void CarControl::UpdateSumAndDiff(int light_r, int light_l, int light_m) {
  light_sum = (light_r + light_l) - (light_m * 1.4);    //Find mean value of the two sensors
  if (light_sum < 0) {
    light_sum = 0;
  }
  light_diff = light_l - light_r;     //Find the differance form the two sensors
  Serial.print(light_sum);
}

void CarControl::CalculateSpeedLegacy() {
  int motorBaseSpeed = constrain(map(light_sum, 670, 800, pwm_max, pwm_min), pwm_min, pwm_max);             //Invert the sum for use to speed and allow for turn at max speeed
  int corrSpeed = map(light_diff, -1000, 1000, -200, 200);                                //Calculate a correction speeds based on the difference

  //For increased sense includes the difference
  motorBaseSpeed = motorBaseSpeed - (abs(corrSpeed)/10);

  if (CarControl::light_sum < 670){
    motorBaseSpeed = pwm_min;                                      //Set the speed to zero if the light source is too far away or to close
  }

  motor_speed_right_ = constrain(motorBaseSpeed - corrSpeed, 0, 255);  //Calculate speed for the right motor and constrain for PWM
  motor_speed_left_ = constrain(motorBaseSpeed + corrSpeed, 0, 255);  //Calculate speed for the left motor and constrain for PWM

}

void CarControl::CalculateSpeed() {
  float motor_speed_light_corrected = constrain(map_float(static_cast<float>(light_sum), light_max, light_min, speed_min, speed_max), speed_min, speed_max);
  float motor_speed_light_turn = static_cast<float>(light_diff*light_turn_amp);

  wheel_request_right = constrain(motor_speed_light_corrected + motor_speed_light_turn, speed_min, speed_max);
  wheel_request_left = constrain(motor_speed_light_corrected - motor_speed_light_turn, speed_min, speed_max);
}

void CarControl::UpdateWheelSpeed(int right_wheel_counter, int left_wheel_counter) {
  unsigned long current_loop_time = static_cast<unsigned long>(millis() - last_time_);

  float rounds_right = static_cast<float>((static_cast<long>(right_wheel_counter)-last_trigger_count_right))/static_cast<float>(trigger_per_round_);
  float rounds_left = static_cast<float>((static_cast<long>(left_wheel_counter)-last_trigger_count_left))/static_cast<float>(trigger_per_round_);

  //long rounds_diff = static_cast<long>(right_wheel_counter)-last_trigger_count_right;

  float loop_time = static_cast<float>(current_loop_time)*0.001;

  if (loop_time != 0) {
    wheel_speed_right_ = (rounds_right*wheel_circumference)/loop_time;
    wheel_speed_left_ = (rounds_left*wheel_circumference)/loop_time;
  } else {
    wheel_speed_right_ = 0;
    wheel_speed_left_ = 0;
  } 

  last_time_ = millis();
  last_trigger_count_right = static_cast<long>(right_wheel_counter);
  last_trigger_count_left = static_cast<long>(left_wheel_counter);
}

float CarControl::map_float(float in_val, float in_min, float in_max, float out_min, float out_max) {
  return ((in_val - in_min) * (out_max - out_min)) / (in_max - in_min) + out_min;
}


int CarControl::getMotorSpeedRight() {
  return motor_speed_right_;
}

int CarControl::getMotorSpeedLeft() {
  return motor_speed_left_;
}

float CarControl::getWheelSpeedRight() {
  return wheel_speed_right_;
}

float CarControl::getWheelSpeedLeft() {
  return wheel_speed_left_;
}
float CarControl::getWheelReqRight() {
  return wheel_request_right;
}
float CarControl::getWheelReqLeft() {
  return wheel_request_left;
}


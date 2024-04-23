//
// Created by Martin Økter on 11/04/2024.
//

#ifndef PHOTOCARV2MONITORE__CARCONTROL_HH_
#define PHOTOCARV2MONITORE__CARCONTROL_HH_

#include <Arduino.h>

class CarControl {
 public:
  CarControl();

  void UpdateSumAndDiff(int light_r, int light_l, int light_m = 0);
  void CalculateSpeed();
  void CalculateSpeedLegacy();
  void UpdateWheelSpeed(int right_wheel_counter, int left_wheel_counter);

  int getMotorSpeedRight();
  int getMotorSpeedLeft();
  float getWheelSpeedRight();
  float getWheelSpeedLeft();
  float getWheelReqRight();
  float getWheelReqLeft();

  float map_float(float in_val, float in_min, float in_max, float out_min, float out_max);

 private:
  int light_sum = 0;
  int light_diff = 0;

  int motor_speed_left_ = 0;
  int motor_speed_right_ = 0;

  float wheel_request_right = 0;
  float wheel_request_left = 0;

  float wheel_speed_right_ = 0;
  float wheel_speed_left_ = 0;

  int pwm_min = 60;
  int pwm_max = 254;

  float speed_min = 0;
  float speed_max = 0.5; // m/s

  float light_min = 0;
  float light_max = 400;
  float light_turn_amp = 0.01;//0.03;

  float wheel_circumference = 0.2;
  int trigger_per_round_ = 80;

  int last_trigger_count_right = 0;
  int last_trigger_count_left = 0;

  unsigned long last_time_;
};

#endif //PHOTOCARV2MONITORE__CARCONTROL_HH_

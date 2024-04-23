//
// Created by Martin Økter on 11/04/2024.
//

#include <iostream>

#include "Carcontrol.hh"

int main () {
  CarControl PhotoCar;

  PhotoCar.UpdateSumAndDiff(124, 124, 60);

  PhotoCar.CalculateSpeed();

  int left_speed = PhotoCar.getMotorSpeedLeft();
  int right_speed = PhotoCar.getMotorSpeedRight();

  std::cout << "Left: " << left_speed << " - Right: " << right_speed;
}
/**
 *  @file       Dual_Motor_DC.h
 *  Project     Motor-Control
 *  @brief      Arduino Due library for controlling two DC motors
 *
 * Contains an example using the Dual_Motor_DC library
 * It is inspired by L298N (https://github.com/AndreaLombardo/L298N).
 *
 *  @author     Otávio Augusto Rocha da Cruz
 *  @bug      No known bugs.
 *  License     GNU Affero General Public License v3.0
 *
 *  @section License
 *
 *  Copyright (c) 2021 Otavio
 *
 * This file is part of Motor-Control.

 *  Motor-Control is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or 
 * (at your option) any later version.

 * Motor-Control is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.

 * You should have received a copy of the GNU Affero General Public License
 * along with Motor-Control. If not, see <https://www.gnu.org/licenses/>
 */

// IMPORTANT, for debug mode do: #define Simple_Motor_DEBUG 1

// Include the (new) library
#include <Simple_Motor_DC.h>

//Pins Motor
const unsigned int IN1_A = 7;
const unsigned int IN2_A = 6;

//Pins Motor
const unsigned int IN2_B = 5;
const unsigned int IN1_B = 4;

SimpleMotor motor1(IN1_A, IN2_A);
SimpleMotor motor2(IN1_B, IN2_B);

void setup() {
  
  // Used to display information
  Serial.begin(9600);

  // Wait for Serial Monitor to be opened
  while (!Serial)
  {
    //do nothing
  }

}

void loop() 
{

  // Tell a motor to go forward with PWM equal to 210
  motor1.forward(210);
  motor2.forward(210);
  Serial.println("Andando para frente");
  // 1 segunds of Delay 
  delay(1000);
  // Stop motor
  motor1.stop();
  motor2.stop();
  delay(1000);

  // Tell a motor to go backward with PWM equal to 210
  motor1.backward(210);
  motor2.backward(210);
  Serial.println("Andando para trás");
  delay(1000);
  motor1.stop();
  motor2.stop();
  delay(1000);

  // Disable 
  motor1.enableOff();
  motor2.enableOff();
  Serial.println("Enable off");
  motor1.backward(210);
  motor2.backward(210);
  // 2 segunds of Delay 
  delay(2000);

  // Enable 
  motor1.enableOn();
  motor2.enableOn();
  Serial.println("Enable on");
  motor1.backward(210);
  motor2.backward(210);
  delay(2000);

  motor1.forward(255);
  motor2.forward(255);
  Serial.print("O PWM atual é de ");
  // Get the current value of PWM
  Serial.println(motor1.getPwm());
  Serial.println("-------------------------------------");
  delay(1000);
  motor1.stop();
  motor2.stop();
}
}

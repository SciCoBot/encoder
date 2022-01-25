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
 
#include <simple_motor_dc.h>
#include <encoder.h>

//Pins Motor
#define IN1_A 7
#define IN2_A 6

//Pins Motor
#define IN2_B 5
#define IN1_B 4

//Pins Encoder
#define OUT_ENCODER_RIGHT 51
#define OUT_ENCODER_LEFT 52

SimpleMotor motorRight;
SimpleMotor motorLeft;

Encoder encoderRight;
Encoder encoderLeft;

void count_encoder_left()
{
  encoderLeft.incrementPulses();
}

void count_encoder_right()
{
  encoderRight.incrementPulses();
}

void setup() {

  motorRight.init(IN1_A, IN2_A);
  motorLeft.init(IN1_B, IN2_B);

  encoderRight.init(OUT_ENCODER_RIGHT, &count_encoder_right);
  encoderLeft.init(OUT_ENCODER_LEFT, &count_encoder_left);
  
  Serial.begin(9600);

  while (!Serial)
  {
    
  }

}

void loop() 
{

  motorRight.forward(210);
  motorLeft.forward(210);

  delay(1000);

  motorRight.stop();
  motorLeft.stop();
  
  Serial.print("Encoder Right: ");
  Serial.println(encoderRight.read());
  Serial.print("Encoder Left: ");
  Serial.println(encoderLeft.read());
  delay(1000);

  motorRight.forward(210);
  motorLeft.forward(210);

  delay(1000);

  motorRight.stop();
  motorLeft.stop();
  
  Serial.print("Encoder Right: ");
  Serial.println(encoderRight.readAndReset());
  Serial.print("Encoder Left: ");
  Serial.println(encoderLeft.readAndReset());
  delay(1000);

  motorRight.forward(210);
  motorLeft.forward(210);

  delay(1000);

  motorRight.stop();
  motorLeft.stop();
  
  Serial.print("Encoder Right: ");
  Serial.println(encoderRight.readAndReset());
  Serial.print("Encoder Left: ");
  Serial.println(encoderLeft.readAndReset());
  delay(1000);
}


/***********************************************************************************
 *  @file       encoder.cpp
 *  Project     encoder
 *  @brief      Arduino Due library for encoder.
 *
 *
 *  @author     Otávio Augusto Rocha da Cruz
 *  @bug 		 No known bugs.
 *  License     MIT
 *
 *  @section License
 *
 * Copyright (c) 2021 SciCoBot
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**********************************************************************************/
#include "encoder.h"

void Encoder::init(uint8_t pinDigital, void (*functionInterrupt)(), uint8_t mode)
{ 
		_pinDigital = pinDigital;
		pinMode(_pinDigital, INPUT);
		
		_pulses = 0;
  		_rpm = 0.0;
  		_prevTime = micros();
		_prevEncoderTicks = 0;
		
		attachInterrupt(digitalPinToInterrupt(_pinDigital), functionInterrupt, mode);
	
		delay(2);
		#if ENCODER_DEBUG == 1
			  DEBUGLN("Encoder starting successfully");
		#endif
}

unsigned short int Encoder::read()
{
	return _pulses;
}

unsigned short int Encoder::readAndReset()
{
	unsigned short int pulseTemp = _pulses;
	#if ENCODER_DEBUG == 1
		DEBUG("readAndReset(): ");
		DEBUGLN(pulseTemp);
	#endif
	_pulses = 0;
	return pulseTemp;	
}

void Encoder::incrementPulses()
{
	_pulses = _pulses + 1;
	
	#if ENCODER_DEBUG == 1
		DEBUG("Increment pulses: ");
		DEBUGLN(_pulses);
	#endif
}

float Encoder::getRpm()
{
		//detachInterrupt(_pinInterrupt);
		//attachInterrupt(_pinInterrupt, &functionInterrupt, _mode);
		long _nowEncoderTicks = readAndReset();
		unsigned long currentTime = micros();
		unsigned long timeDifference = currentTime - _prevTime;

		//convert the time from microseconds to minutes
		float timeDifferenceMin = (float)timeDifference / 60000000.0;
		double DifferenceTicks = _nowEncoderTicks - _prevEncoderTicks;

		_rpm = ((DifferenceTicks/COUNTS_PER_REV)/timeDifferenceMin);
		
		//calculate wheel's speed (RPM)
		_prevTime = currentTime;
		_prevEncoderTicks = _nowEncoderTicks;
		
		#if ENCODER_DEBUG == 1
			  DEBUG("RPM = ");
			  DEBUGLN(_rpm);
		#endif
    	
		return _rpm;
}
	


/***********************************************************************************
 *  @file       encoder.h
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
#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

#define ENCODER_DEBUG 0 // Debug mode
#if ENCODER_DEBUG == 1
	#include <serial_debug.h>
#endif

#define COUNTS_PER_REV 20

class Encoder
{
	public:
		
		float getRpm();
		void init(uint8_t pinDigital, void (*functionInterrupt)(), uint8_t mode= FALLING);
		unsigned short int read();
		unsigned short int readAndReset();
		void incrementPulses();

	private:
		
		volatile unsigned short int _pulses; 
		float _rpm;
		unsigned long _prevTime;
		uint8_t _pinDigital;
		uint8_t _pinInterrupt;
		unsigned short int _prevEncoderTicks;
};
#endif //ENCODER_H

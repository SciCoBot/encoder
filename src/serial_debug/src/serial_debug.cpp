/***********************************************************************************
 *  @file       serial_debug.cpp
 *  Project     serial_debug
 *  @brief      Arduino Due library with functions and macros to help debug code.
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
#include <Arduino.h>
#include "serial_debug.h"

#ifdef SERIAL_DEBUG_ENABLE
	
	void debugTime()                                                           
	{    
		unsigned long timeNowInMillis = millis();                                               
		unsigned long hour = timeNowInMillis / (60UL * 60 * 1000);                                 
		unsigned long minute = (timeNowInMillis / (60UL * 1000)) % 60;                                
		unsigned long second = (timeNowInMillis / (1000UL)) % 60;                                    
		unsigned long millisecond = timeNowInMillis % 1000;
			                            
		char *millisecondsZeros;                                            	
		if(millisecond > 99)
		{
			millisecondsZeros = "";
		}
		else if(millisecond > 9)
		{
			millisecondsZeros = "0";
		}
		else
		{
			millisecondsZeros = "00";
		}
		
		DEBUG(hour); 
		DEBUG(":"); 
		DEBUG(minute); 
		DEBUG(":"); 
		DEBUG(second); 
		DEBUG(":"); 
		DEBUG(millisecondsZeros); 
		DEBUGLN(millisecond); 
		SEPARATOR();
	}

	
	void debugTimeBreak(char* messageReceive, uint32_t timeout)
	{
		DEBUGLN(messageReceive);
		unsigned long tempTimeNowInMillis = millis(); 
		unsigned long tempTimeBeforeInMillis;
		String response = ""; 
		
		while((millis() - tempTimeNowInMillis) < timeout) 
		{
			if (SERIALDEBUG.available() > 0) 
			{
				response.concat((char) Serial.read());
			}
		}
		if(response != "")
		{
			DEBUG("I received: ");
			DEBUGLN(response);
		}
		else
		{
			DEBUGLN("Time exceeded");
		}
		SEPARATOR();
	}
	

	#else
	//NONE
#endif
	

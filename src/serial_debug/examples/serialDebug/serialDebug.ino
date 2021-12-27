/***********************************************************************************
 *  @file       serialDebug.ino
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


// Note: By default the library uses Serial to print as messages.
// If you need to use another Serial (Serial1, Serial2...), 
// go FIRST to the serial_debug.h file and change "Serial" from 
// "#define SERIALDEBUG Serial" to Serial you need

#include<serial_debug.h>

void funcTest()
{
  // Print file name
  DEBUG_PRINT_FILE();
  // Print line of this file
  DEBUG_PRINT_LINE();
  // Print function name
  DEBUG_PRINT_PRETTY_FUNCTION();
}

// Define global variables
int variableIntTest = 5;
char* variableCharTest = "hello world";

void setup() 
{
  // Library does not initialize Serial
  Serial.begin(9600); 

  // Print message
  DEBUGLN("Debug init...");  
}

void loop() 
{
  // Wait for a serial message to be received for a specified amount of time (default 5 sec)
  debugTimeBreak();

  //print the value of a variable
  PRINTVARIABLE("variableIntTest", variableIntTest);

  //print the value of a variable
  PRINTVARIABLE("variableCharTest", variableCharTest);
  
  funcTest();
  
  Serial.print("Running time up to this point: ");
  //format: hours:minutes:seconds:milliseconds 
  debugTime();
}

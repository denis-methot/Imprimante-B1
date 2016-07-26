/* -*- c++ -*- */
//General firmware for the MakerGear M2; specifically, support for Geeetech RepRap Discount Smart Controller LCD; dual extruder;
//single extruder with Z probe (inductive or mechanical); Z MAX or Z MIN endstops; 

//GEETECH LCD with NEW Z MOTOR

/*
To disable Geeetech LCD, comment out (add "//" to the beginning of the line) "#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER" line number 566 in Configuration.h
To enable dual extruder, change "#define EXTRUDERS 1" to "#define EXTRUDERS 2" line 58 in Configuration.h; also uncomment (delete the "//" at the beginning of the line) lines 496 and 497 in Configuration.h
For dual extruder, also change Configuration.h line 108 from "#define TEMP_SENSOR_1 0" to "#define TEMP_SENSOR_1 1".
To enable Z probe, uncomment "//#define ENABLE_AUTO_BED_LEVELING" line 353 in Configuration.h.
To switch between Z MAX and Z MIN endstops, change line 335 in Configuration.h ("#define Z_HOME_DIR -1") to -1 for MIN and 1 for MAX.
/*
    Reprap firmware based on Sprinter and grbl.
 Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 This firmware is a mashup between Sprinter and grbl.
  (https://github.com/kliment/Sprinter)
  (https://github.com/simen/grbl/tree)

 It has preliminary support for Matthew Roberts advance algorithm
    http://reprap.org/pipermail/reprap-dev/2011-May/003323.html
 */

/* All the implementation is done in *.cpp files to get better compatibility with avr-gcc without the Arduino IDE */
/* Use this file to help the Arduino IDE find which Arduino libraries are needed and to keep documentation on GCode */

#include "Configuration.h"
#include "pins.h"

#ifdef ULTRA_LCD
  #if defined(LCD_I2C_TYPE_PCF8575)
    #include <Wire.h>
    #include <LiquidCrystal_I2C.h>
  #elif defined(LCD_I2C_TYPE_MCP23017) || defined(LCD_I2C_TYPE_MCP23008)
    #include <Wire.h>
    #include <LiquidTWI2.h>
  #elif defined(DOGLCD)
    #include "U8glib.h" // library for graphics LCD by Oli Kraus (https://code.google.com/p/u8glib/)
  #else
    #include <LiquidCrystal.h> // library for character LCD
  #endif
#endif

#if defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1
#include <SPI.h>
#endif

#if defined(DIGIPOT_I2C)
  #include <Wire.h>
#endif

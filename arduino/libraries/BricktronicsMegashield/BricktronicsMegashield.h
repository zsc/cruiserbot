/*
   BricktronicsMegashield v1.2 - A software library for Bricktronics Megashield.
   This library is only needed if you are using a Bricktronics Megashield.
   If you are using a break-out board or a motor driver board,
   you can just directly use the motor and sensor libraries.

   Copyright (C) 2015 Adam Wolf, Matthew Beckler, John Baichtal

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

   Wayne and Layne invests time and resources providing this open-source
   code, please support W&L and open-source hardware by purchasing products
   from https://store.wayneandlayne.com/ - Thanks!

   Wayne and Layne, LLC and our products are not connected to or endorsed by the LEGO Group.
   LEGO, Mindstorms, and NXT are trademarks of the LEGO Group.
*/

#ifndef BRICKTRONICSMEGASHIELD_H
#define BRICKTRONICSMEGASHIELD_H

// Header files
#include <inttypes.h>
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "utility/BricktronicsSettings.h"

class BricktronicsMegashield
{
    public:
        // Empty constructor that we never use, since everything is static.
        BricktronicsMegashield();

        static void begin(void);

        // Bricktronics Megashield motor settings
        static const BricktronicsMotorSettings MOTOR_1;
        static const BricktronicsMotorSettings MOTOR_2;
        static const BricktronicsMotorSettings MOTOR_3;
        static const BricktronicsMotorSettings MOTOR_4;
        static const BricktronicsMotorSettings MOTOR_5;
        static const BricktronicsMotorSettings MOTOR_6;

        // Bricktronics Megashield sensor settings
        static const BricktronicsSensorSettings SENSOR_1;
        static const BricktronicsSensorSettings SENSOR_2;
        static const BricktronicsSensorSettings SENSOR_3;
        static const BricktronicsSensorSettings SENSOR_4;
		static const BricktronicsSensorSettings SENSOR_5;
        static const BricktronicsSensorSettings SENSOR_6;

};

#endif // #ifndef BRICKTRONICSMEGASHIELD_H


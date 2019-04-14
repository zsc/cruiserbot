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

#include "BricktronicsMegashield.h"

// Motor settings
const BricktronicsMotorSettings BricktronicsMegashield::MOTOR_1 =
{
	39, // enPin
	38, // dirPin
	13, // pwmPin
	2,  // encoderPin1
	22, // encoderPin2
	false, // reversedMotorDrive
	&::pinMode,
	&::digitalWrite,
	&::digitalRead,
};

const BricktronicsMotorSettings BricktronicsMegashield::MOTOR_2 =
{
	37, // enPin
	36, // dirPin
	12,  // pwmPin
	3,  // encoderPin1
	23, // encoderPin2
	false, // reversedMotorDrive
	&::pinMode,
	&::digitalWrite,
	&::digitalRead,
};
const BricktronicsMotorSettings BricktronicsMegashield::MOTOR_3 =
{
	35, // enPin
	34, // dirPin
	11,  // pwmPin
	18, // encoderPin1
	24,  // encoderPin2
	false, // reversedMotorDrive
	&::pinMode,
	&::digitalWrite,
	&::digitalRead,
};

const BricktronicsMotorSettings BricktronicsMegashield::MOTOR_4 =
{
	33, // enPin
	32, // dirPin
	6,  // pwmPin
	19, // encoderPin1
	25, // encoderPin2
	false, // reversedMotorDrive
	&::pinMode,
	&::digitalWrite,
	&::digitalRead,
};

const BricktronicsMotorSettings BricktronicsMegashield::MOTOR_5 =
{
	31,	// enPin
	30, // dirPin
	5,  // pwmPin
	20, // encoderPin1
	26, // encoderPin2
	false, // reversedMotorDrive
	&::pinMode,
	&::digitalWrite,
	&::digitalRead,
};

const BricktronicsMotorSettings BricktronicsMegashield::MOTOR_6 =
{
	29, // enPin
	28, // dirPin
	4,  // pwmPin
	21, // encoderPin1
	27, // encoderPin2
	false, // reversedMotorDrive
	&::pinMode,
	&::digitalWrite,
	&::digitalRead,
};


// Sensor settings
const BricktronicsSensorSettings BricktronicsMegashield::SENSOR_1 =
{
	A0, // ANA
	40, //POW
	46, // DA
	50, // DB
	&::pinMode,
	&::digitalWrite,
	&::digitalRead,
};

const BricktronicsSensorSettings BricktronicsMegashield::SENSOR_2 =
{
	A1, // ANA
	41, //POW
	47, // DA
	51, // DB
	&::pinMode,
	&::digitalWrite,
	&::digitalRead,
};

const BricktronicsSensorSettings BricktronicsMegashield::SENSOR_3 =
{
	A2, // ANA
	42,  //POW
	48, // DA
	52, // DB
	&::pinMode,
	&::digitalWrite,
	&::digitalRead,
};

const BricktronicsSensorSettings BricktronicsMegashield::SENSOR_4 =
{
	A3, // ANA
	43, //POW
	49, // DA
	53, // DB
	&::pinMode,
	&::digitalWrite,
	&::digitalRead,
};
const BricktronicsSensorSettings BricktronicsMegashield::SENSOR_5 =
{
	A4, // ANA
	44, //POW
	A6, // DA
	A8, // DB
	&::pinMode,
	&::digitalWrite,
	&::digitalRead,
};
const BricktronicsSensorSettings BricktronicsMegashield::SENSOR_6 =
{
	A5, // ANA
	45, //POW
	A7, // DA
	A9, // DB
	&::pinMode,
	&::digitalWrite,
	&::digitalRead,
};

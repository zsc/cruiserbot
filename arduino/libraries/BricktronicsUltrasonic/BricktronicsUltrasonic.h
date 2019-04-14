/*
    BricktronicsUltrasonic v1.2 - A software library for LEGO NXT Ultrasonic sensors.

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

#ifndef BRICKTRONICSULTRASONIC_H
#define BRICKTRONICSULTRASONIC_H

// Arduino header files
#include <stdint.h>
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// Library header files
#include "utility/BricktronicsSettings.h"
#include "utility/SoftI2cMaster.h"


#define ULTRASONIC_READ_COMMAND 0x41
#define ULTRASONIC_READ_MEASUREMENT_BYTE_ZERO 0x42

#define ULTRASONIC_GET_VERSION 0x00
#define ULTRASONIC_GET_PRODUCT_ID 0x08
#define ULTRASONIC_GET_SENSOR_TYPE 0x10
#define ULTRASONIC_FACTORY_ZERO 0x11
#define ULTRASONIC_FACTORY_SCALE_FACTOR 0x12
#define ULTRASONIC_FACTORY_SCALE_DEVICOR 0x13
#define ULTRASONIC_UNITS 0x14

#define ULTRASONIC_ADDRESS 0x02
#define ULTRASONIC_BUFF_LEN 9


class BricktronicsUltrasonic
{
public:
	// Constructor - Simple constructor accepts the SCL and SDA pins
	BricktronicsUltrasonic(const uint8_t sclPin, const uint8_t sdaPin,const uint8_t powPin);

	// Constructor - Advanced constructor accepts a BricktronicsSensorSettings
	// struct to also override the low-level Arduino functions.
	BricktronicsUltrasonic(const BricktronicsSensorSettings &settings);

	// Starts up the sensor
	void begin(void);

	// This is the main API call to get the current distance reading in centimeters.
	// Checks for errors and returns 0 in case of error.
	// Returns the actual distance in centimeters in case of success.
	uint8_t getDistance(void);

	// These might return interesting data.
	// Pass in an 8 byte buffer.
	// These functions check for errors and returns false in case of error, true in case of success.
	uint8_t getProductID(char *buffer);
	uint8_t getVersion(char *buffer);
	uint8_t getSensorType(char *buffer);

	//private:
	// We really don't like to hide things inside private,
	// but if we did, these would be the private items.
	uint8_t _sclPin;
	uint8_t _sdaPin;
	uint8_t _powPin;

	SoftI2cMaster _i2c;

	// Internal functions
	bool writeBytes(const uint8_t startAddress, const uint8_t numBytes, const uint8_t *buffer);
	uint8_t readBytes(const uint8_t startAddress, const uint8_t numBytes, uint8_t *buffer);
	uint8_t readString(const uint8_t startAddress, const uint8_t numBytes, char *buffer);

	// For the Bricktronics Shield, which has an I2C I/O expander chip,
	// we need a way to override some common Arduino functions. We use
	// function pointers here to handle this. For the non-Bricktronics
	// Shield cases, the simple constructor above provides the built-in
	// functions.
	void (*_pinMode)(uint8_t, uint8_t);
	void (*_digitalWrite)(uint8_t, uint8_t);
	int (*_digitalRead)(uint8_t);
};

#endif // #ifndef BRICKTRONICSULTRASONIC_H


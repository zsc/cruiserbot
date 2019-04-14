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

#include "BricktronicsUltrasonic.h"

BricktronicsUltrasonic::BricktronicsUltrasonic(const uint8_t sclPin, const uint8_t sdaPin,const uint8_t powPin):
	_sclPin(sclPin),
	_sdaPin(sdaPin),
	_powPin(powPin),	
	_i2c(),
	_pinMode(&::pinMode),
	_digitalWrite(&::digitalWrite),
	_digitalRead(&::digitalRead)
{
	// Nothing to do here
}

BricktronicsUltrasonic::BricktronicsUltrasonic(const BricktronicsSensorSettings &settings):
	_sclPin(settings.DA),
	_sdaPin(settings.DB),
	_powPin(settings.POW),
	_i2c(),
	_pinMode(settings.pinMode),
	_digitalWrite(settings.digitalWrite),
	_digitalRead(settings.digitalRead)
{
	// Nothing to do here
}

void BricktronicsUltrasonic::begin(void)
{
	_i2c.init(_sclPin, _sdaPin);
	_pinMode(_powPin,OUTPUT);
	_digitalWrite(_powPin,HIGH);
	
}

// readString - Reads a string from the I2C startAddress into supplied buffer.
// Checks for errors and returns false in case of error, true in case of success.
uint8_t BricktronicsUltrasonic::readString(const uint8_t startAddress, const uint8_t numBytes, char *buffer)
{
	uint8_t status = readBytes(startAddress, numBytes, (uint8_t *) buffer);
	buffer[numBytes - 1] = '\0';
	return( status );
}

// readBytes - Reads a bunch of bytes from the I2C startAddress into supplied buffer.
// Checks for errors and returns false in case of error, true in case of success.
uint8_t BricktronicsUltrasonic::readBytes(const uint8_t startAddress, const uint8_t numBytes, uint8_t *buffer)
{
	if( !(_i2c.start(ULTRASONIC_ADDRESS | I2C_WRITE)) ) // Try to start, with a write address
	{
		return( false ); // If it fails, return false.
	}

	if( !(_i2c.write(startAddress)) ) // Try to start a write
	{
		return( false ); // If it fails, return false.
	}

	// Do an I2C restart to switch direction. See HDK for details.
	if( !(_i2c.restart(ULTRASONIC_ADDRESS | I2C_READ)) )
	{
		return( false );
	}

	for( uint8_t i = 0; i < numBytes - 1; i++ )
	{
		buffer[i] = _i2c.read(false); // Read, and then send ack
	}
	buffer[numBytes - 1] = _i2c.read(true); // Read the last byte, then send nak

	_i2c.stop();
	return( true );
}

bool BricktronicsUltrasonic::writeBytes(const uint8_t startAddress, const uint8_t numBytes, const uint8_t *buffer)
{
	if( !_i2c.start(ULTRASONIC_ADDRESS | I2C_WRITE) ) // Try to start, with a write address
	{
		return( false ); // If it fails, return false.
	}

	if( !_i2c.write(startAddress) ) // Try to start a write
	{
		return( false ); // If it fails, return false.
	}

	for( uint8_t i = 0; i < numBytes; i++ )
	{
		if( !_i2c.write(buffer[i]) )
		{
			return( false ); // If it fails, return false.
		}
	}

	_i2c.stop();
	return( true );
}

// Reads the version string from the device into the provided buffer.
// Checks for errors and returns false in case of error, true in case of success.
// Use a buffer of at least size 8.
uint8_t BricktronicsUltrasonic::getVersion(char *buffer)
{
	return( readString(ULTRASONIC_GET_VERSION, 8, buffer) );
}

// Reads the product ID from the device into the provided buffer.
// Checks for errors and returns false in case of error, true in case of success.
// Use a buffer of at least size 8.
uint8_t BricktronicsUltrasonic::getProductID(char *buffer)
{
	return( readString(ULTRASONIC_GET_PRODUCT_ID, 8, buffer) );
}

// Reads the sensor type from the device into the provided buffer.
// Checks for errors and returns false in case of error, true in case of success.
// Use a buffer of at least size 8.
uint8_t BricktronicsUltrasonic::getSensorType(char *buffer)
{
	return( readString(ULTRASONIC_GET_SENSOR_TYPE, 8, buffer) );
}

// This is the main API call to get the current distance reading in centimeters.
// Checks for errors and returns 0 in case of error.
// Returns the actual distance in centimeters in case of success.
uint8_t BricktronicsUltrasonic::getDistance(void)
{
	uint8_t buffer = ULTRASONIC_ADDRESS;
	if( !writeBytes(ULTRASONIC_READ_COMMAND, 1, &buffer) )
	{
		return( 0 );
	}
	delay(20);
	if( !readBytes(ULTRASONIC_READ_MEASUREMENT_BYTE_ZERO, 1, &buffer) )
	{
		return( 0 );
	}
	return( buffer );
}


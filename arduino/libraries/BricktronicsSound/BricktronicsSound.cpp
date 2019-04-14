/*
   BricktronicsSound v1.2 - A software library for LEGO NXT Sound sensors.

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

#include "BricktronicsSound.h"

// This is the simplified constructor that allows you to specify only the
// three pins to connect the Sound Sensor.
BricktronicsSound::BricktronicsSound(uint8_t inputPin, uint8_t dbPin, uint8_t dbaPin):
    _inputPin(inputPin),
    _dbPin(dbPin),
    _dbaPin(dbaPin),
    _mode(SOUND_SENSOR_MODE_DEFAULT),
    _pinMode(&::pinMode),
    _digitalWrite(&::digitalWrite),
    _digitalRead(&::digitalRead)
{
    // Nothing to do here
}

// This is the complicated constructor that allows for overriding the
// low-level Arduino functions.
BricktronicsSound::BricktronicsSound(const BricktronicsSensorSettings &settings):
    _inputPin(settings.ANA),
    _dbPin(settings.DA),
    _dbaPin(settings.DB),
    _mode(SOUND_SENSOR_MODE_DEFAULT),
    _pinMode(settings.pinMode),
    _digitalWrite(settings.digitalWrite),
    _digitalRead(settings.digitalRead)
{
    // Nothing to do here
}

void BricktronicsSound::begin(void)
{
    // Set input pin as an input (analog input)
    _pinMode(_inputPin, INPUT_PULLUP);

    // Set DB/DBA pins as outputs, set them to default values
    _pinMode(_dbPin, OUTPUT);
    _pinMode(_dbaPin, OUTPUT);
    setMode(SOUND_SENSOR_MODE_DEFAULT);
}

uint16_t BricktronicsSound::value(void)
{
    return (SOUND_SENSOR_BASE_VALUE - analogRead(_inputPin));
}

void BricktronicsSound::setMode(uint8_t mode)
{
    // If they pass-in an invalid mode, default to DBA mode
    switch (mode)
    {
        case SOUND_SENSOR_MODE_DB:
            _mode = mode;
            _digitalWrite(_dbPin, HIGH);
            _digitalWrite(_dbaPin, LOW);
            break;
        case SOUND_SENSOR_MODE_DBA:
        default:
            _mode = mode;
            _digitalWrite(_dbPin, LOW);
            _digitalWrite(_dbaPin, HIGH);
            break;
    }
}

uint8_t BricktronicsSound::getMode(void)
{
    return _mode;
}


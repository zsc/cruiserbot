/*
   BricktronicsButton v1.2 - A software library for LEGO NXT Pushbutton sensors.

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

#include "BricktronicsButton.h"

BricktronicsButton::BricktronicsButton(uint8_t inputPin):
    _inputPin(inputPin),
    _pinMode(&::pinMode),
    _digitalWrite(&::digitalWrite),
    _digitalRead(&::digitalRead)
{
    // Nothing to do here
}

BricktronicsButton::BricktronicsButton(const BricktronicsSensorSettings &settings):
    _inputPin(settings.ANA),
    _pinMode(settings.pinMode),
    _digitalWrite(settings.digitalWrite),
    _digitalRead(settings.digitalRead)
{
    // Nothing to do here
}

void BricktronicsButton::begin(void)
{
    _pinMode(_inputPin, INPUT_PULLUP);
}

bool BricktronicsButton::isPressed(void)
{
    return (_digitalRead(_inputPin) == LOW);
}

bool BricktronicsButton::isReleased(void)
{
    return (_digitalRead(_inputPin) == HIGH);
}


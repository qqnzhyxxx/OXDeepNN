/*************************************************
* Copyright (C) 2017 Niu ZhiYong
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or (at
* your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software Foundation.
**************************************************/
/*************************************************
Class type: Class of Input Layer
Author: Niu ZhiYong
Date: 2017-04-21
Description: Data input interface
**************************************************/
#ifndef INPUTLAYER_H
#define INPUTLAYER_H

#include "layers/NeureLayer.h"

class InputLayer: public NeureLayer
{
public:
    InputLayer();
    virtual ~InputLayer();
public:

protected:

};

#endif //INPUTLAYER_H

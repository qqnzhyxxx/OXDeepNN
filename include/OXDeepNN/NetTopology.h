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
Class type: To defind the Topology of Deep Neure Net
Author: Niu ZhiYong
Date: 2017-04-20
Description:
The input of solver,
this Class object is to store the date of hole Net
**************************************************/
#ifndef NETOPOLOGY_H
#define NETOPOLOGY_H

#include "layers/NeureLayer.h"

class NetTopology
{
public:
    NetTopology();
    virtual ~NetTopology();
public:

protected:

};

#endif //NETOPOLOGY_H

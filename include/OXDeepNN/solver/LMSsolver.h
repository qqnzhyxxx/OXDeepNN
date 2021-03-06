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
Class type: Class of Least Mean Square(LMS)
Author: Niu ZhiYong
Date: 2017-04-13
Description:
This class defind the one step Solver of
Least Mean Square.
**************************************************/
#ifndef LMSOVLER_H
#define LMSOVLER_H

#include <Eigen/Eigen>
#include "Macros.h"
#include "ArtificialNeure.h"

using namespace Eigen;
class LMSsolver
{
public:
    LMSsolver(void);
    virtual ~LMSsolver(void);
protected:

public:
    double Solver( INOUT ArtificialNeure *pneure , IN double expectoutput, IN double learnrate);

};

#endif //LMSOVLER_H


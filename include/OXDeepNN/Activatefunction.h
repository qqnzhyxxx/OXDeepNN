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
* Author: Niu ZhiYong
* Date:2017-03-20
* Description:
**************************************************/
/*************************************************
Class type: Class of Neure Activate Function
Author: Niu ZhiYong
Date:2017-03-20
Description:
This class defind all kinds of Activate Function.
And set Activation process algorithm by
(double Activatefunction::Active ( IN double input)).
**************************************************/
#pragma once
#include <cmath>
#include "Macros.h"
#include "Enumeration.h"

/*Class of Neure Activate Function */

class Activatefunction
{
public:

    Activatefunction( IN EnumActiveFunction functype )
    {
         this->m_FuncationEnum = functype;
    }
    virtual ~Activatefunction(void)
    {

    }

public:
     EnumActiveFunction m_FuncationEnum;

protected:
    /// @brief  Sigmoid Activate Function
    /// @input  <double>
    /// @return <double>(0~1)
    inline double Sigmoid( IN double input );
    /// @brief  Heaviside Activate Function
    /// @input  <double>
    /// @return <int>(0,1)
    inline double Heaviside( IN double input );
    /// @brief  Signum Activate Function
    /// @input  <double>
    /// @return <int>(-1,0,1)
    inline double Signum( IN double input);
    /// @brief  tanh() Activate Function
    /// @input  <double>
    /// @return <double>(-1~1)
    inline double Tanh( IN double input);
public:
    /// @brief  (Not Useing)Activate Function Pointer
    /// @input  <double>
    /// @return Function Pointer decide by m_FuncationEnum
    inline auto (Activatefunction::*pActiveFunc())( IN double input)
    {
        return &Activatefunction::Sigmoid;
    }
    /// @brief  Activate Function Pointer
    /// @input  <double>
    /// @return <double>The Output of Activate Function decide by m_FuncationEnum
    inline double ActiveFunc ( IN double input);

};
/* Function implementation */
inline double Activatefunction::ActiveFunc ( IN double input)
{
    switch (m_FuncationEnum)
    {
    case HeavisideEnum:
        return Activatefunction::Heaviside(input);
        break;
    case SigmoidEnum:
        return Activatefunction::Sigmoid(input);
        break;
    case SignumEnum:
        return Activatefunction::Sigmoid(input);
        break;
    case TanhEnum:
        return Activatefunction::Tanh(input);
        break;
    default:
        break;
    }
}

inline double Activatefunction::Sigmoid( IN double input )
{
    return ( 1.0 / ( 1.0 + exp(-input)));
}
inline double Activatefunction::Heaviside( IN double input)
{
    if( input >= 0 )
    {
        return 1;
    }
    else
        return 0;
}
inline double Activatefunction::Signum( IN double input)
{
    if( input > 0 )
        return 1;
    else if( input = 0 )
        return 0;
    else
        return -1;
}
inline double Activatefunction::Tanh( IN double input)
{
    return tanh(input);
}


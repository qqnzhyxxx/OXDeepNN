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
Class type: Class of Basis  Neure Layer
Author: Niu ZhiYong
Date: 2017-03-29
Description: Father Class of Neure Layer.
This class defind the Basic Artificial Neure Layer property.
Each layer of the neural network has two actions,
namely forward propagation and backward propagation
Forward propagation to get the output,
Backward propapation to get the error gradients,
and fix the weight of neuros.
**************************************************/
#pragma once

#include <vector>
#include <memory>
#include "ArtificialNeure.h"
#include "Enumeration.h"
#include "Macros.h"
#include <Eigen/Eigen>

using namespace std;
using namespace Eigen;

class NeureLayer
{
public:
    NeureLayer(IN int neurenumber , IN EnumActiveFunction functype ,
               IN int inputnum ,IN bool boffset);
    virtual ~NeureLayer(void);

protected:
    int                                       m_NeureNumber;    /*the number of neures in layer*/
    vector< shared_ptr<ArtificialNeure> >     m_pNeureList;     /*to store the neures in layer */
    VectorXd                                  m_LayerOutputList;/*to store the output of this layer*/

public:
    /// @brief  Get Neure List in the layer outside the object
    /// @input  <void>
    /// @return <void>
    vector< shared_ptr<ArtificialNeure> > NeureList() const;

    /// @brief  Get Output List of the layer outside the object
    /// @input  <void>
    /// @return <void>
    VectorXd LayerOutputList() const;

    /// @brief  Forward Propagation Function
    /// @input  <bool> boffset
    /// @return <void>
    virtual void Inital();
    /// @brief  Forward Propagation Function
    /// @input  <bool> boffset
    /// @return <void>
    virtual void ForwardPropagate();

    /// @brief  Backward Propagation Function
    /// @input  <bool> boffset
    /// @return <void>
    virtual void BackwardPropagete();




};

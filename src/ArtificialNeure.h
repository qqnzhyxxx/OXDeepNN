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
Class type: Class of Basis Artificial Neure
Author: Niu ZhiYong
Date: 2017-03-20
Description:
This class defind the Artificial Neure property.
**************************************************/
#pragma once

#include <gsl/gsl_vector.h>
#include "Macros.h"
#include "Activatefunction.h"

class ArtificialNeure
{
public:

    /// @param[in] inputNum >= 1
    ArtificialNeure(IN EnumActiveFunction functype, IN int inputnum)
    {
        if(inputnum<1)
            throw "The Input Number of Artificial Neure is < 1!";
        else
        {
            this->SetInputNum( inputnum );
            this->SetWeightNum();
            this->m_pActiveFun = new Activatefunction(functype);
            m_pInputList = gsl_vector_alloc(m_InputNum);
            m_pWeightList = gsl_vector_alloc(m_WeightNum);

        }
    }
    ~ArtificialNeure(void)
    {
        gsl_vector_free(m_pInputList);
        gsl_vector_free(m_pWeightList);
        delete m_pActiveFun;
    }

protected:

   int                  m_WeightNum;
   int                  m_InputNum;
   Activatefunction     *m_pActiveFun;      /*Activate Function*/

   gsl_vector           *m_pWeightList;     /*神经元权重向量 */
   gsl_vector           *m_pInputList;      /*神经元输入参数 */
public:

   /* Property Set Function */
   /// @brief  Set The Number of Artificial Neure Input Vector
   /// @input  <int> inputnum
   /// @return <void>
   inline void SetInputNum( IN int inputnum );
   /// @brief  Set Artificial Neure Input Vector
   /// @input  <gsl_vector> *inputlist
   /// @return <void>
   inline void SetInputList( IN gsl_vector *inputlist );
   /// @brief  Set The Number of Artificial Neure Weight Vector(Decided by InputNum)
   /// @input  <void>
   /// @return <void>
   inline void SetWeightNum();
   /// @brief  Set Artificial Neure Weight Vector
   /// @input  <gsl_vector> *weightlist
   /// @return <void>
   inline void SetWeightList( IN gsl_vector *weightlist );

   /* Property Get Function */
   /// @brief  Get The Number of Artificial Neure Input Vector
   /// @input  <void>
   /// @return <void>
   inline int GetInputNum( );
   /// @brief  Get Artificial Neure Input Vector
   /// @input  <gsl_vector> *inputlist
   /// @return <void>
   inline void GetInputList( OUT gsl_vector *inputlist );
   /// @brief  Get The Number of Artificial Neure Weight Vector(Decided by InputNum)
   /// @input  <void>
   /// @return <void>
   inline int GetWeightNum();
   /// @brief  Get Artificial Neure Weight Vector
   /// @input  <gsl_vector> *weightlist
   /// @return <void>
   inline void GetWeightList( OUT gsl_vector *weightlist );
   /// @brief  Artificial Neure Activation Produces Output
   /// @input  <void>
   /// @return <double> Output of one Artificial Neure
   inline double NeureOutput();

};
/* Function implementation */
inline void ArtificialNeure::SetInputNum( IN int inputnum)
{
    m_InputNum = inputnum;
}
inline void ArtificialNeure::SetWeightNum()
{
    m_WeightNum = m_InputNum + 1;
}
inline void ArtificialNeure::SetInputList( IN gsl_vector *inputlist)
{
    gsl_vector_memcpy(m_pInputList , inputlist);
}
inline void ArtificialNeure::SetWeightList( IN gsl_vector *weightlist)
{
    gsl_vector_memcpy(m_pWeightList, weightlist);
}
/*****************************/
inline int ArtificialNeure::GetInputNum( )
{
    return m_InputNum ;
}
inline int ArtificialNeure::GetWeightNum()
{
    return m_WeightNum ;
}
inline void ArtificialNeure::GetInputList( OUT gsl_vector *inputlist)
{
    gsl_vector_memcpy( inputlist, m_pInputList );
}
inline void ArtificialNeure::GetWeightList( OUT gsl_vector *weightlist)
{
    gsl_vector_memcpy( weightlist, m_pWeightList );
}
/*****************************/
inline double ArtificialNeure::NeureOutput()
{
    double temp = 0;
    return temp;
}

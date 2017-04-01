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

#include <stdexcept>
#include <Eigen/Eigen>
#include "Macros.h"
#include "Activatefunction.h"
using namespace Eigen;

class ArtificialNeure
{
public:

    /// @param[in] inputNum >= 1
    ArtificialNeure(IN EnumActiveFunction functype, IN int inputnum, IN bool boffset)
    {
        if(inputnum<1)
            throw "The Input Number of Artificial Neure is < 1!";
        else
        {
            if(inputnum <1)
                throw std::runtime_error("The Input Number < 1!");
            this->SetbOffset( boffset );
            this->SetInputNum( inputnum );
            this->SetWeightNum();
            this->m_pActiveFun = new Activatefunction(functype);
            m_InputList.resize(m_InputNum);
            m_WeightList.resize(m_WeightNum);
        }
    }
    virtual ~ArtificialNeure(void)
    {
        delete m_pActiveFun;
    }

protected:
    bool                    m_bOffset;              /*set if the Neure has Offset of not */
    int                     m_WeightNum;            /*equal m_InputNum*/
    int                     m_InputNum;             /*equal m_WeightNum*/
    Activatefunction        *m_pActiveFun;          /*Activate Function*/
    VectorXd                m_WeightList;           /*神经元权重向量Row Vector */
    VectorXd                m_InputList;            /*神经元输入参数Column Vector */

public:

    /* Property Set Function */

    /// @brief  Set if the Neure has Offset of not
    /// @input  <bool> boffset
    /// @return <void>
    inline void SetbOffset( IN bool boffset );
    /// @brief  Set The Number of Artificial Neure Input Vector
    /// @input  <int> inputnum
    /// @return <void>
    inline void SetInputNum( IN int inputnum );
    /// @brief  Set Artificial Neure Input Vector
    /// @input  <gsl_vector> *inputlist
    /// @return <void>
    inline void SetInputList( IN const Eigen::VectorXd &inputlist );
    /// @brief  Set The Number of Artificial Neure Weight Vector(Decided by InputNum)
    /// @input  <void>
    /// @return <void>
    inline void SetWeightNum();
    /// @brief  Set Artificial Neure Weight Vector
    /// @input  <gsl_vector> *weightlist
    /// @return <void>
    inline void SetWeightList( IN const Eigen::VectorXd &weightlist );

    /* Property Get Function */

    /// @brief  Find the Neure has Offset of not
    /// @input  <bool> boffset
    /// @return <void>
    inline bool GetbOffset( ) const;
    /// @brief  Get The Number of Artificial Neure Input Vector
    /// @input  <void>
    /// @return <void>
    inline int GetInputNum( ) const;
    /// @brief  Get Artificial Neure Input Vector
    /// @input  <gsl_vector> *inputlist
    /// @return <void>
    inline void GetInputList( OUT Eigen::VectorXd &inputlist ) const;
    /// @brief  Get The Number of Artificial Neure Weight Vector(Decided by InputNum)
    /// @input  <void>
    /// @return <void>
    inline int GetWeightNum() const;
    /// @brief  Get Artificial Neure Weight Vector
    /// @input  <gsl_vector> *weightlist
    /// @return <void>
    inline void GetWeightList( OUT Eigen::VectorXd &weightlist ) const;
    /// @brief  Artificial Neure Activation Produces Output
    /// @input  <void>
    /// @return <double> Output of one Artificial Neure
    inline double NeureOutput() const;

};
/* Function implementation */
inline void ArtificialNeure::SetbOffset(bool boffset)
{
    m_bOffset = boffset;
}
inline void ArtificialNeure::SetInputNum( IN int inputnum)
{

    if (m_bOffset)
        m_InputNum = inputnum + 1;      //m_InputList(0) = 1 for Offset
    else
        m_InputNum = inputnum;          //the Neure has not Offset
}
inline void ArtificialNeure::SetWeightNum()
{
    m_WeightNum = m_InputNum ;
}
inline void ArtificialNeure::SetInputList( IN const Eigen::VectorXd &inputlist)
{
    if( inputlist.maxCoeff()>1 || inputlist.minCoeff()<-1 )
        throw std::range_error("The Input out of range [-1,1]!");

    if (m_bOffset)
    {
        //m_InputList(0) = 1 for Offset
        m_InputList(0)  = 1;
        for (int i = 0; i< inputlist.rows(); i++)
        {
            m_InputList(i+1) = inputlist(i);
        }
    }
    else
    {   //the Neure has not Offset
        for (int i = 0; i< inputlist.rows(); i++)
        {
            m_InputList(i) = inputlist(i);
        }
    }

}
inline void ArtificialNeure::SetWeightList( IN const Eigen::VectorXd &weightlist)
{
    m_WeightList = weightlist;
}
/*****************************/
inline bool ArtificialNeure::GetbOffset() const
{
    return m_bOffset;
}
inline int ArtificialNeure::GetInputNum( ) const
{
    return m_InputNum ;
}
inline int ArtificialNeure::GetWeightNum() const
{
    return m_WeightNum ;
}
inline void ArtificialNeure::GetInputList( OUT Eigen::VectorXd &inputlist) const
{
    if (m_bOffset)
    {
        //m_InputList(0) = 1 for Offset
        inputlist.resize(m_InputList.rows()-1);
        for (int i = 0; i< (m_InputList.rows()-1); i++)
        {
            inputlist(i) = m_InputList(i+1);
        }
    }
    else
    {
        //the Neure has not Offset
        inputlist.resize(m_InputList.rows());
        for (int i = 0; i< m_InputList.rows(); i++)
        {
            inputlist(i) = m_InputList(i);
        }
    }

}
inline void ArtificialNeure::GetWeightList( OUT Eigen::VectorXd &weightlist) const
{
    weightlist = m_WeightList;
}
/*****************************/
inline double ArtificialNeure::NeureOutput() const
{
    return ( m_pActiveFun->ActiveFunc( m_WeightList.dot(m_InputList) ) );
}
#include <iostream>
#include <memory>
#include "qcustomplot.h"
#include "layers/NeureLayer.h"
#include "Enumeration.h"
#include <QApplication>
using namespace std;
/*************************************************
Demo intruduce: Show the Artificial Neure work condition
                in MLPerceptron
Author: Niu ZhiYong
Date: 2017-04-20
tips:
**************************************************/
int main(int argc, char *argv[])
{
    cout<<"MLPerceptron Test"<<endl;
    shared_ptr< NeureLayer > layer = make_shared<NeureLayer>(NeureLayer(1,SigmoidEnum,2,true));

    int i = layer->NeureList().at(0)->GetInputNum();
    cout<<"m_InputNum = "<<i<<endl;
}

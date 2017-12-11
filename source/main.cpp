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
#include <iostream>
#include "qcustomplot.h"

#include "Enumeration.h"
#include "Activatefunction.h"
#include "ArtificialNeure.h"
#include <Eigen/Dense>


using namespace std;

int main(int argc, char *argv[])
{
    cout << "C++ standard version(__cplusplus)=" << __cplusplus  <<endl;
    /*
    Eigen::Vector3d V1;
    Eigen::VectorXd V2;
    V1 = Eigen::Vector3d::Random();
    V2 = V1;
    cout<<"V1 = \n"<<V1<<endl;
    cout<<"V2 = \n"<<V2<<endl;
    cout<<"V2 size = "<<V2.size()<<endl;

    ArtificialNeure *myNeure = new ArtificialNeure(HeavisideEnum, 2, true);
    Eigen::Vector2d invec(1,0.3);
    Eigen::Vector3d weivec1(10,11,12);
    myNeure->SetNormParameter(1);
    myNeure->SetInputList(invec);
    myNeure->SetWeightList(weivec1);
    cout<<"myNeure->NeureOutput() = "<<myNeure->NeureOutput()<<endl;
    Eigen::VectorXd outvec;
    Eigen::VectorXd weioutvec;
    myNeure->GetInputList(outvec);
    myNeure->GetWeightList(weioutvec);
    cout<<"myNeure->GetInputList(outvec) = \n"<<outvec<<endl;
    cout<<"myNeure->GetWeightList(weioutvec) = \n"<<weioutvec<<endl;

    // *********set up gui************
    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;
    if (window->objectName().isEmpty())
        window->setObjectName(QStringLiteral("MainWindow"));
    // setup customPlot as central widget of window:
    QCustomPlot customPlot;
    window->setCentralWidget(&customPlot);

    // create plot (from quadratic plot example):
    QVector<double> x(10), y(10);
    double jj = -5;
    for (int i=0; i<10; ++i)
    {
      x[i] = jj;
      y[i] = jj*jj;
      jj = jj + 1;
    }
    customPlot.addGraph();
    customPlot.graph(0)->setData(x, y);
    customPlot.xAxis->setLabel("x");
    customPlot.yAxis->setLabel("y");
    customPlot.rescaleAxes();
    customPlot.graph(0)->setLineStyle(QCPGraph::lsNone);//lsStepCenter
    customPlot.graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
    //customPlot.graph(1)->setErrorType(QCPGraph::etValue);
    //customPlot.xAxis->setRange(-50, 50);
    //customPlot.yAxis->setRange(-1, 1);
    //customPlot.graph(0)->setLineStyle(QCPGraph::lsLine);
    //customPlot.graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    customPlot.replot();
    window->setGeometry(100, 100, 500, 400);
    window->show();


    cout<<"Build completed!"<<endl;
    return app.exec();
    */
    cout<<"Build completed!"<<endl;
    return 0;
}

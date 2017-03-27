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
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_eigen.h>
#include "qcustomplot.h"
#include <QApplication>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include "Enumeration.h"
#include "Activatefunction.h"
#include "ArtificialNeure.h"
#include <Eigen/Dense>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "C++ standard version(__cplusplus)=" << __cplusplus  <<endl;

    ArtificialNeure *myNeure = new ArtificialNeure(HeavisideEnum,2);
    Eigen::Vector2d invec(2,3);
    Eigen::Vector3d weivec(10,11,12);
    myNeure->SetInputList(invec);
    myNeure->SetWeightList(weivec);
    cout<<"myNeure->NeureOutput() = "<<myNeure->NeureOutput()<<endl;
    Eigen::VectorXd outvec;
    Eigen::VectorXd weioutvec;
    myNeure->GetInputList(outvec);
    myNeure->GetWeightList(weioutvec);
    cout<<"myNeure->GetInputList(outvec) = \n"<<outvec<<endl;
    cout<<"myNeure->GetWeightList(weioutvec) = \n"<<weioutvec<<endl;
    QApplication app(argc, argv);
    /* set up gui*/

    QMainWindow *window = new QMainWindow;

    if (window->objectName().isEmpty())
        window->setObjectName(QStringLiteral("MainWindow"));
    // setup customPlot as central widget of window:
    QCustomPlot customPlot;
    window->setCentralWidget(&customPlot);

    // create plot (from quadratic plot example):
    QVector<double> x(1000), y(1000);
    double jj = -50;
    for (int i=0; i<1000; ++i)
    {
      x[i] = jj;
      y[i] = jj*jj;
      jj = jj + 0.1;
    }
    customPlot.addGraph();
    customPlot.graph(0)->setData(x, y);
    customPlot.xAxis->setLabel("x");
    customPlot.yAxis->setLabel("y");
    customPlot.rescaleAxes();
    customPlot.graph(0)->setLineStyle(QCPGraph::lsStepCenter);
    customPlot.graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
    //customPlot.graph(1)->setErrorType(QCPGraph::etValue);
    //customPlot.xAxis->setRange(-50, 50);
    //customPlot.yAxis->setRange(-1, 1);
    //customPlot.graph(0)->setLineStyle(QCPGraph::lsLine);
    //customPlot.graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    customPlot.replot();
    window->setGeometry(100, 100, 500, 400);
    window->show();



    return app.exec();


    //return 0;
}

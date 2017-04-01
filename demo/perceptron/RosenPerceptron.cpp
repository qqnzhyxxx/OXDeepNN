#include <iostream>
#include "QTplot/qcustomplot.h"
#include "ArtificialNeure.h"
#include "Enumeration.h"
#include <QApplication>
#include <Eigen/Eigen>
using namespace std;
using namespace Eigen;
/*************************************************
Demo intruduce: Show the Artificial Neure work condition
                in Rosenblatt Perceptron
Author: Niu ZhiYong
Date: 2017-04-01
tips:
**************************************************/
int main(int argc, char *argv[])
{
    // first ,produce some date for training
    MatrixXd classA_date = MatrixXd::Random(2,100);
    VectorXd classA_type;
    classA_type.setOnes(100);
    //classA_type= VectorXi::Ones();
    MatrixXd classB_date =  MatrixXd::Random(2,100);
    VectorXd classB_type;
    classB_type.setOnes(100);
    //classB_type= VectorXi::Ones();
    classB_type = -1 * classB_type;
    classA_date = classA_date + MatrixXd::Constant(2,100,3.5);
    classB_date = classB_date + MatrixXd::Constant(2,100,1);
    // set an artificial neure
    ArtificialNeure *neure = new ArtificialNeure(SignumEnum, 2, false);
    // set Normalization parameters
    double classA_normparameter = classA_date.maxCoeff();
    double classB_normparameter = classB_date.maxCoeff();
    // set initial weightlist

    // start to train



    /* *********display result************/
    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;
    if (window->objectName().isEmpty())
        window->setObjectName(QStringLiteral("MainWindow"));
    // setup customPlot as central widget of window:
    QCustomPlot customPlot;
    window->setCentralWidget(&customPlot);
    customPlot.axisRect()->insetLayout()
        ->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    customPlot.legend->setVisible(true);
    // create plot (from quadratic plot example):
    QVector<double> x1(100), y1(100);

    for (int i=0; i<100; i++)
    {
      x1[i] = classA_date(0,i);
      y1[i] = classA_date(1,i);
    }
    customPlot.addGraph(customPlot.xAxis,customPlot.yAxis);
    customPlot.graph(0)->setData(x1, y1);
    customPlot.xAxis->setLabel("x");
    customPlot.yAxis->setLabel("y");
    customPlot.graph(0)->setLineStyle(QCPGraph::lsNone);//lsStepCenter
    customPlot.graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle,
                                                         Qt::red, Qt::white, 7));
    customPlot.graph(0)->setName("classA_date");

    QVector<double> x2(100), y2(100);
    for (int i=0; i<100; i++)
    {
      x2[i] = classB_date(0,i);
      y2[i] = classB_date(1,i);
    }
    customPlot.addGraph(customPlot.xAxis,customPlot.yAxis);
    customPlot.graph(1)->setData(x2, y2);
    customPlot.graph(1)->setLineStyle(QCPGraph::lsNone);//lsStepCenter
    customPlot.graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle,
                                                         Qt::blue, Qt::white, 7));
    customPlot.graph(1)->setName("classB_date");
    customPlot.rescaleAxes();

    window->setGeometry(100, 100, 500, 400);
    window->show();



    return app.exec();
    //return 0;
}

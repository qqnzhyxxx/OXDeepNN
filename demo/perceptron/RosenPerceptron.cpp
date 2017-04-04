#include <iostream>
#include "QTplot/qcustomplot.h"
#include "ArtificialNeure.h"
#include "Enumeration.h"
#include <QApplication>
#include <Eigen/Eigen>
#include <cmath>
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

    classB_type = -1 * classB_type;
    cout<<"classA_type="<<classA_type(0)<<endl;
    cout<<"classB_type="<<classB_type(0)<<endl;

    classA_date = classA_date + MatrixXd::Constant(2,100,3.5);
    classB_date = classB_date + MatrixXd::Constant(2,100,1);
    // set Normalization parameters
    double classA_normparameter = 0;
    if( abs(classA_date.maxCoeff()) >= abs(classA_date.minCoeff()) )
        classA_normparameter =abs(classA_date.maxCoeff());
    else
        classA_normparameter = abs(classA_date.minCoeff());
    double classB_normparameter = 0;

    if( abs(classB_date.maxCoeff()) >= abs(classB_date.minCoeff()) )
        classB_normparameter =abs(classB_date.maxCoeff());
    else
        classB_normparameter = abs(classB_date.minCoeff());

    double normparameter = 0;
    if(classA_normparameter >= classB_normparameter)
        normparameter = classA_normparameter;
    else
        normparameter = classB_normparameter;

    cout<<"normparameter = "<<normparameter<<endl;
    // set initial weightlist
    Vector3d weightlist;// = Vector3d::Random();
    weightlist(0) = -0.888 ;
    weightlist(1) = 3.222;
    weightlist(2) = 3.222;
    //weightlist = Vector3d::Random();
    cout<<"inital_weightlist =\n"<<weightlist<<endl;
    // start to train
    // set an artificial neure
    ArtificialNeure *neure = new ArtificialNeure(SignumEnum, 2, true);
    neure->SetWeightList(weightlist);

    Vector2d inputA = Vector2d::Zero();
    Vector2d inputB = Vector2d::Zero();
    double learnrate = 0.01;
    VectorXd totalinputlist;
    totalinputlist.setZero(weightlist.size());

    for (int i = 0; i < 100; i++)
    {
        VectorXd totalinputlist(weightlist.size());
        inputA(0) = classA_date(0,i)/normparameter;
        inputA(1) = classA_date(1,i)/normparameter;
        neure->SetInputList(inputA);

        neure->GetTotalInputList(totalinputlist);
        weightlist = weightlist +learnrate * ( classA_type(i) - neure->NeureOutput() )*totalinputlist;
        cout<<"inputA = \n"<< inputA<<endl;
        cout<<"totalinputA = \n"<< totalinputlist<<endl;
        cout<<"NeureOutputA = "<<neure->NeureOutput()<<endl;
        cout<<"classA_type-NeureOutput = "<< ( classA_type(i) - neure->NeureOutput() )<<endl;
        cout<<"A_weightlist = \n"<<weightlist<<endl;

        inputB(0) = classB_date(0,i)/normparameter;
        inputB(1) = classB_date(1,i)/normparameter;
        neure->SetInputList(inputB);

        neure->GetTotalInputList(totalinputlist);
        weightlist = weightlist +learnrate * ( classB_type(i) - neure->NeureOutput() )*totalinputlist;
        cout<<"inputB = \n"<< inputB<<endl;
        cout<<"totalinputB = \n"<< totalinputlist<<endl;
        cout<<"NeureOutputB = "<<neure->NeureOutput()<<endl;
        cout<<"classB_type-NeureOutput = "<< ( classB_type(i) - neure->NeureOutput() )<<endl;
        cout<<"B_weightlist = \n"<<weightlist<<endl;
    }



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

    QVector<double> x3(5), y3(5);
//    weightlist(0) = -0.888 ;
//    weightlist(1) = 0.222;
//    weightlist(2) = 0.222;
    weightlist = normparameter*weightlist;
    for (int i=0; i<5; i++)
    {
      x3[i] =i;
      y3[i] =(-1*x3[i]*weightlist(1)/weightlist(2) - weightlist(0)/weightlist(2));
    }
    customPlot.addGraph(customPlot.xAxis,customPlot.yAxis);
    customPlot.graph(2)->setPen(QColor(50, 50, 50, 255));
    customPlot.graph(2)->setData(x3, y3);
    customPlot.graph(2)->setLineStyle(QCPGraph::lsLine);//lsStepCenter

    customPlot.graph(2)->setName("Decision boundary");

    customPlot.rescaleAxes();
    window->setGeometry(100, 100, 500, 400);
    window->show();



    return app.exec();
    //return 0;
}

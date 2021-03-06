#include <iostream>
#include "qcustomplot.h"
#include "ArtificialNeure.h"
#include "Enumeration.h"
#include "solver/Perceptronsolver.h"
#include "solver/LMSsolver.h"
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
    VectorXd weightlistout ;
    Vector3d initalweightlist = Vector3d::Random();
    initalweightlist = Vector3d::Random();
    //initalweightlist = Vector3d::Random();
    //initalweightlist(0) = 0;//-1.5 ;
    //initalweightlist(1) = 0;//0.25;
    //initalweightlist(2) = 0;//0.25;

    cout<<"inital_weightlist =\n"<<initalweightlist<<endl;

    // set an artificial neure
    ArtificialNeure *neure = new ArtificialNeure(SignumEnum, 2, true);
    neure->SetWeightList(initalweightlist);
    neure->SetNormParameter(normparameter);
    Vector2d inputA = Vector2d::Zero();
    Vector2d inputB = Vector2d::Zero();
    double learnrate = 0.01;
    VectorXd totalnorminputlist;
    totalnorminputlist.setZero(initalweightlist.size());
    // start to train
    int looptimes = 0;
    LMSsolver lmssolver;
    Perceptronsolver persolver;

    do
    {
        looptimes++;
        for (int i = 0; i < 100; i++)
        {
            double outerror = 0;

            inputA(0) = classA_date(0,i);
            inputA(1) = classA_date(1,i);
            neure->SetInputList(inputA);

            //outerror = persolver.Sovler(neure, classA_type(i) , learnrate);
            outerror = lmssolver.Solver(neure, classA_type(i) , learnrate);
            neure->GetTotalNormInputList(totalnorminputlist);
            neure->GetWeightList(weightlistout);
            cout<<"The outerror  = "<<outerror<<endl;

            inputB(0) = classB_date(0,i);
            inputB(1) = classB_date(1,i);
            neure->SetInputList(inputB);
            //outerror = persolver.Sovler(neure, classB_type(i) , learnrate);
            outerror = lmssolver.Solver(neure, classB_type(i) , learnrate);
            neure->GetTotalNormInputList(totalnorminputlist);
            neure->GetWeightList(weightlistout);
            cout<<"The outerror  = "<<outerror<<endl;

        }   

    }while( looptimes<= 50  );
    cout<<"number of loop times = "<<looptimes<<endl;


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
    weightlistout = normparameter*weightlistout;
    for (int i=0; i<5; i++)
    {
      x3[i] =i;
      y3[i] =(-1*x3[i]*weightlistout(1)/weightlistout(2) - weightlistout(0)/weightlistout(2));
    }
    customPlot.addGraph(customPlot.xAxis,customPlot.yAxis);
    customPlot.graph(2)->setPen(QColor(50, 50, 50, 255));
    customPlot.graph(2)->setData(x3, y3);
    customPlot.graph(2)->setLineStyle(QCPGraph::lsLine);//lsStepCenter

    customPlot.graph(2)->setName("Decision boundary");

    QVector<double> x4(5), y4(5);

    initalweightlist = normparameter*initalweightlist;
    for (int i=0; i<5; i++)
    {
      x4[i] =i;
      y4[i] =(-1*x4[i]*initalweightlist(1)/initalweightlist(2) - initalweightlist(0)/initalweightlist(2));
    }
    customPlot.addGraph(customPlot.xAxis,customPlot.yAxis);
    customPlot.graph(3)->setPen(QColor(150, 50, 50, 255));
    customPlot.graph(3)->setData(x4, y4);
    customPlot.graph(3)->setLineStyle(QCPGraph::lsLine);//lsStepCenter

    customPlot.graph(3)->setName("inital boundary");
    // set Axis range
    customPlot.xAxis->setRange(0, 5);
    customPlot.yAxis->setRange(0, 5);
    //customPlot.rescaleAxes();
    window->setGeometry(100, 100, 500, 400);
    window->show();


    delete neure;
    return app.exec();
    //return 0;
}

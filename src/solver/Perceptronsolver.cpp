#include "solver/Perceptronsolver.h"



Perceptronsolver::Perceptronsolver()
{

}
Perceptronsolver::~Perceptronsolver()
{

}

double Perceptronsolver::Sovler(ArtificialNeure *pneure, double expectoutput, double learnrate)
{
    VectorXd weightlist;
    VectorXd totalnorminputlist;
    double error = 0;
    pneure->GetWeightList( weightlist );
    pneure->GetTotalNormInputList( totalnorminputlist );

    error = expectoutput - pneure->NeureOutput();
    weightlist = weightlist +learnrate * totalnorminputlist * error;
    pneure->SetWeightList( weightlist );

    return error;

}


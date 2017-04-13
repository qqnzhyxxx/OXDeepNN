#include "solver/LMSsolver.h"




LMSsolver::LMSsolver()
{

}

LMSsolver::~LMSsolver()
{

}

double LMSsolver::Solver(ArtificialNeure *pneure, double expectoutput, double learnrate)
{
    VectorXd weightlist;
    VectorXd totalnorminputlist;
    double error = 0;
    pneure->GetWeightList(weightlist);
    pneure->GetTotalInputList(totalnorminputlist);

    error = expectoutput - totalnorminputlist.dot( weightlist );
    weightlist = weightlist + learnrate * totalnorminputlist * error;
    pneure->SetWeightList(weightlist);

    return error;

}

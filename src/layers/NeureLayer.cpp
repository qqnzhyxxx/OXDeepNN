#include "layers/NeureLayer.h"

NeureLayer::NeureLayer(IN int neurenumber , IN EnumActiveFunction functype ,
                       IN int inputnum ,IN bool boffset)
{
    if(neurenumber <1)
        throw std::runtime_error("The Number of Neure in layer < 1!");
    m_NeureNumber = neurenumber;
    m_pNeureList.clear();
    m_LayerOutputList.resize(m_NeureNumber);
    for (int i = 0; i < m_NeureNumber; i++)
    {
        shared_ptr<ArtificialNeure> p (
                    new ArtificialNeure(functype, inputnum, boffset));
        m_pNeureList.push_back(p);
    }
}
NeureLayer::~NeureLayer()
{

}
void NeureLayer::Inital()
{

}
void NeureLayer::ForwardPropagate()
{
    for (int i = 0; i < m_NeureNumber; i++ )
    {
        m_LayerOutputList(i) = m_pNeureList.at(i)->NeureOutput();
    }

}

void NeureLayer::BackwardPropagete()
{

}
vector< shared_ptr<ArtificialNeure> > NeureLayer::NeureList() const
{
    return m_pNeureList ;
}

VectorXd NeureLayer::LayerOutputList() const
{
    return m_LayerOutputList;
}



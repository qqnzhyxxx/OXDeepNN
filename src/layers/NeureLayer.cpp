#include "layers/NeureLayer.h"

NeureLayer::NeureLayer(IN int neurenumber , IN EnumActiveFunction functype ,
                       IN int inputnum ,IN bool boffset)
{
    m_NeureNumber = neurenumber;
    m_pNeureList.clear();
    m_LayerOutputList.clear();
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

void NeureLayer::ForwardPropagate()
{

}

void NeureLayer::BackwardPropagete()
{

}
vector< shared_ptr<ArtificialNeure> > NeureLayer::GetNeureList() const
{

    return m_pNeureList ;
}

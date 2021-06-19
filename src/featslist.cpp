#include "featslist.h"

FeatsList::FeatsList(QObject *parent) : QObject(parent)
{

}

void FeatsList::push_back(Feats *feats)
{
    int index = m_feats.size();

    m_feats.push_back(feats);

    registerFeats(index);
}

Feats *FeatsList::operator[](int index) const
{
    Q_ASSERT(index < m_feats.size());
    return m_feats[index];
}

void FeatsList::insert(int index, Feats *feats)
{
    emit pre_insert(index);

    m_feats.insert(index, feats);

    for ( ; index < m_feats.size() ; ++index)
        reregisterFeats(index);

    emit post_insert(index);
}

int FeatsList::size() const
{
    return m_feats.size();
}

FeatsList::~FeatsList()
{
    for ( auto feats : m_feats ) {
        delete feats;
    }
}

void FeatsList::commeTuVeux2(int index)
{
    emit itemChanged(index);
}

void FeatsList::registerFeats(int index)
{
    auto feats = m_feats[index];

    connect(feats,&Feats::isFavChanged, this, &FeatsList::commeTuVeux2);
}

void FeatsList::unregisterFeats(int index)
{
    auto feats = (*this)[index];
    disconnect(feats);
}

void FeatsList::reregisterFeats(int index)
{
    unregisterFeats(index);
    registerFeats(index);
}

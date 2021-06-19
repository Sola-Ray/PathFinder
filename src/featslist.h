#ifndef FEATSLIST_H
#define FEATSLIST_H

#include "feats.h"

#include <QDebug>

#include <QObject>


class FeatsList : public QObject
{
    Q_OBJECT
    QList<Feats*> m_feats;

public:
    explicit FeatsList(QObject *parent = nullptr);
    void push_back(Feats* feats);
    Feats* operator[](int index) const;
    void insert(int index, Feats* feats);
    Q_INVOKABLE int size() const;

    ~FeatsList();

public slots:
    void commeTuVeux2(int index);
protected:
    void registerFeats(int index);
    void unregisterFeats(int index);
    void reregisterFeats(int index);

signals:
    void pre_insert(int index);
    void post_insert(int index);
    void itemChanged(int position);
};

#endif // FEATSLIST_H

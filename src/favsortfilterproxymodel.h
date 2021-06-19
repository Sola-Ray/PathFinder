#ifndef FAVSORTFILTERPROXYMODEL_H
#define FAVSORTFILTERPROXYMODEL_H

#include <QDebug>
#include <QSortFilterProxyModel>
#include "featsmodel.h"

class FavSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    FavSortFilterProxyModel(QObject *parent = 0);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
};

#endif // FAVSORTFILTERPROXYMODEL_H

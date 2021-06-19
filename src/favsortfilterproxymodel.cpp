#include "favsortfilterproxymodel.h"

FavSortFilterProxyModel::FavSortFilterProxyModel(QObject *parent):QSortFilterProxyModel(parent)
{
}

bool FavSortFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex index0 = sourceModel()->index(sourceRow, 0, sourceParent);

    return (sourceModel()->data(index0, this->sortRole()).toString().contains(filterRegExp()));
}

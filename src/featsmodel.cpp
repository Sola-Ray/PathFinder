#include "featsmodel.h"

FeatsModel::FeatsModel(QObject *parent)
{

}

void FeatsModel::addFeats(Feats *feats)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    m_feats.push_back(feats);
    //addFavFeats(feats);

    endInsertRows();
}

/*void FeatsModel::addFavFeats(Feats *feats)
{
    if(feats->isFav()) {
        m_fav.push_back(feats);
    }
}

void FeatsModel::removeFavFeats(Feats *feats)
{
    if(!feats->isFav()) {
        m_fav.removeOne(feats);
    }
}*/

int FeatsModel::rowCount(const QModelIndex &parent) const
{
    return m_feats.count();
}

QVariant FeatsModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_feats.count())
        return QVariant();

    Feats * feats = m_feats[index.row()];

    switch (role) {
        case NameRole:
            return feats->name();
        case IdRole:
            return feats->id();
        case DetailRole:
            return QVariant::fromValue(feats);
        case FavRole:
            return feats->isFav();
        default:
            return QVariant();
    }
}

bool FeatsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.row() < 0  || index.row() >= m_feats.count())
        return false;

    if(data(index, role) == value)
        return true;

    Feats * feats = m_feats[index.row()];
    if(role == NameRole)
        feats->setName(value.toString());
    if(role == IdRole)
        return false;
    if(role == FavRole)
        feats->setIsFav(value.toBool());

    QVector<int> roles;
    roles.append(role);

    QModelIndex topLeft = index.sibling(0, 0);
    QModelIndex bottomRight = index.sibling(m_feats.count() -1, 0);

    emit dataChanged(topLeft, bottomRight, roles);

    return true;
}

bool FeatsModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row < 0 || row + count >= m_feats.count())
        return false;

    beginRemoveRows(parent, row, row + count - 1);

    for(int n = 0; n < count; ++n) {
        m_feats.removeAt(row);
    }

    endRemoveRows();
    return true;
}

bool FeatsModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);

    for(int n = 0; n < count; ++n) {
        m_feats.insert(row, new Feats(0, 0, "Oui", "Oui", "", "", "", "", "", "", "", "", "", false));
    }

    endInsertRows();
    return true;
}

QHash<int, QByteArray> FeatsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[IdRole] = "id";
    roles[DetailRole] = "detailFeat";
    roles[FavRole] = "isFav";
    return roles;
}

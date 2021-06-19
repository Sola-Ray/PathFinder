#include "featsmodel.h"

FeatsModel::FeatsModel(QObject *parent) : QAbstractListModel(parent)
{

}

int FeatsModel::rowCount(const QModelIndex &parent) const
{
    return m_feats->size();
}

QVariant FeatsModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_feats->size())
        return QVariant();

    auto feats = (*m_feats)[index.row()];

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
    if(index.row() < 0  || index.row() >= m_feats->size())
        return false;

    if(data(index, role) == value)
        return true;

    auto feats = (*m_feats)[index.row()];
    if(role == NameRole)
        feats->setName(value.toString());
    if(role == IdRole)
        return false;
    if(role == FavRole)
        feats->setIsFav(value.toBool());

    QVector<int> roles;
    roles.append(role);

    QModelIndex topLeft = index.sibling(0, 0);
    QModelIndex bottomRight = index.sibling(m_feats->size() -1, 0);

    emit dataChanged(topLeft, bottomRight, roles);

    return true;
}




bool FeatsModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);

    for(int n = 0; n < count; ++n) {
        m_feats->insert(row, new Feats(0, 0, "Oui", "Oui", "", "", "", "", "", "", "", "", "", false));
    }

    endInsertRows();
    return true;
}

void FeatsModel::setList(FeatsList *list)
{
    beginResetModel();

    if ( m_feats )
        disconnect(m_feats);

    m_feats = list;

    if ( m_feats ) {
        connect(m_feats, &FeatsList::pre_insert, [=](int index){
            this->beginInsertRows(QModelIndex(),index, index);
        } );
        connect(m_feats, &FeatsList::post_insert, [=](){
            this->endInsertRows();
        } );

        connect(m_feats, &FeatsList::itemChanged, this, &FeatsModel::checkChanged);
    }
    endResetModel();
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

void FeatsModel::checkChanged(int index)
{
    qDebug() << "Favori " << index << " changed";
    auto row = this->index(index);
    emit FeatsModel::dataChanged(row, row);
}

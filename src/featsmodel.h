#ifndef FEATSMODEL_H
#define FEATSMODEL_H

#include "feats.h"
#include <QAbstractListModel>
#include <QObject>


class FeatsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum FeatsRoles {
        NameRole = Qt::UserRole + 1,
        IdRole,
        DetailRole,
        FavRole
    };
    FeatsModel(QObject *parent = 0);

    void addFeats(Feats *feats);

    /*void addFavFeats(Feats *feats);
    void removeFavFeats(Feats *feats);*/

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::DisplayRole) override;

    Q_INVOKABLE bool removeRows(int row, int count,
                                const QModelIndex &parent = QModelIndex()) override;
    Q_INVOKABLE bool insertRows(int row, int count,
                                const QModelIndex &parent = QModelIndex()) override;
    protected:
        QHash<int, QByteArray> roleNames() const override;
    private:
        QList<Feats*> m_feats;
        //QList<Feats*> m_fav;
};

#endif // FEATSMODEL_H

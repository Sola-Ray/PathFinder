#ifndef FEATS_H
#define FEATS_H

#include <QObject>

class Feats : public QObject
{
    Q_OBJECT

public:
    Feats();
    Feats(const int id, const int version, const QString name, const QString description, const QString reference, const QString source, const QString summary,
          const QString category, const QString conditions, const QString requires, const QString advantage, const QString special, const QString normal, const bool isFav);

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString reference READ reference WRITE setReference NOTIFY referenceChanged)
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QString summary READ summary WRITE setSummary NOTIFY summaryChanged)
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged)
    Q_PROPERTY(QString conditions READ conditions WRITE setConditions NOTIFY conditionsChanged)
    Q_PROPERTY(QString requires READ requires WRITE setRequires NOTIFY requiresChanged)
    Q_PROPERTY(QString advantage READ advantage WRITE setAdvantage NOTIFY advantageChanged)
    Q_PROPERTY(QString special READ special WRITE setSpecial NOTIFY specialChanged)
    Q_PROPERTY(QString normal READ normal WRITE setNormal NOTIFY normalChanged)

    void setId(int id);
    void setVersion(int version);
    void setIsFav(bool isFav);

    int id() const;
    int version() const;
    int isFav() const;
    QString name() const;
    QString source() const;
    QString summary() const;
    QString description() const;
    QString reference() const;
    QString category() const;
    QString conditions() const;
    QString requires() const;
    QString advantage() const;
    QString special() const;
    QString normal() const;

public slots:
    void setName(QString arg);
    void setAdvantage(QString arg);
    void setReference(QString arg);
    void setSource(QString arg);
    void setSummary(QString arg);
    void setCategory(QString arg);
    void setConditions(QString arg);
    void setRequires(QString arg);
    void setSpecial(QString arg);
    void setNormal(QString arg);
    void setDescription(QString arg);

signals:
    void nameChanged(QString arg);
    void advantageChanged(QString arg);
    void referenceChanged(QString arg);
    void sourceChanged(QString arg);
    void summaryChanged(QString arg);
    void categoryChanged(QString arg);
    void conditionsChanged(QString arg);
    void requiresChanged(QString arg);
    void specialChanged(QString arg);
    void normalChanged(QString arg);
    void descriptionChanged(QString arg);

private:
    int m_id;
    int m_version;
    bool m_isFav;
    QString m_name;
    QString m_description;
    QString m_reference;
    QString m_source;
    QString m_summary;
    QString m_category;
    QString m_conditions;
    QString m_requires;
    QString m_advantage;
    QString m_special;
    QString m_normal;
};

#endif // FEATS_H

#include "feats.h"

Feats::Feats()
{
}

Feats::Feats(const int id, const int version, const QString name, const QString description, const QString reference, const QString source,
             const QString summary, const QString category, const QString conditions, const QString requires, const QString advantage,
             const QString special, const QString normal, const bool isFav) : m_id(id), m_version(version), m_isFav(isFav), m_name(name), m_description(description), m_reference(reference),
             m_source(source), m_summary(summary), m_category(category), m_conditions(conditions), m_requires(requires), m_advantage(advantage),
             m_special(special), m_normal(normal)
{
}

void Feats::setId(int id)
{
    m_id = id;
}

void Feats::setVersion(int version)
{
    m_version = version;
}

void Feats::setIsFav(bool isFav)
{
    m_isFav = isFav;
}

int Feats::id() const
{
    return m_id;
}

int Feats::version() const
{
    return m_version;
}

int Feats::isFav() const
{
    return m_isFav;
}

QString Feats::name() const
{
    return m_name;
}

QString Feats::source() const
{
    return m_source;
}

QString Feats::summary() const
{
    return m_summary;
}

QString Feats::description() const
{
    return m_description;
}

QString Feats::reference() const
{
    return m_reference;
}

QString Feats::category() const
{
    return m_category;
}

QString Feats::conditions() const
{
    return m_conditions;
}

QString Feats::requires() const
{
    return m_requires;
}

QString Feats::advantage() const
{
    return m_advantage;
}

QString Feats::special() const
{
    return m_special;
}

QString Feats::normal() const
{
    return m_normal;
}

void Feats::setName(QString arg)
{
    if(m_name != arg) {
        m_name = arg;
        emit nameChanged(arg);
    }
}

void Feats::setAdvantage(QString arg)
{
    if(m_advantage != arg) {
        m_advantage = arg;
        emit advantageChanged(arg);
    }
}

void Feats::setReference(QString arg)
{
    if(m_reference != arg) {
        m_reference = arg;
        emit referenceChanged(arg);
    }
}

void Feats::setSource(QString arg)
{
    if(m_source != arg) {
        m_source = arg;
        emit sourceChanged(arg);
    }
}

void Feats::setSummary(QString arg)
{
    if(m_summary != arg) {
        m_summary = arg;
        emit summaryChanged(arg);
    }
}

void Feats::setCategory(QString arg)
{
    if(m_category != arg) {
        m_category = arg;
        emit categoryChanged(arg);
    }
}

void Feats::setConditions(QString arg)
{
    if(m_conditions != arg) {
        m_conditions = arg;
        emit conditionsChanged(arg);
    }
}

void Feats::setRequires(QString arg)
{
    if(m_requires != arg) {
        m_requires = arg;
        emit requiresChanged(arg);
    }
}

void Feats::setSpecial(QString arg)
{
    if(m_special != arg) {
        m_special = arg;
        emit specialChanged(arg);
    }
}

void Feats::setNormal(QString arg)
{
    if(m_normal != arg) {
        m_normal = arg;
        emit normalChanged(arg);
    }
}

void Feats::setDescription(QString arg)
{
    if(m_description != arg) {
        m_description = arg;
        emit descriptionChanged(arg);
    }
}

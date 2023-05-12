#include "DancesModel.h"
#include <QAbstractItemModel>
#include <QVariant>

DancesModel::DancesModel(QObject* parent)
    : QAbstractListModel(parent)
    , m_dances()
{

    m_dances.append(Dance { "Fortnite" });
    m_dances.append(Dance { "dawdawdaw" });
    m_dances.append(Dance { "46665" });
    m_dances.append(Dance { "tuuzt" });
}

QVariant DancesModel::data(const QModelIndex& index, int role) const
{
    int idx = index.row();

    if (role == NameRole) {
        return QVariant(m_dances[idx].name);
    }

    return QVariant("Error");
}

QHash<int, QByteArray> DancesModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ImageRole] = "image";
    return roles;
}
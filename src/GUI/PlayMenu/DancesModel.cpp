#include "DancesModel.h"
#include <QAbstractItemModel>
#include <QVariant>
#include <QDebug>

DancesModel::DancesModel(QObject* parent)
    : QAbstractListModel(parent)
    , m_dances()
{
    m_dances.append(Dance { "Beispiel 1", QUrl::fromLocalFile("C:/Users/Ben/source/repos/OpenDance/video/Beispiel_01.mp4").toString() });
    m_dances.append(Dance { "Beispiel 2", QUrl::fromLocalFile("C:/Users/Ben/source/repos/OpenDance/video/Beispiel_02.mp4").toString() });
    m_dances.append(Dance { "Beispiel 3", QUrl::fromLocalFile("C:/Users/Ben/source/repos/OpenDance/video/Beispiel_01.mp4").toString() });
    m_dances.append(Dance { "Beispiel 4", QUrl::fromLocalFile("C:/Users/Ben/source/repos/OpenDance/video/Beispiel_02.mp4").toString() });
}

QVariant DancesModel::data(const QModelIndex& index, int role) const
{
    int idx = index.row();

    if (role == NameRole) {
        return QVariant(m_dances[idx].name);
    }
    if (role == VideoRole) {
        return QVariant(m_dances[idx].video);
    }

    return QVariant("Error");
}

QHash<int, QByteArray> DancesModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[VideoRole] = "video";
    return roles;
}
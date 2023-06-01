#include "DancesModel.h"
#include <QAbstractItemModel>
#include <QVariant>
#include <QDebug>
#include <QCoreApplication>

DancesModel::DancesModel(QObject* parent)
    : QAbstractListModel(parent)
    , m_dances()
{
    QString videosPath = QCoreApplication::applicationDirPath() + "/../../../../";

    m_dances.append(Dance { "Tim 1", QUrl::fromLocalFile(videosPath + "video/Tim_1.MOV").toString() });
    m_dances.append(Dance { "Beispiel 1", QUrl::fromLocalFile(videosPath + "video/Beispiel_01.mp4").toString() });
    m_dances.append(Dance { "Tim 2", QUrl::fromLocalFile(videosPath + "video/Tim_2.MOV").toString() });
    m_dances.append(Dance { "Beispiel 2", QUrl::fromLocalFile(videosPath + "video/Beispiel_02.mp4").toString() });
    m_dances.append(Dance { "Tim 3", QUrl::fromLocalFile(videosPath + "video/Tim_3.MOV").toString() });
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
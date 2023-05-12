#include <QAbstractItemModel>

class DancesModel : public QAbstractListModel {
    Q_OBJECT

public:
    struct Dance {
        QString name;
    };

    enum DanceRoles {
        NameRole = Qt::UserRole + 1,
        ImageRole
    };

    DancesModel(QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int role) const;

    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex& parent = QModelIndex()) const { return m_dances.size(); };

private:
    QList<Dance> m_dances;
};
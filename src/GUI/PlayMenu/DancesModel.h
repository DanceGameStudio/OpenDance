#include <QAbstractItemModel>

class DancesModel : public QAbstractItemModel {
    Q_OBJECT

public:
    struct Dance {
        QString name;
    };

    enum DanceRoles {
        NameRole = Qt::UserRole + 1,
        ImageRole
    };

    DancesModel(QObject* parent);

    QVariant data(const QModelIndex& index, int role);

    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex& parent = QModelIndex()) const { return m_dances.size(); };
    int columnCount(const QModelIndex& parent = QModelIndex()) const { return 0; };

private slots:
    void goLeft();
    void goRight();

private:
    QList<Dance> m_dances;
};
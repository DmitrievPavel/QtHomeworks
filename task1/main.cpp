#include <QCoreApplication>
#include <QtSql>
#include <QtNetwork>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::database();
    QHostInfo info;
    return a.exec();
}

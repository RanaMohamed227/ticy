#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <sstream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

signals:
    void logInSuccessful();
    void signUpRequested();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::login *ui;
    std::istringstream iss;
};

#endif // LOGIN_H

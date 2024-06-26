#include "startup.h"
#include "ui_startup.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

startup::startup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startup)
{
    ui->setupUi(this);
}

startup::~startup()
{
    delete ui;
}

void startup::on_pushButton_clicked()
{
    setWindowTitle("Sign Up");

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QSqlQuery query;
    query.prepare("INSERT INTO Users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QMessageBox::warning(this, "Sign Up", "Sign Up failed: " + query.lastError().text());
    } else {
        QMessageBox::about(this, "Sign Up", "Sign Up is successful!\n\nLog In to play!");
        emit signUpSuccessful();
        this->hide();
    }
}

void startup::on_pushButton_2_clicked()
{
    emit logInRequested();
}

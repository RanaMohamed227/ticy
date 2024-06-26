#include "startup.h"
#include "ui_startup.h"
#include <fstream>
#include <QString>
#include <QMessageBox>

startup::startup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::startup)
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

    std::ofstream file;
    file.open("mydata.txt", std::ios::app);
    file << username.toStdString() << "," << password.toStdString() << std::endl;
    file.close();

    QMessageBox::about(this, "Sign Up", "Sign Up is successful!\n\nLog In to play!");
    emit signUpSuccessful();
    this->hide();
}


void startup::on_pushButton_2_clicked()
{
    emit logInRequested();
}


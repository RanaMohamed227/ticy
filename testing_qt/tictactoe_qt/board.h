#ifndef BOARD_H
#define BOARD_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

#include <QWidget>
#include <QCursor>
#include <QLabel>
#include <QPainter>
#include "gamestate.h"

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(GameState *state, QWidget *parent = 0);
    ~Board();

signals:

public slots:
    void setAllowed(bool);
    void getClicked(int&);

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);

private:
    GameState *state;
    QLabel *statusLabel;
    int tileSize;

public:
    bool allowed;
    int clicked;

};

#endif // BOARD_H

#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QPushButton>
#include <mainwindow.h>
enum Color{red, green, blank, selected};
class Piece:QPushButton
{
    Q_OBJECT

public:
    Piece(int x1,int y1, Color col, QMainWindow *w);
    int x,y;
    Color color=blank;
    bool isClicked = false;

    void getPos();
    void setPos(QPoint a);
    void changeColor(Color col);

public slots:
    void myClick();
    void revertColor();
};

#endif // PIECE_H

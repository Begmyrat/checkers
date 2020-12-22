#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QPushButton>
#include <mainwindow.h>
enum Color{red, green, blank, selected, black, white};

class Piece:QPushButton
{
    Q_OBJECT

public:
    Piece(int x1,int y1, Color col, QMainWindow *w);
    int x,y;
    int current_x, current_y;
    Color color=blank;
    bool isClicked = false;
    bool isChangingLocation= false;
    QPoint getPos();
    void setPos(QPoint a);
    void changeColor(Color col);


public slots:
    void myClick();
    void revertColor();
    void myRelease();
};

extern Piece *selectedPiece;
extern Piece *board[8][8];
extern QPoint *coordinate;
#endif // PIECE_H

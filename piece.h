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
    int current_x_screen_pos, current_y_screen_pos;
    Color color=blank;
    bool isKing = false;
    bool isClicked = false;
    bool isChangingLocation= false;
    QPoint getPos();
    void setPos(QPoint a);
    void changeColor(Color col);
    Piece* findIfPieceIsEatable(int index_x, int index_y);


public slots:
    void myClick();
    void revertColor();
    void myRelease();
};

extern Piece *selectedPiece;
extern Piece *board[8][8];
extern QPoint *coordinate;
#endif // PIECE_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include <vector>

enum Color{red,green,blank};

class Piece{
public:
    int x,y;
    Color color=blank;

    Piece(int x1,int y1, Color col){
        x = x1;
        y = y1;
        color = col;
    }
};

Piece *redObject;
Piece *greenObject;
Piece **board = new Piece*[8];

void drawPieces(QPainter painter){

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if((i+j)%2){
                    painter.setBrush(Qt::black);
                }
                else{
                    painter.setBrush(Qt::white);
                }
                painter.drawRect(j*50,i*50,50,50);
                if(i==1 or i==2){
                    painter.setBrush(Qt::red);
                    painter.drawEllipse(QPoint(j*50+25, i*50+25), 20,20);

                }
                else if(i==5 or i==6){
                    painter.setBrush(Qt::green);
                    painter.drawEllipse(QPoint(j*50+25, i*50+25), 20,20);
                }
            }
        }


}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPainter painter(this);

//    drawPieces(new QPainter(this));

    redObject = (Piece*) malloc(16*sizeof(Piece));
    greenObject = (Piece*) malloc(16*sizeof(Piece));

    for(int i=1;i<=2;i++){
        for(int j=0;j<8;j++){
            Piece red(i, j,Color::red);
            redObject[(i-1)*8+j] = red;
        }
    }

    for(int i=5;i<=6;i++){
        for(int j=0;j<8;j++){
            Piece green(i, j,Color::green);
            greenObject[(i-5)*8+j] = green;
        }
    }


    for(size_t i = 0 ; i < 8 ; ++i)
        board[i] = (Piece*) malloc(8*sizeof(Piece));

    for(int i=0;i<16;i++){
        Piece red_obje = redObject[i];
        board[red_obje.x][red_obje.y] = red_obje;

        Piece green_obje = greenObject[i];
        board[green_obje.x][green_obje.y] = green_obje;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter painter(this);


    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if((i+j)%2){
                painter.setBrush(Qt::black);
            }
            else{
                painter.setBrush(Qt::white);
            }
            painter.drawRect(j*50,i*50,50,50);
            if(i==1 or i==2){
                painter.setBrush(Qt::red);
                painter.drawEllipse(QPoint(j*50+25, i*50+25), 20,20);

            }
            else if(i==5 or i==6){
                painter.setBrush(Qt::green);
                painter.drawEllipse(QPoint(j*50+25, i*50+25), 20,20);
            }
        }
    }

//    for(int i=0;i<8;i++){
//            for(int j=0;j<8;j++){
//                if((i+j)%2){
//                    painter.setBrush(Qt::black);
//                }
//                else{
//                    painter.setBrush(Qt::white);
//                }
//                painter.drawRect(j*50,i*50,50,50);
//                if(board[i][j].color!=Color::blank){
//                    Piece x = board[i][j];
//                    if(x.color==Color::red)
//                        painter.setBrush(Qt::red);
//                    else
//                        painter.setBrush(Qt::green);
//                    painter.drawEllipse(QPoint((board[i][j].y)*50+25, board[i][j].x*50+25), 20,20);
//                }
//            }
//        }
}

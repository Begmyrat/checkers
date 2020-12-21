#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include <vector>
#include <piece.h>
#include <QMessageBox>

Piece *redObject[16];
Piece *greenObject[16];
Piece *board[8][8] = {nullptr};

void drawPieces(QPainter painter){
    printf("Printing Pieces");

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if((i+j)%2){
                painter.setBrush(Qt::black);
            }
            else{
                painter.setBrush(Qt::white);
            }
            painter.drawRect(j*50,i*50+50,50,50);

            if(i==1 or i==2){
                painter.setBrush(Qt::red);
                painter.drawEllipse(QPoint(j*50+25, i*50+75), 20,20);

            }
            else if(i==5 or i==6){
                painter.setBrush(Qt::green);
                painter.drawEllipse(QPoint(j*50+25, i*50+75), 20,20);
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

    for(int i=1;i<=2;i++){
        for(int j=0;j<8;j++){
            Piece *red = new Piece(i, j,Color::red, this);
            red->setPos(QPoint((j)*50+25, i*50+75));
            red->current_x = j*50+25, red->current_y = i*50+75;
            redObject[(i-1)*8+j] = red;
        }
    }

    for(int i=5;i<=6;i++){
        for(int j=0;j<8;j++){
            Piece *green = new Piece(i, j,Color::green, this);
            greenObject[(i-5)*8+j] = green;
            green->setPos(QPoint((j)*50+25, i*50+75));
            green->current_x = j*50+25, green->current_y = i*50+75;
        }
    }
    for(int i=0;i<16;i++){
        Piece *red_obje = redObject[i];
        board[red_obje->x][red_obje->y] = red_obje;

        Piece *green_obje = greenObject[i];
        board[green_obje->x][green_obje->y] = green_obje;
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j] == nullptr){
                Color co;
                if((i+j)%2 == 1)
                    co = Color::black;
                else
                    co = Color::white;
                Piece *x = new Piece(i,j,co, this);
                x->setPos(QPoint(j*50+25,i*50+75));
                x->current_x = j*50+25, x->current_y = i*50+75;
                board[i][j] = x;
            }
        }
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    if(selectedPiece != nullptr && selectedPiece->color != Color::white && selectedPiece->color != Color::black){
        QPoint x = this->mapFromGlobal(QCursor::pos());
        selectedPiece->setPos(x);
        this->update();
    }


    QPainter painter(this);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if((i+j)%2){
                painter.setBrush(Qt::black);
            }
            else{
                painter.setBrush(Qt::white);
            }
            painter.drawRect(j*50,i*50+50,50,50);
            Piece *x = board[i][j];
            if(x != NULL && x->color!=Color::blank){
                if(x->color==Color::red){
                    painter.setBrush(Qt::red);
                }
                else
                    painter.setBrush(Qt::green);
                //painter.drawEllipse(QPoint((x->y)*50+25, x->x*50+25), 20,20);
            }
        }
    }
}

void MainWindow::on_pushButton_File_clicked()
{
    QMessageBox::information(this, "title", "File Button is Clicked");
}

void MainWindow::on_pushButton_Edit_clicked()
{
    QMessageBox::information(this, "title", "Edit Button is Clicked");
}

void MainWindow::on_pushButton_Game_clicked()
{
    QMessageBox::information(this, "title", "Game Button is Clicked");
}

void MainWindow::on_pushButton_Help_clicked()
{
    QMessageBox::information(this, "title", "Help Button is Clicked");
}

void MainWindow::on_pushButton_NewGame_clicked()
{
    QMessageBox::information(this, "title", "NewGame Button is Clicked");
}

void MainWindow::on_pushButton_Left_clicked()
{
    QMessageBox::information(this, "title", "Left Button is Clicked");
}

void MainWindow::on_pushButton_Left_2_clicked()
{
    QMessageBox::information(this, "title", "Up Button is Clicked");
}

void MainWindow::on_pushButton_Left_3_clicked()
{
    QMessageBox::information(this, "title", "Right Button is Clicked");
}

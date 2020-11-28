#include "piece.h"
#include <QMessageBox>

int g = 0;
int r = 0;
Piece *selectedPiece = nullptr;

Piece::Piece(int x1,int y1, Color col, QMainWindow *w):QPushButton(w){
    x = x1;
    y = y1;
    color = col;
    this->connect( this , SIGNAL( clicked() ), this , SLOT( myClick() ) );
    this->setParent(w);
    changeColor(col);
}

void Piece::changeColor(Color col){
    QPalette pal = this->palette();
    if(!isClicked){
        if(col == Color::green)
            this->setStyleSheet(
                    "background-color: green;"
                    "border: 1px solid black;"  //outline
                    "border-radius: 15px;"     //corners
                    "font-size: 35px;"
                    );
        else if(col == Color::red)
            this->setStyleSheet(
                    "background-color: red;"
                    "border: 1px solid black;"  //outline
                    "border-radius: 15px;"     //corners
                    "font-size: 35px;"
                    );
        else if(col == Color::white)
            this->setStyleSheet(
                    "background-color: white;"
                    "border: 1px solid black;"  //outline
                    "font-size: 35px;"
                    );
        else if(col == Color::black)
            this->setStyleSheet(
                    "background-color: black;"
                    "border: 1px solid black;"  //outline
                    "font-size: 35px;"
                    );
    }else{
        if(this->color == Color::red || this->color == Color::green)
            this->setStyleSheet(
                    "background-color: yellow;"
                    "border: 1px solid black;"  //outline
                    "border-radius: 15px;"     //corners
                    "font-size: 35px;"
                    );
        else
            this->setStyleSheet(
                    "background-color: blue;"
                    "border: 1px solid black;"  //outline
                    "font-size: 35px;"
                    );
    }

    this->setAutoFillBackground(false);
    this->setPalette(pal);
    this->update();
}

//Changes color to the original value
void Piece::revertColor(){
    changeColor(this->color);
}
void Piece::myClick(){
    if(selectedPiece == nullptr){ //nothing clicked, click this
        selectedPiece = this;
        this->isClicked = true;
        this->changeColor(Color::selected);
    }else if(selectedPiece != this){ //something is clicked but not this
        selectedPiece->isClicked = false;
        selectedPiece->revertColor();
        selectedPiece = this;

        this->isClicked = true;
        selectedPiece->changeColor(Color::selected);

    }else if(selectedPiece == this){
        this->isClicked = false;
        this->revertColor();
        selectedPiece = nullptr;

    }
}

void Piece::getPos(){
}

void Piece::setPos(QPoint a){
    if(this->color  == Color::black || this->color  == Color::white){
        this->setGeometry(a.x()-25, a.y()-25, 50,50);
        this->show();
    }else{
        this->setGeometry(a.x()-15,a.y()-15,30,30);
        this->show();
    }

}

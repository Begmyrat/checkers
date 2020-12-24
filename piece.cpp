#include "piece.h"
#include <QMessageBox>
#include <math.h>
int g = 0;
int r = 0;


Piece *selectedPiece = nullptr;
QPoint *coordinate = new QPoint(0,0);
QMainWindow *winn = nullptr;
Piece *board[8][8] = {nullptr};

bool isChangingLocation = false;

Piece::Piece(int x1,int y1, Color col, QMainWindow *w):QPushButton(w){
    winn = w;
    x = x1;
    y = y1;
    this->setPos(QPoint(x*50+25, y*50+75));
    this->current_x_screen_pos = x*50+25;
    this->current_y_screen_pos = y*50+75;
    color = col;


    this->connect( this , SIGNAL( pressed() ), this , SLOT( myClick() ) );
    this->connect(this, SIGNAL( released() ), this, SLOT(myRelease()));
    this->setParent(w);
    changeColor(col);
    this->setPos(QPoint(current_x_screen_pos, current_y_screen_pos));
}

void Piece::changeColor(Color col){
    QPalette pal = this->palette();
    if(!isClicked){
        if(col == Color::green){
            if(!this->isKing){
                this->setStyleSheet(
                        "background-color: green;"
                        "border: 1px solid black;"  //outline
                        "border-radius: 15px;"     //corners
                        "font-size: 35px;"
                        );
            }
            else{
                this->setStyleSheet(
                        "background-color: green;"
                        "border: 1px solid black;"  //outline
                        "border-radius: 0px;"     //corners
                        "font-size: 35px;"
                        );
            }

        }
        else if(col == Color::red){
            if(!this->isKing){
                this->setStyleSheet(
                        "background-color: red;"
                        "border: 1px solid black;"  //outline
                        "border-radius: 15px;"     //corners
                        "font-size: 35px;"
                        );
            }
            else{
                this->setStyleSheet(
                        "background-color: red;"
                        "border: 1px solid black;"  //outline
                        "border-radius: 0px;"     //corners
                        "font-size: 35px;"
                        );
            }

        }
        else if(col == Color::white)
            this->setStyleSheet(
                    "background-color: white;"
                    "border: 0px solid black;"  //outline
                    "font-size: 50px;"
                    );
        else if(col == Color::black)
            this->setStyleSheet(
                    "background-color: black;"
                    "border: 0px solid black;"  //outline
                    "font-size: 50px;"
                    );
    }else{
        if(this->color == Color::red || this->color == Color::green){
            if(this->isKing){
                this->setStyleSheet(
                        "background-color: yellow;"
                        "border: 1px solid black;"  //outline
                        "border-radius: 0px;"     //corners
                        "font-size: 35px;"
                        );
            }
            else{
                this->setStyleSheet(
                        "background-color: yellow;"
                        "border: 1px solid black;"  //outline
                        "border-radius: 15px;"     //corners
                        "font-size: 35px;"
                        );
            }
        }
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

QPoint findIndexFromPos(QPoint pos){
    float x = pos.x()-35;
    float y = pos.y()-35;
    int k = round((((x/50) * 50)-25) / 50.0f);
    int l = round((((y/50)* 50)-75) / 50.0f);
    return QPoint(k+1,l+1);
}

QPoint findIndexOfThis(Piece *thisPiece){
    for (int i = 0; i<8 ;i++ ) {
        for (int j = 0; j<8 ;j++ ) {
            if(thisPiece == board[i][j]) return QPoint(i,j);
        }
    }
}
/*
 * x and y is the indexes
 * between 0 and 7
*/
Piece* Piece::findIfPieceIsEatable(int index_x, int index_y){

    Piece *p = board[index_x][index_y];
    if(p->color == Color::black || p->color == Color::white ){
        return nullptr;
    }else if(this->color == Color::green && p->color == Color::red){
        return p;
    }else if(this->color == Color::red && p->color == Color::green){
        return p;
    }
    return nullptr;
}

void Piece::myRelease(){

    QPoint indexes = findIndexFromPos(*coordinate);

    if(indexes.x() > 7 || indexes.y() > 7){
        this->isClicked = false;
        this->revertColor();
        selectedPiece = nullptr;
        this->setPos(QPoint(current_x_screen_pos, current_y_screen_pos));
        return;
    }
    Piece *x = board[indexes.y()][indexes.x()];

    printf("%d,%d\n", indexes.y(), indexes.x());
    this->isClicked = false;
    this->revertColor();
    selectedPiece = nullptr;
    if(this->color == Color::black || this->color == Color::white){
        return;
    }
    //The piece is dropped in its borders no need to change anything
    if(abs(this->getPos().x() - this->current_x_screen_pos) < 20 && abs(this->getPos().y() - this->current_y_screen_pos) < 20){
        this->setPos(QPoint(current_x_screen_pos, current_y_screen_pos));
    }else{ //The piece is outside its previous border

        QPoint b = findIndexFromPos(QPoint(this->getPos().x(), this->getPos().y()));
        int displacementInX = b.x() - findIndexOfThis(this).y();
        int displacementInY = b.y() - findIndexOfThis(this).x();

        bool izin = true;

        if(this->isKing){ //If king
            if(displacementInX!=0 && displacementInY!=0){ //If did not move
                izin=false;
            }
            else{ //If tried to move

            }
        }
        else{ //If not king
            if(this->color==Color::red){ //If red
                if((displacementInY==1 && displacementInX==0) || (displacementInY==0 && (displacementInX==-1 || displacementInX==1))){

                }
                else{ //If made an illegal move
                    izin=false;
                }
            }
            else if(this->color==Color::green){
                if((displacementInY==-1 && displacementInX==0) || (displacementInY==0 && (displacementInX==-1 || displacementInX==1))){

                }else if(
                         ((displacementInY==-2 && displacementInX==0) || (displacementInY==0 && (displacementInX==-2 || displacementInX==2)))
                         &&
                         ((x->color == Color::black || x->color == Color::white))
                        )
                {
                    if(displacementInY == -2){ //Trying to eat to up
                        Piece *p = findIfPieceIsEatable(findIndexOfThis(this).x()-1, findIndexOfThis(this).y());
                        if(p == nullptr){//Cannot eat
                            izin = false;
                        }else{
                            QPoint a = findIndexOfThis(p);

                            if( ( (a.x() + a.y()) % 2 ) == 0){
                                delete board[a.x()][a.y()];
                                board[a.x()][a.y()] = new Piece(a.y(),a.x(), Color::white, winn);
                            }else if( ( (a.x() + a.y()) % 2 ) == 1){
                                board[a.x()][a.y()] = new Piece(a.y(),a.x(), Color::black, winn);
                            }
                                board[a.x()][a.y()]->changeColor(board[a.x()][a.y()]->color);
                        }
                    }else if(displacementInX == -2){ //Trying to eat to left
                        Piece *p = findIfPieceIsEatable(findIndexOfThis(this).x(), findIndexOfThis(this).y()-1);
                        if(p == nullptr){//Cannot eat
                            izin = false;
                        }else{
                            QPoint a = findIndexOfThis(p);

                            if( ( (a.x() + a.y()) % 2 ) == 0){
                                delete board[a.x()][a.y()];
                                board[a.x()][a.y()] = new Piece(a.y(),a.x(), Color::white, winn);
                            }else if( ( (a.x() + a.y()) % 2 ) == 1){
                                board[a.x()][a.y()] = new Piece(a.y(),a.x(), Color::black, winn);
                            }
                                board[a.x()][a.y()]->changeColor(board[a.x()][a.y()]->color);
                        }
                    }else if(displacementInX == 2){ //Trying to eat to right
                        Piece *p = findIfPieceIsEatable(findIndexOfThis(this).x(), findIndexOfThis(this).y()+1);
                        if(p == nullptr){//Cannot eat
                            izin = false;
                        }else{
                            QPoint a = findIndexOfThis(p);

                            if( ( (a.x() + a.y()) % 2 ) == 0){
                                delete board[a.x()][a.y()];
                                board[a.x()][a.y()] = new Piece(a.y(),a.x(), Color::white, winn);
                            }else if( ( (a.x() + a.y()) % 2 ) == 1){
                                board[a.x()][a.y()] = new Piece(a.y(),a.x(), Color::black, winn);
                            }
                                board[a.x()][a.y()]->changeColor(board[a.x()][a.y()]->color);
                        }
                    }else{ //If made an illegal move

                    }
                }
                else{
                    izin = false;
                }
            }
        }

        if(izin){
            if(x!= nullptr && (x->color == Color::black || x->color == Color::white)){ //Will change position
                QPoint a = findIndexFromPos(QPoint(this->getPos().x(), this->getPos().y()));

                Piece *other_piece_being_swapped = board[a.y()][a.x()];
                delete other_piece_being_swapped;
                QPoint curr_pos = findIndexFromPos(QPoint(current_x_screen_pos, current_y_screen_pos));
                Color c;

                (curr_pos.x()+curr_pos.y())%2 == 1 ? c = Color::black : c = Color::white;

                board[curr_pos.y()][curr_pos.x()] = new Piece(curr_pos.x(), curr_pos.y(),c, winn);
                board[a.y()][a.x()] = this;
                QPoint this_index = findIndexOfThis(this);
                //board[this_index.x()][this_index.y()] = other_piece_being_swapped;


                this->setPos(QPoint((a.x())*50+25, (a.y())*50+75));
                current_x_screen_pos = a.x()*50+25, current_y_screen_pos = a.y()*50+75;

            }else{ //Dont change position
                 this->setPos(QPoint(current_x_screen_pos, current_y_screen_pos));
            }
        }
        else{
            this->setPos(QPoint(current_x_screen_pos, current_y_screen_pos));
        }



    }

    QPoint z = findIndexOfThis(this);

    if((z.x()==0 || z.x()==7)){
        this->isKing = true;
        this->changeColor(this->color);
    }
//    else if(this->color==Color::red && z.x()==7){
//        this->isKing = true;
//        this->changeColor(this->color);
//    }
}


void Piece::myClick(){
    if(selectedPiece == nullptr){ //nothing clicked, click this
        selectedPiece = this;
        this->isClicked = true;
        if(this->color == Color::red || this->color == Color::green)
            this->raise();
        this->changeColor(Color::selected);
    }else if(selectedPiece != this){ //something is clicked but not this
        selectedPiece->isClicked = false;
        selectedPiece->revertColor();
        selectedPiece = this;
        this->raise();

        this->isClicked = true;
        selectedPiece->changeColor(Color::selected);

    }else if(selectedPiece == this){
        this->isClicked = false;
        this->revertColor();
        selectedPiece = nullptr;
    }

}



QPoint Piece::getPos(){
    return QPoint(this->pos().x(), this->pos().y());
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

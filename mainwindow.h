#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_File_clicked();

    void on_pushButton_Edit_clicked();

    void on_pushButton_Game_clicked();

    void on_pushButton_Help_clicked();

    void on_pushButton_NewGame_clicked();

    void on_pushButton_Left_clicked();

    void on_pushButton_Left_2_clicked();

    void on_pushButton_Left_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

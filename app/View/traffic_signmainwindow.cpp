#include "traffic_signmainwindow.h"
#include "ui_traffic_signmainwindow.h"

Traffic_signMainWindow::Traffic_signMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Traffic_signMainWindow)
{
    ui->setupUi(this);
}

Traffic_signMainWindow::~Traffic_signMainWindow()
{
    delete ui;
}

void Traffic_signMainWindow::on_VideoButton_clicked()
{

}

void Traffic_signMainWindow::on_ExitButton_clicked()
{

}

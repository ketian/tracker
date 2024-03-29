#include "traffic_signmainwindow.h"
#include "ui_traffic_signmainwindow.h"
#include "MainWindowSink.hpp"
#include <QFileDialog>
#include <QDebug>
#include <boost/make_shared.hpp>
#include <signal.h>

Traffic_signMainWindow::Traffic_signMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Traffic_signMainWindow),
    running_timer(new QTimer(this))
{
    ui->setupUi(this);
    sp_Event = boost::static_pointer_cast<INotification>(
            boost::make_shared<MainWindowSink>(this));
            
    connect(running_timer, SIGNAL(timeout()), this, SLOT(run()));
}

Traffic_signMainWindow::~Traffic_signMainWindow()
{
    delete ui;
}
QLabel * Traffic_signMainWindow::GetLabel(const std::string &s)
{
    if (s=="video") return ui->VideoLabel;
    if (s=="mark") return ui->SignLabel;
}

boost::shared_ptr<QImage> Traffic_signMainWindow::GetImage(const int &x)
{
    if (x==0) return sp_Image;
    else return sp_Mark;
}

boost::shared_ptr<INotification> Traffic_signMainWindow::GetEvent()
{
    return sp_Event;
}

void Traffic_signMainWindow::SetOpenCommand(const boost::shared_ptr<ICommand> &ptr) {
    sp_OpenCommand = ptr;
}

void Traffic_signMainWindow::SetReadCommand(const boost::shared_ptr<ICommand> &ptr) {
    sp_ReadCommand = ptr;
}

void Traffic_signMainWindow::SetRunCommand(const boost::shared_ptr<ICommand> &ptr) {
    sp_RunCommand = ptr;
}

void Traffic_signMainWindow::SetImage(const boost::shared_ptr<QImage> &ptr) {
    sp_Image = ptr;
}

void Traffic_signMainWindow::SetMark(const boost::shared_ptr<QImage> &ptr) {
    sp_Mark = ptr;
}

void Traffic_signMainWindow::on_VideoButton_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, 
            tr("Open Video"), ".", 
            tr("Video Files (*.mp4 *.avi)"));
	qDebug()<<"filenames:"<<fileName;
    if (fileName.toStdString()=="") return;
	boost::shared_ptr<OpenCommandParam> param = boost::make_shared<OpenCommandParam>();
	param->SetParam(fileName.toStdString());
	sp_OpenCommand->Execute(boost::static_pointer_cast<ICommandParam>(param));

    //ui->VideoLabel->setPixmap(QPixmap::fromImage(*sp_ViewModel->GetImage()));
	//ui->VideoLabel->setPixmap(QPixmap::fromImage(*sp_ViewModel->GetImage()));
	//ui->VideoLabel->setScaledContents(true);
}

void Traffic_signMainWindow::on_RunButton_clicked()
{
    init_flag = true;
    
    QString fileName = QFileDialog::getOpenFileName(this, 
            tr("Open Mark Information"), ".", 
            tr("Mark Files (*.txt)"));
	qDebug()<<"filenames:"<<fileName;
    if (fileName.toStdString()=="") return;
    boost::shared_ptr<OpenCommandParam> param = boost::make_shared<OpenCommandParam>();
	param->SetParam(fileName.toStdString());
	sp_ReadCommand->Execute(boost::static_pointer_cast<ICommandParam>(param));

    running_timer->start(100);
}

void Traffic_signMainWindow::on_ExitButton_clicked()
{
    exit(0);
}


void Traffic_signMainWindow::run()
{
    boost::shared_ptr<OpenCommandParam> param = boost::make_shared<OpenCommandParam>();
    if (init_flag)
    {
	    param->SetParam("init");
	    init_flag = false;
	}
	else param->SetParam("run");
    sp_RunCommand->Execute(boost::static_pointer_cast<ICommandParam>(param));
}

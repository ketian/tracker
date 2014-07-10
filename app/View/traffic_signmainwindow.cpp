#include "traffic_signmainwindow.h"
#include "ui_traffic_signmainwindow.h"
#include <QFileDialog>
#include <QDebug>

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
QLabel * Traffic_signMainWindow::GetLabel(const std::string &s)
{
    if (s=="video") return ui->VideoLabel;
    if (s=="sign") return ui->SignLabel;
}

boost::shared_ptr<QImage> Traffic_signMainWindow::GetImage()
{
    return sp_Image;
}

void Traffic_signMainWindow::SetOpenCommand(const boost::shared_ptr<ICommand> &ptr) {
    sp_OpenCommand = boost::dynamic_pointer_cast<OpenCommand>(ptr);
}

void Traffic_signMainWindow::SetImage(const boost::shared_ptr<QImage> &ptr) {
    sp_Image = ptr;
}

void Traffic_signMainWindow::on_VideoButton_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, 
            tr("Open Video"), ".", 
            tr("Video Files (*.mp4 *.avi)"));
	qDebug()<<"filenames:"<<fileName;
	boost::shared_ptr<OpenCommandParam> param = boost::make_shared<OpenCommandParam>();
	param->SetParam(fileName.toStdString());
	sp_OpenCommand->Execute(boost::static_pointer_cast<ICommandParam>(param));

    //ui->VideoLabel->setPixmap(QPixmap::fromImage(*sp_ViewModel->GetImage()));
	//ui->VideoLabel->setPixmap(QPixmap::fromImage(*sp_ViewModel->GetImage()));
	//ui->VideoLabel->setScaledContents(true);
}

void Traffic_signMainWindow::on_ExitButton_clicked()
{
	exit(0);
}

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
	QString fileName = QFileDialog::getOpenFileName(this,tr("Open Video"),".",tr("Video Files (*.mp4 *.avi)"));
        	qDebug()<<"filenames:"<<fileName;
	std::shared_ptr<OpenCommandParam> param=std::make_shared<OpenCommandParam>(*(new OpenCommandParam));
	param->SetParam(fileName.toStdString());
	sp_OpenCommand->Execute(std::static_pointer_cast<ICommandParam>(param));
}

void Traffic_signMainWindow::on_ExitButton_clicked()
{
	exit(0);
}

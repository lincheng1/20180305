#include "GEN.h"
#include <QtCore/QCoreApplication>
#include <QJsonObject>
#include<QJsonDocument>
#include <QDebug>
#include <QCoreApplication>  
#include <QDebug>  
#include <QJsonObject>  
#include <QJsonArray>  
#include <QFile>  
#include <QJsonDocument>  
#include <QPushButton>
#include <QComboBox>
#include <QProcess>
#include<ui_GEN.h>
#include <QMap>
#include<QProgressDialog>
#include<QTimer>

GEN::GEN(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);	
	connect(ui.pushButton_2, &QPushButton::clicked, this, &GEN::saveset);
}

void GEN::setline()
{
	
}

void GEN::saveset()
{
	
	progDlg = new QProgressDialog();
	progDlg->setWindowTitle("Please wait...");
	progDlg->setFixedWidth(300);
	progDlg->setRange(0, 100);
	progDlg->show();
	QTimer *timer = new QTimer();
	currentValue = 0;
	progDlg->setValue(currentValue);
	//progDlg->exec();
	//为什么信号与曹进不去呢
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateProgressDialog()));
	timer->start(50);//开启一个没有终点的定时器
	

						/*QJsonObject Properties;
						Properties.insert("ORDER", ui.comboBox_2->currentText());
						Properties.insert("SIZE", ui.lineEdit_2->text().toDouble());
						Properties.insert("TYPE", ui.comboBox_4->currentText());
						Properties.insert("CORE", ui.comboBox_3->currentText());
						Properties.insert("IsFine", ui.comboBox->currentText());
						Properties.insert("MaxSize", ui.lineEdit_6->text().toFloat());
						Properties.insert("MinSize", ui.lineEdit_7->text().toDouble());
						Properties.insert("MaxAngle", ui.lineEdit_8->text().toDouble());
						Properties.insert("MinAngle", ui.lineEdit_9->text().toDouble());
						Properties.insert("SpanAngle", ui.lineEdit_10->text().toDouble());
						Properties.insert("MaxEdgeAlt", ui.lineEdit_11->text().toDouble());

						obj1.insert("Properties", Properties);

						QJsonDocument jsonDoc(obj1);
						QByteArray ba = jsonDoc.toJson();

						QFile file("mesh22.json");
						if (!file.open(QIODevice::WriteOnly))
						{
							qDebug() << "write json file failed";
							return ;
						}
						file.write(ba);

						file.close();
						this->close();*/

	//////////////////////////////
	QMap<QString, QVariant> mapJson;

	QMap<QString, QVariant> mapJson1;
	mapJson1.insert("ORDER", ui.comboBox_2->currentText());
	mapJson1.insert("SIZE", ui.lineEdit_2->text().toDouble());
	mapJson1.insert("TYPE", ui.comboBox_4->currentText());
	mapJson1.insert("CORE", ui.comboBox_3->currentText());
	mapJson1.insert("IsFine", ui.comboBox->currentText());

	QJsonObject IsFineValue;
	IsFineValue.insert("MaxSize", ui.lineEdit_6->text().toFloat());
	IsFineValue.insert("MinSize", ui.lineEdit_7->text().toDouble());
	IsFineValue.insert("MaxAngle", ui.lineEdit_8->text().toDouble());
	IsFineValue.insert("MinAngle", ui.lineEdit_9->text().toDouble());
	IsFineValue.insert("SpanAngle", ui.lineEdit_10->text().toDouble());
	IsFineValue.insert("MaxEdgeAlt", ui.lineEdit_11->text().toDouble());
	mapJson1.insert("IsFineValue", IsFineValue);

	QList<QVariant> dat_namelist;
	dat_namelist.append(mapJson1);

	mapJson.insert("Properties", dat_namelist);


	QJsonDocument jsonDoc = QJsonDocument::fromVariant(QVariant(mapJson));
	QByteArray ba = jsonDoc.toJson(QJsonDocument::JsonFormat::Indented);


	QFile jsonFile("mesh22.json");
	if (jsonFile.exists())
		jsonFile.remove();
	if (!jsonFile.open(QIODevice::WriteOnly))
	{
		printf("write js on file failed ! \n");
		return ;
	}
	jsonFile.write(ba);
	jsonFile.close();

	///////
	//QProcess p(0);
	////QDir::setCurrent("D:/GEN/genInpnew/genInp/");
	//p.setWorkingDirectory("D:/GEN/genInpnew/genInp");//指定进程的工作目录
	//QString command = "D:/GEN/genInpnew/genInp/VkiMeshGen.exe";
	//QStringList args;
	//args.append("-i");
	//args.append("D:/GEN/genInpnew/genInp/hwjt_asmsss_fstl/GUANGLAN.fstl");
	//args.append("-o");
	//args.append("D:/GEN/genInpnew/genInp/Test");
	//args.append("-j");
	//args.append("D:/GEN/genInpnew/genInp/mesh.json");
	//args.append("-l");
	//args.append("D:/GEN/genInpnew/genInp/Test/log.txt");

	//p.execute(command, args);//command是要执行的命令,args是参数
	//p.waitForFinished();
	////qDebug() << QString::fromLocal8Bit(p.readAllStandardError());

	this->close();

	/*QProgressDialog process(this);
	process.setLabelText(tr("processing..."));
	process.setRange(0, 50000);
	process.setModal(true);
	process.setCancelButtonText(tr("cancel"));
	for (int i = 0; i<50000; i++)
	{
		for (int j = 0; j<20000; j++);
		process.setValue(i);
		if (process.wasCanceled())
			break;
	}*/



	//耗时操作完成后，关闭进度对话框
	timer->stop();//停止定时器
	if (currentValue != 100)
		currentValue = 100;
	progDlg->setValue(currentValue);//进度达到最大值
	//progDlg->exec();
	delete progDlg;//关闭进度对话框


}

//借助定时器，不断更新进度条，直到耗时操纵结束
void GEN::updateProgressDialog()
{
	currentValue++;
	if (currentValue == 100)
		currentValue = 0;
	progDlg->setValue(currentValue);
	QCoreApplication::processEvents();//避免界面冻结
	if (progDlg->wasCanceled())
		progDlg->setHidden(true);//隐藏对话框
}





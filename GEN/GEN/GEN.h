#pragma once

#include <QtWidgets/QWidget>
#include "ui_GEN.h"
#include <QJsonObject>
#include<QProgressDialog>
#include<QTimer>

class GEN : public QWidget
{
    Q_OBJECT

public:
    GEN(QWidget *parent = Q_NULLPTR);

	//QJsonObject obj1;
	int currentValue;

private:
    Ui::GENClass ui;
	
	QProgressDialog *progDlg;

private slots:
	
	void setline();
	void saveset();
	void updateProgressDialog();
};

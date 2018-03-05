#pragma once

#include <QtWidgets/QWidget>
#include "ui_barchart.h"

class barchart : public QWidget
{
    Q_OBJECT

public:
    barchart(QWidget *parent = Q_NULLPTR);

private:
    Ui::barchartClass ui;

private slots:
	void on_inputSpinBox1_valueChanged(int value);
	void on_inputSpinBox2_valueChanged(int value);

};

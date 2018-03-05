#include "barchart.h"
#include <ui_barchart.h>
#include <QLabel>
#include <QSpinBox>

barchart::barchart(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//信号参数有两个，需要进行参数类型转换来确定用哪个参数。
	connect(ui.inputspinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &barchart::on_inputSpinBox1_valueChanged);

	connect(ui.inputspinBox2, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &barchart::on_inputSpinBox2_valueChanged);


}


void barchart::on_inputSpinBox1_valueChanged(int value)
{
	ui.outputWidget->setText(QString::number(value + ui.inputspinBox2->value()));

}

void barchart::on_inputSpinBox2_valueChanged(int value)
{
	ui.outputWidget->setText(QString::number(value + ui.inputspinBox->value()));

}  

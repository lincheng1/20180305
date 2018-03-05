/********************************************************************************
** Form generated from reading UI file 'barchart.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARCHART_H
#define UI_BARCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_barchartClass
{
public:
    QSpinBox *inputspinBox;
    QSpinBox *inputspinBox2;
    QLabel *outputWidget;

    void setupUi(QWidget *barchartClass)
    {
        if (barchartClass->objectName().isEmpty())
            barchartClass->setObjectName(QStringLiteral("barchartClass"));
        barchartClass->resize(600, 400);
        inputspinBox = new QSpinBox(barchartClass);
        inputspinBox->setObjectName(QStringLiteral("inputspinBox"));
        inputspinBox->setGeometry(QRect(70, 110, 42, 22));
        inputspinBox2 = new QSpinBox(barchartClass);
        inputspinBox2->setObjectName(QStringLiteral("inputspinBox2"));
        inputspinBox2->setGeometry(QRect(170, 110, 42, 22));
        outputWidget = new QLabel(barchartClass);
        outputWidget->setObjectName(QStringLiteral("outputWidget"));
        outputWidget->setGeometry(QRect(280, 110, 54, 12));

        retranslateUi(barchartClass);

        QMetaObject::connectSlotsByName(barchartClass);
    } // setupUi

    void retranslateUi(QWidget *barchartClass)
    {
        barchartClass->setWindowTitle(QApplication::translate("barchartClass", "barchart", Q_NULLPTR));
        outputWidget->setText(QApplication::translate("barchartClass", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class barchartClass: public Ui_barchartClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARCHART_H

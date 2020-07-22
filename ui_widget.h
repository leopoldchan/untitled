/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QSpinBox *spinBox;
    QLabel *label_6;
    QComboBox *comboBox_3;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QTableView *tableView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(905, 650);
        verticalLayout_4 = new QVBoxLayout(Widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(22);
        font.setBold(false);
        font.setWeight(50);
        groupBox->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 9, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Aharoni"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit_2->setFont(font1);

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 5);
        gridLayout->setColumnStretch(2, 1);

        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font2);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font2);

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_4->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(22);
        font3.setBold(false);
        font3.setWeight(50);
        groupBox_3->setFont(font3);
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        horizontalLayout_3->addWidget(label_4);

        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        lineEdit_3->setFont(font4);
        lineEdit_3->setReadOnly(false);

        horizontalLayout_3->addWidget(lineEdit_3);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        horizontalLayout_3->addWidget(label_5);

        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(false);
        spinBox->setFont(font4);
        spinBox->setStyleSheet(QString::fromUtf8("QSpinBox::up-button,QSpinBox::down-button\n"
"{\n"
"	width:0px;\n"
"}"));
        spinBox->setReadOnly(false);
        spinBox->setMaximum(65535);

        horizontalLayout_3->addWidget(spinBox);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        horizontalLayout_3->addWidget(label_6);

        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEnabled(false);
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font5.setPointSize(18);
        font5.setBold(false);
        font5.setWeight(50);
        comboBox_3->setFont(font5);

        horizontalLayout_3->addWidget(comboBox_3);

        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setFont(font2);

        horizontalLayout_3->addWidget(pushButton_3);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 2);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 2);
        horizontalLayout_3->setStretch(5, 3);
        horizontalLayout_3->setStretch(6, 2);

        verticalLayout_4->addWidget(groupBox_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font3);
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font5);

        horizontalLayout_2->addWidget(comboBox);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        horizontalLayout_2->addWidget(label_3);

        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setFont(font5);

        horizontalLayout_2->addWidget(comboBox_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font6.setPointSize(16);
        font6.setBold(false);
        font6.setWeight(50);
        tableView->setFont(font6);
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setSortingEnabled(true);

        verticalLayout_3->addWidget(tableView);


        verticalLayout_4->addWidget(groupBox_2);

        verticalLayout_4->setStretch(0, 4);
        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 2);
        verticalLayout_4->setStretch(3, 1);
        verticalLayout_4->setStretch(4, 24);

        retranslateUi(Widget);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Widget, SLOT(close()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245pin\347\240\201\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\344\277\241\344\273\273\346\234\215\345\212\241AS\351\205\215\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "IP:", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\347\261\273\345\236\213\357\274\232", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Widget", "\345\244\226\344\272\244\351\203\250\345\205\250\347\220\203\347\275\221918", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Widget", "311\346\226\260\344\270\200\344\273\243", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("Widget", "918\346\224\277\345\212\241\344\272\221", nullptr));

        pushButton_3->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\346\266\210\346\201\257\344\270\255\345\277\203", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\266\210\346\201\257\347\272\247\345\210\253\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "\345\205\250\351\203\250", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "\344\277\241\346\201\257", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Widget", "\350\255\246\345\221\212", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Widget", "\351\224\231\350\257\257", nullptr));

        label_3->setText(QCoreApplication::translate("Widget", "\346\266\210\346\201\257\346\235\245\346\272\220\357\274\232", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Widget", "\345\205\250\351\203\250", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *et_red;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *et_green;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *et_blue;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *layoutRight;
    QSpacerItem *verticalSpacer_4;
    QLabel *lb_color;
    QWidget *ivColor;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnCopy;
    QCheckBox *cbIsMessage;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(300, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(300, 200));
        MainWindow->setMaximumSize(QSize(300, 245));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/izumikonata.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_6 = new QHBoxLayout(centralWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        et_red = new QLineEdit(centralWidget);
        et_red->setObjectName(QStringLiteral("et_red"));
        et_red->setMaxLength(3);

        horizontalLayout_2->addWidget(et_red);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        et_green = new QLineEdit(centralWidget);
        et_green->setObjectName(QStringLiteral("et_green"));
        et_green->setMaxLength(3);

        horizontalLayout_3->addWidget(et_green);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        et_blue = new QLineEdit(centralWidget);
        et_blue->setObjectName(QStringLiteral("et_blue"));
        et_blue->setMaxLength(3);

        horizontalLayout_4->addWidget(et_blue);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_6->addLayout(verticalLayout_2);

        layoutRight = new QVBoxLayout();
        layoutRight->setSpacing(6);
        layoutRight->setObjectName(QStringLiteral("layoutRight"));
        layoutRight->setSizeConstraint(QLayout::SetDefaultConstraint);
        layoutRight->setContentsMargins(20, -1, 20, -1);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutRight->addItem(verticalSpacer_4);

        lb_color = new QLabel(centralWidget);
        lb_color->setObjectName(QStringLiteral("lb_color"));

        layoutRight->addWidget(lb_color);

        ivColor = new QWidget(centralWidget);
        ivColor->setObjectName(QStringLiteral("ivColor"));
        ivColor->setLayoutDirection(Qt::LeftToRight);
        ivColor->setAutoFillBackground(true);
        verticalLayout_3 = new QVBoxLayout(ivColor);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(50, 50, -1, -1);

        layoutRight->addWidget(ivColor);

        btnCopy = new QPushButton(centralWidget);
        btnCopy->setObjectName(QStringLiteral("btnCopy"));
        sizePolicy.setHeightForWidth(btnCopy->sizePolicy().hasHeightForWidth());
        btnCopy->setSizePolicy(sizePolicy);
        btnCopy->setMinimumSize(QSize(50, 0));
        btnCopy->setMaximumSize(QSize(50, 50));

        layoutRight->addWidget(btnCopy);

        cbIsMessage = new QCheckBox(centralWidget);
        cbIsMessage->setObjectName(QStringLiteral("cbIsMessage"));
        sizePolicy.setHeightForWidth(cbIsMessage->sizePolicy().hasHeightForWidth());
        cbIsMessage->setSizePolicy(sizePolicy);

        layoutRight->addWidget(cbIsMessage);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutRight->addItem(verticalSpacer_3);


        horizontalLayout_6->addLayout(layoutRight);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ColorCalculator", nullptr));
        label->setText(QApplication::translate("MainWindow", "R : ", nullptr));
        et_red->setPlaceholderText(QApplication::translate("MainWindow", "255", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "G : ", nullptr));
        et_green->setPlaceholderText(QApplication::translate("MainWindow", "255", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "B : ", nullptr));
        et_blue->setPlaceholderText(QApplication::translate("MainWindow", "255", nullptr));
        lb_color->setText(QString());
        btnCopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
        cbIsMessage->setText(QApplication::translate("MainWindow", "\346\217\220\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

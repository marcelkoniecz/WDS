/********************************************************************************
** Form generated from reading UI file 'disDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISDIALOG_H
#define UI_DISDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_disDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *disconnectButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *disDialog)
    {
        if (disDialog->objectName().isEmpty())
            disDialog->setObjectName(QStringLiteral("disDialog"));
        disDialog->resize(396, 140);
        verticalLayout_2 = new QVBoxLayout(disDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(disDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(disDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(150, 0));
        lineEdit->setFont(font);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        disconnectButton = new QPushButton(disDialog);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));
        disconnectButton->setMinimumSize(QSize(100, 0));
        disconnectButton->setFont(font);

        horizontalLayout->addWidget(disconnectButton);

        cancelButton = new QPushButton(disDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMinimumSize(QSize(100, 0));
        cancelButton->setFont(font);

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(disDialog);

        QMetaObject::connectSlotsByName(disDialog);
    } // setupUi

    void retranslateUi(QDialog *disDialog)
    {
        disDialog->setWindowTitle(QApplication::translate("disDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("disDialog", "Are you sure to disconnect:", Q_NULLPTR));
        disconnectButton->setText(QApplication::translate("disDialog", "Disconnect", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("disDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class disDialog: public Ui_disDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISDIALOG_H

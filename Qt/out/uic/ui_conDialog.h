/********************************************************************************
** Form generated from reading UI file 'conDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONDIALOG_H
#define UI_CONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_conDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *searchDeviceButton;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *devicesList;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *connectButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *conDialog)
    {
        if (conDialog->objectName().isEmpty())
            conDialog->setObjectName(QStringLiteral("conDialog"));
        conDialog->resize(364, 113);
        verticalLayout = new QVBoxLayout(conDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        searchDeviceButton = new QPushButton(conDialog);
        searchDeviceButton->setObjectName(QStringLiteral("searchDeviceButton"));
        searchDeviceButton->setMinimumSize(QSize(120, 0));

        horizontalLayout_2->addWidget(searchDeviceButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        devicesList = new QComboBox(conDialog);
        devicesList->setObjectName(QStringLiteral("devicesList"));
        devicesList->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(devicesList);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        connectButton = new QPushButton(conDialog);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(connectButton);

        cancelButton = new QPushButton(conDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(conDialog);

        QMetaObject::connectSlotsByName(conDialog);
    } // setupUi

    void retranslateUi(QDialog *conDialog)
    {
        conDialog->setWindowTitle(QApplication::translate("conDialog", "Dialog", Q_NULLPTR));
        searchDeviceButton->setText(QApplication::translate("conDialog", "Search devices", Q_NULLPTR));
        connectButton->setText(QApplication::translate("conDialog", "Connect", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("conDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class conDialog: public Ui_conDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONDIALOG_H

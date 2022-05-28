/********************************************************************************
** Form generated from reading UI file 'endGameDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDGAMEDIALOG_H
#define UI_ENDGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_endGameDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *statisticsButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *restartButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *endGameDialog)
    {
        if (endGameDialog->objectName().isEmpty())
            endGameDialog->setObjectName(QStringLiteral("endGameDialog"));
        endGameDialog->resize(400, 400);
        endGameDialog->setMinimumSize(QSize(300, 300));
        endGameDialog->setMaximumSize(QSize(400, 400));
        QFont font;
        font.setPointSize(12);
        endGameDialog->setFont(font);
        verticalLayout = new QVBoxLayout(endGameDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label = new QLabel(endGameDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(22);
        label->setFont(font1);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        statisticsButton = new QPushButton(endGameDialog);
        statisticsButton->setObjectName(QStringLiteral("statisticsButton"));
        statisticsButton->setMinimumSize(QSize(150, 30));

        horizontalLayout->addWidget(statisticsButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        restartButton = new QPushButton(endGameDialog);
        restartButton->setObjectName(QStringLiteral("restartButton"));
        restartButton->setMinimumSize(QSize(150, 30));

        horizontalLayout_2->addWidget(restartButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        exitButton = new QPushButton(endGameDialog);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setMinimumSize(QSize(150, 30));

        horizontalLayout_3->addWidget(exitButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        retranslateUi(endGameDialog);

        QMetaObject::connectSlotsByName(endGameDialog);
    } // setupUi

    void retranslateUi(QDialog *endGameDialog)
    {
        endGameDialog->setWindowTitle(QApplication::translate("endGameDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("endGameDialog", "End of game", Q_NULLPTR));
        statisticsButton->setText(QApplication::translate("endGameDialog", "Statistics", Q_NULLPTR));
        restartButton->setText(QApplication::translate("endGameDialog", "Restart", Q_NULLPTR));
        exitButton->setText(QApplication::translate("endGameDialog", "Exit application", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class endGameDialog: public Ui_endGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDGAMEDIALOG_H

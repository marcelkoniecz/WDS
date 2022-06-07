/********************************************************************************
** Form generated from reading UI file 'gameStatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESTATISTICS_H
#define UI_GAMESTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameStatistics
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *mainText;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QFrame *frameStatistics;
    QGridLayout *gridLayout;
    QLabel *bouncingLabel;
    QLineEdit *ballVelLab;
    QLabel *gameTimeLabel;
    QLineEdit *gameTimeLable;
    QLineEdit *bouncingLable;
    QLabel *ballVelLabel;
    QFrame *frameChart;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *returnButton;

    void setupUi(QWidget *gameStatistics)
    {
        if (gameStatistics->objectName().isEmpty())
            gameStatistics->setObjectName(QStringLiteral("gameStatistics"));
        gameStatistics->resize(700, 500);
        gameStatistics->setMinimumSize(QSize(700, 500));
        verticalLayout_2 = new QVBoxLayout(gameStatistics);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frame = new QFrame(gameStatistics);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(16777215, 100));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mainText = new QLabel(frame);
        mainText->setObjectName(QStringLiteral("mainText"));
        QFont font;
        font.setPointSize(23);
        mainText->setFont(font);

        horizontalLayout->addWidget(mainText);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(frame);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        frameStatistics = new QFrame(gameStatistics);
        frameStatistics->setObjectName(QStringLiteral("frameStatistics"));
        frameStatistics->setMinimumSize(QSize(300, 0));
        frameStatistics->setMaximumSize(QSize(300, 500));
        frameStatistics->setFrameShape(QFrame::StyledPanel);
        frameStatistics->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frameStatistics);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        bouncingLabel = new QLabel(frameStatistics);
        bouncingLabel->setObjectName(QStringLiteral("bouncingLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bouncingLabel->sizePolicy().hasHeightForWidth());
        bouncingLabel->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(15);
        bouncingLabel->setFont(font1);
        bouncingLabel->setLayoutDirection(Qt::LeftToRight);
        bouncingLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(bouncingLabel, 3, 0, 1, 1);

        ballVelLab = new QLineEdit(frameStatistics);
        ballVelLab->setObjectName(QStringLiteral("ballVelLab"));
        ballVelLab->setMaximumSize(QSize(100, 16777215));
        ballVelLab->setAlignment(Qt::AlignCenter);
        ballVelLab->setReadOnly(true);

        gridLayout->addWidget(ballVelLab, 6, 1, 1, 1);

        gameTimeLabel = new QLabel(frameStatistics);
        gameTimeLabel->setObjectName(QStringLiteral("gameTimeLabel"));
        gameTimeLabel->setFont(font1);
        gameTimeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(gameTimeLabel, 2, 0, 1, 1);

        gameTimeLable = new QLineEdit(frameStatistics);
        gameTimeLable->setObjectName(QStringLiteral("gameTimeLable"));
        gameTimeLable->setMaximumSize(QSize(100, 16777215));
        gameTimeLable->setAlignment(Qt::AlignCenter);
        gameTimeLable->setReadOnly(true);

        gridLayout->addWidget(gameTimeLable, 2, 1, 1, 1);

        bouncingLable = new QLineEdit(frameStatistics);
        bouncingLable->setObjectName(QStringLiteral("bouncingLable"));
        bouncingLable->setMaximumSize(QSize(100, 16777215));
        bouncingLable->setAlignment(Qt::AlignCenter);
        bouncingLable->setReadOnly(true);

        gridLayout->addWidget(bouncingLable, 3, 1, 1, 1);

        ballVelLabel = new QLabel(frameStatistics);
        ballVelLabel->setObjectName(QStringLiteral("ballVelLabel"));
        ballVelLabel->setFont(font1);

        gridLayout->addWidget(ballVelLabel, 6, 0, 1, 1);


        horizontalLayout_6->addWidget(frameStatistics);

        frameChart = new QFrame(gameStatistics);
        frameChart->setObjectName(QStringLiteral("frameChart"));
        frameChart->setMinimumSize(QSize(500, 300));
        frameChart->setFrameShape(QFrame::StyledPanel);
        frameChart->setFrameShadow(QFrame::Raised);

        horizontalLayout_6->addWidget(frameChart);


        verticalLayout_2->addLayout(horizontalLayout_6);

        widget = new QWidget(gameStatistics);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        returnButton = new QPushButton(widget);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        QFont font2;
        font2.setPointSize(14);
        returnButton->setFont(font2);
        returnButton->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(returnButton);


        verticalLayout_2->addWidget(widget);


        retranslateUi(gameStatistics);

        QMetaObject::connectSlotsByName(gameStatistics);
    } // setupUi

    void retranslateUi(QWidget *gameStatistics)
    {
        gameStatistics->setWindowTitle(QApplication::translate("gameStatistics", "Form", Q_NULLPTR));
        mainText->setText(QApplication::translate("gameStatistics", "Game Statistics", Q_NULLPTR));
        bouncingLabel->setText(QApplication::translate("gameStatistics", "Bouncing:", Q_NULLPTR));
        gameTimeLabel->setText(QApplication::translate("gameStatistics", "Game time:", Q_NULLPTR));
        ballVelLabel->setText(QApplication::translate("gameStatistics", "Average ball velocity", Q_NULLPTR));
        returnButton->setText(QApplication::translate("gameStatistics", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gameStatistics: public Ui_gameStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESTATISTICS_H

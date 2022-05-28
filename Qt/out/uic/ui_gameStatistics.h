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
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QLabel *bouncingLabel;
    QLineEdit *lineEdit_3;
    QLabel *gameTimeLabel;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *ballVelLabel;
    QFrame *frame_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *backButton;

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
        frame_2 = new QFrame(gameStatistics);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(300, 0));
        frame_2->setMaximumSize(QSize(300, 500));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        bouncingLabel = new QLabel(frame_2);
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

        lineEdit_3 = new QLineEdit(frame_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lineEdit_3, 6, 1, 1, 1);

        gameTimeLabel = new QLabel(frame_2);
        gameTimeLabel->setObjectName(QStringLiteral("gameTimeLabel"));
        gameTimeLabel->setFont(font1);
        gameTimeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(gameTimeLabel, 2, 0, 1, 1);

        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lineEdit_2, 3, 1, 1, 1);

        ballVelLabel = new QLabel(frame_2);
        ballVelLabel->setObjectName(QStringLiteral("ballVelLabel"));
        ballVelLabel->setFont(font1);

        gridLayout->addWidget(ballVelLabel, 6, 0, 1, 1);


        horizontalLayout_6->addWidget(frame_2);

        frame_3 = new QFrame(gameStatistics);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(500, 300));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);

        horizontalLayout_6->addWidget(frame_3);


        verticalLayout_2->addLayout(horizontalLayout_6);

        widget = new QWidget(gameStatistics);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        backButton = new QPushButton(widget);
        backButton->setObjectName(QStringLiteral("backButton"));
        QFont font2;
        font2.setPointSize(14);
        backButton->setFont(font2);
        backButton->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(backButton);


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
        backButton->setText(QApplication::translate("gameStatistics", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gameStatistics: public Ui_gameStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESTATISTICS_H

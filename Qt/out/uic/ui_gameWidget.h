/********************************************************************************
** Form generated from reading UI file 'gameWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameWidget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *infoBox;
    QGridLayout *gridLayout;
    QLabel *gameTimeLabel;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *endGame;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *exitAplication;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pauzeGame;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *gameWidget)
    {
        if (gameWidget->objectName().isEmpty())
            gameWidget->setObjectName(QStringLiteral("gameWidget"));
        gameWidget->resize(541, 453);
        verticalLayout = new QVBoxLayout(gameWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        infoBox = new QVBoxLayout();
        infoBox->setObjectName(QStringLiteral("infoBox"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gameTimeLabel = new QLabel(gameWidget);
        gameTimeLabel->setObjectName(QStringLiteral("gameTimeLabel"));
        QFont font;
        font.setPointSize(12);
        gameTimeLabel->setFont(font);

        gridLayout->addWidget(gameTimeLabel, 0, 1, 1, 1);

        lineEdit = new QLineEdit(gameWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(100, 16777215));
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 3, 1, 1);


        infoBox->addLayout(gridLayout);

        frame = new QFrame(gameWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(16777215, 200));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(1);
        frame->setMidLineWidth(2);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);

        endGame = new QPushButton(frame);
        endGame->setObjectName(QStringLiteral("endGame"));
        endGame->setMaximumSize(QSize(300, 16777215));
        endGame->setFont(font);

        gridLayout_2->addWidget(endGame, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 6, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 4, 1, 1, 1);

        exitAplication = new QPushButton(frame);
        exitAplication->setObjectName(QStringLiteral("exitAplication"));
        exitAplication->setMaximumSize(QSize(300, 16777215));
        exitAplication->setFont(font);

        gridLayout_2->addWidget(exitAplication, 5, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        pauzeGame = new QPushButton(frame);
        pauzeGame->setObjectName(QStringLiteral("pauzeGame"));
        pauzeGame->setMinimumSize(QSize(200, 0));
        pauzeGame->setMaximumSize(QSize(300, 16777215));
        pauzeGame->setFont(font);

        gridLayout_2->addWidget(pauzeGame, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        infoBox->addWidget(frame);


        verticalLayout->addLayout(infoBox);


        retranslateUi(gameWidget);

        QMetaObject::connectSlotsByName(gameWidget);
    } // setupUi

    void retranslateUi(QWidget *gameWidget)
    {
        gameWidget->setWindowTitle(QApplication::translate("gameWidget", "Form", Q_NULLPTR));
        gameTimeLabel->setText(QApplication::translate("gameWidget", "Game time", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("gameWidget", "00:00:00", Q_NULLPTR));
        endGame->setText(QApplication::translate("gameWidget", "End game", Q_NULLPTR));
        exitAplication->setText(QApplication::translate("gameWidget", "Exit application", Q_NULLPTR));
        pauzeGame->setText(QApplication::translate("gameWidget", "Pause", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gameWidget: public Ui_gameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H

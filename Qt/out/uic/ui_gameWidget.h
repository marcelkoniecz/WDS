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
#include <QtWidgets/QHBoxLayout>
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
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *infoBox;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *gameTimeLabel;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pauzeGame;
    QSpacerItem *verticalSpacer_2;
    QPushButton *endGame;
    QSpacerItem *verticalSpacer_3;
    QPushButton *exitAplication;
    QSpacerItem *verticalSpacer_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *gameBox;

    void setupUi(QWidget *gameWidget)
    {
        if (gameWidget->objectName().isEmpty())
            gameWidget->setObjectName(QStringLiteral("gameWidget"));
        gameWidget->resize(664, 418);
        gameWidget->setInputMethodHints(Qt::ImhNone);
        verticalLayoutWidget_2 = new QWidget(gameWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(500, 40, 141, 271));
        infoBox = new QVBoxLayout(verticalLayoutWidget_2);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infoBox->addItem(verticalSpacer_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        gameTimeLabel = new QLabel(verticalLayoutWidget_2);
        gameTimeLabel->setObjectName(QStringLiteral("gameTimeLabel"));

        horizontalLayout_2->addWidget(gameTimeLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        infoBox->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        lineEdit = new QLineEdit(verticalLayoutWidget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        infoBox->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infoBox->addItem(verticalSpacer);

        pauzeGame = new QPushButton(verticalLayoutWidget_2);
        pauzeGame->setObjectName(QStringLiteral("pauzeGame"));

        infoBox->addWidget(pauzeGame);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infoBox->addItem(verticalSpacer_2);

        endGame = new QPushButton(verticalLayoutWidget_2);
        endGame->setObjectName(QStringLiteral("endGame"));

        infoBox->addWidget(endGame);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infoBox->addItem(verticalSpacer_3);

        exitAplication = new QPushButton(verticalLayoutWidget_2);
        exitAplication->setObjectName(QStringLiteral("exitAplication"));

        infoBox->addWidget(exitAplication);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infoBox->addItem(verticalSpacer_4);

        verticalLayoutWidget = new QWidget(gameWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 471, 391));
        gameBox = new QVBoxLayout(verticalLayoutWidget);
        gameBox->setObjectName(QStringLiteral("gameBox"));
        gameBox->setContentsMargins(0, 0, 0, 0);

        retranslateUi(gameWidget);

        QMetaObject::connectSlotsByName(gameWidget);
    } // setupUi

    void retranslateUi(QWidget *gameWidget)
    {
        gameWidget->setWindowTitle(QApplication::translate("gameWidget", "Form", Q_NULLPTR));
        gameTimeLabel->setText(QApplication::translate("gameWidget", "Czas gry", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("gameWidget", "00:00:00", Q_NULLPTR));
        pauzeGame->setText(QApplication::translate("gameWidget", "Pauza", Q_NULLPTR));
        endGame->setText(QApplication::translate("gameWidget", "Koniec gry", Q_NULLPTR));
        exitAplication->setText(QApplication::translate("gameWidget", "Wyjdz z aplikacji", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gameWidget: public Ui_gameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H

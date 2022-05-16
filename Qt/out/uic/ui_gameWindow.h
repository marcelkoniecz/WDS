/********************************************************************************
** Form generated from reading UI file 'gameWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameWindow
{
public:
    QAction *actionUstawienia;
    QAction *actionPolaczenie;
    QAction *actionSettings;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuUstawienia_gry;
    QMenu *menuPolaczenie;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gameWindow)
    {
        if (gameWindow->objectName().isEmpty())
            gameWindow->setObjectName(QStringLiteral("gameWindow"));
        gameWindow->resize(800, 600);
        actionUstawienia = new QAction(gameWindow);
        actionUstawienia->setObjectName(QStringLiteral("actionUstawienia"));
        actionPolaczenie = new QAction(gameWindow);
        actionPolaczenie->setObjectName(QStringLiteral("actionPolaczenie"));
        actionSettings = new QAction(gameWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionConnect = new QAction(gameWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(gameWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        centralwidget = new QWidget(gameWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setEnabled(true);
        gameWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gameWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuUstawienia_gry = new QMenu(menubar);
        menuUstawienia_gry->setObjectName(QStringLiteral("menuUstawienia_gry"));
        menuPolaczenie = new QMenu(menubar);
        menuPolaczenie->setObjectName(QStringLiteral("menuPolaczenie"));
        gameWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(gameWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        gameWindow->setStatusBar(statusbar);

        menubar->addAction(menuUstawienia_gry->menuAction());
        menubar->addAction(menuPolaczenie->menuAction());
        menuUstawienia_gry->addAction(actionSettings);
        menuPolaczenie->addAction(actionConnect);
        menuPolaczenie->addAction(actionDisconnect);

        retranslateUi(gameWindow);

        QMetaObject::connectSlotsByName(gameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *gameWindow)
    {
        gameWindow->setWindowTitle(QApplication::translate("gameWindow", "MainWindow", Q_NULLPTR));
        actionUstawienia->setText(QApplication::translate("gameWindow", "Ustawienia", Q_NULLPTR));
        actionPolaczenie->setText(QApplication::translate("gameWindow", "Polaczenie", Q_NULLPTR));
        actionSettings->setText(QApplication::translate("gameWindow", "Settings", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("gameWindow", "Connect", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("gameWindow", "Disconnect", Q_NULLPTR));
        menuUstawienia_gry->setTitle(QApplication::translate("gameWindow", "Game Settings", Q_NULLPTR));
        menuPolaczenie->setTitle(QApplication::translate("gameWindow", "Connectivity", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gameWindow: public Ui_gameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H

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
#include <QtWidgets/QToolBar>
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
    QWidget *mainwidget;
    QMenuBar *menubar;
    QMenu *menuUstawienia_gry;
    QMenu *menuPolaczenie;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *gameWindow)
    {
        if (gameWindow->objectName().isEmpty())
            gameWindow->setObjectName(QStringLiteral("gameWindow"));
        gameWindow->resize(796, 600);
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
        mainwidget = new QWidget(gameWindow);
        mainwidget->setObjectName(QStringLiteral("mainwidget"));
        mainwidget->setEnabled(true);
        gameWindow->setCentralWidget(mainwidget);
        menubar = new QMenuBar(gameWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 796, 22));
        menuUstawienia_gry = new QMenu(menubar);
        menuUstawienia_gry->setObjectName(QStringLiteral("menuUstawienia_gry"));
        menuPolaczenie = new QMenu(menubar);
        menuPolaczenie->setObjectName(QStringLiteral("menuPolaczenie"));
        gameWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(gameWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        gameWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(gameWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        gameWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(gameWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        gameWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

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
        toolBar->setWindowTitle(QApplication::translate("gameWindow", "toolBar", Q_NULLPTR));
        toolBar_2->setWindowTitle(QApplication::translate("gameWindow", "toolBar_2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gameWindow: public Ui_gameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H

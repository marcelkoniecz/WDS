/********************************************************************************
** Form generated from reading UI file 'settingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *setings;
    QSpacerItem *horizontalSpacer;
    QFrame *gridFrame;
    QGridLayout *gridLayout;
    QCheckBox *vellCheck;
    QLabel *label;
    QLabel *label_3;
    QComboBox *levelBox;
    QComboBox *lifesBox;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_4;
    QCheckBox *bouncingCheck;
    QComboBox *languageBox;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(750, 550);
        Dialog->setMinimumSize(QSize(750, 550));
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(Dialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(16777215, 100));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        setings = new QLabel(frame);
        setings->setObjectName(QStringLiteral("setings"));
        setings->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setPointSize(23);
        setings->setFont(font);

        horizontalLayout_3->addWidget(setings);

        horizontalSpacer = new QSpacerItem(304, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addWidget(frame);

        gridFrame = new QFrame(Dialog);
        gridFrame->setObjectName(QStringLiteral("gridFrame"));
        gridFrame->setFrameShape(QFrame::Box);
        gridLayout = new QGridLayout(gridFrame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        vellCheck = new QCheckBox(gridFrame);
        vellCheck->setObjectName(QStringLiteral("vellCheck"));
        QFont font1;
        font1.setPointSize(15);
        vellCheck->setFont(font1);
        vellCheck->setIconSize(QSize(30, 30));

        gridLayout->addWidget(vellCheck, 4, 1, 1, 1, Qt::AlignHCenter);

        label = new QLabel(gridFrame);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setPointSize(14);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(gridFrame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        levelBox = new QComboBox(gridFrame);
        levelBox->setObjectName(QStringLiteral("levelBox"));
        levelBox->setFont(font2);

        gridLayout->addWidget(levelBox, 3, 1, 1, 1);

        lifesBox = new QComboBox(gridFrame);
        lifesBox->setObjectName(QStringLiteral("lifesBox"));
        lifesBox->setFont(font2);

        gridLayout->addWidget(lifesBox, 2, 1, 1, 1);

        label_2 = new QLabel(gridFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_5 = new QLabel(gridFrame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_4 = new QLabel(gridFrame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        bouncingCheck = new QCheckBox(gridFrame);
        bouncingCheck->setObjectName(QStringLiteral("bouncingCheck"));
        bouncingCheck->setFont(font1);
        bouncingCheck->setLayoutDirection(Qt::LeftToRight);
        bouncingCheck->setIconSize(QSize(22, 22));

        gridLayout->addWidget(bouncingCheck, 5, 1, 1, 1, Qt::AlignHCenter);

        languageBox = new QComboBox(gridFrame);
        languageBox->setObjectName(QStringLiteral("languageBox"));
        languageBox->setFont(font2);

        gridLayout->addWidget(languageBox, 0, 1, 1, 1);


        verticalLayout->addWidget(gridFrame);

        frame_2 = new QFrame(Dialog);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 100));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(frame_2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        setings->setText(QApplication::translate("Dialog", "Settings", Q_NULLPTR));
        vellCheck->setText(QString());
        label->setText(QApplication::translate("Dialog", "Language", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "Difficulty Level", Q_NULLPTR));
        levelBox->clear();
        levelBox->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Easy", Q_NULLPTR)
         << QApplication::translate("Dialog", "Medium", Q_NULLPTR)
         << QApplication::translate("Dialog", "Hard", Q_NULLPTR)
        );
        lifesBox->clear();
        lifesBox->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "1", Q_NULLPTR)
         << QApplication::translate("Dialog", "2", Q_NULLPTR)
         << QApplication::translate("Dialog", "3", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Dialog", "Lifes", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "Random bouncing", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "Random ball velocity", Q_NULLPTR));
        bouncingCheck->setText(QString());
        languageBox->clear();
        languageBox->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "English", Q_NULLPTR)
         << QApplication::translate("Dialog", "Polish", Q_NULLPTR)
        );
        pushButton_2->setText(QApplication::translate("Dialog", "Save", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog", "Return without saving", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H

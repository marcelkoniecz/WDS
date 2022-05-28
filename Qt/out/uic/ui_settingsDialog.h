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
    QCheckBox *checkBox;
    QLabel *label;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_4;
    QCheckBox *checkBox_2;
    QComboBox *comboBox;
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
        checkBox = new QCheckBox(gridFrame);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QFont font1;
        font1.setPointSize(15);
        checkBox->setFont(font1);
        checkBox->setIconSize(QSize(30, 30));

        gridLayout->addWidget(checkBox, 4, 1, 1, 1, Qt::AlignHCenter);

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

        comboBox_3 = new QComboBox(gridFrame);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setFont(font2);

        gridLayout->addWidget(comboBox_3, 3, 1, 1, 1);

        comboBox_2 = new QComboBox(gridFrame);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setFont(font2);

        gridLayout->addWidget(comboBox_2, 2, 1, 1, 1);

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

        checkBox_2 = new QCheckBox(gridFrame);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setFont(font1);
        checkBox_2->setLayoutDirection(Qt::LeftToRight);
        checkBox_2->setIconSize(QSize(22, 22));

        gridLayout->addWidget(checkBox_2, 5, 1, 1, 1, Qt::AlignHCenter);

        comboBox = new QComboBox(gridFrame);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font2);

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);


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
        checkBox->setText(QString());
        label->setText(QApplication::translate("Dialog", "Language", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "Difficulty Level", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Easy", Q_NULLPTR)
         << QApplication::translate("Dialog", "Medium", Q_NULLPTR)
         << QApplication::translate("Dialog", "Hard", Q_NULLPTR)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "1", Q_NULLPTR)
         << QApplication::translate("Dialog", "2", Q_NULLPTR)
         << QApplication::translate("Dialog", "3", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Dialog", "Lifes", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "Random bouncing", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "Random ball velocity", Q_NULLPTR));
        checkBox_2->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
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

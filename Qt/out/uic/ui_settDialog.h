/********************************************************************************
** Form generated from reading UI file 'settDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTDIALOG_H
#define UI_SETTDIALOG_H

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

class Ui_settDialog
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
    QPushButton *saveButton;
    QPushButton *returnButton;

    void setupUi(QDialog *settDialog)
    {
        if (settDialog->objectName().isEmpty())
            settDialog->setObjectName(QStringLiteral("settDialog"));
        settDialog->resize(750, 550);
        settDialog->setMinimumSize(QSize(750, 550));
        verticalLayout = new QVBoxLayout(settDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(settDialog);
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

        gridFrame = new QFrame(settDialog);
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

        frame_2 = new QFrame(settDialog);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 100));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        saveButton = new QPushButton(frame_2);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setFont(font1);
        saveButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(saveButton);

        returnButton = new QPushButton(frame_2);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setFont(font1);

        horizontalLayout->addWidget(returnButton);


        verticalLayout->addWidget(frame_2);


        retranslateUi(settDialog);

        QMetaObject::connectSlotsByName(settDialog);
    } // setupUi

    void retranslateUi(QDialog *settDialog)
    {
        settDialog->setWindowTitle(QApplication::translate("settDialog", "Dialog", Q_NULLPTR));
        setings->setText(QApplication::translate("settDialog", "Settings", Q_NULLPTR));
        checkBox->setText(QString());
        label->setText(QApplication::translate("settDialog", "Language", Q_NULLPTR));
        label_3->setText(QApplication::translate("settDialog", "Difficulty Level", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("settDialog", "Easy", Q_NULLPTR)
         << QApplication::translate("settDialog", "Medium", Q_NULLPTR)
         << QApplication::translate("settDialog", "Hard", Q_NULLPTR)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("settDialog", "1", Q_NULLPTR)
         << QApplication::translate("settDialog", "2", Q_NULLPTR)
         << QApplication::translate("settDialog", "3", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("settDialog", "Lifes", Q_NULLPTR));
        label_5->setText(QApplication::translate("settDialog", "Random bouncing", Q_NULLPTR));
        label_4->setText(QApplication::translate("settDialog", "Random ball velocity", Q_NULLPTR));
        checkBox_2->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("settDialog", "English", Q_NULLPTR)
         << QApplication::translate("settDialog", "Polish", Q_NULLPTR)
        );
        saveButton->setText(QApplication::translate("settDialog", "Save", Q_NULLPTR));
        returnButton->setText(QApplication::translate("settDialog", "Return without saving", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class settDialog: public Ui_settDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTDIALOG_H

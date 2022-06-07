#include "mainWidget.hpp"

mainWidget::mainWidget(gameWindow* parent) {
  QHBoxLayout* whZarzadzca = new QHBoxLayout;
  gameTimer = new QTimer(this);
  gameTimer->start(10);
  gameTimer->stop();
  okienko = new mainGameWidget(this, parent);
  statystyki = new SidePanelWidget(this,parent);
  okienko->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  okienko->setMinimumSize(500, 500);
  statystyki->setMinimumSize(250, 500);
  statystyki->setMaximumSize(250, 500);
  connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
  whZarzadzca->addWidget(okienko);
  whZarzadzca->addWidget(statystyki);
  setLayout(whZarzadzca);
};

void mainWidget::updateTime() {
  //qDebug()<<"tak";
}
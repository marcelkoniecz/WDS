#include "mainWidget.hpp"

mainWidget:: mainWidget(gameWindow* parent, gameParameters* gameInfo) {
  QHBoxLayout* whZarzadzca = new QHBoxLayout;
  gameTimer = new QTimer(this);
  gameTimer->start(10);
  gameTimer->stop();
  okienko = new mainGameWidget(this,gameInfo,gameTimer);
  statystyki = new gameWidget(this,gameTimer);
  okienko->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  okienko->setMinimumSize(500, 500);
  statystyki->setMinimumSize(250, 500);
  statystyki->setMaximumSize(250, 500);
  connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
  // statystyki->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
   // statystyki->move(400,30);
  // std::cout<<"tak";

  whZarzadzca->addWidget(okienko);
  //whZarzadzca->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));
  whZarzadzca->addWidget(statystyki);
  setLayout(whZarzadzca);

};

void mainWidget::updateTime() {
  //qDebug()<<"tak";
}
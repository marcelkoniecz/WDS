#include "mainWidget.hpp"

mainWidget:: mainWidget(gameWindow* parent, UARTVal* gameInfo, gameParameters* gameParam) {
  QHBoxLayout* whZarzadzca = new QHBoxLayout;
  gameTimer = new QTimer(this);
  gameTimer->start(10);
  gameTimer->stop();
  okienko = new mainGameWidget(this,gameInfo,gameTimer,gameParam);
  statystyki = new SidePanelWidget(this,gameTimer);
  okienko->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  okienko->setMinimumSize(500, 500);
  statystyki->setMinimumSize(250, 500);
  statystyki->setMaximumSize(250, 500);
  connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
  //connect(statystyki,SIGNAL(EmitEndGame()),this,SLOT(endGame()));
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
APP = main
START_APP =./main
SOURCE = `/bin/pwd`/src/*.cpp `/bin/pwd`/inc/*.hpp
QT = OBJECTS_DIR=obj QT+=widgets\
      QT+=serialport\
	  QT+=core
FLAGS = -Wall
__start__:${APP}
	rm -f core*; ${START_APP}

${APP}: Makefile.app __check__ 

__check__:
	make -f Makefile.app

Makefile.app: ${APP}.pro    
	qmake -o Makefile.app ${APP}.pro    

${APP}.pro: Makefile
	qmake -project -o ${APP}.pro ${QT} ${SOURCE}    

clean:
	make -f Makefile.app clean

cleanall: clean
	rm -f ${APP}
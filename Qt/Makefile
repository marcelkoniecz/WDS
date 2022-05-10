APP = gra
START_APP =./gra
SOURCE = `/bin/pwd`/src/*.cpp `/bin/pwd`/inc/*.hpp `/bin/pwd`/ui/*.ui \
		`/bin/pwd`/res/*.qrc

OBJ_FOL=./out/obj
MOC_FOL=./out/moc

QT = OBJECTS_DIR=${OBJ_FOL} INCLUDEPATH=inc INCLUDEPATH+=ui/inc\
		INCLUDEPATH+=.inc\
		INCLUDEPATH+=./res/inc\
		INCLUDEPATH+=./ui/inc\
		RCC_DIR=./out/rcc\
        UI_DIR=./out/uic\
        QMAKE_CXXFLAGS+=-g\
		MOC_DIR=${MOC_FOL}\
		QT+=widgets\
    	QT+=serialport\
		QT+=gui\
		LIBS+=-lpthread\
		QT+=core


__start__: Makefile.app ${APP}
	rm -f core*; ${START_APP}

${APP}: out/pro/${APP}.pro __check__ 

out/pro:
	mkdir -p out/pro

__check__:
	make -f Makefile.app

Makefile.app: out/pro/${APP}.pro    
	qmake -o Makefile.app out/pro/${APP}.pro    

out/pro/${APP}.pro: Makefile
	rm -f ${APP}
	qmake -project -nopwd -o out/pro/${APP}.pro\
			${QT} ${SOURCE}  

project: __del_pro__ out/pro/${APP}.pro 

__del_pro__:
	rm -f out/pro/${APP}.pro

clean:
	make -f Makefile.app clean

cleanall: clean
	rm -f ${APP}
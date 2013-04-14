APP_NAME = bbmoviez
TARGET = bbmoviez

CONFIG += qt warn_on cascades10

INCLUDEPATH += ../../../bbmoviez/
INCLUDEPATH += ../../Box2D/
INCLUDEPATH += ../src
INCLUDEPATH += ../src/REST/
INCLUDEPATH += ../src/controllers
INCLUDEPATH += ../src/controllers/home
SOURCES += ../src/*.cpp
SOURCES +=  ../src/controllers/*.cpp
SOURCES += ../src/controllers/home/*.cpp
HEADERS += ../src/*.hpp
HEADERS +=  ../src/controllers/*.hpp
HEADERS +=  ../src/controllers/*.h
HEADERS +=  ../src/controllers/home/*.hpp
HEADERS +=  ../src/controllers/home/*.h

LIBS += -lpps
LIBS += -lcurl
LIBS += -lcsm
LIBS += -lbbdevice
LIBS += -lbbsystem
LIBS += -lbbdata
LIBS += -lbb
LIBS += -lbbplatform
LIBS += -lbbpim
LIBS += $$_PRO_FILE_PWD_/../Box2D/Device-Debug/libBox2D.a

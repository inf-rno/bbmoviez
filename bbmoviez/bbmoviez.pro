APP_NAME = bbmoviez
TARGET = bbmoviez

CONFIG += qt warn_on cascades10

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
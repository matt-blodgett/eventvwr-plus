DEFINES += QT_DEPRECATED_WARNINGS


CONFIG += c++11


QT += gui
QT += core
QT += widgets


TARGET = eventvwr-plus
TEMPLATE = app


RESOURCES += run/run.qrc


SOURCES += main.cpp
HEADERS += common/mframe.h
SOURCES += common/mframe.cpp

HEADERS += run/mroot.h
SOURCES += run/mroot.cpp
HEADERS += run/mframecommand.h
SOURCES += run/mframecommand.cpp
HEADERS += run/mframebuttons.h
SOURCES += run/mframebuttons.cpp

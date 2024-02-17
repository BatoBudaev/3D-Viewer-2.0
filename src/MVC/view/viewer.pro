QT += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets 
include(3rdparty/QtGifImage/src/gifimage/qtgifimage.pri)

CONFIG += c++17

SOURCES += \
    ../../patterns/movecommand.cc \
    ../../patterns/rotatecommand.cc \
    ../../patterns/singleton.cc \
    main.cpp \
    mainwindow.cpp \
    myglwidget.cpp \
    ../model/vertex.cc \
    ../model/surface.cc \
    ../model/model.cc \
    ../controller/controller.cc \

HEADERS += \
    ../../patterns/icommand.h \
    ../../patterns/movecommand.h \
    ../../patterns/observer.h \
    ../../patterns/rotatecommand.h \
    ../../patterns/singleton.h \
    ../../patterns/subject.h \
    ../controller/controller.h \
    mainwindow.h \
    myglwidget.h \
    ../model/model.h \
    ../model/vertex.h \
    ../model/surface.h \
    ../controller/controller.h \

FORMS += \
    mainwindow.ui

qnx: target.path = ../build/$${TARGET}/
unix:!android: target.path = ../build/$${TARGET}/
!isEmpty(target.path): INSTALLS += target

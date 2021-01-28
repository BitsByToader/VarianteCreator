QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


HEADERS += \
        worker.h

SOURCES += \
        main.cpp \
        worker.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../PDF-Writer/PDFWriter/ -lPDFWriter

INCLUDEPATH += $$PWD/../PDF-Writer/PDFWriter
DEPENDPATH += $$PWD/../PDF-Writer/PDFWriter

unix:!macx: PRE_TARGETDEPS += $$PWD/../PDF-Writer/PDFWriter/libPDFWriter.a

unix:!macx: LIBS += -L$$PWD/../PDF-Writer/FreeType/ -lFreeType

INCLUDEPATH += $$PWD/../PDF-Writer/FreeType
DEPENDPATH += $$PWD/../PDF-Writer/FreeType

unix:!macx: PRE_TARGETDEPS += $$PWD/../PDF-Writer/FreeType/libFreeType.a

unix:!macx: LIBS += -L$$PWD/../PDF-Writer/LibAesgm/ -lLibAesgm

INCLUDEPATH += $$PWD/../PDF-Writer/LibAesgm
DEPENDPATH += $$PWD/../PDF-Writer/LibAesgm

unix:!macx: PRE_TARGETDEPS += $$PWD/../PDF-Writer/LibAesgm/libLibAesgm.a

unix:!macx: LIBS += -L$$PWD/../PDF-Writer/LibJpeg/ -lLibJpeg

INCLUDEPATH += $$PWD/../PDF-Writer/LibJpeg
DEPENDPATH += $$PWD/../PDF-Writer/LibJpeg

unix:!macx: PRE_TARGETDEPS += $$PWD/../PDF-Writer/LibJpeg/libLibJpeg.a

unix:!macx: LIBS += -L$$PWD/../PDF-Writer/LibPng/ -lLibPng

INCLUDEPATH += $$PWD/../PDF-Writer/LibPng
DEPENDPATH += $$PWD/../PDF-Writer/LibPng

unix:!macx: PRE_TARGETDEPS += $$PWD/../PDF-Writer/LibPng/libLibPng.a

unix:!macx: LIBS += -L$$PWD/../PDF-Writer/LibTiff/ -lLibTiff

INCLUDEPATH += $$PWD/../PDF-Writer/LibTiff
DEPENDPATH += $$PWD/../PDF-Writer/LibTiff

unix:!macx: PRE_TARGETDEPS += $$PWD/../PDF-Writer/LibTiff/libLibTiff.a

unix:!macx: LIBS += -L$$PWD/../PDF-Writer/ZLib/ -lZlib

INCLUDEPATH += $$PWD/../PDF-Writer/ZLib
DEPENDPATH += $$PWD/../PDF-Writer/ZLib

unix:!macx: PRE_TARGETDEPS += $$PWD/../PDF-Writer/ZLib/libZlib.a

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += freetype2

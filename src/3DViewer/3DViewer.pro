QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(QtGifImage/src/gifimage/qtgifimage.pri)

CONFIG += c++17
QMAKE_CXXFLAGS += -DGL_SILENCE_DEPRECATION

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/Converter/converter.cc \
    Controller/controller.cc \
    Model/CalculationsClass/calculationsclass.cc \
    Model/CalculationsClass/Parcer/parcer.cc \
    Model/Data/Iterator/vertexiterator.cc \
    Model/Setting/boolsettings.cc \
    Model/Setting/colorsettings.cc \
    Model/Setting/modelsettings.cc \
    Model/Setting/sizesettings.cc \
    Model/Gif/imagegif.cc \
    View/GLModule/glmodule.cc \
    main.cc \
    Model/model.cc \
    View/view.cc

HEADERS += \
    Controller/Converter/converter.h \
    Controller/controller.h \
    Model/CalculationsClass/calculationsclass.h \
    Model/CalculationsClass/Parcer/parcer.h \
    Model/Data/vertexcoordinates.h \
    Model/Data/modelfromparcer.h \
    Model/Data/Iterator/vertexiterator.h \
    Model/Setting/boolsettings.h \
    Model/Setting/colorsettings.h \
    Model/Setting/modelsettings.h \
    Model/Setting/sizesettings.h \
    Model/Gif/imagegif.h \
    Model/Observer/observer.h \
    View/GLModule/glmodule.h \
    Model/model.h \
    View/view.h \
    View/uiobjectmodel.h \

FORMS += \
    View/view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

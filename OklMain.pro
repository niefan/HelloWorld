#-------------------------------------------------
#
# Project created by QtCreator 2018-05-18T18:39:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OklMain
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Src/CommonUserWidget/BmpButton.cpp \
    Src/CommonUserWidget/BmpWidget.cpp \
    Src/CommonUserWidget/CustomItemDelegate.cpp \
    Src/CommonUserWidget/CustomScrollBar.cpp \
    Src/CommonUserWidget/MessageBox.cpp \
    Src/CommonUserWidget/Slider.cpp \
    Src/CommonUserWidget/TextWidget.cpp \
    Src/CommonUserWidget/UserInterfaceUtility.cpp \
    Src/Framework/Base/Core/application.cpp \
    Src/Framework/Base/Audio/audiomanager.cpp \
    Src/Framework/Base/Video/videomanager.cpp \
    Src/Framework/View/toast.cpp \
    Src/Framework/Base/Core/context.cpp \
    Src/Framework/Base/Core/activity.cpp \
    Src/Framework/Base/Core/service.cpp \
    Src/Application/Launcher/launcher.cpp \
    Src/Framework/Base/Core/message.cpp \
    Src/Application/Radio/radio.cpp \
    Src/Application/Settings/settings.cpp \
    Src/Application/BlueTooth/Music/btmusic.cpp \
    Src/Application/BlueTooth/Phone/btphone.cpp \
    Src/Application/Ipod/ipod.cpp \
    Src/Application/MultiMedia/Image/image.cpp \
    Src/Application/MultiMedia/Music/music.cpp \
    Src/Application/MultiMedia/Video/video.cpp \
    Src/Application/SystemUi/systemui.cpp \
    Src/Application/Avin/avin.cpp \
    Src/Framework/Base/Core/simulation.cpp \
    Src/Simulation/simulationda.cpp \
    Src/Application/Radio/radio_am.cpp \
    Src/Application/MultiMedia/Music/musicplaywidget.cpp \
    Src/Application/MultiMedia/Music/musiclistwidget.cpp \
    Src/Application/MultiMedia/Music/musiclistitem.cpp \
    Src/Application/MultiMedia/Music/musicprogresswidget.cpp \
    Src/Application/MultiMedia/Music/musicclickwidget.cpp \
    Src/CommonUserWidget/rotatewidget.cpp \
    Src/Application/MultiMedia/Music/btmusicwidget.cpp \
    Src/CommonUserWidget/flowview.cpp \
    Src/CommonUserWidget/flowadapter.cpp \
    Src/Application/MultiMedia/Video/videoplaywidget.cpp \
    Src/Application/MultiMedia/Video/videolistwidget.cpp \
    Src/Application/MultiMedia/Tools/mediatoolswidget.cpp

HEADERS  += mainwindow.h \
    configuration.h \
    Src/CommonUserWidget/BmpButton.h \
    Src/CommonUserWidget/BmpWidget.h \
    Src/CommonUserWidget/CustomItemDelegate.h \
    Src/CommonUserWidget/CustomScrollBar.h \
    Src/CommonUserWidget/MessageBox.h \
    Src/CommonUserWidget/Slider.h \
    Src/CommonUserWidget/TextWidget.h \
    Src/CommonUserWidget/UserInterfaceUtility.h \
    Src/Framework/Base/Core/application.h \
    Src/Framework/Base/Audio/audiomanager.h \
    Src/Framework/Base/Video/videomanager.h \
    Src/Framework/View/toast.h \
    Src/Framework/Base/Core/context.h \
    Src/Framework/Base/Core/activity.h \
    Src/Framework/Base/Core/service.h \
    Src/Framework/Base/Core/message.h \
    Src/Framework/Base/Core/apptype.h \
    Src/Application/AllApplication.h \
    Src/Application/Launcher/launcher.h \
    Src/Application/Radio/radio.h \
    Src/Application/Settings/settings.h \
    Src/Application/BlueTooth/Phone/btphone.h \
    Src/Application/Ipod/ipod.h \
    Src/Application/MultiMedia/Image/image.h \
    Src/Application/MultiMedia/Music/music.h \
    Src/Application/MultiMedia/Video/video.h \
    Src/Application/SystemUi/systemui.h \
    Src/Application/BlueTooth/Music/btmusic.h \
    Src/Application/Avin/avin.h \
    Src/Framework/Base/Core/simulation.h \
    Src/Simulation/simulationda.h \
    Src/Application/Radio/radio_am.h \
    Src/Application/MultiMedia/Music/musicplaywidget.h \
    Src/Application/MultiMedia/Music/musiclistwidget.h \
    Src/Application/MultiMedia/Music/musiclistitem.h \
    Src/Application/MultiMedia/Music/musicprogresswidget.h \
    Src/Application/MultiMedia/Music/musicclickwidget.h \
    Src/CommonUserWidget/rotatewidget.h \
    Src/Application/MultiMedia/Music/btmusicwidget.h \
    Src/CommonUserWidget/flowview.h \
    Src/CommonUserWidget/flowadapter.h \
    Src/Application/MultiMedia/Video/videoplaywidget.h \
    Src/Application/MultiMedia/Video/videolistwidget.h \
    Src/Application/MultiMedia/Tools/mediatoolswidget.h



RESOURCES += \
    Res/test.qrc \
    Res/simulation.qrc \
    Res/multimedia.qrc \
    Res/settingsrc.qrc \
    Res/commonsrc.qrc \
    Res/systemuisrc.qrc \
    Res/launchersrc.qrc

#DISTFILES += \



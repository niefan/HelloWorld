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
    Src/Application/Avin/avin.cpp

HEADERS  += mainwindow.h \
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
    Src/Application/Avin/avin.h


RESOURCES += \
    Res/test.qrc


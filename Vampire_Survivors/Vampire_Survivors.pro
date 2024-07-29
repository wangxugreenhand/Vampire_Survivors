QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choose_survivor_scene.cpp \
    enemy.cpp \
    form.cpp \
    lose_return.cpp \
    main.cpp \
    mainscene.cpp \
    mainscene_2.cpp \
    revive.cpp \
    shop.cpp \
    survivors.cpp \
    upgrade.cpp \
    weapon.cpp \
    win_return.cpp

HEADERS += \
    choose_survivor_scene.h \
    config.h \
    enemy.h \
    form.h \
    lose_return.h \
    mainscene.h \
    mainscene_2.h \
    revive.h \
    shop.h \
    survivors.h \
    upgrade.h \
    weapon.h \
    win_return.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

FORMS += \
    form.ui

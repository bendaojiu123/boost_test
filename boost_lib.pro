QT += core

TEMPLATE = app
DEFINES += BOOST_LIB_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/date_time/greg_month.cpp

HEADERS += \
    boost/date_time/gregorian/gregorian.hpp \
    boost/date_time/src/greg_names.hpp \
    boost/timer.hpp \
    boost/timer/config.hpp \
    boost/timer/progress_display.hpp \
    boost/timer/timer.hpp \
    src/date_time/greg_names.hpp \
    templateTest1.h \
    test/date_time/date_time_Test.h \
    test/date_time/timerTest.h \
    test/date_time_Test.h


# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

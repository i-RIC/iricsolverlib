TEMPLATE = app
TARGET = iricsolverlibTest
CONFIG += testcase
QT += testlib

# iricsolverlib

INCLUDEPATH += "../src"

CONFIG(debug, debug|release) {
	LIBS += -L"../src/debug"
} else {
	LIBS += -L"../src/release"
}
LIBS += -liricsolverlib

# Input
HEADERS += testarea.h testinterpolate.h testregion.h
SOURCES += main.cpp testarea.cpp testinterpolate.cpp testregion.cpp

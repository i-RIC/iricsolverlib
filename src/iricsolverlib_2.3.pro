TEMPLATE = lib
TARGET = iricsolverlib_2.3
DEPENDPATH += .
CONFIG += static

DEFINES += IRICSOLVERLIBSTATIC_LIBRARY
DEFINES += UPPERCASE
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += _SECURE_SCL=0

# cgnslib

win32 {
	INCLUDEPATH += "../../libs/include"
	LIBS += -L"../../libs/lib" -llibcgns_x64_ifort_release
}

# Input
HEADERS += fortran_macros.h \
           iricsolverlib.h \
           iricsolverlib_api.h \
           iricsolverlib_cell2d.h \
           iricsolverlib_grid2d.h \
           iricsolverlib_point2d.h \
           iricsolverlib_quadcell.h \
           iricsolverlib_rect2d.h \
           iricsolverlib_tricell.h \
           private/iricsolverlib_cell2d_impl.h \
           private/iricsolverlib_grid2d_impl.h \
           private/iricsolverlib_point2d_detail.h
SOURCES += iricsolver_ftoc.c \
           iricsolverlib.cpp \
           iricsolverlib_cell2d.cpp \
           iricsolverlib_grid2d.cpp \
           iricsolverlib_quadcell.cpp \
           iricsolverlib_rect2d.cpp \
           iricsolverlib_tricell.cpp

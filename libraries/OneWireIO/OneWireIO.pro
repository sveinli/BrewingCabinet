CDPVERSION = 4.7
TYPE = library
PROJECTNAME = OneWireIO

DEPS += \

HEADERS += \
    OneWireIO.h \
    OneWireIOBuilder.h \
    OneWireIOServer.h \
    OneWireSensor.h

SOURCES += \
    OneWireIOBuilder.cpp \
    OneWireIOServer.cpp \
    OneWireSensor.cpp

DISTFILES += $$files(*.xml, true) \
    Templates/Models/OneWireIO.OneWireSensor.xml \
    Templates/Models/OneWireIO.OneWireIOServer.xml

load(cdp)

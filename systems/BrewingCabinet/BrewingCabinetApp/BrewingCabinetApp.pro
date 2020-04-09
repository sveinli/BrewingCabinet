TYPE = application
PROJECTNAME = BrewingCabinetApp

DEPS += automation brewinglib cdpeventmanager cdplogger gpiopinio mqttio onewireio

HEADERS += Libraries.h
SOURCES += CDPMain.cpp

DISTFILES += \
    $$files(*.xml, true) \
    $$files(*.lic, true) \
    $$files(Application/www/*.*, true)

load(cdp)

ID = 359556465057295 # do not change

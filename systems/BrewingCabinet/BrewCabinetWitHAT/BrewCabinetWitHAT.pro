TYPE = application
PROJECTNAME = BrewCabinetWitHAT

DEPS += gpiopinio onewireio

HEADERS += Libraries.h
SOURCES += CDPMain.cpp

DISTFILES += \
    $$files(*.xml, true) \
    $$files(*.lic, true) \
    $$files(Application/www/*.*, true)

load(cdp)

ID = 205594814551370 # do not change

CDPVERSION = 4.10
TYPE = library
PROJECTNAME = BrewingLib

DEPS += \

HEADERS += \
    brewinglib.h \
    BrewingLibBuilder.h \
    Cabinet.h \
    BrewingCabinetSim.h \
    SSRControlledHeater.h

SOURCES += \
    BrewingLibBuilder.cpp \
    Cabinet.cpp \
    BrewingCabinetSim.cpp \
    SSRControlledHeater.cpp

DISTFILES += $$files(*.xml, true) \
    Templates/Models/BrewingLib.Cabinet.xml \
    Templates/Models/BrewingLib.BrewingCabinetSim.xml \
    Templates/Models/BrewingLib.SSRControlledHeater.xml

load(cdp)

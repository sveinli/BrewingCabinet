/**
ONEWIREIO header file. Include this file in the project to use the library.
*/
#ifndef ONEWIREIO_ONEWIREIO_H
#define ONEWIREIO_ONEWIREIO_H

#include "OneWireIOBuilder.h"

namespace OneWireIO {

/** Instantiate the OneWireIOBuilder for this object */
OneWireIOBuilder gOneWireIOBuilder("OneWireIO", __TIMESTAMP__);

}

#endif

/**
BrewingLib header file. Include this file in the project to use the library.
*/
#ifndef BREWINGLIB_BREWINGLIB_H
#define BREWINGLIB_BREWINGLIB_H

#include "BrewingLibBuilder.h"

namespace BrewingLib {

/** Instantiate the BrewingLibBuilder for this object */
BrewingLibBuilder gBrewingLibBuilder("BrewingLib", __TIMESTAMP__);

}

#endif // BREWINGLIB_BREWINGLIB_H

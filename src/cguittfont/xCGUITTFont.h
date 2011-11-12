// A wrapper header to avoid hack with gcc and modifying
// the CGUITTFont files.

#define USTRING_NO_STL
#include "irrUString.h"  // must be included before CGUITTFont.h
#include "CGUITTFont.h"

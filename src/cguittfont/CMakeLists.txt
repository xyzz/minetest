# Alas, CGUITTFont.{cpp,h} don't include irrUString.h even though they use
# core::ustring.
# We don't want to (and shouldn't have to) modify our copies of
# CGUITTFont.{cpp,h} because that would complicate updating them later.

#if(CMAKE_COMPILER_IS_GNUCXX)
#	add_definitions(-include "${CMAKE_CURRENT_SOURCE_DIR}/irrUString.h")
#	add_definitions(-include "stddef.h")
#endif(CMAKE_COMPILER_IS_GNUCXX)

include_directories(
	${IRRLICHT_INCLUDE_DIR}
	${FREETYPE_INCLUDE_DIRS}
)

add_library(cguittfont CGUITTFont.cpp)

target_link_libraries(
	cguittfont
	${IRRLICHT_LIBRARY}
	${FREETYPE_LIBRARIES}
)

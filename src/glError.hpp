/**
 * glError.hpp
 * Contributors:
 *      * Arthur Sonzogni (author)
 * Licence:
 *      * MIT
 */

#pragma once

void _glCheckError(const char* file, unsigned int line);

// Ask Opengl for errors:
// Result is printed on the standard output
// usage :
//      glCheckError();
#define glCheckError() _glCheckError(__FILE__, __LINE__)

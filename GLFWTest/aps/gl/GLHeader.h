#pragma once

#ifdef APS_USE_GL3

#  ifndef __gl3_h_
#    ifdef __APPLE__
#      include <OpenGL/gl3.h>
#    else
#      ifdef _WIN32
#        include <windows.h>
#      endif
#      include <GL/gl3.h>
#    endif
#  endif

#else

#  ifndef __gl_h_
#    ifdef __APPLE__
#      include <OpenGL/gl.h>
#      include <OpenGL/glu.h>
#    else
#      ifdef _WIN32
#        include <windows.h>
#      endif
#      include <GL/gl.h>
#      include <GL/glu.h>
#    endif
#  endif

#endif
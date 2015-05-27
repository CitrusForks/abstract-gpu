#ifndef _AGPU_DEVICE_HPP_
#define _AGPU_DEVICE_HPP_

#if defined(_WIN32)
#include <windows.h>
#include <GL/GL.h>
#include <GL/glext.h>
#elif defined(__linux__)
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glext.h>
#else
#error unsupported platform
#endif

#include <string>

#include "object.hpp"

class AgpuGLImmediateContext;

/**
 * OpenGL version number
 */
enum class OpenGLVersion
{
    Version10 = 10,
    Version20 = 20,
    Version21 = 21,
    Version30 = 30,
    Version31 = 31,
    Version32 = 32,
    Version33 = 33,
    Version40 = 40,
    Version41 = 41,
    Version42 = 42,
    Version43 = 43,
};

/**
 * Agpu OpenGL device
 */
class _agpu_device: public Object<_agpu_device>
{
public:
    _agpu_device();

    void lostReferences();

    static bool isExtensionSupported(const char *extList, const char *extension);
    static agpu_device *open(agpu_device_open_info* openInfo);

    agpu_context* createDeferredContext();
    agpu_context* getImmediateContext();

    agpu_error swapBuffers();

    bool makeCurrent();
    void readVersionInformation();
    void loadExtensions();
    void *getProcAddress(const char *symbolName);

    template<typename FT>
    void loadExtensionFunction(FT &functionPointer, const char *functionName)
    {
        functionPointer = reinterpret_cast<FT> (getProcAddress(functionName));
    }

    OpenGLVersion versionNumber;
    std::string rendererString, shaderString;

#ifdef _WIN32
#elif defined(__linux__)
    Display *display;
    Window window;
    GLXContext context;
#endif
    agpu_context* immediateContext;
    
public:
    // OpenGL API
    
    // Vertex buffer object
    PFNGLGENBUFFERSPROC glGenBuffers;
    PFNGLDELETEBUFFERSPROC glDeleteBuffers;
    PFNGLBINDBUFFERPROC glBindBuffer;
    PFNGLBUFFERDATAPROC glBufferData;
    PFNGLBUFFERSUBDATAPROC glBufferSubData;
    PFNGLMAPBUFFERPROC glMapBuffer;
    PFNGLUNMAPBUFFERPROC glUnmapBuffer;
    PFNGLBUFFERSTORAGEPROC glBufferStorage;


};

#endif //_AGPU_DEVICE_HPP_


#if defined(SOKOL_IMPL) && !defined(SOKOL_FRAMEBUFFER_IMPL)
#define SOKOL_FRAMEBUFFER_IMPL
#endif

#ifndef SOKOL_FRAMEBUFFER_INCLUDED
/*
    sokol_framebuffer.h -- old-school pixel framebuffers on top of sokol_gfx.h

    Project URL: https://github.com/floooh/sokol

    Do this:
        #define SOKOL_IMPL or
        #define SOKOL_FRAMEBUFFER_IMPL

    before you include this file in *one* C or C++ file to create the
    implementation.

    The following defines are used by the implementation to select the
    platform-specific embedded shader code (these are the same defines as
    used by sokol_gfx.h and sokol_app.h):

    SOKOL_GLCORE
    SOKOL_GLES3
    SOKOL_D3D11
    SOKOL_METAL
    SOKOL_WGPU

    Optionally provide the following macros before including the implementation
    to override defaults:

    SOKOL_ASSERT(c)     - your own assert macro (default: assert(c))
    SOKOL_FRAMEBUFFER_API_DECL- public function declaration prefix (default: extern)
    SOKOL_API_DECL      - same as SOKOL_FRAMEBUFFER_API_DECL
    SOKOL_API_IMPL      - public function implementation prefix (default: -)

    If sokol_framebuffer.h is compiled as a DLL, define the following before
    including the declaration or implementation:

    SOKOL_DLL

    On Windows, SOKOL_DLL will define SOKOL_FRAMEBUFFER_API_DECL as __declspec(dllexport)
    or __declspec(dllimport) as needed.

    Include the following headers before sokol_framebuffer.h (both before including
    the declaration and implementation):

        sokol_gfx.h

    FEATURE OVERVIEW
    ================
    [TODO]


    LICENSE
    =======

    zlib/libpng license

    Copyright (c) 2024 Andre Weissflog

    This software is provided 'as-is', without any express or implied warranty.
    In no event will the authors be held liable for any damages arising from the
    use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

        1. The origin of this software must not be misrepresented; you must not
        claim that you wrote the original software. If you use this software in a
        product, an acknowledgment in the product documentation would be
        appreciated but is not required.

        2. Altered source versions must be plainly marked as such, and must not
        be misrepresented as being the original software.

        3. This notice may not be removed or altered from any source
        distribution.
*/
#define SOKOL_FRAMEBUFFER_INCLUDED (1)
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h> // size_t

#if !defined(SOKOL_GFX_INCLUDED)
#error "Please include sokol_gfx.h before sokol_framebuffer.h"
#endif

#if defined(SOKOL_API_DECL) && !defined(SOKOL_FRAMEBUFFER_API_DECL)
#define SOKOL_FRAMEBUFFER_API_DECL SOKOL_API_DECL
#endif
#ifndef SOKOL_FRAMEBUFFER_API_DECL
#if defined(_WIN32) && defined(SOKOL_DLL) && defined(SOKOL_FRAMEBUFFER_IMPL)
#define SOKOL_FRAMEBUFFER_API_DECL __declspec(dllexport)
#elif defined(_WIN32) && defined(SOKOL_DLL)
#define SOKOL_FRAMEBUFFER_API_DECL __declspec(dllimport)
#else
#define SOKOL_FRAMEBUFFER_API_DECL extern
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

// TODO: public API

SOKOL_FRAMEBUFFER_API_DECL void sfb_setup(sfb_desc* desc);
SOKOL_FRAMEBUFFER_API_DECL void sfb_shutdown(void);

SOKOL_FRAMEBUFFER_API_DECL sfb_framebuffer sfb_make_framebuffer(const sfb_framebuffer_desc* desc);
SOKOL_FRAMEBUFFER_API_DECL void sfb_destroy_framebuffer(sfb_framebuffer fb);

SOKOL_FRAMEBUFFER_API_DECL void sfb_update(sfb_update_info upd_info)
SOKOL_FRAMEBUFFER_API_DECL sfb_draw(sfb_draw_info draw_info);

#ifdef __cplusplus
} // extern "C"

// TODO: C++ helpers

#endif
#endif // SOKOL_FRAMEBUFFER_INCLUDED

// ██ ███    ███ ██████  ██      ███████ ███    ███ ███████ ███    ██ ████████  █████  ████████ ██  ██████  ███    ██
// ██ ████  ████ ██   ██ ██      ██      ████  ████ ██      ████   ██    ██    ██   ██    ██    ██ ██    ██ ████   ██
// ██ ██ ████ ██ ██████  ██      █████   ██ ████ ██ █████   ██ ██  ██    ██    ███████    ██    ██ ██    ██ ██ ██  ██
// ██ ██  ██  ██ ██      ██      ██      ██  ██  ██ ██      ██  ██ ██    ██    ██   ██    ██    ██ ██    ██ ██  ██ ██
// ██ ██      ██ ██      ███████ ███████ ██      ██ ███████ ██   ████    ██    ██   ██    ██    ██  ██████  ██   ████
//
// >>implementation
#ifdef SOKOL_FRAMEBUFFER_IMPL
#define SOKOL_FRAMEBUFFER_IMPL_INCLUDED (1)

#ifndef SOKOL_API_IMPL
    #define SOKOL_API_IMPL
#endif
#ifndef SOKOL_DEBUG
    #ifndef NDEBUG
        #define SOKOL_DEBUG
    #endif
#endif
#ifndef SOKOL_ASSERT
    #include <assert.h>
    #define SOKOL_ASSERT(c) assert(c)
#endif

// TODO: implementation

#endif // SOKOL_FRAMEBUFFER_IMPL
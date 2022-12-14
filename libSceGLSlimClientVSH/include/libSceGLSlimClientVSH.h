#pragma once

#include "prerequisites.h"

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglsce.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <GLES2/gl2sce.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EGL_EGLEXT_PROTOTYPES 1

#define GL_GLES_PROTOTYPES 1
#define GL_GLEXT_PROTOTYPES 1

#define SCE_PGL_MAX_PROCESS_ORDER (2)

#define SCE_PGL_FLAGS_USE_COMPOSITE_EXT (0x8)
#define SCE_PGL_FLAGS_SKIP_APP_INITIALIZATION (0x10)
#define SCE_PGL_FLAGS_USE_TILED_TEXTURE (0x40)
#define SCE_PGL_FLAGS_USE_FLEXIBLE_MEMORY (0x80) /* should be used with SCE_PGL_FLAGS_USE_COMPOSITE_EXT */

#define SCE_PGL_MAX_SYS_SHARED_MEM (0x20000000)
#define SCE_PGL_MAX_VIDEO_SHARED_MEM (0x20000000)
#define SCE_PGL_MAX_VIDEO_PRIV_MEM (0x20000000)

#define SIZEOF_SCE_PGL_CONFIG 0xA0 //0x88 on orbis

TYPE_BEGIN(struct _ScePglConfig, SIZEOF_SCE_PGL_CONFIG);
	TYPE_FIELD(uint32_t size, 0x00);
	TYPE_FIELD(uint32_t flags, 0x04);
	TYPE_FIELD(uint32_t processOrder, 0x08);
	TYPE_FIELD(uint32_t unk_0x0C, 0x0C);
	TYPE_FIELD(uint64_t systemMemoryPointer, 0x10);
	TYPE_FIELD(uint64_t systemSharedMemorySize, 0x18);

	TYPE_FIELD(uint64_t videoMemoryPointer, 0x20);
	TYPE_FIELD(uint64_t videoSharedMemorySize, 0x28);
	TYPE_FIELD(uint64_t maxMappedFlexibleMemory, 0x30);
	TYPE_FIELD(uint64_t minFlexibleMemoryChunkSize, 0x38);

	TYPE_FIELD(uint32_t display_width, 0x40);
	TYPE_FIELD(uint32_t display_height, 0x44);
	TYPE_FIELD(uint32_t dbgPosCmd_0x48, 0x48);
	TYPE_FIELD(uint32_t dbgPosCmd_0x4C, 0x4C);
	TYPE_FIELD(uint8_t dbgPosCmd_0x50, 0x50);

	TYPE_FIELD(uint32_t drawCommandBufferSize, 0x54);
	TYPE_FIELD(uint32_t lcueResourceBufferSize, 0x58);

	TYPE_FIELD(uint32_t numCmdBuffer, 0x5C);

	TYPE_FIELD(uint64_t AllocInitFunction, 0x60);
	TYPE_FIELD(uint64_t AllocFinishFunction, 0x68);
	TYPE_FIELD(uint64_t AllocFunction, 0x70);
	TYPE_FIELD(uint64_t DeallocFunciton, 0x78);
	
	TYPE_FIELD(uint64_t unk_0x80, 0x80);
	TYPE_FIELD(uint64_t unk_0x88, 0x88);
	TYPE_FIELD(uint64_t unk_0x90, 0x90);
	TYPE_FIELD(uint64_t unk_0x98, 0x98);
TYPE_END();
typedef struct _ScePglConfig ScePglConfig;

bool scePigletSetConfigurationVSH(const ScePglConfig* config);
bool scePigletGetConfigurationVSH(const ScePglConfig* config);

#ifdef __cplusplus
}
#endif

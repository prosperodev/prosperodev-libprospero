/*
#  ____   ____   ____      ___  ____   ____  ____   ____  ____   ____ _     _
#  ____|  ____> |    |    |     ____| <____  ____> |    |     | <____  \   /
# |      |    \ |____| ___|    |      <____ |    \ |____| ____| <____   \_/  
# 
# PROSPERODEV Open Source Project.
#------------------------------------------------------------------------------------
# Copyright 2010-2022, prosperodev - http://github.com/prosperodev
# Licenced under MIT License
# Review README & LICENSE files for further details.
*/

#include <stdint.h>
#include <sys/types.h>
#include <stdarg.h>
#include <stdio.h>
#include "libSceVideoOut.h"
#include <libkernel.h>
#include <libprospero.h>

int (* _sceVideoOutOpen)(SceUserServiceUserId userId, int type, int index, const void *param);
int (* _sceVideoOutClose)(int handle);
int (* _sceVideoOutRegisterBuffers)(int handle, int initialIndex, void * const *addr, int numBuf, const SceVideoOutBufferAttribute *attr);
int (* _sceVideoOutUnregisterBuffers)(int handle, int indexAttr);
int (* _sceVideoOutSubmitFlip)(int handle, int indexBuf, unsigned int flipMode, int64_t flipArg);
void (* _sceVideoOutSetBufferAttribute)(SceVideoOutBufferAttribute *attr, unsigned int format, unsigned int tmode,unsigned int aspect, unsigned int width, unsigned int height, unsigned int pixelPitch);
int (* _sceVideoOutSetFlipRate)(int handle, int flipRate);
int (* _sceVideoOutAddFlipEvent)(SceKernelEqueue eq, int handle, void *data);
int (* _sceVideoOutGetFlipStatus)(int handle, SceVideoOutFlipStatus *status);


int libSceVideoOut_init()
{
	int handle=sceKernelLoadStartModule("libSceVideoOut.sprx",0,0,0,0,0);
	#define LIBSCEVIDEOOUT_RESOLVE(name) prosperoDlsym(handle, #name, (void **)&_##name)
	
	LIBSCEVIDEOOUT_RESOLVE(sceVideoOutOpen);
	LIBSCEVIDEOOUT_RESOLVE(sceVideoOutClose);
	LIBSCEVIDEOOUT_RESOLVE(sceVideoOutRegisterBuffers);
	LIBSCEVIDEOOUT_RESOLVE(sceVideoOutUnregisterBuffers);
	LIBSCEVIDEOOUT_RESOLVE(sceVideoOutSubmitFlip);
	LIBSCEVIDEOOUT_RESOLVE(sceVideoOutSetBufferAttribute);
	LIBSCEVIDEOOUT_RESOLVE(sceVideoOutSetFlipRate);
	LIBSCEVIDEOOUT_RESOLVE(sceVideoOutAddFlipEvent);
	LIBSCEVIDEOOUT_RESOLVE(sceVideoOutGetFlipStatus);
	
	#undef LIBSCEVIDEOOUT_RESOLVE
	return handle;
}

int sceVideoOutOpen(SceUserServiceUserId userId, int type, int index, const void *param)
{
	return _sceVideoOutOpen(userId,type,index,param);
}

int sceVideoOutClose(int handle)
{
	return _sceVideoOutClose(handle);
}

int sceVideoOutRegisterBuffers(int handle, int initialIndex, void * const *addr, int numBuf, const SceVideoOutBufferAttribute *attr)
{
	return _sceVideoOutRegisterBuffers(handle,initialIndex,addr,numBuf,attr);
}

int sceVideoOutUnregisterBuffers(int handle, int indexAttr)
{
	return _sceVideoOutUnregisterBuffers(handle,indexAttr);
}

int sceVideoOutSubmitFlip(int handle, int indexBuf, unsigned int flipMode, int64_t flipArg)
{
	return _sceVideoOutSubmitFlip(handle,indexBuf,flipMode,flipArg);
}

void sceVideoOutSetBufferAttribute(SceVideoOutBufferAttribute *attr, unsigned int format, unsigned int tmode,unsigned int aspect, unsigned int width, unsigned int height, unsigned int pixelPitch)
{
	return _sceVideoOutSetBufferAttribute(attr,format,tmode,aspect,width,height,pixelPitch);
}

int sceVideoOutSetFlipRate(int handle, int flipRate)
{
	return _sceVideoOutSetFlipRate(handle,flipRate);
}

int sceVideoOutAddFlipEvent(SceKernelEqueue eq, int handle, void *data)
{
	return _sceVideoOutAddFlipEvent(eq,handle,data);
}

int sceVideoOutGetFlipStatus(int handle, SceVideoOutFlipStatus *status)
{
	return _sceVideoOutGetFlipStatus(handle,status);
}




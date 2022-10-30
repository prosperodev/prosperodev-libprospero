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
#include "libSceAudioOut.h"
#include <libkernel.h>
#include <libSceSysmodule.h>
#include <libprospero.h>

int (* _sceAudioOutInit)();
int (* _sceAudioOutOpen)(SceUserServiceUserId userId,unsigned int channel,int unknown ,unsigned int samples, unsigned int frequency, unsigned int format);
int (* _sceAudioOutClose)(int handle);
int (* _sceAudioOutOutput)(int handle, void *buf);
int (* _sceAudioOutSetVolume)(int handle, int filter, int *value);

int libSceAudioOut_init()
{
	sceSysmoduleLoadModuleInternal(SCE_SYSMODULE_INTERNAL_AUDIO_OUT);
	int handle=sceKernelLoadStartModule("libScepPad.sprx",0,0,0,0,0);
	#define LIBSCEAUDIOOUT_RESOLVE(name) prosperoDlsym(handle, #name, (void **)&_##name)
	
	LIBSCEAUDIOOUT_RESOLVE(sceAudioOutInit);
	LIBSCEAUDIOOUT_RESOLVE(sceAudioOutOpen);
	LIBSCEAUDIOOUT_RESOLVE(sceAudioOutClose);
	LIBSCEAUDIOOUT_RESOLVE(sceAudioOutOutput);
	LIBSCEAUDIOOUT_RESOLVE(sceAudioOutSetVolume);
	
	#undef LIBSCEAUDIOOUT_RESOLVE
	return handle;
}

int sceAudioOutInit()
{
	return _sceAudioOutInit();
}

int sceAudioOutOpen(SceUserServiceUserId userId,unsigned int channel,int unknown ,unsigned int samples, unsigned int frequency, unsigned int format)
{
	return _sceAudioOutOpen(userId,channel,unknown,samples,frequency,format);
}

int sceAudioOutClose(int handle)
{
	return _sceAudioOutClose(handle);
}

int sceAudioOutOutput(int handle, void *buf)
{
	return _sceAudioOutOutput(handle,buf);
}

int sceAudioOutSetVolume(int handle, int filter, int *value)
{
	return _sceAudioOutSetVolume(handle,filter,value);
}




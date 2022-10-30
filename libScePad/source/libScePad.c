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
#include "libScePad.h"
#include <libkernel.h>
#include <libSceSysmodule.h>
#include <libprospero.h>

int (* _scePadInit)(void);
int (* _scePadOpen)(SceUserServiceUserId userId,int type,int index,uint8_t *param);
int (* _scePadClose)(int handle);
int (* _scePadRead)(int handle, ScePadData *data, int count);
int (* _scePadReadState)(int handle, ScePadData *data);
int (* _scePadGetHandle)(SceUserServiceUserId userId, int type, int index);

int libScePad_init()
{
	sceSysmoduleLoadModuleInternal(SCE_SYSMODULE_INTERNAL_PAD);
	int handle=sceKernelLoadStartModule("libScePad.sprx",0,0,0,0,0);
	#define LIBSCEPAD_RESOLVE(name) prosperoDlsym(handle, #name, (void **)&_##name)
	
	LIBSCEPAD_RESOLVE(scePadInit);
	LIBSCEPAD_RESOLVE(scePadOpen);
	LIBSCEPAD_RESOLVE(scePadClose);
	LIBSCEPAD_RESOLVE(scePadRead);
	LIBSCEPAD_RESOLVE(scePadReadState);
	LIBSCEPAD_RESOLVE(scePadGetHandle);

	
	#undef LIBSCEPAD_RESOLVE
	return handle;
}

int scePadInit()
{
	return _scePadInit();
}

int scePadOpen(SceUserServiceUserId userId,int type,int index,uint8_t *param)
{
	return _scePadOpen(userId,type,index,param);
}

int scePadClose(int handle)
{
	return _scePadClose(handle);
}

int scePadRead(int handle, ScePadData *data, int count)
{
	return _scePadRead(handle,data,count);
}

int scePadReadState(int handle, ScePadData *data)
{
	return _scePadReadState(handle,data);
}

int scePadGetHandle(SceUserServiceUserId userId, int32_t type, int32_t index)
{
	return _scePadGetHandle(userId,type,index);
}




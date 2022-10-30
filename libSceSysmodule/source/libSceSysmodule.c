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
#include "libSceSysmodule.h"
#include <libkernel.h>
#include <libprospero.h>

int (* _sceSysmoduleIsLoaded)(uint16_t id);
int (* _sceSysmoduleLoadModule)(uint16_t id);
int (* _sceSysmoduleUnloadModule)(uint16_t id);
int (* _sceSysmoduleLoadModuleInternal)(uint32_t id);
int (* _sceSysmoduleUnloadModuleInternal)(uint32_t id);
int (* _sceSysmoduleIsLoadedInternal)(uint32_t id);
int (* _sceSysmoduleGetModuleHandleInternal)(int id,int *h);

int libSceSysmodule_init()
{
	int handle=sceKernelLoadStartModule("libSceSysmodule.sprx",0,0,0,0,0);
	#define LIBSCESYSMODULE_RESOLVE(name) prosperoDlsym(handle, #name, (void **)&_##name)
	
	LIBSCESYSMODULE_RESOLVE(sceSysmoduleIsLoaded);
	LIBSCESYSMODULE_RESOLVE(sceSysmoduleLoadModule);
	LIBSCESYSMODULE_RESOLVE(sceSysmoduleUnloadModule);
	LIBSCESYSMODULE_RESOLVE(sceSysmoduleLoadModuleInternal);
	LIBSCESYSMODULE_RESOLVE(sceSysmoduleUnloadModuleInternal);
	LIBSCESYSMODULE_RESOLVE(sceSysmoduleIsLoadedInternal);
	LIBSCESYSMODULE_RESOLVE(sceSysmoduleGetModuleHandleInternal);

	#undef LIBSCESYSMODULE_RESOLVE
	return handle;
}

int sceSysmoduleIsLoaded(uint16_t id)
{
	return _sceSysmoduleIsLoaded(id);
}

int sceSysmoduleLoadModule(uint16_t id)
{
	return _sceSysmoduleLoadModule(id);
}

int sceSysmoduleUnloadModule(uint16_t id)
{
	return _sceSysmoduleUnloadModule(id);
}

int sceSysmoduleLoadModuleInternal(uint32_t id)
{
	return _sceSysmoduleLoadModuleInternal(id);
}

int sceSysmoduleUnloadModuleInternal(uint32_t id)
{
	return _sceSysmoduleUnloadModuleInternal(id);
}

int sceSysmoduleIsLoadedInternal(uint32_t id)
{
	return _sceSysmoduleIsLoadedInternal(id);
}

int sceSysmoduleGetModuleHandleInternal(int id,int *h)
{
	return _sceSysmoduleGetModuleHandleInternal(id,h);
}



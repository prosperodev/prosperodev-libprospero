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
#include "libSceUserService.h"
#include <libkernel.h>
#include <libSceSysmodule.h>
#include <libprospero.h>

int (* _sceUserServiceInitialize)(int *params);
int (* _sceUserServiceTerminate)();
int (* _sceUserServiceGetInitialUser)(SceUserServiceUserId *userId);

int libSceUserService_init()
{
	sceSysmoduleLoadModuleInternal(SCE_SYSMODULE_INTERNAL_USER_SERVICE);
	int handle=sceKernelLoadStartModule("libSceUserService.sprx",0,0,0,0,0);
	#define LIBSCEUSERSERVICE_RESOLVE(name) prosperoDlsym(handle, #name, (void **)&_##name)
	
	LIBSCEUSERSERVICE_RESOLVE(sceUserServiceInitialize);
	LIBSCEUSERSERVICE_RESOLVE(sceUserServiceTerminate);
	LIBSCEUSERSERVICE_RESOLVE(sceUserServiceGetInitialUser);
	
	#undef LIBSCEUSERSERVICE_RESOLVE
	return handle;
}

int sceUserServiceInitialize(int *params)
{
	return _sceUserServiceInitialize(params);
}

int sceUserServiceTerminate()
{
	return _sceUserServiceTerminate();
}

int sceUserServiceGetInitialUser(SceUserServiceUserId *userId)
{
	return _sceUserServiceGetInitialUser(userId);
}





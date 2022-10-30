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
#include "libSceSystemService.h"
#include <libkernel.h>
#include <libprospero.h>

int (* _sceSystemServiceHideSplashScreen)();

int libSceSystemService_init()
{
	int handle=sceKernelLoadStartModule("libSceSystemService.sprx",0,0,0,0,0);
	#define LIBSCESYSTEMSERVICE_RESOLVE(name) prosperoDlsym(handle, #name, (void **)&_##name)
	
	LIBSCESYSTEMSERVICE_RESOLVE(sceSystemServiceHideSplashScreen);
	
	#undef LIBSCESYSTEMSERVICE_RESOLVE
	return handle;
}

int sceSystemServiceHideSplashScreen()
{
	return _sceSystemServiceHideSplashScreen();
}




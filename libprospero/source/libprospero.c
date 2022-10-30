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

#include <stdio.h>
#include "libprospero.h"
void libprospero_init()
{
	

	libkernel_sys_init();
	libSceLibcInternal_init();
	libSceSysmodule_init();
	libSceSystemService_init();
	libSceUserService_init();
	libSceNet_init();
	libScePad_init();
	libSceVideoOut_init();
	libSceAudioOut_init();


}
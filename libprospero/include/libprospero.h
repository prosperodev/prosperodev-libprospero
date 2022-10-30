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

#ifndef _PROSPERO_LIBPROSPERO_H_
#define _PROSPERO_LIBPROSPERO_H_

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
typedef int dlsym_t(int, const char*, void*);
extern dlsym_t* prosperoDlsym;

struct payload_args
{
    dlsym_t* dlsym;
    int *rwpipe;
    int *rwpair;
    uint64_t kpipe_addr;
    uint64_t kdata_base_addr;
    int *payloadout;
};

void libprospero_init();
int libkernel_sys_init();
int libSceLibcInternal_init();
int libSceNet_init();
int libSceSysmodule_init();
int libSceSystemService_init();
int libSceUserService_init();
int libScePad_init();
int libSceVideoOut_init();
int libSceAudioOut_init();

#ifdef __cplusplus
}
#endif

#endif

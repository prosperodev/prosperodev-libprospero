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

#ifndef _PROSPERO_AUDIOOUT_H_
#define _PROSPERO_AUDIOOUT_H_


#pragma once

#include <stdint.h>
#include <libSceUserService.h>

#ifdef __cplusplus
extern "C" {
#endif


int sceAudioOutInit();
int sceAudioOutOpen(SceUserServiceUserId userId,unsigned int channel,int unknown ,unsigned int samples, unsigned int frequency, unsigned int format);
int sceAudioOutClose(int handle);
int sceAudioOutOutput(int handle, void *buf);
int sceAudioOutSetVolume(int handle, int filter, int *value);

#ifdef __cplusplus
}
#endif

#endif

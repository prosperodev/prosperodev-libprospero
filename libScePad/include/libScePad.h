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

#ifndef _PROSPERO_LIBSCEPAD_H_
#define _PROSPERO_LIBSCEPAD_H_
#pragma once

#include <stdint.h>
#include <libSceUserService.h>

#ifdef __cplusplus
extern "C" {
#endif



typedef struct vec_float3
{
	float x;
	float y;
	float z;
}vec_float3;

typedef struct vec_float4
{
	float x;
	float y;
	float z;
	float w;
}vec_float4;

typedef struct ScePadData {
	unsigned int buttons;	
	uint8_t lx;
	uint8_t ly;
	uint8_t rx;
	uint8_t ry;
	uint8_t l2;
	uint8_t r2;
	uint16_t padding;
	vec_float4 quat;
	vec_float3 acell;
	vec_float3 vel;
	uint8_t touch[24];
	uint8_t connected;
	uint64_t timestamp;
	uint8_t ext[16];
	uint8_t count;
	uint8_t unknown[15];
}ScePadData;
		 
int scePadInit(void);
int scePadOpen(SceUserServiceUserId userId,int type,int index,uint8_t *param);
int scePadGetHandle(SceUserServiceUserId userId,int type,int index);
int scePadClose(int handle);
int scePadRead(int handle, ScePadData *data, int count);
int scePadReadState(int handle, ScePadData *data);

#ifdef __cplusplus
}
#endif

#endif

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

#ifndef _PROSPERO_LIBSCELIBCINTERNAL_H_
#define _PROSPERO_LIBSCELIBCINTERNAL_H_

#pragma once

#include <stdint.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef void* ProsperoMspace;
typedef struct ProsperoMallocManagedSize 
{
	unsigned short sz;
	unsigned short ver;
	unsigned int reserv;
	size_t maxSysSz;
	size_t curSysSz;
	size_t maxUseSz;
	size_t curUseSz;
}ProsperoMallocManagedSize;
	
ProsperoMspace sceLibcMspaceCreate(char *, void *, size_t, unsigned int);
int sceLibcMspaceDestroy(ProsperoMspace);
void * sceLibcMspaceMalloc(ProsperoMspace, size_t size);
int sceLibcMspaceFree(ProsperoMspace, void *);
void * sceLibcMspaceCalloc(ProsperoMspace, size_t, size_t);
void * sceLibcMspaceMemalign(ProsperoMspace, size_t, size_t);
void * sceLibcMspaceRealloc(ProsperoMspace, void *, size_t);
void * sceLibcMspaceReallocalign(ProsperoMspace, void *, size_t, size_t);
int sceLibcMspacePosixMemalign(ProsperoMspace, void **, size_t, size_t);
int sceLibcMspaceMallocStats(ProsperoMspace, ProsperoMallocManagedSize *);
int sceLibcMspaceMallocStatsFast(ProsperoMspace, ProsperoMallocManagedSize *);
size_t sceLibcMspaceMallocUsableSize(void *);
int sceLibcMspaceMspaceisHeapEmpty(ProsperoMspace);

#ifdef __cplusplus
}
#endif

#endif

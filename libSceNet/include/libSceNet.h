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


#ifndef _PROSPERO_LIBSCENET_H_
#define _PROSPERO_LIBSCENET_H_

#ifdef __cplusplus
extern "C" {
#endif


#pragma once

#include <stdint.h>
#include <netinet/in.h>

/* useless C / POSIX wrappers */
char sceNetInetNtop(int af, const void *src, char *dst, int size);
int sceNetAccept(int, struct sockaddr *, unsigned int *);
int sceNetBind(int, struct sockaddr *, int);
int sceNetConnect(int, struct sockaddr *, int);
int sceNetGetsockname(int, struct sockaddr *, unsigned int *);
int sceNetGetsockopt(int s, int level, int optname, void * optval, socklen_t * optlen);
int sceNetInetPton(int af, const char *src, void *dst);
int sceNetListen(int, int);
int sceNetRecv(int, void *, size_t, int);
int sceNetSend(int, const void *, size_t, int);
int sceNetSetsockopt(int s, int level, int optname, const void *optval, socklen_t optlen);
int sceNetSocket(const char *, int, int, int);
int sceNetSocketAbort(int , int );
int sceNetSocketClose(int);
uint16_t sceNetHtons(uint16_t host16);
uint16_t sceNetNtohs(uint16_t net16);
uint32_t sceNetHtonl(uint32_t host32);
uint32_t sceNetNtohl(uint32_t net32);
uint64_t sceNetHtonll(uint64_t host64);
uint64_t sceNetNtohll(uint64_t net64);

#ifdef __cplusplus
}
#endif

#endif

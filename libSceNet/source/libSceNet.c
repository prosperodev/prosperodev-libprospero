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
#include "libSceNet.h"
#include <libkernel.h>
#include <libprospero.h>

int (* _sceNetSocket)(const char *, int, int, int);
int (* _sceNetSocketClose)(int);
int (* _sceNetSocketAbort)(int , int );
int (* _sceNetGetsockopt)(int s, int level, int optname, void * optval, socklen_t * optlen);
int (* _sceNetSetsockopt)(int s, int level, int optname, const void *optval, socklen_t optlen);
int (* _sceNetGetsockname)(int, struct sockaddr *, unsigned int *);
int (* _sceNetConnect)(int, struct sockaddr *, int);
int (* _sceNetBind)(int, struct sockaddr *, int);
int (* _sceNetListen)(int, int);
int (* _sceNetAccept)(int, struct sockaddr *, unsigned int *);
int (* _sceNetSend)(int, const void *, size_t, int);
int (* _sceNetRecv)(int, void *, size_t, int);
int (* _sceNetInetPton)(int af, const char *src, void *dst);
char (* _sceNetInetNtop)(int af, const void *src, char *dst, int size);
uint16_t (* _sceNetHtons)(uint16_t host16);
uint16_t (* _sceNetNtohs)(uint16_t net16);
uint32_t (* _sceNetHtonl)(uint32_t host32);
uint32_t (* _sceNetNtohl)(uint32_t net32);
uint64_t (* _sceNetHtonll)(uint64_t host64);
uint64_t (* _sceNetNtohll)(uint64_t net64);

int libSceNet_init()
{
	int handle=sceKernelLoadStartModule("libSceNet.sprx",0,0,0,0,0);
	#define LIBSCENET_RESOLVE(name) prosperoDlsym(handle, #name, (void **)&_##name)
	
	LIBSCENET_RESOLVE(sceNetSocket);
	LIBSCENET_RESOLVE(sceNetSocketClose);
	LIBSCENET_RESOLVE(sceNetSocketAbort);
	LIBSCENET_RESOLVE(sceNetGetsockopt);
	LIBSCENET_RESOLVE(sceNetSetsockopt);
	LIBSCENET_RESOLVE(sceNetGetsockname);
	LIBSCENET_RESOLVE(sceNetConnect);
	LIBSCENET_RESOLVE(sceNetBind);
	LIBSCENET_RESOLVE(sceNetListen);
	LIBSCENET_RESOLVE(sceNetAccept);
	LIBSCENET_RESOLVE(sceNetSend);
	LIBSCENET_RESOLVE(sceNetRecv);
	LIBSCENET_RESOLVE(sceNetInetPton);
	LIBSCENET_RESOLVE(sceNetInetNtop);
	LIBSCENET_RESOLVE(sceNetHtons);
	LIBSCENET_RESOLVE(sceNetNtohs);
	LIBSCENET_RESOLVE(sceNetHtonl);
	LIBSCENET_RESOLVE(sceNetNtohl);
	LIBSCENET_RESOLVE(sceNetHtonll);
	LIBSCENET_RESOLVE(sceNetNtohll);

	#undef LIBSCENET_RESOLVE
	return handle;
}

int sceNetSocket(const char *a, int b, int c, int d)
{
	return _sceNetSocket(a,b,c,d);
}

int sceNetSocketClose(int a)
{
	return _sceNetSocketClose(a);
}

int sceNetSocketAbort(int a , int b)
{
	return _sceNetSocketAbort(a,b);
}

int sceNetGetsockopt(int s, int level, int optname, void * optval, socklen_t * optlen)
{
	return _sceNetGetsockopt(s,level,optname,optval,optlen);
}

int sceNetSetsockopt(int s, int level, int optname, const void *optval, socklen_t optlen)
{
	return _sceNetSetsockopt(s,level,optname,optval,optlen);
}

int sceNetGetsockname(int a, struct sockaddr * b, unsigned int * c)
{
	return _sceNetGetsockname(a,b,c);
}

int sceNetConnect(int a, struct sockaddr * b, int c)
{
	return _sceNetConnect(a,b,c);
}

int sceNetBind(int a, struct sockaddr * b, int c)
{
	return _sceNetBind(a,b,c);
}

int sceNetListen(int a, int b)
{
	return _sceNetListen(a,b);
}

int sceNetAccept(int a, struct sockaddr * b, unsigned int * c)
{
	return _sceNetAccept(a,b,c);
}

int sceNetSend(int a, const void *b, size_t c, int d)
{
	return _sceNetSend(a,b,c,d);
}

int sceNetRecv(int a, void * b, size_t c, int d)
{
	return _sceNetRecv(a,b,c,d);
}

int sceNetInetPton(int af, const char *src, void *dst)
{
	return _sceNetInetPton(af,src,dst);
}

char sceNetInetNtop(int af, const void *src, char *dst, int size)
{
	return _sceNetInetNtop(af,src,dst,size);
}

uint16_t sceNetHtons(uint16_t host16)
{
	return _sceNetHtons(host16);
}

uint16_t sceNetNtohs(uint16_t net16)
{
	return _sceNetNtohs(net16);
}

uint32_t sceNetHtonl(uint32_t host32)
{
	return _sceNetHtonl(host32);
}

uint32_t sceNetNtohl(uint32_t net32)
{
	return _sceNetNtohl(net32);
}

uint64_t sceNetHtonll(uint64_t host64)
{
	return _sceNetHtonll(host64);
}

uint64_t sceNetNtohll(uint64_t net64)
{
	return _sceNetNtohll(net64);
}


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

#include "libSceLibcInternal.h"
#include <stdint.h>
#include <sys/types.h>
#include <stdarg.h>
#include <stdio.h>
#include <libkernel.h>
#include <libprospero.h>

FILE *(*_fopen)(const char *restrict path, const char *restrict mode);
int (*_fclose)(FILE *stream);
size_t (*_fread)(void *restrict ptr, size_t size, size_t nmemb,FILE *restrict stream);
size_t (* _fwrite)(const void * restrict ptr, size_t size, size_t nmemb,FILE *restrict stream);
int (*_fseek)(FILE *stream, long offset, int whence);
long (*_ftell)(FILE *stream);

void (*_free)(void *ptr);
void *(*_malloc)(size_t size);
void *(*_calloc)(size_t number, size_t size);
void *(*_realloc)(void *ptr, size_t size);
void *(*_memcpy)(void *dst, const void *src, size_t len);
void *(*_memset)(void *s, int c, size_t n);
int (* _memcmp)(const void *b1, const void *b2, size_t len);
int (* _atoi)(const char *nptr);

int (* _vsnprintf)(char *restrict str, size_t size, const char *restrict format,va_list ap);
int (* _vsprintf)(char * restrict str, const char * restrict format, va_list ap);
int (* _vsscanf)(const char * restrict str,const char * restrict format,va_list ap);

char *(*_strcat)(char *restrict s, const char *restrict append);
char *(*_strchr)(const char *s, int c);
char *(*_strrchr)(const char *s, int c);
int (*_strcmp)(const char *s1, const char *s2);
char *(*_strcpy)(char *restrict dst, const char *restrict src);
size_t (*_strlen)(const char *s);
int (*_strncmp)(const char *s1, const char *s2, size_t len);
int (* _strcasecmp)(const char *s1, const char *s2);
char *(* _strdup)(const char *str);
char *(* _strncpy)(char * __restrict, const char * __restrict, size_t);
char *(* _strerror)(int errnum);
char *(* _strstr)(const char *big, const char *little);
void (* __DefaultRuneLocale)();
time_t (* _time)(time_t *tloc);
struct tm *(* _localtime)(const time_t *clock);



ProsperoMspace (* _sceLibcMspaceCreate)(char *, void *, size_t, unsigned int);
int (* _sceLibcMspaceDestroy)(ProsperoMspace);
void * (* _sceLibcMspaceMalloc)(ProsperoMspace, size_t size);
int (* _sceLibcMspaceFree)(ProsperoMspace, void *);
void * (* _sceLibcMspaceCalloc)(ProsperoMspace, size_t, size_t);
void * (* _sceLibcMspaceMemalign)(ProsperoMspace, size_t, size_t);
void * (* _sceLibcMspaceRealloc)(ProsperoMspace, void *, size_t);
void * (* _sceLibcMspaceReallocalign)(ProsperoMspace, void *, size_t, size_t);
int (* _sceLibcMspacePosixMemalign)(ProsperoMspace, void **, size_t, size_t);
int (* _sceLibcMspaceMallocStats)(ProsperoMspace, ProsperoMallocManagedSize *);
int (* _sceLibcMspaceMallocStatsFast)(ProsperoMspace, ProsperoMallocManagedSize *);
size_t (* _sceLibcMspaceMallocUsableSize)(void *);
int (* _sceLibcMspaceMspaceisHeapEmpty)(ProsperoMspace);

int libSceLibcInternal_init()
{
	int handle=sceKernelLoadStartModule("libSceLibcInternal.sprx",0,0,0,0,0);
	#define LIBSCELIBCINTERNAL_RESOLVE(name) prosperoDlsym(handle, #name, (void **)&_##name)
	
	LIBSCELIBCINTERNAL_RESOLVE(fopen);
	LIBSCELIBCINTERNAL_RESOLVE(fclose);
	LIBSCELIBCINTERNAL_RESOLVE(fread);
	LIBSCELIBCINTERNAL_RESOLVE(fwrite);
	LIBSCELIBCINTERNAL_RESOLVE(fseek);
	LIBSCELIBCINTERNAL_RESOLVE(ftell);

	LIBSCELIBCINTERNAL_RESOLVE(free);
	LIBSCELIBCINTERNAL_RESOLVE(malloc);
	LIBSCELIBCINTERNAL_RESOLVE(calloc);
	LIBSCELIBCINTERNAL_RESOLVE(realloc);
	LIBSCELIBCINTERNAL_RESOLVE(memcpy);
	LIBSCELIBCINTERNAL_RESOLVE(memset);

	LIBSCELIBCINTERNAL_RESOLVE(atoi);
	LIBSCELIBCINTERNAL_RESOLVE(vsnprintf);
	LIBSCELIBCINTERNAL_RESOLVE(vsprintf);
	LIBSCELIBCINTERNAL_RESOLVE(vsscanf);

	LIBSCELIBCINTERNAL_RESOLVE(strcat);
	LIBSCELIBCINTERNAL_RESOLVE(strchr);
	LIBSCELIBCINTERNAL_RESOLVE(strrchr);
	LIBSCELIBCINTERNAL_RESOLVE(strcmp);
	LIBSCELIBCINTERNAL_RESOLVE(strcpy);
	LIBSCELIBCINTERNAL_RESOLVE(strlen);
	LIBSCELIBCINTERNAL_RESOLVE(strncmp);
	LIBSCELIBCINTERNAL_RESOLVE(strcasecmp);
	LIBSCELIBCINTERNAL_RESOLVE(strdup);
	LIBSCELIBCINTERNAL_RESOLVE(strncpy);
	LIBSCELIBCINTERNAL_RESOLVE(strerror);
	LIBSCELIBCINTERNAL_RESOLVE(strstr);


	LIBSCELIBCINTERNAL_RESOLVE(_DefaultRuneLocale);
	LIBSCELIBCINTERNAL_RESOLVE(time);
	LIBSCELIBCINTERNAL_RESOLVE(localtime);



	

	
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspaceCreate);
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspaceDestroy);
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspaceMalloc);
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspaceFree);
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspaceCalloc);
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspaceMemalign);
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspaceRealloc);
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspaceReallocalign);
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspacePosixMemalign);
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspaceMallocStats);
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspaceMallocStatsFast);
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspaceMallocUsableSize);
	LIBSCELIBCINTERNAL_RESOLVE(sceLibcMspaceMspaceisHeapEmpty);
	#undef LIBSCELIBCINTERNAL_RESOLVE
	return handle;
}

FILE *fopen(const char *restrict path, const char *restrict mode)
{
	return _fopen(path, mode);
}

int fclose(FILE *stream)
{
	return _fclose(stream);
}

size_t fread(void *restrict ptr, size_t size, size_t nmemb,FILE *restrict stream)
{
	return _fread(ptr, size, nmemb, stream);
}

size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb,FILE *restrict stream)
{
	return _fwrite(ptr,size,nmemb,stream);
}

int fseek(FILE *stream, long offset, int whence)
{
	return _fseek(stream, offset, whence);
}

long ftell(FILE *stream)
{
	return _ftell(stream);
}

void free(void *ptr)
{
	_free(ptr);
}

void *malloc(size_t size)
{
	return _malloc(size);
}

void *calloc(size_t number, size_t size)
{
	return _calloc(number, size);
}

void *realloc(void *ptr, size_t size)
{
	return _realloc(ptr, size);
}

void *memcpy(void *dst, const void *src, size_t len)
{
	return _memcpy(dst, src, len);
}

void *memset(void *s, int c, size_t n)
{
	return _memset(s, c, n);
}

int memcmp(const void *b1, const void *b2, size_t len)
{
	return _memcmp(b1,b2,len);
}

int atoi(const char *nptr)
{
	return _atoi(nptr);
}

int vsnprintf(char *restrict str, size_t size, const char *restrict format,va_list ap)
{
	return _vsnprintf(str, size, format, ap);
}

int snprintf(char *restrict str, size_t size, const char *restrict format,...)
{
	int r;
	va_list args;
	va_start(args, format);
	r = vsnprintf(str, size, format, args);
	va_end(args);
	return r;
}

int vsprintf(char * restrict str, const char * restrict format, va_list ap)
{
	return _vsprintf(str,format,ap);
}

int sprintf(char * restrict str, const char * restrict format, ...)
{
	int r;
	va_list ap;
	va_start(ap, format);
	r = vsprintf(str, format, ap);
	va_end(ap);
	return r;
}

int vsscanf(const char * restrict str,const char * restrict format,va_list ap)
{
	return _vsscanf(str,format,ap);
}

int sscanf(const char * restrict str, const char * restrict format, ...)
{
	int r;
	va_list ap;
	va_start(ap, format);
	r = vsscanf(str, format, ap);
	va_end(ap);
	return r;
}

char *strcat(char *restrict s, const char *restrict append)
{
	return _strcat(s, append);
}

int strcmp(const char *s1, const char *s2)
{
	return _strcmp(s1, s2);
}

char *strchr(const char *s, int c)
{
	return _strchr(s, c);
}

char *strrchr(const char *s, int c)
{
	return _strrchr(s, c);
}

char *strcpy(char *restrict dst, const char *restrict src)
{
	return _strcpy(dst, src);
}

size_t strlen(const char *s)
{
	return _strlen(s);
}

int strncmp(const char *s1, const char *s2, size_t len)
{
	return _strncmp(s1, s2, len);
}

int strcasecmp(const char *s1, const char *s2)
{
	return _strcasecmp(s1,s2);
}

char *strdup(const char *str)
{
	return _strdup(str);
}

char *strncpy(char * restrict dst, const char * restrict src, size_t len)
{
	return _strncpy(dst,src,len);
}

char * strerror(int errnum)
{
	return _strerror(errnum);
}

char *strstr(const char *big, const char *little)
{
	return _strstr(big,little);
}

void _DefaultRuneLocale()
{
	return __DefaultRuneLocale();
}

time_t time(time_t *tloc)
{
	return _time(tloc);
}

struct tm *localtime(const time_t *clock)
{
	return _localtime(clock);
}

ProsperoMspace sceLibcMspaceCreate(char * a, void * b, size_t c, unsigned int d)
{
	return _sceLibcMspaceCreate(a,b,c,d);
}

int sceLibcMspaceDestroy(ProsperoMspace a)
{
	return _sceLibcMspaceDestroy(a);
}

void * sceLibcMspaceMalloc(ProsperoMspace a, size_t size)
{
	return _sceLibcMspaceMalloc(a,size);
}

int sceLibcMspaceFree(ProsperoMspace a, void * b)
{
	return _sceLibcMspaceFree(a,b);
}

void * sceLibcMspaceCalloc(ProsperoMspace a, size_t b, size_t c)
{
	return _sceLibcMspaceCalloc(a,b,c);
}

void * sceLibcMspaceMemalign(ProsperoMspace a, size_t b, size_t c)
{
	return _sceLibcMspaceMemalign(a,b,c);
}

void * sceLibcMspaceRealloc(ProsperoMspace a, void * b, size_t c)
{
	return _sceLibcMspaceRealloc(a,b,c);
}

void * sceLibcMspaceReallocalign(ProsperoMspace a, void * b, size_t c, size_t d)
{
	return _sceLibcMspaceReallocalign(a,b,c,d);
}

int sceLibcMspacePosixMemalign(ProsperoMspace a, void ** b, size_t c, size_t d)
{
	return _sceLibcMspacePosixMemalign(a,b,c,d);
}

int sceLibcMspaceMallocStats(ProsperoMspace a, ProsperoMallocManagedSize * b)
{
	return _sceLibcMspaceMallocStats(a,b);
}

int sceLibcMspaceMallocStatsFast(ProsperoMspace a, ProsperoMallocManagedSize * b)
{
	return _sceLibcMspaceMallocStatsFast(a,b);
}

size_t sceLibcMspaceMallocUsableSize(void * a)
{
	return _sceLibcMspaceMallocUsableSize(a);
}

int sceLibcMspaceMspaceisHeapEmpty(ProsperoMspace a)
{
	return _sceLibcMspaceMspaceisHeapEmpty(a);
}

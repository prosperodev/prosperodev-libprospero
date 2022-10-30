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

#include "libkernel.h"
#include <errno.h>
#include <netinet/in.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
//#include <fcntl.h>
#include <sys/socket.h>
#include <poll.h>
#include <libprospero.h>

#define LIBKERNEL_MODULE_HANDLE 0x2001

int *(*___error)(void);

int (* _open)(const	char *path, int	flags, ...);
int (* _close)(int fd);
ssize_t (* f_read)(int fd, void *buf, size_t nbytes);
ssize_t (* f__read)(int fd, void *buf, size_t nbytes);
ssize_t (* _write)(int fd, const void *buf, size_t nbytes);
off_t (* _lseek)(int fildes, off_t offset, int whence);
int (* _rmdir)(const char *path);
int (* _mkdir)(const char *path, mode_t mode);
int (* _rename)(const char *from, const char *to);
int (* _unlink)(const char *path);
int (* _stat)(const	char * restrict	path, struct stat * restrict sb);
int (* _fstat)(int fd, struct stat *sb);
int (* _getdents)(int fd, char *buf, int nbytes);
int (* _fcntl)(int fd, int cmd, int arg);
int (* _ioctl)(int fd, unsigned long request, char *argp);
pid_t (* _fork)(void);
void (* f_exit)(int status);
pid_t (* _getpid)();
uid_t (* _getuid)(void);
gid_t (* _getgid)(void);

int (*_socket)(int domain, int type, int protocol);
int (*_connect)(int s, const struct sockaddr *name, socklen_t namelen);
int (*_bind)(int s, const struct sockaddr *addr, socklen_t addrlen);
int (*_listen)(int s, int backlog);
int (*_accept)(int s, struct sockaddr *restrict addr,socklen_t *restrict addrlen);
int (*_inet_pton)(int af, const char *restrict src, void *restrict dst);
int (* _getsockopt)(int  s, int level, int optname, void *optval, socklen_t *optlen);
int (* _setsockopt)(int s, int  level,  int  optname,	 const	void  *optval, socklen_t optlen);
ssize_t (* _send)(int s, const void *msg, size_t len, int flags);
ssize_t (* _sendto)(int	s, const void *msg, size_t len,	int flags, const struct sockaddr *to, socklen_t tolen);
ssize_t (* _recv)(int s, void *buf, size_t len, int flags);
ssize_t (* _recvfrom)(int s, void *buf, size_t len, int	flags, struct	sockaddr * restrict from, socklen_t * restrict fromlen);
int (* _poll)(struct pollfd fds[], nfds_t nfds, int timeout);
int (* _dup2)(int oldd, int newd);
int (* _gettimeofday)(struct timeval *tp, struct timezone *tzp);

void *(*_mmap)(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
int (* _munmap)(void *addr,	size_t len);

int (* _sceKernelStat)(const char *path, void * buf);
int (* _sceKernelOpen)(const char *path, int flags, int mode);
int (* _sceKernelRead)(int fd, void *buf, size_t nbyte);
int (* _sceKernelWrite)(int fd, void *buf, size_t nbyte);
int (* _sceKernelLseek)(int fd, off_t offset, int whence);
int (* _sceKernelClose)(int fd);
int (* _sceKernelMkdir)(const char *path, mode_t mode);
int (* _sceKernelChmod)(const char *path, mode_t mode);
int (* _sceKernelGetCurrentCpu)(void);
int (* _sceKernelGettimeofday)(SceKernelTimeval *tp);
uint64_t (* _sceKernelGetProcessTime)();
int (* _sceKernelUsleep)(unsigned int microseconds);
int (* _scePthreadCancel)(ScePthread thread);
int (* _scePthreadCreate)(ScePthread *thread, const ScePthreadAttr *attr, void *(*entry)(void *), void *arg, const char *name);
int (* _scePthreadDetach)(ScePthread thread);
int (* _scePthreadJoin)(ScePthread thread, void **value_ptr);
int (* _scePthreadMutexDestroy)(ScePthreadMutex *mutex);
int (* _scePthreadMutexInit)(ScePthreadMutex *mutex, const ScePthreadMutexattr *attr, const char *name);
int (* _scePthreadMutexLock)(ScePthreadMutex *mutex);
int (* _scePthreadMutexTimedlock)(ScePthreadMutex *mutex, SceKernelUseconds usec);
int (* _scePthreadMutexTrylock)(ScePthreadMutex *mutex);
int (* _scePthreadMutexUnlock)(ScePthreadMutex *mutex);
ScePthread (* _scePthreadSelf)(void);
uint64_t (* _sceKernelGetProcessTime)(void);
unsigned int (* _sceKernelSleep)(unsigned int seconds);
void (* _scePthreadExit)(void *value);
void (* _scePthreadYield)(void);
int (* _scePthreadGetprio)(ScePthread thread, int *p);
int (* _scePthreadSetprio)(ScePthread thread, int p);
int (* _scePthreadGetname)(ScePthread thread, char * name);
int (* _sceKernelCreateSema)(SceKernelSema *s, const char *name, uint32_t attr, int count, int maxCount, void *);
int (* _sceKernelDeleteSema)(SceKernelSema s);
int (* _sceKernelPollSema)(SceKernelSema s, int count);
int (* _sceKernelWaitSema)(SceKernelSema s, int count, SceKernelUseconds *t);
int (* _sceKernelSignalSema)(SceKernelSema s, int signal);
int (* _sceKernelCreateEqueue)(SceKernelEqueue *eq, const char *name);
int (* _sceKernelDeleteEqueue)(SceKernelEqueue eq);
int (* _sceKernelAddUserEvent)(SceKernelEqueue eq, int id);
int (* _sceKernelAddReadEvent)(SceKernelEqueue eq, int fd, size_t size, void *data);
int (* _sceKernelWaitEqueue)(SceKernelEqueue eq, SceKernelEvent *ev, int num, int *out, SceKernelUseconds *timo);   
size_t (* _sceKernelGetDirectMemorySize)();
int (* _sceKernelAllocateDirectMemory)(off_t, off_t, size_t, size_t, int, off_t *);
int (* _sceKernelMapMainDirectMemory)(size_t, size_t, int, off_t *);
int (* _sceKernelMapDirectMemory)(void **, size_t, int, int, off_t, size_t);
int (* _sceKernelMapNamedSystemFlexibleMemory)(void** , size_t, int, int, const char*);
int (* _sceKernelMprotect)(const void *, size_t, int);
int (* _sceKernelReserveVirtualRange)(void **, size_t, int, size_t);
int (* _sceKernelReleaseFlexibleMemory)(void *, size_t);
int (* _sceKernelMunmap)(void *, size_t);
int (* _sceKernelLoadStartModule)(const char *name, size_t argc, const void *argv, uint32_t flags, void *, int *result);
int (* _sceKernelDlsym)(SceKernelModule handle, const char *symbol, void **address);
int (* _sceKernelGetModuleList)(SceKernelModule *array, size_t size, size_t *available);
int (* _sceKernelGetModuleInfo)(SceKernelModule handle, SceKernelModuleInfo *info);
int (* _sceKernelGetModuleInfoByName)(const char* name, SceKernelModuleInfo* info);
int (* _sceKernelStopUnloadModule)(SceKernelModule handle, size_t argc, const void *argv, uint32_t flags, void *, int *result);
int (* _sceKernelSync)();
const char *(* _sceKernelGetFsSandboxRandomWord)();
int (* _sceKernelJitCreateSharedMemory)(int flags, size_t size, int protection, int *destinationHandle);
int (* _sceKernelJitCreateAliasOfSharedMemory)(int handle, int protection, int *destinationHandle);
int (* _sceKernelJitMapSharedMemory)(int handle, int protection, void **destination);
int (* _sceKernelVirtualQuery)(void *addr, int flags, void *inf,size_t infSize);
int (* _sceKernelQueryMemoryProtection)(void *addr,void **begin,void **end,int *prot);

int (* _sceKernelIccSetBuzzer)(int mode);

int (* _sysctl)(const int *name, u_int namelen, void *oldp,	size_t *oldlenp,const void *newp, size_t newlen);

int libkernel_sys_init()
{
	#define LIBKERNEL_RESOLVE(name) prosperoDlsym(LIBKERNEL_MODULE_HANDLE, #name, (void **)&_##name)
	LIBKERNEL_RESOLVE(__error);
 	
	LIBKERNEL_RESOLVE(open);
	LIBKERNEL_RESOLVE(close);
	//LIBKERNEL_RESOLVE(read);
	prosperoDlsym(LIBKERNEL_MODULE_HANDLE, "read", (void **)&f_read);
	prosperoDlsym(LIBKERNEL_MODULE_HANDLE, "_read", (void **)&f__read);
	LIBKERNEL_RESOLVE(write);
	LIBKERNEL_RESOLVE(lseek);
	LIBKERNEL_RESOLVE(rmdir);
	LIBKERNEL_RESOLVE(mkdir);
	LIBKERNEL_RESOLVE(rename);
	LIBKERNEL_RESOLVE(unlink);

	LIBKERNEL_RESOLVE(fcntl);
	LIBKERNEL_RESOLVE(ioctl);
	LIBKERNEL_RESOLVE(stat);
	LIBKERNEL_RESOLVE(fstat);
	LIBKERNEL_RESOLVE(getdents);
	
	LIBKERNEL_RESOLVE(getpid);
	LIBKERNEL_RESOLVE(getuid);
	LIBKERNEL_RESOLVE(getgid);

	LIBKERNEL_RESOLVE(socket);
	LIBKERNEL_RESOLVE(connect);
	LIBKERNEL_RESOLVE(bind);
	LIBKERNEL_RESOLVE(listen);
	LIBKERNEL_RESOLVE(accept);
	LIBKERNEL_RESOLVE(getsockopt);
	LIBKERNEL_RESOLVE(setsockopt);
	LIBKERNEL_RESOLVE(send);
	LIBKERNEL_RESOLVE(sendto);
	LIBKERNEL_RESOLVE(recv);
	LIBKERNEL_RESOLVE(recvfrom);
	LIBKERNEL_RESOLVE(poll);
	LIBKERNEL_RESOLVE(dup2);
	LIBKERNEL_RESOLVE(gettimeofday);

	LIBKERNEL_RESOLVE(mmap);
	LIBKERNEL_RESOLVE(munmap);

	LIBKERNEL_RESOLVE(sceKernelStat);
	LIBKERNEL_RESOLVE(sceKernelOpen);
	LIBKERNEL_RESOLVE(sceKernelRead);
	LIBKERNEL_RESOLVE(sceKernelWrite);
	LIBKERNEL_RESOLVE(sceKernelLseek);
	LIBKERNEL_RESOLVE(sceKernelClose);
	LIBKERNEL_RESOLVE(sceKernelMkdir);
	LIBKERNEL_RESOLVE(sceKernelChmod);
	LIBKERNEL_RESOLVE(sceKernelGetCurrentCpu);
	LIBKERNEL_RESOLVE(sceKernelGettimeofday);
	LIBKERNEL_RESOLVE(sceKernelGetProcessTime);
	LIBKERNEL_RESOLVE(sceKernelUsleep);
	LIBKERNEL_RESOLVE(scePthreadCancel);
	LIBKERNEL_RESOLVE(scePthreadCreate);
	LIBKERNEL_RESOLVE(scePthreadDetach);
	LIBKERNEL_RESOLVE(scePthreadJoin);
	LIBKERNEL_RESOLVE(scePthreadMutexDestroy);
	LIBKERNEL_RESOLVE(scePthreadMutexInit);
	LIBKERNEL_RESOLVE(scePthreadMutexLock);
	LIBKERNEL_RESOLVE(scePthreadMutexTimedlock);
	LIBKERNEL_RESOLVE(scePthreadMutexTrylock);
	LIBKERNEL_RESOLVE(scePthreadMutexUnlock);
	LIBKERNEL_RESOLVE(scePthreadSelf);
	LIBKERNEL_RESOLVE(sceKernelSleep);
	LIBKERNEL_RESOLVE(scePthreadExit);
	LIBKERNEL_RESOLVE(scePthreadYield);
	LIBKERNEL_RESOLVE(scePthreadGetprio);
	LIBKERNEL_RESOLVE(scePthreadSetprio);
	LIBKERNEL_RESOLVE(scePthreadGetname);
	LIBKERNEL_RESOLVE(sceKernelCreateSema);
	LIBKERNEL_RESOLVE(sceKernelDeleteSema);
	LIBKERNEL_RESOLVE(sceKernelPollSema);
	LIBKERNEL_RESOLVE(sceKernelWaitSema);
	LIBKERNEL_RESOLVE(sceKernelSignalSema);
	LIBKERNEL_RESOLVE(sceKernelCreateEqueue);
	LIBKERNEL_RESOLVE(sceKernelDeleteEqueue);
	LIBKERNEL_RESOLVE(sceKernelAddUserEvent);
	LIBKERNEL_RESOLVE(sceKernelAddReadEvent);
	LIBKERNEL_RESOLVE(sceKernelWaitEqueue);
	LIBKERNEL_RESOLVE(sceKernelGetDirectMemorySize);
	LIBKERNEL_RESOLVE(sceKernelAllocateDirectMemory);
	LIBKERNEL_RESOLVE(sceKernelMapMainDirectMemory);
	LIBKERNEL_RESOLVE(sceKernelMapDirectMemory);
	LIBKERNEL_RESOLVE(sceKernelMapNamedSystemFlexibleMemory);
	LIBKERNEL_RESOLVE(sceKernelMprotect);
	LIBKERNEL_RESOLVE(sceKernelReserveVirtualRange);
	LIBKERNEL_RESOLVE(sceKernelReleaseFlexibleMemory);
	LIBKERNEL_RESOLVE(sceKernelMunmap);
	LIBKERNEL_RESOLVE(sceKernelLoadStartModule);
	LIBKERNEL_RESOLVE(sceKernelDlsym);
	LIBKERNEL_RESOLVE(sceKernelGetModuleList);
	LIBKERNEL_RESOLVE(sceKernelGetModuleInfo);
	LIBKERNEL_RESOLVE(sceKernelGetModuleInfoByName);
	LIBKERNEL_RESOLVE(sceKernelStopUnloadModule);
	LIBKERNEL_RESOLVE(sceKernelSync);
	LIBKERNEL_RESOLVE(sceKernelGetFsSandboxRandomWord);
	LIBKERNEL_RESOLVE(sceKernelJitCreateSharedMemory);
	LIBKERNEL_RESOLVE(sceKernelJitCreateAliasOfSharedMemory);
	LIBKERNEL_RESOLVE(sceKernelJitMapSharedMemory);
	LIBKERNEL_RESOLVE(sceKernelVirtualQuery);
	LIBKERNEL_RESOLVE(sceKernelQueryMemoryProtection);
	LIBKERNEL_RESOLVE(sceKernelIccSetBuzzer);
	LIBKERNEL_RESOLVE(sysctl);

	f_exit = (void *) (f__read + 0xE30);
  _fork = (void *) (f__read + 0x1DE0);

	#undef LIBKERNEL_RESOLVE
	return LIBKERNEL_MODULE_HANDLE;
}

int *__error(void)
{ 
	return ___error();
}

int open(const	char *path, int	flags, ...)
{
	return _open(path,flags);
}

int close(int fd)
{ 
	return _close(fd);
}

ssize_t read(int fd, void *buf, size_t nbytes)
{
	return f_read(fd, buf, nbytes);
}

ssize_t _read(int fd, void *buf, size_t nbytes)
{
	return f__read(fd, buf, nbytes);
}

pid_t fork(void)
{
	return _fork();
}

void exit(int status)
{
	return f_exit(status);
}

ssize_t write(int fd, const void *buf, size_t nbytes)
{
	return _write(fd, buf, nbytes);
}

off_t lseek(int fildes, off_t offset, int whence)
{
	return _lseek(fildes,offset,whence);
}

int rmdir(const char *path)
{
	return _rmdir(path);
}

int mkdir(const char *path, mode_t mode)
{
	return _mkdir(path,mode);
}

int rename(const char *from, const char *to)
{
	return _rename(from,to);
}

int unlink(const char *path)
{
	return _unlink(path);
}

int stat(const	char * restrict	path, struct stat * restrict sb)
{
	return _stat(path,sb);
}

int fstat(int fd, struct stat *sb)
{
	return _fstat(fd,sb);
}

int getdents(int fd, char *buf, int nbytes)
{
	return _getdents(fd,buf,nbytes);
}

int fcntl(int fd, int cmd, int arg)
{
	return _fcntl(fd,cmd,arg);
}

int ioctl(int fd, unsigned long request, char *argp)
{
	
	return _ioctl(fd,request,argp);
}


pid_t getpid()
{
	return _getpid();
}

uid_t getuid(void)
{
	return _getuid();
}

gid_t getgid(void)
{
	return _getgid();
}

int socket(int domain, int type, int protocol)
{
	return _socket(domain, type, protocol);
}

int connect(int s, const struct sockaddr *name, socklen_t namelen)
{
	return _connect(s, name, namelen);
}

int bind(int s, const struct sockaddr *addr, socklen_t addrlen)
{
  return _bind(s, addr, addrlen);
}

int listen(int s, int backlog)
{
	return _listen(s, backlog);
}

int accept(int s, struct sockaddr *restrict addr, socklen_t *restrict addrlen)
{
  return _accept(s, addr, addrlen);
}

int inet_pton(int af, const char *restrict src, void *restrict dst)
{
	return _inet_pton(af, src, dst);
}

int getsockopt(int  s, int level, int optname, void *optval, socklen_t *optlen)
{
	return _getsockopt(s,level,optname,optval,optlen);

}

int setsockopt(int s, int level, int optname, const	void *optval, socklen_t optlen)
{
	return _setsockopt(s,level,optname,optval,optlen);
}

ssize_t send(int s, const void *msg, size_t len, int flags)
{
	return _send(s,msg,len,flags);
}

ssize_t sendto(int	s, const void *msg, size_t len,	int flags, const struct sockaddr *to, socklen_t tolen)
{
	return _sendto(s,msg,len,flags,to,tolen);
}

ssize_t recv(int s, void *buf, size_t len,	int flags)
{
	return _recv(s,buf,len,flags);
}

ssize_t recvfrom(int s, void *buf, size_t len, int flags, struct sockaddr * restrict from, socklen_t * restrict fromlen)
{
	return _recvfrom(s,buf,len,flags,from,fromlen);
}

int poll(struct pollfd fds[], nfds_t nfds, int timeout)
{
	return _poll(fds,nfds,timeout);
}

int dup2(int oldd, int newd)
{
	return _dup2(oldd,newd);
}

int gettimeofday(struct timeval *tp, struct timezone *tzp)
{
	return gettimeofday(tp,tzp);
}

void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset)
{
	return _mmap(addr, len, prot, flags, fd, offset);
}

int munmap(void *addr,	size_t len)
{
	return _munmap(addr,len);
}

int sceKernelStat(const char *path, void * buf)
{
	return _sceKernelStat(path,buf);
}

int sceKernelOpen(const char *path, int flags, int mode)
{
	return _sceKernelOpen(path,flags,mode);
}

int sceKernelRead(int fd, void *buf, size_t nbyte)
{
	return _sceKernelRead(fd,buf,nbyte);
}

int sceKernelWrite(int fd, void *buf, size_t nbyte)
{
	return _sceKernelWrite(fd,buf,nbyte);
}

int sceKernelLseek(int fd, off_t offset, int whence)
{
	return _sceKernelLseek(fd,offset,whence);
}

int sceKernelClose(int fd)
{
	return _sceKernelClose(fd);
}

int sceKernelMkdir(const char *path, mode_t mode)
{
	return _sceKernelMkdir(path,mode);
}

int sceKernelChmod(const char *path, mode_t mode)
{
	return _sceKernelChmod(path,mode);
}

int sceKernelGetCurrentCpu(void)
{
	return _sceKernelGetCurrentCpu();
}

int sceKernelGettimeofday(SceKernelTimeval *tp)
{
	return _sceKernelGettimeofday(tp);
}

uint64_t sceKernelGetProcessTime()
{
	return _sceKernelGetProcessTime();
}

int sceKernelUsleep(unsigned int microseconds)
{
	return _sceKernelUsleep(microseconds);
}

int scePthreadCancel(ScePthread thread)
{
	return _scePthreadCancel(thread);
}

int scePthreadCreate(ScePthread *thread, const ScePthreadAttr *attr, void *(*entry)(void *), void *arg, const char *name)
{
	return _scePthreadCreate(thread,attr,entry,arg,name);
}

int scePthreadDetach(ScePthread thread)
{
	return _scePthreadDetach(thread);
}

int scePthreadJoin(ScePthread thread, void **value_ptr)
{
	return _scePthreadJoin(thread,value_ptr);
}

int scePthreadMutexDestroy(ScePthreadMutex *mutex)
{
	return _scePthreadMutexDestroy(mutex);
}

int scePthreadMutexInit(ScePthreadMutex *mutex, const ScePthreadMutexattr *attr, const char *name)
{
	return _scePthreadMutexInit(mutex,attr,name);
}

int scePthreadMutexLock(ScePthreadMutex *mutex)
{
	return _scePthreadMutexLock(mutex);
}

int scePthreadMutexTimedlock(ScePthreadMutex *mutex, SceKernelUseconds usec)
{
	return _scePthreadMutexTimedlock(mutex,usec);
}

int scePthreadMutexTrylock(ScePthreadMutex *mutex)
{
	return _scePthreadMutexTrylock(mutex);
}

int scePthreadMutexUnlock(ScePthreadMutex *mutex)
{
	return _scePthreadMutexUnlock(mutex);
}

ScePthread scePthreadSelf(void)
{
	return _scePthreadSelf();
}

unsigned int sceKernelSleep(unsigned int seconds)
{
	return _sceKernelSleep(seconds);
}

void scePthreadExit(void *value)
{
	return _scePthreadExit(value);
}

void scePthreadYield(void)
{
	return _scePthreadYield();
}

int scePthreadGetprio(ScePthread thread, int *p)
{
	return _scePthreadGetprio(thread,p);
}

int scePthreadSetprio(ScePthread thread, int p)
{
	return _scePthreadSetprio(thread,p);
}

int scePthreadGetname(ScePthread thread, char * name)
{
	return _scePthreadGetname(thread,name);
}

int sceKernelCreateSema(SceKernelSema *s, const char *name, uint32_t attr, int count, int maxCount, void *a)
{
	return _sceKernelCreateSema(s,name,attr,count,maxCount,a);
}

int sceKernelDeleteSema(SceKernelSema s)
{
	return _sceKernelDeleteSema(s);
}

int sceKernelPollSema(SceKernelSema s, int count)
{
	return _sceKernelPollSema(s,count);
}

int sceKernelWaitSema(SceKernelSema s, int count, SceKernelUseconds *t)
{
	return _sceKernelWaitSema(s,count,t);
}

int sceKernelSignalSema(SceKernelSema s, int signal)
{
	return _sceKernelSignalSema(s,signal);
}

int sceKernelCreateEqueue(SceKernelEqueue *eq, const char *name)
{
	return _sceKernelCreateEqueue(eq,name);
}

int sceKernelDeleteEqueue(SceKernelEqueue eq)
{
	return _sceKernelDeleteEqueue(eq);
}

int sceKernelAddUserEvent(SceKernelEqueue eq, int id)
{
	return _sceKernelAddUserEvent(eq,id);
}

int sceKernelAddReadEvent(SceKernelEqueue eq, int fd, size_t size, void *data)
{
	return _sceKernelAddReadEvent(eq,fd,size,data);
}

int sceKernelWaitEqueue(SceKernelEqueue eq, SceKernelEvent *ev, int num, int *out, SceKernelUseconds *timo)
{
	return _sceKernelWaitEqueue(eq,ev,num,out,timo);
}

size_t sceKernelGetDirectMemorySize()
{
	return _sceKernelGetDirectMemorySize();
}

int sceKernelAllocateDirectMemory(off_t a, off_t b, size_t c, size_t d, int e, off_t *f)
{
	return _sceKernelAllocateDirectMemory(a,b,c,d,e,f);
}

int sceKernelMapMainDirectMemory(size_t a, size_t b, int c, off_t *d)
{
	return _sceKernelMapMainDirectMemory(a,b,c,d);
}

int sceKernelMapDirectMemory(void ** a, size_t b, int c, int d, off_t e, size_t f)
{
	return _sceKernelMapDirectMemory(a,b,c,d,e,f);
}

int sceKernelMapNamedSystemFlexibleMemory(void** a, size_t b, int c, int d, const char* e)
{
	return _sceKernelMapNamedSystemFlexibleMemory(a,b,c,d,e);
}

int sceKernelMprotect(const void * a, size_t b, int c)
{
	return _sceKernelMprotect(a,b,c);
}

int sceKernelReserveVirtualRange(void ** a, size_t b, int c, size_t d)
{
	return _sceKernelReserveVirtualRange(a,b,c,d);
}

int sceKernelReleaseFlexibleMemory(void * a, size_t b)
{
	return _sceKernelReleaseFlexibleMemory(a,b);
}

int sceKernelMunmap(void * a, size_t b)
{
	return _sceKernelMunmap(a,b);
}

int sceKernelLoadStartModule(const char *name, size_t argc, const void *argv, uint32_t flags, void * a, int *result)
{
	return _sceKernelLoadStartModule(name,argc,argv,flags,a,result);
}

int sceKernelDlsym(SceKernelModule handle, const char *symbol, void **address)
{
	return _sceKernelDlsym(handle,symbol,address);
}

int sceKernelGetModuleList(SceKernelModule *array, size_t size, size_t *available)
{
	return _sceKernelGetModuleList(array,size,available);
}

int sceKernelGetModuleInfo(SceKernelModule handle, SceKernelModuleInfo *info)
{
	return _sceKernelGetModuleInfo(handle,info);
}

int sceKernelGetModuleInfoByName(const char* name, SceKernelModuleInfo* info)
{
	return _sceKernelGetModuleInfoByName(name,info);
}

int sceKernelStopUnloadModule(SceKernelModule handle, size_t argc, const void *argv, uint32_t flags, void * a, int *result)
{
	return _sceKernelStopUnloadModule(handle,argc,argv,flags,a,result);
}

int sceKernelSync()
{
	return _sceKernelSync();
}

const char *sceKernelGetFsSandboxRandomWord()
{
	return _sceKernelGetFsSandboxRandomWord();
}

int sceKernelJitCreateSharedMemory(int flags, size_t size, int protection, int *destinationHandle)
{
	return _sceKernelJitCreateSharedMemory(flags,size,protection,destinationHandle);
}

int sceKernelJitCreateAliasOfSharedMemory(int handle, int protection, int *destinationHandle)
{
	return _sceKernelJitCreateAliasOfSharedMemory(handle,protection,destinationHandle);
}

int sceKernelJitMapSharedMemory(int handle, int protection, void **destination)
{
	return _sceKernelJitMapSharedMemory(handle,protection,destination);
}

int sceKernelIccSetBuzzer(int mode)
{
	return _sceKernelIccSetBuzzer(mode);
}

int sysctl(const int *name, u_int namelen, void *oldp,	size_t *oldlenp,const void *newp, size_t newlen)
{
	return _sysctl(name,namelen,oldp,oldlenp,newp,newlen);
}

int sceKernelVirtualQuery(void *addr, int flags, void *inf,size_t infSize)
{
	return _sceKernelVirtualQuery(addr,flags,inf,infSize);
}

int sceKernelQueryMemoryProtection(void *addr,void **begin,void **end,int *prot)
{
	return _sceKernelQueryMemoryProtection(addr,begin,end,prot);
}
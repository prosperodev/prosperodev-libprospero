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

//#include <stdint.h>
//#include <sys/types.h>
//#include <stdarg.h>
//#include <stdio.h>
#include <libkernel.h>
#include <libprospero.h>
#include "libSceGLSlimClientVSH.h"


bool (* _scePigletSetConfigurationVSH)(const ScePglConfig* config);
bool (* _scePigletGetConfigurationVSH)(const ScePglConfig* config);
GL_APICALL GLuint GL_APIENTRY (* _glCreateShader) (GLenum type);
GL_APICALL void GL_APIENTRY (* _glUniform4f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GL_APICALL void GL_APIENTRY (* _glDisable) (GLenum cap);
GL_APICALL void GL_APIENTRY (* _glGetIntegerv) (GLenum pname, GLint *data);
GL_APICALL void GL_APIENTRY (* _glDeleteTextures) (GLsizei n, const GLuint *textures);
GL_APICALL void GL_APIENTRY (* _glDrawArrays) (GLenum mode, GLint first, GLsizei count);
GL_APICALL void GL_APIENTRY (* _glVertexAttrib1f) (GLuint index, GLfloat x);
GL_APICALL void GL_APIENTRY (* _glVertexAttrib1fv) (GLuint index, const GLfloat *v);
GL_APICALL void GL_APIENTRY (* _glDeleteBuffers) (GLsizei n, const GLuint *buffers);
GL_APICALL void GL_APIENTRY (* _glGetProgramInfoLog) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GL_APICALL void GL_APIENTRY (* _glHint) (GLenum target, GLenum mode);
GL_APICALL void GL_APIENTRY (* _glGetVertexAttribiv) (GLuint index, GLenum pname, GLint *params);
GL_APICALL void GL_APIENTRY (* _glReleaseShaderCompiler) (void);
GL_APICALL void GL_APIENTRY (* _glTexParameterfv) (GLenum target, GLenum pname, const GLfloat *params);
GL_APICALL void GL_APIENTRY (* _glUniform1iv)(GLint location, GLsizei count, const GLint *value);
GL_APICALL void GL_APIENTRY (* _glGenerateMipmap) (GLenum target);
GL_APICALL void GL_APIENTRY (* _glBlendEquation) (GLenum mode);
GL_APICALL void GL_APIENTRY (* _glBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
GL_APICALL GLint GL_APIENTRY (* _glGetUniformLocation) (GLuint program, const GLchar *name);
GL_APICALL void GL_APIENTRY (* _glTexParameteriv)(GLenum target, GLenum pname, const GLint *params);
GL_APICALL void GL_APIENTRY (* _glUniform2i) (GLint location, GLint v0, GLint v1);
GL_APICALL void GL_APIENTRY (* _glUniform4i) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GL_APICALL void GL_APIENTRY (* _glEnable) (GLenum cap);
GL_APICALL void GL_APIENTRY (* _glEnableVertexAttribArray) (GLuint index);
GL_APICALL void GL_APIENTRY (* _glTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GL_APICALL void GL_APIENTRY (* _glUniform3f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GL_APICALL void GL_APIENTRY (* _glBindAttribLocation) (GLuint program, GLuint index, const GLchar *name);
GL_APICALL void GL_APIENTRY (* _glGetFramebufferAttachmentParameteriv) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
GL_APICALL void GL_APIENTRY (* _glCompressedTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GL_APICALL void GL_APIENTRY (* _glDeleteRenderbuffers) (GLsizei n, const GLuint *renderbuffers);
GL_APICALL void GL_APIENTRY (* _glGenBuffers) (GLsizei n, GLuint *buffers);
GL_APICALL void GL_APIENTRY (* _glGetUniformiv) (GLuint program, GLint location, GLint *params);
GL_APICALL void GL_APIENTRY (* _glStencilOp) (GLenum fail, GLenum zfail, GLenum zpass);
GL_APICALL void GL_APIENTRY (* _glStencilOpSeparate) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
GL_APICALL void GL_APIENTRY (* _glViewport) (GLint x, GLint y, GLsizei width, GLsizei height);
GL_APICALL void GL_APIENTRY (* _glSampleCoverage) (GLfloat value, GLboolean invert);
GL_APICALL void GL_APIENTRY (* _glGetBufferParameteriv) (GLenum target, GLenum pname, GLint *params);
GL_APICALL void GL_APIENTRY (* _glGetAttachedShaders) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GL_APICALL void GL_APIENTRY (* _glDeleteFramebuffers) (GLsizei n, const GLuint *framebuffers);
GL_APICALL void GL_APIENTRY (* _glValidateProgram) (GLuint program);
GL_APICALL void GL_APIENTRY (* _glGetRenderbufferParameteriv) (GLenum target, GLenum pname, GLint *params);
GL_APICALL void GL_APIENTRY (* _glCompressedTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GL_APICALL void GL_APIENTRY (* _glCopyTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GL_APICALL void GL_APIENTRY (* _glBufferData) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
GL_APICALL void GL_APIENTRY (* _glFrontFace) (GLenum mode);
GL_APICALL void GL_APIENTRY (* _glGenRenderbuffers) (GLsizei n, GLuint *renderbuffers);
GL_APICALL void GL_APIENTRY (* _glTexImage2D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GL_APICALL void GL_APIENTRY (* _glUniform4iv) (GLint location, GLsizei count, const GLint *value);
GL_APICALL void GL_APIENTRY (* _glUniform1f) (GLint location, GLfloat v0);
GL_APICALL void GL_APIENTRY (* _glDisableVertexAttribArray) (GLuint index);
GL_APICALL void GL_APIENTRY (* _glGetUniformfv) (GLuint program, GLint location, GLfloat *params);
GL_APICALL void GL_APIENTRY (* _glBlendColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GL_APICALL void GL_APIENTRY (* _glDetachShader) (GLuint program, GLuint shader);
GL_APICALL void GL_APIENTRY (* _glUniformMatrix3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GL_APICALL void GL_APIENTRY (* _glVertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
GL_APICALL void GL_APIENTRY (* _glVertexAttrib2f) (GLuint index, GLfloat x, GLfloat y);
GL_APICALL void GL_APIENTRY (* _glVertexAttrib3f) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
GL_APICALL void GL_APIENTRY (* _glClear) (GLbitfield mask);
GL_APICALL GLint GL_APIENTRY (* _glGetAttribLocation) (GLuint program, const GLchar *name);
GL_APICALL void GL_APIENTRY (* _glGetVertexAttribPointerv) (GLuint index, GLenum pname, void **pointer);
GL_APICALL void GL_APIENTRY (* _glVertexAttrib4f) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GL_APICALL void GL_APIENTRY (* _glGenTextures) (GLsizei n, GLuint *textures);
GL_APICALL void GL_APIENTRY (* _glPixelStorei) (GLenum pname, GLint param);
GL_APICALL void GL_APIENTRY (* _glStencilFuncSeparate) (GLenum face, GLenum func, GLint ref, GLuint mask);
GL_APICALL void GL_APIENTRY (* _glUniform2fv) (GLint location, GLsizei count, const GLfloat *value);
GL_APICALL void GL_APIENTRY (* _glGetVertexAttribfv) (GLuint index, GLenum pname, GLfloat *params);
GL_APICALL void GL_APIENTRY (* _glGetProgramiv) (GLuint program, GLenum pname, GLint *params);
GL_APICALL void GL_APIENTRY (* _glGetShaderInfoLog) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GL_APICALL void GL_APIENTRY (* _glLineWidth) (GLfloat width);
GL_APICALL void GL_APIENTRY (* _glScissor) (GLint x, GLint y, GLsizei width, GLsizei height);
GL_APICALL void GL_APIENTRY (* _glUniform3fv) (GLint location, GLsizei count, const GLfloat *value);
GL_APICALL void GL_APIENTRY (* _glBlendFunc) (GLenum sfactor, GLenum dfactor);
GL_APICALL void GL_APIENTRY (* _glGetFloatv) (GLenum pname, GLfloat *data);
GL_APICALL const GLubyte *GL_APIENTRY (* _glGetString) (GLenum name);
GL_APICALL void GL_APIENTRY (* _glCompileShader) (GLuint shader);
GL_APICALL void GL_APIENTRY (* _glVertexAttrib3fv) (GLuint index, const GLfloat *v);
GL_APICALL void GL_APIENTRY (* _glGetShaderPrecisionFormat) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
GL_APICALL void GL_APIENTRY (* _glStencilMaskSeparate) (GLenum face, GLuint mask);
GL_APICALL void GL_APIENTRY (* _glUniform1i) (GLint location, GLint v0);
GL_APICALL void GL_APIENTRY (* _glShaderSource) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
GL_APICALL void GL_APIENTRY (* _glBlendFuncSeparate) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GL_APICALL void GL_APIENTRY (* _glUniformMatrix4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GL_APICALL void GL_APIENTRY (* _glAttachShader) (GLuint program, GLuint shader);
GL_APICALL void GL_APIENTRY (* _glCullFace) (GLenum mode);
GL_APICALL void GL_APIENTRY (* _glGetActiveUniform) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GL_APICALL void GL_APIENTRY (* _glActiveTexture) (GLenum texture);
GL_APICALL void GL_APIENTRY (* _glUniform2iv) (GLint location, GLsizei count, const GLint *value);
GL_APICALL void GL_APIENTRY (* _glUniform3i) (GLint location, GLint v0, GLint v1, GLint v2);
GL_APICALL void GL_APIENTRY (* _glGetBooleanv) (GLenum pname, GLboolean *data);
GL_APICALL void GL_APIENTRY (* _glStencilFunc) (GLenum func, GLint ref, GLuint mask);
GL_APICALL void GL_APIENTRY (* _glUniform1fv)(GLint location, GLsizei count, const GLfloat *value);
GL_APICALL void GL_APIENTRY (* _glUniform4fv) (GLint location, GLsizei count, const GLfloat *value);
GL_APICALL void GL_APIENTRY (* _glUniform2f) (GLint location, GLfloat v0, GLfloat v1);
GL_APICALL void GL_APIENTRY (* _glCopyTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GL_APICALL void GL_APIENTRY (* _glGenFramebuffers) (GLsizei n, GLuint *framebuffers);
GL_APICALL void GL_APIENTRY (* _glGetActiveAttrib) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GL_APICALL void GL_APIENTRY (* _glLinkProgram) (GLuint program);
GL_APICALL void GL_APIENTRY (* _glUniform3iv)(GLint location, GLsizei count, const GLint *value);
GL_APICALL void GL_APIENTRY (* _glShaderBinary) (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
GL_APICALL void GL_APIENTRY (* _glUniformMatrix2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GL_APICALL void GL_APIENTRY (* _glVertexAttrib4fv) (GLuint index, const GLfloat *v);
GL_APICALL void GL_APIENTRY (* _glDrawElements) (GLenum mode, GLsizei count, GLenum type, const void *indices);
GL_APICALL void GL_APIENTRY (* _glVertexAttrib2fv) (GLuint index, const GLfloat *v);
GL_APICALL void GL_APIENTRY (* _glBlendEquationSeparate) (GLenum modeRGB, GLenum modeAlpha);
GL_APICALL void GL_APIENTRY (* _glGetShaderiv) (GLuint shader, GLenum pname, GLint *params);
GL_APICALL GLboolean GL_APIENTRY (* _glIsEnabled) (GLenum cap);





EGLAPI EGLBoolean EGLAPIENTRY (* _eglDestroyContext) (EGLDisplay dpy, EGLContext ctx);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglQuerySurface) (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglBindTexImage) (EGLDisplay dpy, EGLSurface surface, EGLint buffer);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglSurfaceAttrib) (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value);
EGLAPI __eglMustCastToProperFunctionPointerType EGLAPIENTRY (* _eglGetProcAddress) (const char *procname);
EGLAPI EGLContext EGLAPIENTRY (* _eglCreateContext) (EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglSwapInterval) (EGLDisplay dpy, EGLint interval);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglReleaseTexImage) (EGLDisplay dpy, EGLSurface surface, EGLint buffer);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglWaitNative) (EGLint engine);
EGLAPI EGLDisplay EGLAPIENTRY (* _eglGetDisplay) (EGLNativeDisplayType display_id);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglGetConfigAttrib) (EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value);
EGLAPI EGLSurface EGLAPIENTRY (* _eglCreateWindowSurface) (EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint *attrib_list);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglSwapBuffers) (EGLDisplay dpy, EGLSurface surface);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglTerminate) (EGLDisplay dpy);
EGLAPI EGLSurface EGLAPIENTRY (* _eglCreatePbufferSurface) (EGLDisplay dpy, EGLConfig config, const EGLint *attrib_list);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglDestroySurface) (EGLDisplay dpy, EGLSurface surface);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglInitialize) (EGLDisplay dpy, EGLint *major, EGLint *minor);
EGLAPI const char *EGLAPIENTRY (* _eglQueryString) (EGLDisplay dpy, EGLint name);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglQueryContext) (EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint *value);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglMakeCurrent) (EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglChooseConfig) (EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config);
EGLAPI EGLBoolean EGLAPIENTRY (* _eglGetConfigs) (EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config);



int libSceGLSlimClientVSH_init()
{
	int handle=sceKernelLoadStartModule("libSceGLSlimClientVSH.sprx",0,0,0,0,0);
	#define LIBSCEGLSLIMCLIENTVSH_RESOLVE(name) prosperoDlsym(handle, #name, (void **)&_##name)
	
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(scePigletSetConfigurationVSH);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(scePigletGetConfigurationVSH);
	
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glCreateShader);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform4f);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glDisable);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetIntegerv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glDeleteTextures);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glDrawArrays);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glVertexAttrib1f);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glVertexAttrib1fv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glDeleteBuffers);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetProgramInfoLog);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glHint);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetVertexAttribiv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glReleaseShaderCompiler);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glTexParameterfv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform1iv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGenerateMipmap);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glBlendEquation);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glBufferSubData);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetUniformLocation);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glTexParameteriv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform2i);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform4i);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glEnable);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glEnableVertexAttribArray);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glTexSubImage2D);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform3f);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glBindAttribLocation);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetFramebufferAttachmentParameteriv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glCompressedTexImage2D);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glDeleteRenderbuffers);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGenBuffers);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetUniformiv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glStencilOp);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glStencilOpSeparate);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glViewport);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glSampleCoverage);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetBufferParameteriv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetAttachedShaders);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glDeleteFramebuffers);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glValidateProgram);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetRenderbufferParameteriv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glCompressedTexSubImage2D);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glCopyTexImage2D);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glBufferData);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glFrontFace);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGenRenderbuffers);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glTexImage2D);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform4iv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform1f);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glDisableVertexAttribArray);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetUniformfv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glBlendColor);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glDetachShader);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniformMatrix3fv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glVertexAttribPointer);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glVertexAttrib2f);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glVertexAttrib3f);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glClear);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetAttribLocation);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetVertexAttribPointerv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glVertexAttrib4f);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGenTextures);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glPixelStorei);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glStencilFuncSeparate);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform2fv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetVertexAttribfv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetProgramiv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetShaderInfoLog);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glLineWidth);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glScissor);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform3fv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glBlendFunc);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetFloatv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetString);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glCompileShader);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glVertexAttrib3fv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetShaderPrecisionFormat);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glStencilMaskSeparate);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform1i);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glShaderSource);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glBlendFuncSeparate);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniformMatrix4fv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glAttachShader);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glCullFace);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetActiveUniform);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glActiveTexture);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform2iv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform3i);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetBooleanv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glStencilFunc);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform1fv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform4fv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform2f);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glCopyTexSubImage2D);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGenFramebuffers);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetActiveAttrib);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glLinkProgram);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniform3iv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glShaderBinary);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glUniformMatrix2fv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glVertexAttrib4fv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glDrawElements);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glVertexAttrib2fv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glBlendEquationSeparate);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glGetShaderiv);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(glIsEnabled);







	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglDestroyContext);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglQuerySurface);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglBindTexImage);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglSurfaceAttrib);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglGetProcAddress);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglCreateContext);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglSwapInterval);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglReleaseTexImage);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglWaitNative);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglGetDisplay);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglGetConfigAttrib);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglCreateWindowSurface);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglSwapBuffers);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglTerminate);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglCreatePbufferSurface);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglDestroySurface);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglInitialize);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglQueryString);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglQueryContext);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglMakeCurrent);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglChooseConfig);
	LIBSCEGLSLIMCLIENTVSH_RESOLVE(eglGetConfigs);


	#undef LIBSCEGLSLIMCLIENTVSH_RESOLVE
	return handle;
}

bool scePigletSetConfigurationVSH(const ScePglConfig* config)
{
	return _scePigletSetConfigurationVSH(config);
}

bool scePigletGetConfigurationVSH(const ScePglConfig* config)
{
	return _scePigletGetConfigurationVSH(config);
}

GL_APICALL GLuint GL_APIENTRY glCreateShader (GLenum type)
{
	return _glCreateShader(type);
}

GL_APICALL void GL_APIENTRY glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	return _glUniform4f(location,v0,v1,v2,v3);
}

GL_APICALL void GL_APIENTRY glDisable (GLenum cap)
{
	return _glDisable(cap);
}

GL_APICALL void GL_APIENTRY glGetIntegerv (GLenum pname, GLint *data)
{
	return _glGetIntegerv(pname,data);
}

GL_APICALL void GL_APIENTRY glDeleteTextures (GLsizei n, const GLuint *textures)
{
	return _glDeleteTextures(n,textures);
}

GL_APICALL void GL_APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count)
{
	return _glDrawArrays(mode,first,count);
}

GL_APICALL void GL_APIENTRY glVertexAttrib1f (GLuint index, GLfloat x)
{
	return _glVertexAttrib1f(index,x);
}

GL_APICALL void GL_APIENTRY glVertexAttrib1fv (GLuint index, const GLfloat *v)
{
	return _glVertexAttrib1fv(index,v);
}

GL_APICALL void GL_APIENTRY glDeleteBuffers (GLsizei n, const GLuint *buffers)
{
	return _glDeleteBuffers(n,buffers);
}

GL_APICALL void GL_APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	return _glGetProgramInfoLog(program,bufSize,length,infoLog);
}

GL_APICALL void GL_APIENTRY glHint (GLenum target, GLenum mode)
{
	return _glHint(target,mode);
}

GL_APICALL void GL_APIENTRY glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params)
{
	return _glGetVertexAttribiv(index,pname,params);
}

GL_APICALL void GL_APIENTRY glReleaseShaderCompiler (void)
{
	return _glReleaseShaderCompiler();
}

GL_APICALL void GL_APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params)
{
	return _glTexParameterfv(target,pname,params);
}

GL_APICALL void GL_APIENTRY glUniform1iv (GLint location, GLsizei count, const GLint *value)
{
	return _glUniform1iv(location,count,value);
}

GL_APICALL void GL_APIENTRY glGenerateMipmap (GLenum target)
{
	return _glGenerateMipmap(target);
}

GL_APICALL void GL_APIENTRY glBlendEquation (GLenum mode)
{
	return _glBlendEquation(mode);
}

GL_APICALL void GL_APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void *data)
{
	return _glBufferSubData(target,offset,size,data);
}

GL_APICALL GLint GL_APIENTRY glGetUniformLocation (GLuint program, const GLchar *name)
{
	return _glGetUniformLocation(program,name);
}

GL_APICALL void GL_APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint *params)
{
	return _glTexParameteriv(target,pname,params);
}

GL_APICALL void GL_APIENTRY glUniform2i (GLint location, GLint v0, GLint v1)
{
	return _glUniform2i(location,v0,v1);
}

GL_APICALL void GL_APIENTRY glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	return _glUniform4i(location,v0,v1,v2,v3);
}

GL_APICALL void GL_APIENTRY glEnable (GLenum cap)
{
	return _glEnable(cap);
}

GL_APICALL void GL_APIENTRY glEnableVertexAttribArray (GLuint index)
{
	return _glEnableVertexAttribArray(index);
}

GL_APICALL void GL_APIENTRY glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels)
{
	return _glTexSubImage2D(target,level,xoffset,yoffset,width,height,format,type,pixels);
}

GL_APICALL void GL_APIENTRY glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	return _glUniform3f(location,v0,v1,v2);
}

GL_APICALL void GL_APIENTRY glBindAttribLocation (GLuint program, GLuint index, const GLchar *name)
{
	return _glBindAttribLocation(program,index,name);
}

GL_APICALL void GL_APIENTRY glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params)
{
	return _glGetFramebufferAttachmentParameteriv(target,attachment,pname,params);
}

GL_APICALL void GL_APIENTRY glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data)
{
	return _glCompressedTexImage2D(target,level,internalformat,width,height,border,imageSize,data);
}

GL_APICALL void GL_APIENTRY glDeleteRenderbuffers (GLsizei n, const GLuint *renderbuffers)
{
	return _glDeleteRenderbuffers(n,renderbuffers);
}

GL_APICALL void GL_APIENTRY glGenBuffers (GLsizei n, GLuint *buffers)
{
	return _glGenBuffers(n,buffers);
}

GL_APICALL void GL_APIENTRY glGetUniformiv (GLuint program, GLint location, GLint *params)
{
	return _glGetUniformiv(program,location,params);
}

GL_APICALL void GL_APIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass)
{
	return _glStencilOp(fail,zfail,zpass);
}

GL_APICALL void GL_APIENTRY glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
	return _glStencilOpSeparate(face,sfail,dpfail,dppass);
}

GL_APICALL void GL_APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height)
{
	return _glViewport(x,y,width,height);
}

GL_APICALL void GL_APIENTRY glSampleCoverage (GLfloat value, GLboolean invert)
{
	return _glSampleCoverage(value,invert);
}

GL_APICALL void GL_APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params)
{
	return _glGetBufferParameteriv(target,pname,params);
}

GL_APICALL void GL_APIENTRY glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)
{
	return _glGetAttachedShaders(program,maxCount,count,shaders);
}

GL_APICALL void GL_APIENTRY glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers)
{
	return _glDeleteFramebuffers(n,framebuffers);
}

GL_APICALL void GL_APIENTRY glValidateProgram (GLuint program)
{
	return _glValidateProgram(program);
}

GL_APICALL void GL_APIENTRY glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params)
{
	return _glGetRenderbufferParameteriv(target,pname,params);
}

GL_APICALL void GL_APIENTRY glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)
{
	return _glCompressedTexSubImage2D(target,level,xoffset,yoffset,width,height,format,imageSize,data);
}

GL_APICALL void GL_APIENTRY glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	return _glCopyTexImage2D(target,level,internalformat,x,y,width,height,border);
}

GL_APICALL void GL_APIENTRY glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage)
{
	return _glBufferData(target,size,data,usage);
}

GL_APICALL void GL_APIENTRY glFrontFace (GLenum mode)
{
	return _glFrontFace(mode);
}

GL_APICALL void GL_APIENTRY glGenRenderbuffers (GLsizei n, GLuint *renderbuffers)
{
	return _glGenRenderbuffers(n,renderbuffers);
}

GL_APICALL void GL_APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels)
{
	return _glTexImage2D(target,level,internalformat,width,height,border,format,type,pixels);
}

GL_APICALL void GL_APIENTRY glUniform4iv (GLint location, GLsizei count, const GLint *value)
{
	return _glUniform4iv(location,count,value);
}

GL_APICALL void GL_APIENTRY glUniform1f (GLint location, GLfloat v0)
{
	return _glUniform1f(location,v0);
}

GL_APICALL void GL_APIENTRY glDisableVertexAttribArray (GLuint index)
{
	return _glDisableVertexAttribArray(index);
}

GL_APICALL void GL_APIENTRY glGetUniformfv (GLuint program, GLint location, GLfloat *params)
{
	return _glGetUniformfv(program,location,params);
}

GL_APICALL void GL_APIENTRY glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	return _glBlendColor(red,green,blue,alpha);
}

GL_APICALL void GL_APIENTRY glDetachShader (GLuint program, GLuint shader)
{
	return _glDetachShader(program,shader);
}

GL_APICALL void GL_APIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	return _glUniformMatrix3fv(location,count,transpose,value);
}

GL_APICALL void GL_APIENTRY glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
{
	return _glVertexAttribPointer(index,size,type,normalized,stride,pointer);
}

GL_APICALL void GL_APIENTRY glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y)
{
	return _glVertexAttrib2f(index,x,y);
}

GL_APICALL void GL_APIENTRY glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
	return _glVertexAttrib3f(index,x,y,z);
}

GL_APICALL void GL_APIENTRY glClear (GLbitfield mask)
{
	return _glClear(mask);
}

GL_APICALL GLint GL_APIENTRY glGetAttribLocation (GLuint program, const GLchar *name)
{
	return  _glGetAttribLocation(program,name);
}

GL_APICALL void GL_APIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer)
{
	return _glGetVertexAttribPointerv(index,pname,pointer);
}

GL_APICALL void GL_APIENTRY glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	return _glVertexAttrib4f(index,x,y,z,w);
}

GL_APICALL void GL_APIENTRY glGenTextures (GLsizei n, GLuint *textures)
{
	return _glGenTextures(n,textures);
}

GL_APICALL void GL_APIENTRY glPixelStorei (GLenum pname, GLint param)
{
	return _glPixelStorei(pname,param);
}

GL_APICALL void GL_APIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask)
{
	return _glStencilFuncSeparate(face,func,ref,mask);
}

GL_APICALL void GL_APIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat *value)
{
	return _glUniform2fv(location,count,value);
}

GL_APICALL void GL_APIENTRY glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params)
{
	return _glGetVertexAttribfv(index,pname,params);
}

GL_APICALL void GL_APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint *params)
{
	return _glGetProgramiv(program,pname,params);
}

GL_APICALL void GL_APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	return _glGetShaderInfoLog(shader,bufSize,length,infoLog);
}

GL_APICALL void GL_APIENTRY glLineWidth (GLfloat width)
{
	return _glLineWidth(width);
}

GL_APICALL void GL_APIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height)
{
	return _glScissor(x,y,width,height);
}

GL_APICALL void GL_APIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat *value)
{
	return _glUniform3fv(location,count,value);
}

GL_APICALL void GL_APIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor)
{
	return _glBlendFunc(sfactor,dfactor);
}

GL_APICALL void GL_APIENTRY glGetFloatv (GLenum pname, GLfloat *data)
{
	return _glGetFloatv(pname,data);
}

GL_APICALL const GLubyte *GL_APIENTRY glGetString (GLenum name)
{
	return _glGetString(name);
}

GL_APICALL void GL_APIENTRY glCompileShader (GLuint shader)
{
	return _glCompileShader(shader);
}

GL_APICALL void GL_APIENTRY glVertexAttrib3fv (GLuint index, const GLfloat *v)
{
	return _glVertexAttrib3fv(index,v);
}

GL_APICALL void GL_APIENTRY glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)
{
	return _glGetShaderPrecisionFormat(shadertype,precisiontype,range,precision);
}

GL_APICALL void GL_APIENTRY glStencilMaskSeparate (GLenum face, GLuint mask)
{
	return _glStencilMaskSeparate(face,mask);
}

GL_APICALL void GL_APIENTRY glUniform1i (GLint location, GLint v0)
{
	return _glUniform1i(location,v0);
}

GL_APICALL void GL_APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length)
{
	return _glShaderSource(shader,count,string,length);
}

GL_APICALL void GL_APIENTRY glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
	return _glBlendFuncSeparate(sfactorRGB,dfactorRGB,sfactorAlpha,dfactorAlpha);
}

GL_APICALL void GL_APIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	return _glUniformMatrix4fv(location,count,transpose,value);
}

GL_APICALL void GL_APIENTRY glAttachShader (GLuint program, GLuint shader)
{
	return _glAttachShader(program,shader);
}

GL_APICALL void GL_APIENTRY glCullFace (GLenum mode)
{
	return _glCullFace(mode);
}

GL_APICALL void GL_APIENTRY glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
	return _glGetActiveUniform(program,index,bufSize,length,size,type,name);
}

GL_APICALL void GL_APIENTRY glActiveTexture (GLenum texture)
{
	return _glActiveTexture(texture);
}

GL_APICALL void GL_APIENTRY glUniform2iv (GLint location, GLsizei count, const GLint *value)
{
	return _glUniform2iv(location,count,value);
}

GL_APICALL void GL_APIENTRY glUniform3i (GLint location, GLint v0, GLint v1, GLint v2)
{
	return _glUniform3i(location,v0,v1,v2);
}

GL_APICALL void GL_APIENTRY glGetBooleanv (GLenum pname, GLboolean *data)
{
	return _glGetBooleanv(pname,data);
}

GL_APICALL void GL_APIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask)
{
	return _glStencilFunc(func,ref,mask);
}

GL_APICALL void GL_APIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat *value)
{
	return _glUniform1fv(location,count,value);
}

GL_APICALL void GL_APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat *value)
{
	return _glUniform4fv(location,count,value);
}

GL_APICALL void GL_APIENTRY glUniform2f (GLint location, GLfloat v0, GLfloat v1)
{
	return _glUniform2f(location,v0,v1);
}

GL_APICALL void GL_APIENTRY glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	return _glCopyTexImage2D(target,level,xoffset,yoffset,x,y,width,height);
}

GL_APICALL void GL_APIENTRY glGenFramebuffers (GLsizei n, GLuint *framebuffers)
{
	return _glGenFramebuffers(n,framebuffers);
}

GL_APICALL void GL_APIENTRY glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
	return _glGetActiveAttrib(program,index,bufSize,length,size,type,name);
}

GL_APICALL void GL_APIENTRY glLinkProgram (GLuint program)
{
	return _glLinkProgram(program);
}

GL_APICALL void GL_APIENTRY glUniform3iv (GLint location, GLsizei count, const GLint *value)
{
	return _glUniform3iv(location,count,value);
}

GL_APICALL void GL_APIENTRY glShaderBinary (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length)
{
	return _glShaderBinary(count,shaders,binaryformat,binary,length);
}

GL_APICALL void GL_APIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	return _glUniformMatrix2fv(location,count,transpose,value);
}

GL_APICALL void GL_APIENTRY glVertexAttrib4fv (GLuint index, const GLfloat *v)
{
	return _glVertexAttrib4fv(index,v);
}

GL_APICALL void GL_APIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const void *indices)
{
	return _glDrawElements(mode,count,type,indices);
}

GL_APICALL void GL_APIENTRY glVertexAttrib2fv (GLuint index, const GLfloat *v)
{
	return _glVertexAttrib2fv(index,v);
}

GL_APICALL void GL_APIENTRY glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha)
{
	return _glBlendEquationSeparate(modeRGB,modeAlpha);
}

GL_APICALL void GL_APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint *params)
{
	return _glGetShaderiv(shader,pname,params);
}

GL_APICALL GLboolean GL_APIENTRY glIsEnabled (GLenum cap)
{
	return _glIsEnabled(cap);
}


EGLAPI EGLBoolean EGLAPIENTRY eglDestroyContext (EGLDisplay dpy, EGLContext ctx)
{
	return _eglDestroyContext(dpy,ctx);
}

EGLAPI EGLBoolean EGLAPIENTRY eglQuerySurface (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value)
{
	return _eglQuerySurface(dpy,surface,attribute,value);
}

EGLAPI EGLBoolean EGLAPIENTRY eglBindTexImage (EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
	return _eglBindTexImage(dpy,surface,buffer);
}

EGLAPI EGLBoolean EGLAPIENTRY eglSurfaceAttrib (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value)
{
	return _eglSurfaceAttrib(dpy,surface,attribute,value);
}

EGLAPI __eglMustCastToProperFunctionPointerType EGLAPIENTRY eglGetProcAddress (const char *procname)
{
	return _eglGetProcAddress(procname);
}

EGLAPI EGLContext EGLAPIENTRY eglCreateContext (EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list)
{
	return _eglCreateContext(dpy,config,share_context,attrib_list);
}

EGLAPI EGLBoolean EGLAPIENTRY eglSwapInterval (EGLDisplay dpy, EGLint interval)
{
	return _eglSwapInterval(dpy,interval);
}

EGLAPI EGLBoolean EGLAPIENTRY eglReleaseTexImage (EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
	return _eglReleaseTexImage(dpy,surface,buffer);
}

EGLAPI EGLBoolean EGLAPIENTRY eglWaitNative (EGLint engine)
{
	return _eglWaitNative(engine);
}

EGLAPI EGLDisplay EGLAPIENTRY eglGetDisplay (EGLNativeDisplayType display_id)
{
	return _eglGetDisplay(display_id);
}

EGLAPI EGLBoolean EGLAPIENTRY eglGetConfigAttrib (EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value)
{
	return _eglGetConfigAttrib(dpy,config,attribute,value);
}

EGLAPI EGLSurface EGLAPIENTRY eglCreateWindowSurface (EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint *attrib_list)
{
	return _eglCreateWindowSurface(dpy,config,win,attrib_list);
}

EGLAPI EGLBoolean EGLAPIENTRY eglSwapBuffers (EGLDisplay dpy, EGLSurface surface)
{
	return _eglSwapBuffers(dpy,surface);
}

EGLAPI EGLBoolean EGLAPIENTRY eglTerminate (EGLDisplay dpy)
{
	return _eglTerminate(dpy);
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePbufferSurface (EGLDisplay dpy, EGLConfig config, const EGLint *attrib_list)
{
	return _eglCreatePbufferSurface(dpy,config,attrib_list);
}

EGLAPI EGLBoolean EGLAPIENTRY eglDestroySurface (EGLDisplay dpy, EGLSurface surface)
{
	return _eglDestroySurface(dpy,surface);
}

EGLAPI EGLBoolean EGLAPIENTRY eglInitialize (EGLDisplay dpy, EGLint *major, EGLint *minor)
{
	return _eglInitialize(dpy,major,minor);
}

EGLAPI const char *EGLAPIENTRY eglQueryString (EGLDisplay dpy, EGLint name)
{
	return _eglQueryString(dpy,name);
}

EGLAPI EGLBoolean EGLAPIENTRY eglQueryContext (EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint *value)
{
	return _eglQueryContext(dpy,ctx,attribute,value);
}

EGLAPI EGLBoolean EGLAPIENTRY eglMakeCurrent (EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx)
{
	return _eglMakeCurrent(dpy,draw,read,ctx);
}

EGLAPI EGLBoolean EGLAPIENTRY eglChooseConfig (EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config)
{
	return _eglChooseConfig(dpy,attrib_list,configs,config_size,num_config);
}

EGLAPI EGLBoolean EGLAPIENTRY eglGetConfigs (EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config)
{
	return _eglGetConfigs(dpy,configs,config_size,num_config);
}

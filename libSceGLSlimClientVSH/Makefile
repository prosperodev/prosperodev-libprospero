ifndef PROSPERODEV
$(error PROSPERODEV, is not set)
endif

target := prospero_lib_no_all
OutPath := lib
TargetFile := libSceGLSlimClientVSH_stub
AllTarget = $(OutPath)/$(TargetFile).a 

include $(PROSPERODEV)/make/prosperosdk.mk
CompilerFlags += -DHAVE_CONFIG_H -D_U_="__attribute__((unused))" -DNDEBUG -D_BSD_SOURCE 
CompilerFlagsCpp += -DHAVE_CONFIG_H -D_U_="__attribute__((unused))" -DNDEBUG -D_BSD_SOURCE
#IncludePath += -I$(ORBISDEV)/usr/include -Iinclude/nfsc 


$(OutPath)/$(TargetFile).a: $(ObjectFiles)
	$(dirp)
	$(archive)

install:
	@cp $(OutPath)/$(TargetFile).a $(PROSPERODEV)/usr/lib
	@cp include/*.h $(PROSPERODEV)/usr/include/prospero
	@mkdir $(PROSPERODEV)/usr/include/prospero/EGL
	@mkdir $(PROSPERODEV)/usr/include/prospero/GLES2
	@mkdir $(PROSPERODEV)/usr/include/prospero/KHR
	@cp include/EGL/*.h $(PROSPERODEV)/usr/include/prospero/EGL
	@cp include/GLES2/*.h $(PROSPERODEV)/usr/include/prospero/GLES2
	@cp include/KHR/*.h $(PROSPERODEV)/usr/include/prospero/KHR
	@echo "$(TargetFile) Installed!"


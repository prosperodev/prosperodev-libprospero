#!/bin/bash -x
SUBDIRS="libprospero libkernel_sys libSceLibcInternal libSceSysmodule libSceSystemService libSceUserService libSceNet libScePad libSceVideoOut libSceAudioOut libSceGLSlimClientVSH"
PROC_NR=$(getconf _NPROCESSORS_ONLN)


## Fetch the main headers
#git clone https://github.com/prosperodev/prosperodev-headers --depth=1
#cp -a prospero-headers/include/* $PROSPERODEV/usr/include/

## Download the source code.
for dir in ${SUBDIRS}
do 
	echo $dir
	cd $dir
	make --quiet -j $PROC_NR clean || { exit 1; }
	make --quiet -j $PROC_NR || { exit 1; }
	make --quiet -j $PROC_NR install || { exit 1; }
	make --quiet -j $PROC_NR clean || { exit 1; } 
	cd ..
done

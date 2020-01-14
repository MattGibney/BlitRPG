prepare-build: 
	mkdir build; cd build; cmake .. -DCMAKE_TOOLCHAIN_FILE=../libs/32blit-beta/32blit.toolchain

compile:
	cd build; make

flash:
	cd build; dfu-util -a 0 -s 0x08000000 -D rpg.bin;

clean :
	rm -rf build

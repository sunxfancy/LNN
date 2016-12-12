build:
	-mkdir build
	-cd build && cmake .. && make
	-mv lua/liblnn.so lua/lnn.so
run:
	cd lua && lua5.3 main.lua

.PHONY: build run

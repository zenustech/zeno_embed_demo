run: all
	build/testApp/testApp

all:
	cmake -B build
	make -C build -j 32

run: all
	./run.sh

all:
	cmake -B build
	make -C build -j 32

all:
	cmake -B build
	make -C build -j 32

run:
	python run.py

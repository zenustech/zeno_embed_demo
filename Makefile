all:
	PYTHONPATH=external/zeno cmake -B build
	make -C build -j 32

run:
	PYTHONPATH=external/zeno python -m zenqt

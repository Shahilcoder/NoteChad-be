prepare:
	rm -rf build
	mkdir build
	cd build && cmake .. -G "Unix Makefiles"

run:
	cd build && cmake --build . -j6
	cd build && ./NoteChadBe

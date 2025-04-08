# define command for cmake
.PHONY: config
config:
		cmake -B build

.PHONY: build
build: config
		cmake --build build

.PHONY: install
install: build
		cmake --install build

TEST_FLAG =

.PHONY: uninstall
uninstall:
		rm -rf bin
		rm -rf lib
		rm -rf include

.PHONY: clean
clean:
		rm -rf build
		rm -rf bin
		rm -rf lib
		rm -rf include

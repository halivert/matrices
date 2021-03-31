.PHONY: build

build:
	@cmake -S . -B build -G "Unix Makefiles"
	@cmake --build build/

test: build
	@ctest --build-and-test . build --build-generator "Unix Makefiles"
	@(cd build; make test)

clean:
	@rm -rf build
	@echo "Cleaned files"


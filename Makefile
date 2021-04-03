.PHONY: build

build:
	@cmake -S . -B build -G "Unix Makefiles"
	@cmake --build build/

run: build
	@./build/Main

test: build
	@ctest --build-and-test . build --build-generator "Unix Makefiles" \
		--output-on-failure
	@(cd build; make test)

clean:
	@rm -rf build
	@echo "Cleaned files"


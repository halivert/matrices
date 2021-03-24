a.out: Fraction.o
	@g++ Fraction.o main.cpp -Wall
	@echo "Compiled a.out"

Fraction.o: Fraction.h Fraction.cpp
	@g++ Fraction.cpp -c -o Fraction.o
	@echo "Compile header Fraction.o"

run: a.out
	@./a.out
	@rm -rf a.out

clean:
	@rm -rf Fraction.o a.out
	@echo "Cleaned files"


all:example.cpp
		gcc example.cpp -lgsl -lcblas -latlas -lm -Wall -o example.exe
clean:
		rm -rf *.o
		rm -rf mathlib/*.o
		rm -rf mathlib/*.a
		rm example.exe

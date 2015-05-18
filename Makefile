lab5: main.o HugeInt.o
	g++ -o lab5 main.o HugeInt.o
main.o: main.cpp HugeInt.h
	g++ -c main.cpp
HugeInt.o: HugeInt.cpp
	g++ -c HugeInt.cpp -std=c++0x
clean:
	rm main.o HugeInt.o

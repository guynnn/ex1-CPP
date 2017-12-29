GCC_FLAGS = g++ -std=c++11 -Wall -Wextra

all: MySet.cpp MySet.h SetBinaryOperations.cpp
	$(GCC_FLAGS) MySet.cpp SetBinaryOperations.cpp -o ex1

run: 
	./ex1	

tar: 
	tar cvf ex1.tar MySet.h MySet.cpp SetBinaryOperations.cpp Makefile

clean:
	rm -f ex1 ex1.tar

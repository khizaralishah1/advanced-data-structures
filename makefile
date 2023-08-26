cpp = memory-efficient-doubly-linked-list.cpp
std = -std=c++20

all:
	g++ -o ./a.out $(cpp) -Wall $(std)
	./a.out

r:
	./a.out
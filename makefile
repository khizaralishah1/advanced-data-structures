cpp1 = memory-efficient-doubly-linked-list.cpp
cpp2 = unrolled-linked-list.cpp
std = -std=c++20

all:
	g++ -o ./a.out $(cpp2) -Wall $(std)
	./a.out

r:
	./a.out
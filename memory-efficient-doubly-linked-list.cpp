#include <iostream>

struct node
{
    int data;
    struct *ptrdiff;

    node(int value) { data = value; }
} *head = nullptr;

void insert(int value)
{
    if (head == nullptr)
    {
        head = new node(value);
        head->ptrdiff = nullptr;
        return;
    }

    node *cur = new node(value);
    cur->ptrdiff = head;
    head->ptrdiff = ptrdiff ^ cur;
    head = cur;
}

void print()
{
    node *prev = nullptr;
    node *next = head;

    while (next)
    {
        std::cout << next->data << " ";
        next = next->ptrdiff ^ prev;
    }
}

int main()
{
    for (int i = 0; i < 5; ++i)
        insert(i);

    print();

    return 0;
}
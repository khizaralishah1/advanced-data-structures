#include <iostream>

struct node
{
    int data;
    uint64_t ptrdiff;

    node(int value) { data = value; }
} *head = nullptr;

void insert(int value)
{
    if (head == nullptr)
    {
        head = new node(value);
        head->ptrdiff = 0;
        return;
    }

    node *cur = new node(value);
    cur->ptrdiff = (uint64_t)head;
    head->ptrdiff = head->ptrdiff ^ (uint64_t)cur;
    head = cur;
}

void print()
{
    uint64_t prev = 0;
    uint64_t prev2 = 0;
    uint64_t next = (uint64_t)head;

    while (next)
    {
        std::cout << ((node *)next)->data << " ";
        prev = prev2;
        prev2 = next;
        next = ((node *)prev2)->ptrdiff ^ prev;
    }
}

int main()
{
    for (int i = 0; i < 10; ++i)
        insert(i);

    print();

    return 0;
}
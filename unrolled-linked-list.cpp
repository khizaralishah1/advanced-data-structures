#include <iostream>

#define total_nodes_per_block 5 // keep it similar to the size of block of cache

struct node
{
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

struct block
{
    node *head;
    block *next;
    int node_count;

    block(int val)
    {
        head = new node(val);
        node_count = 1;
        next = nullptr;
    }

} *head = nullptr;

void insert(int val)
{
    if (head == nullptr || (head->node_count >= total_nodes_per_block))
    {
        block *new_block = new block(val);
        new_block->next = head;
        head = new_block;
    }
    else
    {
        node *new_node = new node(val);
        new_node->next = head->head;
        head->head = new_node;
        head->node_count += 1;
    }
};

void print()
{
    block *block_temp = head;
    node *node_temp;

    while (block_temp)
    {
        node_temp = (block_temp != nullptr) ? block_temp->head : nullptr;

        while (node_temp)
        {
            std::cout << node_temp->data << " ";
            node_temp = node_temp->next;
        }
        std::cout << std::endl;
        block_temp = block_temp->next;
    }
}

int main()
{
    for (int i = 0; i < 18; ++i)
    {
        insert(i);
    }

    print();

    return 0;
}
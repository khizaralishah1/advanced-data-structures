# Linked Lists

## Memory-Efficient Doubly

    - Instead of using *prev* and *next* pointers in a node, we can use one pointer.
    - *ptrdiff* pointer in the node will store the *xor* of previous and next node's address
    - A ⓧ null = A
    - A ⓧ A    = null
    - ptrdiff has A ⓧ B
    - To go back, xor with next node     => (A ⓧ B) ⓧ B = A ⓧ null = A
    - To go next, xor with previous node => (A ⓧ B) ⓧ A = B ⓧ null = B

## Un-rolled

    - Search in a linked list has time complexity O(n)
    - If blocks of nodes are placed in cache, search can improve greatly
    - This implementation has blocks, each of size similar to cache block size, and having that many number of nodes.
    - In a list with *n* number of nodes, search can be of time complexity *O(√n)* when there are √n blocks, each having √n number of nodes

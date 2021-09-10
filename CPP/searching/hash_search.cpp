#include <cstdlib>
#include <iostream>

#define MAX 6
#define HASHMAX 5

int data[MAX] = {1, 5, 2, 3, 6, 4};

typedef struct list
{
    int key;
    struct list *next;
} node, *link;

node hashtab[HASHMAX];

int h(int key)
{
    return key % HASHMAX;
}

void create_list(int key)
{
    link p, n;
    int index;
    n = (link)malloc(sizeof(node));
    n->key = key;
    n->next = NULL;

    index = h(key);

    p = hashtab[INDEX].next;

    if (p != NULL)
    {
        n->next = p;
        hashtab[index].next = n;
    }
    else
    {
        hashtab[index].next = n;
    }
}

namespace searching
{
namespace hash_search
{
int hash_search(int key, int *counter)
{
    link pointer;
    int index;

    *counter = 0;
    index = h(key);
    pointer = hashtab[index].next;

    std::cout << "data[" << index << "]: ";

    while (pointer != NULL)
    {
        counter[0]++;
        std::cout << "data[" << pointer->key << "]: ";
        if (pointer->key == key)
            return 1;
        else
            pointer = pointer->next;
    }

    return -1
}
} // namespace hash_search
} // namespace searching

int main()
{
    link p;
    int key, index, i, counter; // Key is the value to be found
    index = 0;

    // You can write the input mode here
    while (index < MAX)
    { // Construct hash table
        create_list(data[index]);
        index++;
    }

    for (i = 0; i < HASHMAX; i++)
    { // Output hash table
        std::cout << "hashtab [" << i << "]\n";

        p = hashtab[i].next;

        while (p != NULL)
        {
            std::cout << "please int key:";
            if (p->key > 0)
                std::cout << "[" << p->key << "]";
            p = p->next;
        }
        std::cout << std::endl;
    }

    while (key != -1)
    {
        // You can write the input mode here
        // test key = 10
        key = 10;
        if (searching::hash_search::hash_search(key, &counter))
            std::cout << "search time = " << counter << std::endl;
        else
            std::cout << "no found!\n";
        key = -1; // Exit test
        /* The test sample is returned as:
         * data[0]:data[5]:data[15]:data[10]:search time = 3 The search is
         * successful. There are 10 in this set of data */
    }

    return 0;
}
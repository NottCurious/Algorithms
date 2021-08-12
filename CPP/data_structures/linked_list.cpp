#include <cstdio>
#include <cstdlib>
#include <iostream>

struct node
{
    int val;
    node *next;
} * start;

class linked_list
{
  public:
    linked_list()
    {
        start = NULL;
    };
    void insert(int x);
    void remove(int x);
    void search(int x);
    void show();
};

void linked_list::insert(int x)
{
    node *t = start;

    if (start != NULL)
    {
        while (t->next != NULL)
        {
            t = t->next;
        }

        node *n = new node;
        t->next = n;
        n->val = x;
        n->next = NULL;
    }
    else
    {
        node *n = new node;
        n->val = x;
        n->next = NULL;
        start = n;
    }
}

void linked_list::remove(int x)
{
    node *t = start;

    while (t != NULL && t->val != x)
    {
        t = t->next;
    }
    if (t == NULL)
    {
        return;
    }
    if (t->next == NULL)
    {
        start = NULL;
    }
    else
    {
        start = t->next;
    }

    delete t;
}

void linked_list::search(int x)
{
    node *t = start;
    int found = 0;

    while (t != NULL)
    {
        if (t->val == x)
        {
            std::cout << "Found" << std::endl;
            found = 1;
            break;
        }

        t = t->next;
    }

    if (found == 0)
    {
        std::cout << "Not Found" << std::endl;
    }
}

void linked_list::show()
{
    node *t = start;

    while (t != NULL)
    {
        std::cout << t->val << "\t";
        t = t->next;
    }
}

int main()
{
    int choice, x;
    linked_list ob;

    do
    {
        std::cout << "\n1. Insert";
        std::cout << "\n2. Delete";
        std::cout << "\n3. Search";
        std::cout << "\n4. Print";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "\nEnter the element to be inserted : ";
            std::cin >> x;
            ob.insert(x);
            break;
        case 2:
            std::cout << "\nEnter the element to be removed : ";
            std::cin >> x;
            ob.remove(x);
            break;
        case 3:
            std::cout << "\nEnter the element to be searched : ";
            std::cin >> x;
            ob.search(x);
            break;
        case 4:
            ob.show();
            break;
        }
    } while (choice != 0);

    return 0;
}

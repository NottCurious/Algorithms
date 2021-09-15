#include <iostream>

struct node
{
    int val;
    node *next;
};

node *start;

namespace linked_list
{
namespace functions
{
void insert(int x)
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

void reverse(node *p, node *q)
{
    if (q->next = NULL)
    {
        q->next = p;
        p->next = NULL;
        start = q;
        return;
    }
    else
    {
        linked_list::functions::reverse(q, q->next);
        q->next = p;
        p->next = NULL;
    }
}

void show()
{
    node *t = start;
    while (t != NULL)
    {
        std::cout << t->val << "\t";
        t = t->next;
    }
}
} // namespace functions
} // namespace linked_list

int main()
{
    linked_list::functions::insert(1);
    linked_list::functions::insert(2);
    linked_list::functions::insert(3);
    linked_list::functions::insert(4);
    linked_list::functions::insert(5);
    linked_list::functions::insert(6);

    linked_list::functions::reverse(start, start->next);

    linked_list::functions::show();

    return 0;
}
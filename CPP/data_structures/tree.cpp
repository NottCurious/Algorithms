#include <iostream>
#include <list>

struct node
{
    int val;
    node *left;
    node *right;
};

void CreateTree(node *curr, node *n, int x, char pos)
{
    if (n != NULL)
    {
        char ch;
        std::cout << std::endl << "Left or Right of " << n->val << " : ";
        std::cin >> ch;
        if (ch == 'l')
            CreateTree(n, n->left, x, ch);
        else if (ch == 'r')
            CreateTree(n, n->right, x, ch);
    }
    else
    {
        node *t = new node;
        t->val = x;
        t->left = NULL;
        t->right = NULL;
        if (pos == 'l')
        {
            curr->left = t;
        }
        else if (pos == 'r')
        {
            curr->right = t;
        }
    }
}

void BFT(node *n)
{
    std::list<node *> queue;

    queue.push_back(n);

    while (!queue.empty())
    {
        n = queue.front();
        std::cout << n->val << "  ";
        queue.pop_front();

        if (n->left != NULL)
            queue.push_back(n->left);
        if (n->right != NULL)
            queue.push_back(n->right);
    }
}

void Pre(node *n)
{
    if (n != NULL)
    {
        std::cout << n->val << "  ";
        Pre(n->left);
        Pre(n->right);
    }
}

void In(node *n)
{
    if (n != NULL)
    {
        In(n->left);
        std::cout << n->val << "  ";
        In(n->right);
    }
}

void Post(node *n)
{
    if (n != NULL)
    {
        Post(n->left);
        Post(n->right);
        std::cout << n->val << "  ";
    }
}

int main()
{
    int value;
    int ch;
    node *root = new node;
    std::cout << std::endl << "Enter the value of root node :";
    std::cin >> value;
    root->val = value;
    root->left = NULL;
    root->right = NULL;
    do
    {
        std::cout << std::endl << "1. Insert";
        std::cout << std::endl << "2. Breadth First";
        std::cout << std::endl << "3. Preorder Depth First";
        std::cout << std::endl << "4. Inorder Depth First";
        std::cout << std::endl << "5. Postorder Depth First";

        std::cout << std::endl << "Enter Your Choice : ";
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            int x;
            char pos;
            std::cout << std::endl << "Enter the value to be Inserted : ";
            std::cin >> x;
            std::cout << std::endl << "Left or Right of Root : ";
            std::cin >> pos;
            if (pos == 'l')
                CreateTree(root, root->left, x, pos);
            else if (pos == 'r')
                CreateTree(root, root->right, x, pos);
            break;
        case 2:
            BFT(root);
            break;
        case 3:
            Pre(root);
            break;
        case 4:
            In(root);
            break;
        case 5:
            Post(root);
            break;
        }
    } while (ch != 0);
}
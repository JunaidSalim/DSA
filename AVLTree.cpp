#include <iostream>
using namespace std;

class AVLTree
{
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        int height;
    };

public:
    Node *root;
    AVLTree()
    {
        root = NULL;
    }
    typedef struct Node *Position;
    typedef struct Node *Tree;
    int height(Position p)
    {
        if (p == NULL)
        {
            return -1;
        }
        else
        {
            return p->height;
        }
    }
    Position single_rotation_l(Position r)
    {
        Position r2;
        r2 = r->left;
        r->left = r2->right;
        r2->right = r;
        r->height = max(height(r->left), height(r->right)) + 1;
        r2->height = max(height(r2->left), height(r)) + 1;
        return r2;
    }

    Position double_rotation_l(Position r)
    {
        r->left = single_rotation_r(r->left);
        return single_rotation_l(r);
    }

    Position single_rotation_r(Position r)
    {
        Position r2;
        r2 = r->right;
        r->right = r2->left;
        r2->left = r;
        r->height = max(height(r->left), height(r->left)) + 1;
        r2->height = max(height(r2->right), r->height) + 1;
        return r2;
    }

    Position double_rotation_r(Position r)
    {
        r->right = single_rotation_l(r->right);
        return single_rotation_r(r);
    }
    int max(int n1, int n2)
    {
        return n1 > n2 ? n1 : n2;
    }
    Tree insert(int val, Tree r)
    {
        if (r == NULL)
        {
            r = new Node;
            r->left = r->right = NULL;
            r->data = val;
            r->height = 0;
        }
        else if (val < r->data)
        {
            r->left = insert(val, r->left);
            if (height(r->left) - height(r->right) == 2)
            {
                if (val < r->left->data)
                {
                    r = single_rotation_l(r);
                }
                else
                {
                    r = double_rotation_l(r);
                }
            }
        }
        else if (val > r->data)
        {
            r->right = insert(val, r->left);
            if (height(r->right) - height(r->left) == 2)
            {
                if (val > r->right->data)
                {
                    r = single_rotation_r(r);
                }
                else
                {
                    r = double_rotation_r(r);
                }
            }
        }
        r->height = max(height(r->left), height(r->right)) + 1;
        return r;
    }
    void display(Node *r)
    {
        display(r->left);
        cout << r->data << " ";
        display(r->right);
    }
};

int main()
{
    AVLTree tree;
    return 0;
}
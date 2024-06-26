#include <iostream>
#include <queue>
using namespace std;

class BSTree
{
    struct BSTNode
    {
        float data;
        BSTNode *left;
        BSTNode *right;
    };

public:
    BSTNode *root;
    BSTree()
    {
        root = NULL;
    }
    void insert(float val)
    {
        BSTNode *newNode = new BSTNode;
        newNode->data = val;
        newNode->right = newNode->left = NULL;
        if (!root)
        {
            root = newNode;
        }
        else
        {
            BSTNode *parent = nullptr;
            BSTNode *current = root;

            while (current != nullptr)
            {
                parent = current;
                if (val > current->data)
                {
                    current = current->right;
                }
                else if (val < current->data)
                {
                    current = current->left;
                }
                else
                {
                    cout << "\nDuplicate Found";
                    return;
                }
            }

            if (val > parent->data)
            {
                parent->right = newNode;
            }
            else
            {
                parent->left = newNode;
            }
        }
    }
    void search(int val)
    {
        BSTNode *current = root;
        if (root == NULL)
        {
            cout << "\nNot Fond. Tree is empty";
        }

        while (current != NULL)
        {
            if (val > current->data)
            {
                current = current->right;
            }
            else if (val < current->data)
            {
                current = current->left;
            }
            else
            {
                cout << "\nValue is in Tree";
                return;
            }
        }
        cout << "\nNot Found";
    }
   
    void makedeletion(BSTNode *&node)
    {
        BSTNode *temp;
        if (node == NULL)
        {
            return;
        }
        else if (node->left == NULL)
        {
            temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == NULL)
        {
            temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            temp = node->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            temp->left = node->left;
            temp = node;
            node = node->right;
            delete temp;
        }
    }
    void deleteNode(BSTNode *&node, int num)
    {
        if (num < node->data)
        {
            deleteNode(node->left, num);
        }
        else if (num > node->data)
        {
            deleteNode(node->right, num);
        }
        else
        {
            makedeletion(node);
        }
    }
    void level_display(BSTNode *r)
    {
        if (!r)
        {
            return;
        }
        queue<BSTNode *> q;
        q.push(r);
        q.push(NULL);
        while (!q.empty())
        {
            BSTNode *node = q.front();
            q.pop();
            if (node != NULL)
            {
                cout << node->data << " ";
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            else if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
    int sumAtK(BSTNode *r, int k)
    {
        if (!r)
        {
            return -1;
        }
        queue<BSTNode *> q;
        q.push(r);
        q.push(NULL);
        int level = 0, sum = 0;
        while (!q.empty())
        {
            BSTNode *node = q.front();
            q.pop();
            if (node)
            {
                if (level == k)
                {
                    sum += node->data;
                }
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            else if (!q.empty())
            {
                q.push(NULL);
                level++;
            }
        }
        return sum;
    }
    void display(BSTNode *rt)
    {
        if (rt != NULL)
        {
            display(rt->left);
            cout << rt->data << " ";
            display(rt->right);
        }
        else
        {
            return;
        }
    }
    void print(BSTNode *r)
    {
        BSTNode *temp = r;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->right;
        }
        recursive_print(r->left, r->right->left);
    }
    int countNodes(BSTNode *r)
    {
        if (r == NULL)
        {
            return 0;
        }
        return countNodes(r->left) + countNodes(r->right) + 1;
    }
    int sumNodes(BSTNode *r)
    {
        if (r == NULL)
        {
            return 0;
        }
        return sumNodes(r->left) + sumNodes(r->right) + r->data;
    }
    int calcHeight(BSTNode *r)
    {
        if (!r)
        {
            return 0;
        }
        int lheight = calcHeight(r->left);
        int rheight = calcHeight(r->right);
        return max(lheight, rheight) + 1;
    }
    int calcDiameter(BSTNode *r)
    {
        if (!r)
        {
            return 0;
        }
        int lheight = calcHeight(r->left);
        int rheight = calcHeight(r->right);
        int current_diameter = lheight + rheight + 1;
        int ldiameter = calcDiameter(r->left);
        int rdiameter = calcDiameter(r->right);
        return max(current_diameter, max(ldiameter, rdiameter));
    }
    int optimized_calc_diameter(BSTNode *r, int *height)
    {
        if (!r)
        {
            *height = 0;
            return 0;
        }
        int lh = 0, rh = 0;
        int ld = optimized_calc_diameter(r->left, &lh);
        int rd = optimized_calc_diameter(r->right, &rh);

        int cd = lh + rh + 1;
        *height = max(lh, rh) + 1;
        return max(cd, max(ld, rd));
    }
    void sumReplace(BSTNode *r)
    {
        if (!r)
        {
            return;
        }
        sumReplace(r->left);
        sumReplace(r->right);
        if (r->left)
        {
            r->data += r->left->data;
        }
        if (r->right)
        {
            r->data += r->right->data;
        }
    }
    void recursive_print(BSTNode *l, BSTNode *r)
    {
        if (l && r)
        {
            BSTNode *temp1 = l;
            BSTNode *temp2 = r;
            while (temp1 != NULL)
            {
                cout << temp1->data << " ";
                temp1 = temp1->right;
            }
            while (temp2 != NULL)
            {
                cout << temp2->data << " ";
                temp2 = temp2->right;
            }
            recursive_print(l->left, r->left);
        }
        else
        {
            if (l)
            {
                BSTNode *temp = l;
                while (temp)
                {
                    cout << temp->data << " ";
                    temp = temp->right;
                }
                recursive_print(l->left, r);
            }
            else if (r)
            {
                BSTNode *temp = r;
                while (temp)
                {
                    cout << temp->data << " ";
                    temp = temp->right;
                }
                recursive_print(l, r->left);
            }
            return;
        }
    }
};

int main()
{
    system("cls");
    BSTree tree;
}


#include <iostream>
using namespace std;

class LinkList
{
    struct Node
    {
        int data;
        Node *next;
    };

public:
    Node *head;
    LinkList()
    {
        head = NULL;
    }
    void add(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }
    void display()
    {
        Node *temp = head;
        cout << "\nLink List Elements: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    Node *merge(Node *left, Node *right)
    {
        Node *result = NULL;
        if (!left)
        {
            return right;
        }
        if (!right)
        {
            return left;
        }

        if (left->data <= right->data)
        {
            result = left;
            result->next = merge(left->next, right);
        }
        else
        {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }
    void mergeSort(Node *node)
    {
        if (!node || !node->next)
        {
            return;
        }
        Node *slow = node;
        Node *fast = node->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *left = node;
        Node *right = slow->next;
        slow->next = NULL;

        mergeSort(left);
        mergeSort(right);
        node = merge(left, right);
    }
};

int main()
{
    LinkList list;
}
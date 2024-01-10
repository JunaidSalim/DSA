#include <iostream>
using namespace std;

class DoublyLinkList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    };
    Node *head;

public:
    DoublyLinkList()
    {
        head = NULL;
    }
    void addNodeAtHead(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        if (!head)
        {
            newNode->prev = NULL;
        }
        else
        {
            head->prev = newNode;
            newNode->prev = NULL;
        }
        head = newNode;
    }
    void addNodeAtTail(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (!this->head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void deleteAtHead()
    {
        if (!head)
        {
            cout << "\nEmpty Link List";
            return;
        }
        Node *temp = head;
        if (head->next == NULL)
        {
            head = NULL;
            delete temp;
            return;
        }
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    void deleteAtVal(int val)
    {
        if (!head)
        {
            cout << "\nEmpty Link List";
        }
        Node *temp = head;
        Node *temp2 = head;
        while (temp != NULL && temp->data != val)
        {
            temp2 = temp;
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "\nValue Not Found In Link List";
            return;
        }
        if (temp == head)
        {
            if (head->next != NULL)
            {
                head = head->next;
                head->prev = NULL;
            }
            else
            {
                head = NULL;
            }
            delete temp;
            return;
        }
        if (temp->next == NULL)
        {
            temp2->next = NULL;
            delete temp;
            return;
        }
        temp2->next = temp->next;
        temp->next->prev = temp2;
        delete temp;
    }
    void deleteAtTail()
    {
        if (!head)
        {
            cout << "\nEmpty Link List";
            return;
        }
        Node *temp = head;
        Node *temp2 = head;
        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            head = NULL;
            delete temp;
            return;
        }
        temp2->next = NULL;
        delete temp;
    }
    void print()
    {
        if (!head)
        {
            cout << "\nEmpty Link List";
            return;
        }
        Node *temp = this->head;
        cout << "\nLink List elements are: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void reverseLinkList()
    {
        Node *temp = head;
        Node *current = head;
        while (temp != NULL)
        {
            current = temp->prev;
            temp->prev = temp->next;
            temp->next = current;
            temp = temp->prev;
        }
        head = current->prev;
    }
    void printInBothWays()
    {
        if (!head)
        {
            cout << "\nEmpty Link List";
            return;
        }
        Node *temp = head;
        Node *temp2 = head;
        cout << "\nLink List elements are: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp2 = temp;
            temp = temp->next;
        }
        cout << "\nLink List elements in Reverse Order are: ";
        while (temp2 != NULL)
        {
            cout << temp2->data << " ";
            temp2 = temp2->prev;
        }
    }

    void BubbleSort()
    {
        Node *temp = this->head;
        Node *temp2 = this->head;
        while (temp != NULL)
        {
            temp2 = head;
            while (temp2 != NULL)
            {
                if (temp->data < temp2->data)
                {
                    int val;
                    val = temp->data;
                    temp->data = temp2->data;
                    temp2->data = val;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    DoublyLinkList list;
    return 0;
}
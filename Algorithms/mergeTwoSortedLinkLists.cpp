#include <iostream>
using namespace std;

class LinkList
{
public:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *ListHeadptr;

    LinkList()
    {
        ListHeadptr = NULL;
    }
    void add(int newData)
    {
        Node *newNodeptr = new Node;
        newNodeptr->data = newData;
        newNodeptr->next = NULL;
        Node *tempptr = ListHeadptr;
        if (ListHeadptr == NULL)
        {
            ListHeadptr = newNodeptr;
        }
        else
        {
            while (tempptr->next != NULL)
            {
                tempptr = tempptr->next;
            }
            tempptr->next = newNodeptr;
        }
    }

    void remove(int newData)
    {
        Node *ptrCurrent = ListHeadptr, *ptrPrevious;
        if (ListHeadptr == NULL)
        {
            cout << "\nNo NODE to remove!";
        }
        else
        {
            while (ptrCurrent != NULL && ptrCurrent->data != newData)
            {
                ptrPrevious = ptrCurrent;
                ptrCurrent = ptrCurrent->next;
            }
            if (ptrCurrent == NULL)
            {
                cout << "\nNode Not Found!";
            }
            else
            {
                if (ptrCurrent == ListHeadptr)
                {
                    ListHeadptr = ListHeadptr->next;
                }
                else
                {
                    ptrPrevious->next = ptrCurrent->next;
                }
            }
        }
    }

    void display()
    {
        Node *currentptr = ListHeadptr;
        cout << "\nData in Linked List is: ";
        while (currentptr != NULL)
        {
            cout << currentptr->data << " ";
            currentptr = currentptr->next;
        }
    }
};

LinkList mergeLinkList(LinkList &list1, LinkList &list2)
{
    LinkList mergeList;
    LinkList::Node *list1ptr = list1.ListHeadptr;
    LinkList::Node *list2ptr = list2.ListHeadptr;
    while (list1ptr != NULL && list2ptr != NULL)
    {
        if (list1ptr->data < list2ptr->data)
        {
            mergeList.add(list1ptr->data);
            list1ptr = list1ptr->next;
        }
        else
        {
            mergeList.add(list2ptr->data);
            list2ptr = list2ptr->next;
        }
    }
    while (list1ptr != NULL)
    {
        mergeList.add(list1ptr->data);
        list1ptr = list1ptr->next;
    }
    while (list2ptr != NULL)
    {
        mergeList.add(list2ptr->data);
        list2ptr = list2ptr->next;
    }

    return mergeList;
}

int main()
{
    LinkList list1, list2, mergeList;

    return 0;
}
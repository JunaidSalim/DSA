#include <iostream>
#include <list>
using namespace std;

list<int> Union(list<int> &l1, list<int> &l2)
{
    list<int> l3;
    auto it1 = l1.begin();
    auto it2 = l2.begin();

    while (it1 != l1.end() && it2 != l2.end())
    {
        if (*it1 < *it2)
        {
            l3.push_back(*it1);
            ++it1;
        }
        else if (*it1 > *it2)
        {
            l3.push_back(*it2);
            ++it2;
        }
        else
        {
            l3.push_back(*it1);
            ++it1;
            ++it2;
        }
    }

    while (it1 != l1.end())
    {
        l3.push_back(*it1);
        ++it1;
    }

    while (it2 != l2.end())
    {
        l3.push_back(*it2);
        ++it2;
    }

    return l3;
}

list<int> Intersection(list<int> l1, list<int> l2)
{
    auto i1 = l1.begin();
    auto i2 = l2.begin();
    list<int> l3;

    while (i1 != l1.end() && i2 != l2.end())
    {
        if (*i1 == *i2)
        {
            l3.push_back(*i1);
            ++i1;
            ++i2;
        }
        else if (*i1 < *i2)
        {
            ++i1;
        }
        else
        {
            ++i2;
        }
    }

    return l3;
}
void display(list<int> l)
{
    cout << endl;
    for (auto &&i : l)
    {
        cout << i << " ";
    }
}
int main()
{
    list<int> list1;
    list<int> list2;
    return 0;
}
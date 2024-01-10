#include <iostream>
#include <vector>
using namespace std;

vector<bool> Union(vector<bool> v1, vector<bool> v2)
{
    vector<bool> result;
    for (int i = 0; i < v1.size(); i++)
    {
        result.push_back((v1[i] || v2[i]));
    }
    return result;
}
vector<bool> Intersection(vector<bool> v1, vector<bool> v2)
{
    vector<bool> result;
    for (int i = 0; i < v1.size(); i++)
    {
        result.push_back((v1[i] && v2[i]));
    }
    return result;
}

void display(vector<bool> v)
{
    cout << endl;

    for (auto &&i : v)
    {
        cout << i << "\t";
    }
}

int main()
{
    vector<bool> v1{1, 0, 1, 1, 0, 1, 1};
    vector<bool> v2{1, 1, 1, 1, 0, 0, 0};
    return 0;
}
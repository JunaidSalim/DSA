#include <iostream>
using namespace std;

class Trie
{
    struct Node
    {
        Node *links[26];
        bool flag;
        bool inTrie(char c)
        {
            return (links[c - 'a'] != NULL);
        }
    };
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *temp = root;
        int length = word.length();
        for (int i = 0; i < length; i++)
        {
            if (!temp->inTrie(word[i]))
            {
                temp->links[word[i] - 'a'] = new Node();
            }
            temp = temp->links[word[i] - 'a'];
        }
        temp->flag = true;
    }
    bool search(string word)
    {
        Node *temp = root;
        int length = word.length();
        for (int i = 0; i < length; i++)
        {
            if (!temp->inTrie(word[i]))
            {
                return false;
            }
            temp = temp->links[word[i] - 'a'];
        }
        return temp->flag;
    }
    bool startWith(char check)
    {
        return root->inTrie(check);
    }
};

int main()
{
    Trie tree;
    return 0;
}
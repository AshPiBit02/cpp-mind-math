#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node *next,*random;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
        random=nullptr;
    }
};
Node* copyRandomList(Node* head)
{
    if(!head) return NULL;
    unordered_map<Node*,Node*>mp;
    Node* curr=head;
    //Create copy of each node and store in map
    while(curr)
    {
        mp[curr]=new Node(curr->data);
        curr=curr->next;
    }
    //Assign next and random pointers
    curr=head;
    while(curr)
    {
        mp[curr]->next=mp[curr->next];
        mp[curr]->random=mp[curr->random];
        curr=curr->next;
    }
    return mp[head];
}
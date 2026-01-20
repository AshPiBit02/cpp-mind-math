//Flatten Mulit-level doubly linked list
#include<iostream>
using namespace std;
class Node
{
    public:
    Node *next,*prev,*child;
    int data;
    Node(int data)
    {
        this->data=data;
        next=prev=child=nullptr;
    }
};
class DLL
{
    Node* flatten(Node* head)
    {
        if(head==nullptr)
        {
            return head;
        }
        Node* curr=head;
        while(curr!=nullptr)
        {
            if(curr->child!=nullptr)
            {
                //flatten the child node
                Node* temp=curr->next;
                curr->next=flatten(curr->child);
                curr->next->prev=curr;//doubly link between child and parent
                curr->child=nullptr;
                //find tail
                while(curr->next!=nullptr)
                {
                    curr=curr->next;
                }
                if(temp!=nullptr)
                {
                    curr->next=temp;//doubly link with the child's last node with it's parent next node;
                    temp->prev=curr;
                }
            }
            curr=curr->next;//if no child 
        }
        return head;
    }
};
int main()
{
    return 0;
}
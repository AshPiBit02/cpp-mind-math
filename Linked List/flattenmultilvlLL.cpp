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
    if(head == nullptr)
    {
        return head;
    }

    Node* curr = head;

    while(curr != nullptr)
    {
        if(curr->child != nullptr)
        {
            Node* temp=curr->next;
            //Flatten the child list
            Node* childHead=flatten(curr->child);
            // Attach child
            curr->next=childHead;
            childHead->prev=curr;
            curr->child=nullptr;
            //Find tail of child list
            Node* tail=childHead;
            while(tail->next!=nullptr)
            {
                tail=tail->next;
            }
            // Reattach the saved next
            if(temp!=nullptr)
            {
                tail->next=temp;
                temp->prev=tail;
            }
        }
        curr=curr->next;
    }

    return head;
}

};
int main()
{
    return 0;
}
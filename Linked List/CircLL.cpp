#include<iostream>
using namespace std;
class Node
{
    public:
    Node* next;
    int data;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};
class CLL
{
    public:
    Node* head,*tail;
    CLL()
    {
        head=tail=nullptr;
    }
    bool isempty()
    {
        return head==nullptr;
    }
    void push_front(int data)
    {
        Node* newNode=new Node(data);
        if(isempty())
        {
            head=tail=newNode;
            tail->next=head;
        }
        else
        {
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
        cout<<data<<" Pushed to front"<<endl;
    }
    void push_back(int data)
    {
        Node* newNode =new Node(data);
        if(isempty())
        {
            head=tail=newNode;
            tail->next=head;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
            tail->next=head;
        }
        cout<<data<<" pushed to back"<<endl;
    }
    void pop_front()
    {
        if(isempty())
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        Node* temp=head;
        if(head==tail)
        {
            head=tail=nullptr;
        }
        else
        {
            head=head->next;
            tail->next=head;
        }
        cout<<temp->data<<" popped from front"<<endl;
        delete temp;
    }
    void pop_back()
    {
        if(isempty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=tail;
        if(head==tail)
        {
            head=tail=nullptr;
        }
        else
        {
           while(temp->next!=tail)
           {
            temp=temp->next;
           } 
           tail=temp;
           tail->next=head;
        }
        cout<<temp->data<<" popped from back"<<endl;
        delete temp;
    }

};
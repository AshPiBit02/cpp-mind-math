#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next,*prev;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
        prev=nullptr;
    }
};
class DLL
{
    public:
    Node *head,*tail;
    DLL()
    {
        head=tail=nullptr;
    }
    bool isempty()
    {
        return head==nullptr;
    }
    void push_head(int data)
    {
        Node* newNode= new Node(data);
        if(isempty())
        {
            head=tail=newNode;
            tail->next=nullptr;
            head->prev=nullptr;        
        }
        else
        {
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
            head->prev=nullptr;
        }
        cout<<data<<" pushed to head"<<endl;
    }
    void push_tail(int data)
    {
        Node* newNode=new Node(data);
        if(isempty())
        {
            head=tail=newNode;
            tail->next=nullptr;
            head->prev=nullptr;
        }
        else
        {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
            tail->next=nullptr;
        }
    }
    void pop_head()
    {
        if(isempty())
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        Node* temp=head;
        if(head==tail)
        {
            head=tail=nullptr;
        }else
        {
            head=temp->next;
            head->prev=nullptr;
        }
        cout<<temp->data<<" poped from head"<<endl;
        delete temp;
    }
    void pop_tail()
    {
        if(isempty())
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        Node* temp=tail;
        if(head==tail)
        {
            tail=head=nullptr;
        }
        else
        {
            tail=temp->prev;
            tail->next=nullptr;
        }
        cout<<temp->data<<" poped from tail"<<endl;
        delete temp;
    }
    void traverseListF()
    {
        if(isempty())
        {
            cout<<"List is emtpy"<<endl;
            return;
        }
        Node* temp=head;
        cout<<"\nNULL";
        while(temp!=nullptr)
        {
            cout<<"temp->data"<<" <-> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void traverseListB()
    {
        if(isempty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=tail;
        cout<<"\nNULL";
        while(temp!=nullptr)
        {
            cout<<temp->data<<" <-> ";
            temp=temp->prev;
        }
        cout<<"NULL"<<endl;
    }

};
int main()
{
    return 0;
}
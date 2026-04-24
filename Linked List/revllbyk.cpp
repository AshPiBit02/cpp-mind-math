#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node
{
    public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};
class LL
{
    public:
    Node *head,*tail;
    LL()
    {
        head=tail=nullptr;
    }
    bool isempty()
    {
        return head==nullptr;
    }
    void push_back(int data)
    {
        Node *newNode=new Node(data);
        if(isempty())
        {
            head=tail=newNode;
        }else
        {
            tail->next=newNode;
            tail=newNode;
            tail->next=nullptr;
        }
        cout<<data<<" pushed to back"<<endl;
    }
    void traverse()
    {
        if(isempty())
        {
            cout<<"LL is empty!"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void reverse(int k,Node* i,Node* j)
    {
        
    }
};
int main()
{
    LL l;
    for(int i=1;i<=8;i++)
    {
        l.push_back(i);
    }
    l.traverse();
}
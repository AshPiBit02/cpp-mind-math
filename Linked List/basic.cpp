#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};
class linkedList
{
    public:
    Node* head,*tail;
    linkedList()
    {
        head=tail=nullptr;
    }
    bool isempty()
    {
        return head==nullptr;
    }
    void push_front(int data)
    {
        Node* newNode= new Node(data);
        if(isempty())
        {
            head=tail=newNode;
            tail->next=nullptr;
        }else
        {
            newNode->next=head;
            head=newNode;
        }
        cout<<data<<" Pushed to front"<<endl;
    }
    void push_back(int data)
    {
        Node* newNode=new Node(data);
        if(isempty())
        {
            head=tail=newNode;
            tail->next=nullptr;
        }else
        {
            tail->next=newNode;
            tail=newNode;
            tail->next=nullptr;
        }
        cout<<data<<" Pushed to back"<<endl;
    }
    void pop_front()
    {
        if(isempty())
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        if(head==tail)
        {
            delete head;
            head=tail=nullptr;
            return ;
        }
        Node* temp=head;
        head=temp->next;
        delete temp;
    }
    void pop_back()
    {
        if(isempty())
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        if(head==tail)
        {
            delete head;
            head=tail=nullptr;
            return;
        }
        Node* temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=nullptr;
    }
    void traverseList()
    {
        if(isempty())
        {
            cout<<"List is empty!"<<endl;
        }
        Node* temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

};
int main()
{
    linkedList ll;
    cout<<ll.isempty()<<endl;
    ll.push_front(30);
    ll.push_front(40);
    ll.push_front(50);
    ll.push_back(20);
    ll.push_back(10);
    ll.traverseList();
    ll.pop_back();
    ll.traverseList();
    ll.pop_front();
    ll.traverseList();
    ll.pop_back();
    cout<<ll.isempty();
    return 0;
}
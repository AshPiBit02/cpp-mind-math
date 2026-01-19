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
class List
{
    public:
    Node* head,*tail;
    List()
    {
        head=tail=nullptr;
    }
    void push_back(int data)
    {
        Node* newNode=new Node(data);
        if(head==nullptr)
        {
            head=tail=newNode;
            tail->next=nullptr;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }
    void displayLL()
    {
        if(head==nullptr)
        {
            cout<<"Empty List!"<<endl;
            return ;
        }
        Node *temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
List sortedMerged(List& l1,List& l2)
{
    List result;
    Node* ptr1 = l1.head;
    Node* ptr2 = l2.head;

    while(ptr1 != nullptr && ptr2 != nullptr)
    {
        if(ptr1->data <= ptr2->data)
        {
            result.push_back(ptr1->data);
            ptr1 = ptr1->next;
        }
        else
        {
            result.push_back(ptr2->data);
            ptr2 = ptr2->next;
        }
    }

    while(ptr1 != nullptr)
    {
        result.push_back(ptr1->data);
        ptr1 = ptr1->next;
    }

    while(ptr2 != nullptr)
    {
        result.push_back(ptr2->data);
        ptr2 = ptr2->next;
    }

    return result;
}
int main()
{
    List l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(40);
    l1.push_back(50);
    l1.displayLL();
    List l2;
    l2.push_back(15);
    l2.push_back(21);
    l2.push_back(30);
    l2.push_back(90);
    l2.displayLL();
    List merge=sortedMerged(l1,l2);
    merge.displayLL();
    return 0;

}

//This program uses circular linked list to solve josephus problemq1q
#include<iostream>
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
class CircularLL
{
    public:
    Node *head,*tail;
    CircularLL()
    {
        head=tail=nullptr;
    }
    void Insert(int item,int n)
    {
        for(int i=item;i<=n;i++)
        {
            Node* newNode=new Node(i);
            if(head==nullptr)
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
        }
    }
    void displayLL(int n)
    {
        Node* temp=head->next;
        cout<<head->data;
        while(temp!=head)
        {
            cout<<" --> "<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
    }
    void Execute(int count,int n)
    {
        int conqueror;
        Node* current=head;
        Node* target=head->next;
        cout<<"War Begins....."<<endl;
        while(count>1)
        {
            if(current->data==0)
            {
                while(current->data==0)
                {
                    current=current->next;
                }
                target=current->next;
            }
            else
            {
                conqueror=current->data;
                while(target->data==0)
                {
                    target=target->next;
                }
                target->data=0;
                displayLL(n);
                count--;
                current=target->next;
                target=current->next;
            }

        }
        cout<<"The Conqueror is Warrior: "<<conqueror<<endl;

    }
};
int main()
{
    CircularLL CLL;
    int n;
    cout<<"Enter number of warriors: ";
    cin>>n;
    CLL.Insert(1,n);
    cout<<"Ready Warriors....."<<endl;
    CLL.displayLL(n);
    CLL.Execute(n,n);
    return 0;
}

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
    int llsize=0;
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
        llsize++;
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
        llsize++;
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
        }else
        {
            Node* temp=head;
            head=temp->next;
            delete temp;
        }
        llsize--;
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
        }else
        {
            Node* temp=head;
            while(temp->next!=tail)
            {
                temp=temp->next;
            }
            delete tail;
            tail=temp;
            tail->next=nullptr;
        }
        llsize--;
    }
    void insertAt(int data, int pos)
    {
        if(pos>llsize+1 || pos<1)
        {
            cout<<"Position out of bound!"<<endl;
            return;
        }
        if(pos==1)
        {
            push_front(data);
            return;
        }else if(pos==llsize+1)
        {
            push_back(data);
            return;
        }
        Node* newNode=new Node(data);
            Node* temp=head;
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        cout<<data<<" inserted at position "<<pos<<endl;
        llsize++;
    }
    void reverseLL()
    {
        if(isempty() || head==tail)
        {
            return;
        }
        Node *prev=nullptr;
        Node *current=head;
        Node *next=nullptr;
        tail=head;//head becomes tail
        while(current!=nullptr)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;//prev becomes head(i.e. tail now becomes head)
        cout<<"Linked list reversed"<<endl;
    }
    void search(int data)
    {
        if(isempty())
        {
            cout<<data<<" doesn't exists!"<<endl;
            return;
        }
        int pos=1;
        Node* temp=head;
        while(temp!=nullptr)
        {
            if(temp->data==data)
            {
                cout<<data<<" found at position "<<pos<<endl;
                return;
            }
            temp=temp->next;
            pos++;
        }
        cout<<data<<" not found!"<<endl;
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
    // ll.insertAt(60,5);
    // ll.traverseList();
    // ll.pop_back();
    // ll.traverseList();
    // ll.pop_front();
    // ll.traverseList();
    // ll.pop_back();
    // ll.search(40);
    // ll.search(70);
    ll.reverseLL();
    ll.traverseList();
    return 0;
}
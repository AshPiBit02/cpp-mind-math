#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class List
{
public:
    Node* head;
    List() { head = nullptr; }

    void push_back(int data)
    {
        Node* newNode = new Node(data);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void printList()
    {
        Node* temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Void function to reverse in k-groups
    void reverseKGroup(int k)
    {
        head = reverseKGroupUtil(head, k);
    }

private:
    Node* reverseKGroupUtil(Node* curr, int k)
    {
        Node* temp = curr;
        int count = 0;

        // Check if k nodes exist
        while (count < k)
        {
            if (!temp) return curr; // Less than k nodes left
            temp = temp->next;
            count++;
        }

        // Reverse k nodes
        Node* prev = reverseKGroupUtil(temp, k); // Recursive reverse of rest
        Node* node = curr;
        count = 0;
        while (count < k)
        {
            Node* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
            count++;
        }

        return prev; // New head of this group
    }
};

int main()
{
    List l;
    for (int i = 1; i <= 6; i++) l.push_back(i);

    cout << "Original List: ";
    l.printList();

    l.reverseKGroup(2);

    cout << "Reversed in groups of 2: ";
    l.printList();

    return 0;
}

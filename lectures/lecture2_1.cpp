#include <iostream>
using namespace std;

class LinkedList {    // LinkedList class
private:

    class Node {       // Node class
    public:
        int data;
        Node* next;

        Node(int value) {    // Constructor of Node
            data = value;
            next = nullptr;
        }
    };

    Node* head;             // Attribute of LinkedList

public:

    // Constructor of LinkedList class
    LinkedList() {
        head = nullptr;
    }

    // Checks if LinkedList is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Insert at beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    // Insert at tail of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        // If the list is empty
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Start from the first node
        Node* current = head;

        // Go to the last node
        while (current->next != nullptr) {
            current = current->next;
        }

        // Add the new node at the end
        current->next = newNode;
    }

    void display(){
        if(isEmpty()){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};                     


int main() {
    LinkedList list;

    // Insert elements
    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);
    cout << "After inserting at the beginning: ";
    list.display();

    list.insertAtEnd(40);
    list.insertAtEnd(50);
    cout << "After inserting at the end: ";
    list.display();

    list.insertAfter(30, 35);
    list.insertAfter(50, 55);
    cout << "After inserting after specific nodes: ";
    list.display();

    // Deletion operations
    list.deleteFirst();
    cout << "After deleting first node: ";
    list.display();

    list.deleteAt(2);
    cout << "After deleting node at index 2: ";
    list.display();

    list.deleteLast();
    cout << "After deleting last node: ";
    list.display();

    // Traverse
    list.traverse();

    return 0;
}
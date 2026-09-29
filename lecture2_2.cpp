#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr; // list starts empty
    }

    ~LinkedList() {
        Node* current = head; // start from the first node

        while (current != nullptr) {
            Node* temp = current; // save the current node
            current = current->next; // move to the next node
            delete temp; // delete the old node from memory
        }

        head = nullptr;
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value); // create a new node in memory

        newNode->next = head; // new node points to the old first node
        head = newNode; // head points to the new node
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value); // create a new node in memory

        if (head == nullptr) { // check if the list is empty
            head = newNode; // make head point to the new node
            return;
        }

        Node* current = head; // start from the first node

        while (current->next != nullptr) { // check if another node exists
            current = current->next; // move to the next node
        }

        current->next = newNode; // last node points to the new node
    }

    bool deleteValue(int value) {
        if (head == nullptr) { // check if the list is empty
            return false;
        }

        if (head->data == value) { // check if the value is in the first node
            Node* temp = head; // save the node we want to delete
            head = head->next; // move head to the next node
            delete temp; // delete the old node
            return true;
        }

        Node* current = head; // start from the first node

        while (current->next != nullptr && current->next->data != value) {
            current = current->next; // move to the next node
        }

        if (current->next == nullptr) { // value was not found
            return false;
        }

        Node* temp = current->next; // point to the node we want to delete
        current->next = temp->next; // connect the previous node to the next node
        delete temp; // delete the node from memory

        return true;
    }

    bool search(int value) {
        Node* current = head; // start from the first node

        while (current != nullptr) {
            if (current->data == value) { // check if the value is found
                return true;
            }

            current = current->next; // move to the next node
        }

        return false; // value was not found
    }

    int length() {
        int count = 0; // counter starts at 0
        Node* current = head; // start from the first node

        while (current != nullptr) {
            count++; // increase count
            current = current->next; // move to the next node
        }

        return count;
    }

    void reverse() {
        Node* previous = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* nextNode = current->next; // save the next node

            current->next = previous; // reverse the link

            previous = current;
            current = nextNode;
        }

        head = previous; // head points to the new first node
    }

    void print() {
        Node* current = head; // start from the first node

        while (current != nullptr) {
            cout << current->data << " -> "; // print the current value
            current = current->next; // move to the next node
        }

        cout << "null" << endl;
    }
};
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

class LinkedStr {
private:
    Node* ptr;

public:
    LinkedStr() : ptr(nullptr) {}

    // Destructor: Remove all nodes from dynamic memory
    ~LinkedStr() {
        while (ptr) {
            removeFirst();
        }
    }

    // Creating a linked list with n elements
    void makeStr(int len) {
        for (int i = len; i > 0; --i) {
            Node* newNode = new Node;
            newNode->info = i;
            newNode->next = ptr;
            ptr = newNode;
        }
    }

       // Display all elements of the linked structure
    void displayStr() {
        Node* current = ptr;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "\nValues in the linked list are: ";
        while (current) {
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Remove the first element
    void removeFirst() {
        if (!ptr) return;
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
    }

    // Remove the last element
    void removeLast() {
        if (!ptr) return; 
        if (!ptr->next) { 
            delete ptr;
            ptr = nullptr;
            return;
        }
        Node* current = ptr;
        while (current->next->next) {
            current = current->next;
        }
        delete current->next; // Delete the last node
        current->next = nullptr;
    }

    // Remove the first element with info field equal to k
    void remove(int k) {
        if (!ptr) return; // Do nothing if the list is empty
        if (ptr->info == k) { // If the first node matches
            removeFirst();
            return;
        }
        Node* current = ptr;
        while (current->next && current->next->info != k) {
            current = current->next;
        }
        if (current->next) { // If we found the node to delete
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }
};

// A Driver program to test the manual implementation of a linked list
int main() {
    int x;

    do {
        cout << "\nEnter the number of elements you want in the linked list, e.g.between(4-20): ";
        cin >> x;

    } while (x < 4 || x > 20);
    LinkedStr list;
    list.makeStr(x);
    list.displayStr();

    cout << "\nAfter removing first and last element:" << endl;
    list.removeFirst();
    list.removeLast();
    list.displayStr();

    cout << "\nAfter removing the 3 element:" << endl;
    list.remove(3);
    list.displayStr();

    return 0;
}

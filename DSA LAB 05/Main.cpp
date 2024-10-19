//#include <iostream>
//#include <conio.h>  // For getch()
//#include<iomanip>
// //manually implement stack using linked list
//using namespace std;
//
//template<class ItemType>
//class List {
//protected:
//    struct node {
//        ItemType info;
//        struct node* next; // Creating pointer to the next node
//    };
//    typedef struct node* NODEPTR;
//    NODEPTR listptr;
//
//public:
//    List();
//    ~List();
//    bool emptyList();
//    void insertafter(ItemType oldvalue, ItemType newvalue);
//    void deleteItem(ItemType oldvalue);
//    void push(ItemType newvalue);
//    ItemType pop();
//    void display(); // Function to display the list
//};
//
//// A Default Constructor
//template<class ItemType>
//List<ItemType>::List() {
//    listptr = nullptr;
//}
//
//// Destructor
//template<class ItemType>
//List<ItemType>::~List() {
//    NODEPTR p, q;
//    for (p = listptr; p != nullptr; ) {
//        q = p->next;
//        delete p;
//        p = q;
//    }
//}
//
////TO Check if the list is empty
//template<class ItemType>
//bool List<ItemType>::emptyList() {
//    return (listptr == nullptr);
//}
//
//// Insert after a specific value
//template<class ItemType>
//void List<ItemType>::insertafter(ItemType oldvalue, ItemType newvalue) {
//    NODEPTR p, q;
//    for (p = listptr; p != nullptr && p->info != oldvalue; p = p->next);
//
//    if (p == nullptr) {
//        cout << "ERROR: value sought is not in the list." << endl;
//        return;
//    }
//    q = new node;
//    q->info = newvalue;
//    q->next = p->next;
//    p->next = q;
//}
//
//// Push a new value to the front of the list
//template<class ItemType>
//void List<ItemType>::push(ItemType newvalue) {
//    NODEPTR p = new node;
//    p->info = newvalue;
//    p->next = listptr;
//    listptr = p;
//}
//
//// Delete an item from the list
//template<class ItemType>
//void List<ItemType>::deleteItem(ItemType oldvalue) {
//    NODEPTR p, q;
//    for (q = nullptr, p = listptr; p != nullptr && p->info != oldvalue; q = p, p = p->next);
//
//    if (p == nullptr) {
//        cout << "ERROR: value sought is not in the list." << endl;
//        return;
//    }
//    if (q == nullptr) {
//        listptr = p->next; // Deleting the head
//    }
//    else {
//        q->next = p->next;
//    }
//    delete p;
//}
//
//// Pop the first item from the list
//template<class ItemType>
//ItemType List<ItemType>::pop() {
//    NODEPTR p;
//    ItemType x;
//    if (emptyList()) {
//        cout << "ERROR: the list is empty." << endl;
//        exit(1);
//    }
//    p = listptr;
//    listptr = p->next;
//    x = p->info;
//    delete p;
//    return x;
//}
//
//// Display the entire list
//template<class ItemType>
//void List<ItemType>::display() {
//    NODEPTR p = listptr;
//    if (emptyList()) {
//        cout << "The list is empty." << endl;
//        return;
//    }
//    cout << "List contents: ";
//    while (p != nullptr) {
//        cout << p->info << " ";
//        p = p->next;
//    }
//    cout << endl;
//}
//
//
//int main() {
//    List<int> l;
//    int choice, value, newValue;
//    char continueChoice;
//
//    do {
//        cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n";
//        cout << "Menu:\n";
//        cout << "1. Push\n";
//        cout << "2. Pop\n";
//        cout << "3. Insert After\n";
//        cout << "4. Delete Item\n";
//        cout << "5. Display List\n";
//        cout << "6. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter value to push: ";
//            cin >> value;
//            l.push(value);
//            break;
//        case 2:
//            cout << "Popped value: " << l.pop() << endl;
//            break;
//        case 3:
//            cout << "Enter old value: ";
//            cin >> value;
//            cout << "Enter new value to insert: ";
//            cin >> newValue;
//            l.insertafter(value, newValue);
//            break;
//        case 4:
//            cout << "Enter value to delete: ";
//            cin >> value;
//            l.deleteItem(value);
//            break;
//        case 5:
//            l.display();
//            break;
//        case 6:
//            cout << "Exiting..." << endl;
//            return 0; // Exit the program
//        default:
//            cout << "Invalid choice. Please try again." << endl;
//        }
//        
//        // Ask if the user wants to continue or not..
//        cout << "\nDo you want to continue? (y/n): ";
//        cin >> continueChoice;
//        cin.ignore();      //to  Ignore the newline character in the input buffer 
//        
//    } while (continueChoice == 'y' || continueChoice == 'Y');
//
//    return 0;
//}

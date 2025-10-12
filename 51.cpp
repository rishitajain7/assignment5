#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;


void insertBegin(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}


void insertEnd(int value) {
    Node* newNode = new Node{value, NULL};
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}


void insertBefore(int value, int ref) {
    if (head == NULL || head->data == ref) {
        insertBegin(value);
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != ref)
        temp = temp->next;
    if (temp->next) {
        Node* newNode = new Node{value, temp->next};
        temp->next = newNode;
    }
}

void insertAfter(int value, int ref) {
    Node* temp = head;
    while (temp && temp->data != ref)
        temp = temp->next;
    if (temp) {
        Node* newNode = new Node{value, temp->next};
        temp->next = newNode;
    }
}


void deleteBegin() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}


void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}


void deleteNode(int value) {
    if (head == NULL) return;
    if (head->data == value) {
        deleteBegin();
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != value)
        temp = temp->next;
    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}


void searchNode(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found" << endl;
}


void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    int choice, value, ref;
    while (true) {
        cout << "\nMenu:\n"
             << "1. Insert at beginning\n"
             << "2. Insert at end\n"
             << "3. Insert before a node\n"
             << "4. Insert after a node\n"
             << "5. Delete from beginning\n"
             << "6. Delete from end\n"
             << "7. Delete a specific node\n"
             << "8. Search for a node\n"
             << "9. Display list\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                insertBegin(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter node value to insert before: ";
                cin >> ref;
                insertBefore(value, ref);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter node value to insert after: ";
                cin >> ref;
                insertAfter(value, ref);
                break;
            case 5:
                deleteBegin();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;
            case 9:
                display();
                break;
            case 0:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }

}

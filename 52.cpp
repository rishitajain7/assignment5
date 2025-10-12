#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertEnd(int value) {
    Node* newNode = new Node{value, NULL};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void countAndDelete(int key) {
    int count = 0;
    Node* temp = head;

    
    while (temp) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    
    while (head && head->data == key) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

   
    temp = head;
    while (temp && temp->next) {
        if (temp->next->data == key) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    display();
}

void display() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        insertEnd(arr[i]);

    int key = 1;
    cout << "Original Linked List: ";
    display();

    countAndDelete(key);
    return 0;
}

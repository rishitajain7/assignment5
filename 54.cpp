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

void reverseList() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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
    cout << "->NULL\n";
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        insertEnd(arr[i]);

    cout << "Original List: ";
    display();

    reverseList();

    cout << "Reversed List: ";
    display();

    return 0;
}

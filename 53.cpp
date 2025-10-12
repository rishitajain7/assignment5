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

int findMiddle() {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

void display() {
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
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        insertEnd(arr[i]);

    cout << "Linked List: ";
    display();

    cout << "Middle Element: " << findMiddle() << endl;

    return 0;
}

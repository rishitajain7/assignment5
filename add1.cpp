#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

int getLength(Node* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

Node* getIntersection(Node* head1, Node* head2){

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    Node* p1 = head1;
    Node* p2 = head2;

   
    if(len1 > len2){
        while(diff--) p1 = p1->next;
    } else {
        while(diff--) p2 = p2->next;
    }


    while(p1 != NULL && p2 != NULL){
        if(p1 == p2)     
            return p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL; 
}

int main(){
   
    Node* common = new Node(30);
    common->next = new Node(40);
    common->next->next = new Node(50);

    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = common;

    Node* head2 = new Node(5);
    head2->next = common;

    Node* ans = getIntersection(head1, head2);

    if(ans)
        cout << "Intersection at node: " << ans->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}

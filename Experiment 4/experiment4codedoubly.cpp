//Apply the concept of Linked list and write code to Insert and Delete an element at the beginning and atend in Doubly and Circular Linked List.

 



#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyList {
    Node* head;
public:
    DoublyList() {
        head = NULL;
    }

    void insertBegin(int val) {
        Node* temp = new Node;
        temp->data = val;
        temp->prev = NULL;
        temp->next = head;
        if (head != NULL)
            head->prev = temp;
        head = temp;
    }

    void insertEnd(int val) {
        Node* temp = new Node;
        temp->data = val;
        temp->next = NULL;
        if (head == NULL) {
            temp->prev = NULL;
            head = temp;
            return;
        }
        Node* cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = temp;
        temp->prev = cur;
    }

    void deleteBegin() {
        if (head == NULL)
            return;
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
    }

    void deleteEnd() {
        if (head == NULL)
            return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->prev->next = NULL;
        delete cur;
    }

    void display() {
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "Doubly Linked List Output:" << endl;
    DoublyList d;
    d.insertBegin(10);
    d.insertEnd(20);
    d.insertBegin(5);
    cout << "After insertions: ";
    d.display();
    d.deleteBegin();
    d.deleteEnd();
    cout << "After deletions: ";
    d.display();
    cout << endl;
    return 0;
}


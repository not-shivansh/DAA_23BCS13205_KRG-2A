//Apply the concept of Linked list and write code to Insert and Delete an element at the beginning and atend in Doubly and Circular Linked List.




#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularList {
    Node* last;
public:
    CircularList() {
        last = NULL;
    }

    void insertBegin(int val) {
        Node* temp = new Node;
        temp->data = val;
        if (last == NULL) {
            temp->next = temp;
            last = temp;
            return;
        }
        temp->next = last->next;
        last->next = temp;
    }

    void insertEnd(int val) {
        Node* temp = new Node;
        temp->data = val;
        if (last == NULL) {
            temp->next = temp;
            last = temp;
            return;
        }
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }

    void deleteBegin() {
        if (last == NULL)
            return;
        Node* temp = last->next;
        if (temp == last) {
            delete temp;
            last = NULL;
            return;
        }
        last->next = temp->next;
        delete temp;
    }

    void deleteEnd() {
        if (last == NULL)
            return;
        Node* cur = last->next;
        if (cur == last) {
            delete last;
            last = NULL;
            return;
        }
        while (cur->next != last)
            cur = cur->next;
        cur->next = last->next;
        delete last;
        last = cur;
    }

    void display() {
        if (last == NULL) {
            cout << endl;
            return;
        }
        Node* cur = last->next;
        do {
            cout << cur->data << " ";
            cur = cur->next;
        } while (cur != last->next);
        cout << endl;
    }
};

int main() {
    cout << "Circular Linked List Output:" << endl;
    CircularList c;
    c.insertBegin(10);
    c.insertEnd(20);
    c.insertBegin(5);
    cout << "After insertions: ";
    c.display();
    c.deleteBegin();
    c.deleteEnd();
    cout << "After deletions: ";
    c.display();
    return 0;
}

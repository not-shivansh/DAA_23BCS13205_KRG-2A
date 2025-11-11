// Analyze if the stack is empty or full, and if elements are present, return the top element in the stack using templates. Also, perform push and pop operations on the stack.

 


#include <iostream>

const int SIZE = 10;

template <class T>
class Stack {
    T arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SIZE - 1;
    }

    void push(T val) {
        if (!isFull()) {
            arr[++top] = val;
        }
    }

    void pop() {
        if (!isEmpty()) {
            --top;
        }
    }

    T peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return T();
    }
};

int main() {
    Stack<int> s;

    s.push(5);
    s.push(10);
    s.push(15);

    if (!s.isEmpty()) {
        std::cout << "Top: " << s.peek() << std::endl;
    }

    s.pop();

    if (!s.isEmpty()) {
        std::cout << "Top after pop: " << s.peek() << std::endl;
    }

    return 0;
}

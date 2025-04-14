#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
private:
    class Node {
    public:
        T data;
        Node *next;

        Node(const T &value, Node *next = nullptr) : data(value), next(next) {}
    };

    Node *top;
    int count;

public:
    Stack() : top(nullptr), count(0) {}

    ~Stack() {
        while (top != nullptr) {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(const T &value) {
        Node *newNode = new Node(value, top);
        top = newNode;
        count++;
    }

    bool pop(T &value) {
        if (isEmpty()) {
            return false;
        }
        value = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        count--;
        return true;
    }

    bool peek(T &value) const {
        if (isEmpty()) {
            return false;
        }
        value = top->data;
        return true;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int getSize() const {
        return count;
    }

    void print() const {
        Node *current = top;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

#endif // STACK_H

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Queue {
private:
    class Node {
    public:
        T data;
        Node *next;

        Node(const T &value, Node *next = nullptr) : data(value), next(next) {}
    };

    Node *front;
    Node *back;
    int count;

public:
    Queue() : front(nullptr), back(nullptr), count(0) {}

    ~Queue() {
        while (front != nullptr) {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    void push(const T &value) {
        Node *newNode = new Node(value);
        if (back == nullptr) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        count++;
    }

    bool pop(T &value) {
        if (front == nullptr) {
            return false;
        }
        value = front->data;
        Node *temp = front;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }
        delete temp;
        count--;
        return true;
    }

    bool peek(T &value) const {
        if (front == nullptr) {
            return false;
        }
        value = front->data;
        return true;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    int getSize() const {
        return count;
    }

    void print() const {
        Node *current = front;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

#endif // QUEUE_H

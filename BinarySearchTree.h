#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include "Vector.h"
using namespace std;

template <typename T>
class BinarySearchTree {
private:
    class Node {
    public:
        T data;
        Node *left;
        Node *right;

        Node(const T &value) {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *root;

    Node* _insert(Node *node, const T &value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = _insert(node->left, value);
        } else {
            node->right = _insert(node->right, value);
        }

        return node;
    }

    bool _search(Node *node, const T &value) const {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        }

        if (value < node->data) {
            return _search(node->left, value);
        } else {
            return _search(node->right, value);
        }
    }

    void _inorder(Node *node) const {
        if (node != nullptr) {
            _inorder(node->left);
            cout << node->data << " ";
            _inorder(node->right);
        }
    }

    void _preorder(Node *node) const {
        if (node != nullptr) {
            cout << node->data << " ";
            _preorder(node->left);
            _preorder(node->right);
        }
    }

    void _postorder(Node *node) const {
        if (node != nullptr) {
            _postorder(node->left);
            _postorder(node->right);
            cout << node->data << " ";
        }
    }

    void destroy(Node *node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    void storeInorder(Node *node, Vector<T> &values) const {
        if (node != nullptr) {
            storeInorder(node->left, values);
            values.pushBack(node->data);
            storeInorder(node->right, values);
        }
    }

    Node* buildBalancedTree(const Vector<T> &values, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;
        Node *newNode = new Node(values.at(mid));
        newNode->left = buildBalancedTree(values, start, mid - 1);
        newNode->right = buildBalancedTree(values, mid + 1, end);
        return newNode;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    ~BinarySearchTree() {
        destroy(root);
    }

    void insert(const T &value) {
        root = _insert(root, value);
    }

    bool search(const T &value) const {
        return _search(root, value);
    }

    void inorder() const {
        _inorder(root);
        cout << endl;
    }

    void preorder() const {
        _preorder(root);
        cout << endl;
    }

    void postorder() const {
        _postorder(root);
        cout << endl;
    }

    void balance() {
        Vector<T> values;
        storeInorder(root, values);
        destroy(root);
        root = buildBalancedTree(values, 0, values.getSize() - 1);
    }
};

#endif // BINARYSEARCHTREE_H

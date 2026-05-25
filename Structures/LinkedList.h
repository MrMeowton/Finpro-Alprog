#pragma once

#include <iostream>

using namespace std;

template <typename T>
struct Node {

    T data;
    Node<T>* next;

    Node(T data) {

        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class LinkedList {
private:

    Node<T>* head;

public:

    // Constructor
    LinkedList() {

        head = nullptr;
    }

    // Destructor
    ~LinkedList() {

        Node<T>* current = head;

        while (current != nullptr) {

            Node<T>* temp = current;

            current = current->next;

            delete temp;
        }
    }

    // Insert Node
    void insert(T data) {

        Node<T>* newNode =
            new Node<T>(data);

        // jika linked list kosong
        if (head == nullptr) {

            head = newNode;

            return;
        }

        Node<T>* current = head;

        // menuju node terakhir
        while (current->next != nullptr) {
            current = current->next;
        }

        // sambungkan node baru
        current->next = newNode;
    }

    // Get Head
    Node<T>* getHead() const {

        return head;
    }

    // Check Empty
    bool isEmpty() const {

        return head == nullptr;
    }

    // Count Size
    int size() const {

        int count = 0;

        Node<T>* current = head;

        while (current != nullptr) {

            count++;

            current = current->next;
        }

        return count;
    }
};
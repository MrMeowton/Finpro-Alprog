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

    // menambahkan node baru ke akhir linked list

    void insert(T data) {

        Node<T>* newNode = new Node<T>(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node<T>* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // transversal linked list
    void display() const {

        Node<T>* current = head;

        while (current != nullptr) {

            cout << current->data << " -> ";

            current = current->next;
        }

        cout << "nullptr" << endl;
    }
};
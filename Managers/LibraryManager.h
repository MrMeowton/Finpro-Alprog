#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:

    LinkedList() {
        head = nullptr;
    }

    // tambah data
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

    // hapus data berdasarkan id
    void remove(T data) {

        if (head == nullptr) {
            return;
        }

        // kalau head yang dihapus
        if (head->data.getId() == data.getId()) {

            Node<T>* temp = head;

            head = head->next;

            delete temp;

            return;
        }

        Node<T>* current = head;

        while (current->next != nullptr) {

            if (current->next->data.getId() == data.getId()) {

                Node<T>* temp = current->next;

                current->next = current->next->next;

                delete temp;

                return;
            }

            current = current->next;
        }
    }

    // cari data
    Node<T>* find(int id) {

        Node<T>* current = head;

        while (current != nullptr) {

            if (current->data.getId() == id) {
                return current;
            }

            current = current->next;
        }

        return nullptr;
    }

    // tampilkan semua data
    void traversal() {

        Node<T>* current = head;

        while (current != nullptr) {

            current->data.displayBook();

            current = current->next;
        }
    }

    // cek list kosong
    bool isEmpty() {
        return head == nullptr;
    }

    // ambil head
    Node<T>* getHead() {
        return head;
    }
};
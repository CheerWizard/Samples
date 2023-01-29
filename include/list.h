#pragma once

struct Node {
    int value;
    struct Node* next;

    Node(int x) : value(x), next(nullptr) {}
};

class List final {

public:
    void push(int value);
    void fill(int arr[], int n);
    void insert_sort();
    void sortedPush(Node* newNode);
    void print();

private:
    Node* head = nullptr;
    Node* sorted = nullptr;
};
#include <list.h>
#include <Timer.h>

#include <iostream>

using namespace std;

void List::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void List::insert_sort() {
    MEASURE_FUNC()
    sorted = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        sortedPush(current);
        current = next;
    }
    head = sorted;
}

void List::sortedPush(Node* newNode) {
    if (!sorted || sorted->value >= newNode->value) {
        newNode->next = sorted;
        sorted = newNode;
    } else {
        Node* current = sorted;
        while (current->next && current->next->value < newNode->value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void List::print() {
    cout << "Nodes: ";
    while (head) {
        cout << head->value;
        if (head->next) {
            cout << ", ";
        }
        head = head->next;
    }
    cout << endl;
}

void List::fill(int arr[], int n) {
    for (int i = 0 ; i < n ; i++) {
        push(arr[i]);
    }
}

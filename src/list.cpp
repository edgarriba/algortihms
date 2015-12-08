#include <iostream>
#include "list.h"

using namespace std;

List::List() {
    head = NULL;
    current = NULL;
    tmp = NULL;
}

void List::add_node(const int data) {
    node_ptr ptr = new Node;
    ptr->data = data;
    ptr->next = NULL;

    if (head != NULL) {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = ptr;
    } else {
        head = ptr;
    }

}

void List::delete_node(const int data) {
    node_ptr del_ptr = NULL;
    tmp = head;
    current = head;
    while (current != NULL && current->data != data) {
        tmp = current;
        current = current->next;
    }

    if (current == NULL) {
        delete del_ptr;

        cout << data << " was not in the list\n";
    } else {
        del_ptr = current;
        current = current->next;
        tmp->next = current;
        if (del_ptr == head) {
            head = head->next;
            tmp = NULL;
        }
        delete del_ptr;

        cout << data << " was delete from the list\n";
    }
}

void List::print_list() {
    current = head;
    while (current != NULL) {
        cout << current->data << "\n";
        current = current->next;
    }
}
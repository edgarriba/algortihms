#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

class List {
public:
    List();
    void add_node(const int data);
    void delete_node(const int data);
    void print_list();

private:

    typedef struct Node {
        int data;
        Node* next;
    }* node_ptr;

    node_ptr head;
    node_ptr current;
    node_ptr tmp;
};


#endif /* _LIST_H_ */

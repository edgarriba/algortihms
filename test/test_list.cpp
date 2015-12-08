#include <iostream>
#include "list.h"

using namespace std;

int main(int argc, char **argv)
{
    cout << "Hello Linked List!" << endl;

    List list;

    list.add_node(2);
    list.add_node(4);
    list.add_node(7);
    list.add_node(28);
    list.add_node(22);
    list.add_node(98);

    list.print_list();

    int data;
    while ((std::cout << "Enter a value to add it to the list: ")
           && (std::cin >> data) && (data != -1)) {
        list.delete_node(data);
    }

    list.print_list();

    std::cout << "Ending program" << std::endl;

    return 0;
}

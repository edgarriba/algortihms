#include <iostream>
#include <string>
#include <limits>

#include "hash.h"

using namespace std;

int main(int argc, char **argv)
{
    cout << "Hello Hash table!" << endl;

    Hash hashy;

    hashy.add_item("Edgar", "Cola");
    hashy.add_item("Gore", "Cola");
    hashy.add_item("Pol", "Cola");
    hashy.add_item("Maria", "Cola");
    hashy.add_item("Daga", "Cola");
    hashy.add_item("Marro", "Cola");
    hashy.add_item("Marta", "Cola");
    hashy.add_item("Valenti", "Cola");
    hashy.print_table();

    string key;
    while ((std::cout << "Enter a string key to remove from hash table: ")
           && (std::cin >> key) && (key != "exit")) {
        hashy.remove_item(key);
    }

    hashy.print_table();

    std::cout << "Ending program" << std::endl;

    return 0;
}

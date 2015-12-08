#ifndef _HASH_H_
#define _HASH_H_

#include <iostream>

class Hash {
public:
    Hash();
    int hash_f(const std::string key);
    void add_item(const std::string key, const std::string value);
    int num_items(const int index);
    void print_table();
    void print_items(const int index);
    std::string find_value(const std::string key);
    void remove_item(const std::string key);

private:

    struct Item {
        std::string key;
        std::string value;
        Item* next_p;
    };

    static const int table_size_ = 4;
    Item* hash_table_[table_size_];
};


#endif /* _HASH_H_ */

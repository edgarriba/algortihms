#include "hash.h"

using namespace std;

Hash::Hash() {
    for (int i = 0; i < table_size_; ++i) {
        hash_table_[i] = new Item;
        hash_table_[i]->key = "empty";
        hash_table_[i]->value = "empty";
        hash_table_[i]->next_p = NULL;
    }
}

int Hash::hash_f(const string key) {
    int hash = 0;

    for (int i = 0; i < key.length(); ++i)
        hash += static_cast<int>(key[i]);

    return hash % table_size_;
}

void Hash::add_item(const std::string key, const std::string value) {
    int index = hash_f(key);

    if (hash_table_[index]->key == "empty") {
        hash_table_[index]->key = key;
        hash_table_[index]->value = value;
    } else {
        Item* ptr = hash_table_[index];
        Item* ptr_new = new Item;
        ptr_new->key = key;
        ptr_new->value = value;
        ptr_new->next_p = NULL;

        while (ptr->next_p != NULL)
            ptr = ptr->next_p;
        ptr->next_p = ptr_new;
    }
}

int Hash::num_items(const int index) {
    int count = 0;

    if (hash_table_[index]->key == "empty")
        return count;
    else {
        count++;
        Item* ptr = hash_table_[index];
        while (ptr->next_p != NULL) {
            count++;
            ptr = ptr->next_p;
        }
    }

    return count;
}

void Hash::print_table() {
    int number;
    for (int i = 0; i < table_size_; ++i) {
        number = num_items(i);
        cout << "--------------------\n";
        cout << "index: " << i << endl;
        cout << hash_table_[i]->key << endl;
        cout << hash_table_[i]->value << endl;
        cout << "# of items: " << number << endl;
        cout << "--------------------\n";
    }
}

void Hash::print_items(const int index) {
    Item* ptr = hash_table_[index];

    if (ptr->key == "empty") {
        cout << "index: " << index << " is empty";
    } else {
        cout << "index: " << index << " contains the following list\n";
        while (ptr->next_p != NULL) {
            cout << "--------------------\n";
            cout << ptr->key << endl;
            cout << ptr->value << endl;
            cout << "--------------------\n";
            ptr = ptr->next_p;
        }
    }

}

string Hash::find_value(const string key) {
    int index = hash_f(key);
    Item* ptr = hash_table_[index];
    while (ptr != NULL) {
        if (ptr->key == key)
            return ptr->value;
        ptr = ptr->next_p;
    }
    return string("empty");
}


void Hash::remove_item(const string key) {
    int index = hash_f(key);
    Item *del_ptr, *ptr1, *ptr2;

    // Case 0 - Bucket is empty.
    if (hash_table_[index]->key == "empty" &&
        hash_table_[index]->value == "empty") {
        cout << key << " was not found in the hash table\n";
    }

    // Case 1 - Only one item contained in bucket and that iter has
    //          matching name.
    else if (hash_table_[index]->key == key &&
             hash_table_[index]->next_p == NULL) {
        hash_table_[index]->key = "empty";
        hash_table_[index]->value = "empty";

        cout << key << " was removed from the hash table\n";
    }

    // Case 2 - Match is located in the first item in the bucket but
    //          there are more items in the bucket.
    else if(hash_table_[index]->key == key ) {
        del_ptr = hash_table_[index];
        hash_table_[index] = hash_table_[index]->next_p;
        delete del_ptr;

        cout << key << " was removed from the hash table\n";
    }

    // Case 3 - Bucket contains items but first item is not a match.
    else {
        ptr1 = hash_table_[index]->next_p;
        ptr2 = hash_table_[index];

        while (ptr1 != NULL && ptr1->key != key) {
            ptr2 = ptr1;
            ptr1 = ptr1->next_p;
        }
        // Case 3.1 - no match
        if (ptr1 == NULL) {
            cout << key << " was not found in the hash table\n";
        }
        // Case 3.2 - match is found
        else {
            del_ptr = ptr1;
            ptr1 = ptr1->next_p;
            ptr2->next_p = ptr1;
            delete del_ptr;

            cout << key << " was removed from the hash table\n";
        }
    }

}
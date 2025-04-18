#include "note.h"
#include "linked_list.h"
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class Binary_tree {
public:
    Note *root;

    Binary_tree(int first_val);

    void add(int d);

    bool search(int val);

    int get_max();

    int get_min();

    void remove(int val);

    void symmetrical_bypass();

    void delete_tree();

    void copy_tree();

    int get_balance();

    void left_rotate();

    void right_rotate();

    void left_right_rotate();

    void right_left_rotate();

private:

    void recursion_add(Note *el, int data);

    bool recursion_search(Note *el, int val);

    int recursion_get_max(Note *el);

    int recursion_get_min(Note *el);

    void recursion_remove(Note *el, int val);

    void del_el(Note *el);
    

    void set_hieght(Note *el);
};

#endif

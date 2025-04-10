#include "note.h"
#include "linked_list.h"
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class Binary_tree {
public:
    Note *root;

    Binary_tree(int first_val);

    int add(int d);

    void remove(int d);

    int get_height();

    void show_bt();

private:
    int recursion_add(Note *el, int data);

    L_list *recursion_move_to_ll(Note *el);

    Note *go_through(Note *el);

    Note *go_left(Note *el);

    Note *go_right(Note *el);
};

#endif

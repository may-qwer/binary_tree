#include "note.h"
#include "linked_list.h"
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class Binary_tree {
public:
    Note *root;

    Binary_tree(int first_val);

    int add(int d);

    void remove_add(int d);

    int get_height();

private:
    L_list *ll;
    L_list *ll_for_show;

    int height = 0;

    int recursion_add(Note *el, int data);

    void go_through_for_remove(Note *el);

    int recurse_get_height(Note *el);

    int get_max(int a1, int a2);

};

#endif

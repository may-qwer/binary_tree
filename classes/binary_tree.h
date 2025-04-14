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

    void remove_move(int d);

    int get_height();

    int get_width();

    void show_bt();

private:
    L_list *ll;

    int height = 0;

    int recursion_add(Note *el, int data);

    void go_through_for_remove(Note *el);

    int recurse_get_height(Note *el);

    int get_max(int a1, int a2);

    void pr_str(char **m_str);

    char **add_to_str(Note *el);

};

#endif

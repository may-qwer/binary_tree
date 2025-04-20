#include "note.h"
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class Binary_tree {
public:
    Note *root;

    int pr_data = 0;
    int pr_height = 1;

    Binary_tree(int first_val);

    void add(int d);

    bool search(int val);

    int get_max();

    int get_min();

    void remove(int val);//if no chalds or 1 chald - delete and move chald (if no chalds - nullptr), if 2 chalds - remove to greater of left tree;

    void symmetrical_bypass(int what_pr = 0);//left, data, right;

    void delete_tree();//left, right, data;

    Binary_tree *copy_tree();//data, left, right

    int get_balance_for_tree();
    
    void recursion_balance(Note *el);

private:

    void recursion_add(Note *el, int data);

    bool recursion_search(Note *el, int val);

    int recursion_get_max(Note *el);

    int recursion_get_min(Note *el);

    void recursion_remove(Note *el, int val);

    void del_el(Note *el);

    void recursion_symmetrical_bypass(Note *el, int what_pr);

    void recursion_delete_tree(Note *el);

    void recursion_add_to_copy_tree(Note *el, Binary_tree *copy_bt);
    
    void set_hieght(Note *el);

    int get_max(int a1, int a2);

    int get_balance_for_el(Note *el);

    void left_rotate(Note *el);

    void right_rotate(Note *el);

    void swap(Note *el_parent, Note *el_chald);
};

#endif

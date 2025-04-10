#include "binary_tree.h"

Binary_tree::Binary_tree(int first_val) {
    root->data = first_val;
    root->right = nullptr;
    root->left = nullptr;
    root->parent = nullptr;
}

int Binary_tree::add(int d) {
    return recursion_add(root, d); 
}

void Binary_tree::remove(int d) {
    Note *tmp = new Note;
    tmp = root;
    for (tmp; tmp->data != d; ) {
        if (tmp->data < d) {
            tmp = tmp->right;
        }
        else {
            tmp = tmp->left;
        }
    }
    recursion_move_to_ll(tmp);    
}

L_list *Binary_tree::recursion_move_to_ll(Note *el) {
    L_list *ll_of_moved = new L_list;
}

Note *Binary_tree::go_through(Note *el) {

}

Note *Binary_tree::go_left(Note *el) {
    if (el->left == nullptr) {
        return;
    }
    go_through(el->left);
}

Note *Binary_tree::go_right(Note *el) {

}

int Binary_tree::recursion_add(Note *el, int d) {
    if (el->data > d && el->left == nullptr) {
        Note *new_bt = new Note;
        new_bt->data = d;
        new_bt->left = nullptr;
        new_bt->right = nullptr;
        new_bt->parent = el;
        el->left = new_bt;
        return d;
    } else if (el->data < d && el->right == nullptr) {
        Note *new_bt = new Note;
        new_bt->data = d;
        new_bt->left = nullptr;
        new_bt->right = nullptr;
        new_bt->parent = el;
        el->right = new_bt;
        return d;
    } else if (el->data > d) {
        recursion_add(el->left, d);
        return -1;
    } else if (el->data < d) {
        recursion_add(el->right, d);
        return -1;
    }
    return -1;
}


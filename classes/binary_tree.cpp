#include "binary_tree.h"

Binary_tree::Binary_tree(int first_val) {
    root->data = first_val;
    root->right = nullptr;
    root->left = nullptr;
    root->parent = nullptr;  
    ll = new L_list();
}

int Binary_tree::add(int d) {
    return recursion_add(root, d); 
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


void Binary_tree::remove(int d) {
    Note *tmp = root;
    for (tmp; tmp->data != d; ) {
        if (tmp->data < d) {
            tmp = tmp->right;
        }
        else {
            tmp = tmp->left;
        }
    }
    go_through_for_remove(tmp->left);
    go_through_for_remove(tmp->right);
    delete tmp;
    while (ll->fst->next != nullptr) {
        this->add(ll->pop());
    }
}

void Binary_tree::go_through_for_remove(Note *el) {
    if (el) {
        ll->push(el->data);
        if (el->left != nullptr ) {
            go_through_for_remove(el->left);
        }
        if (el->right != nullptr) {
            go_through_for_remove(el->right);
        }
        delete el;
    }
}



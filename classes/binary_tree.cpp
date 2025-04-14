#include "binary_tree.h"
#include <iostream>
using namespace std;

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


void Binary_tree::remove_add(int d) {
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
    if (tmp->parent->data < d) {
        tmp->parent->right = nullptr;
    } else {
        tmp->parent->left = nullptr;
    }
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

int Binary_tree::get_height() {
    return recurse_get_height(root);
}

int Binary_tree::recurse_get_height(Note *el) {
    if (el == nullptr) {
        return 0;
    }
    int left_tree = recurse_get_height(el->left);
    int right_tree = recurse_get_height(el->right);
    return get_max(left_tree, right_tree) + 1;
}

int Binary_tree::get_width() {
    
}

int Binary_tree::get_max(int a1, int a2) {
    if (a1 < a2) {
        return a2;
    } else {
        return a1;
    }
}

void Binary_tree::show_bt() {
    height = get_height();


    height = 0;
}

void Binary_tree::pr_str(char **m_str) {

}

char **Binary_tree::add_to_str(Note *el){
    char **str = new char*[2*height];

    
}

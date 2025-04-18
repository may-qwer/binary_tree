#include "binary_tree.h"
#include <iostream>
using namespace std;

Binary_tree::Binary_tree(int first_val) {
    root = new Note;
    root->data = first_val;
    root->right = nullptr;
    root->left = nullptr;
    root->parent = nullptr;
    root->height = 0;  
}

void Binary_tree::add(int d) {
    recursion_add(root, d); 
}

void Binary_tree::recursion_add(Note *el, int d) {
    if (el->data > d && el->left != nullptr) {
        recursion_add(el->left, d);
    } else if (el->data < d && el->right != nullptr) {
        recursion_add(el->right, d);
    } else {
        Note *new_bt = new Note;
        new_bt->data = d;
        new_bt->left = nullptr;
        new_bt->right = nullptr;
        new_bt->height = 0;
        new_bt->parent = el;
        if (el->data > d) {
            el->left = new_bt;
        } else if (el->data < d) {
            el->right = new_bt;
        }
        set_hieght(new_bt->parent);
    }
}

bool Binary_tree::search(int val) {
    return recursion_search(root, val);
}

bool Binary_tree::recursion_search(Note* el, int val) {
    if (el->data == val) {
        return true;
    }
    if (val > el->data && el->right) {
        return recursion_search(el->right, val);
    } else if (val < el->data && el->left) {
        return recursion_search(el->left, val);
    } else {
        return false;
    }
}

int Binary_tree::get_max() {
    return recursion_get_max(root);
}

int Binary_tree::recursion_get_max(Note *el) {
    if (!el->right) {
        return el->data;
    }
    return recursion_get_max(el->right);
}

int Binary_tree::get_min() {
    return recursion_get_min(root);
}

int Binary_tree::recursion_get_min(Note *el) {
    if (!el->left) {
        return el->data;
    }
    return recursion_get_min(el->left);
}

void Binary_tree::remove(int val) {
    recursion_remove(root, val);
}

void Binary_tree::recursion_remove(Note *el, int val) {
    if (val > el->data && el->right) {
        recursion_remove(el->right, val);
        return;
    } else if (val < el->data && el->left) {
        recursion_remove(el->left, val);
        return;
    } else if (val == el->data) {
        del_el(el);
        set_hieght(el->parent);
        return;
    }
    cout << "There isn't note with value = " << val << endl;
}


void Binary_tree::del_el(Note *el) {
    if (!el->right && !el->left) {
        el->parent->right == el ? el->parent->right = nullptr : el->parent->left = nullptr;
        delete el;
    } else if (el->right && !el->left) {
        if (el->parent->right == el) {
            el->parent->right = el->right;
            el->right->parent = el->parent;
        } else {
            el->parent->left = el->right;
            el->left->parent = el->parent;
        }
        delete el;
    } else if (!el->right && el->left) {
        if (el->parent->right == el) {
            el->parent->right = el->left;
            el->right->parent = el->parent;
        } else {
            el->parent->left = el->left;
            el->left->parent = el->parent;
        }
        delete el;
    } else {
        int max_of_left = recursion_get_max(el->left);
        remove(max_of_left);
        el->data = max_of_left;
    }
}


void Binary_tree::set_hieght(Note *el) {

}

void Binary_tree::symmetrical_bypass() {

}




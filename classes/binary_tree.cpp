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
        set_hieght(root);
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
        set_hieght(root);
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

void Binary_tree::symmetrical_bypass(int what_pr) {
    recursion_symmetrical_bypass(root, what_pr);
    cout << endl;
}

void Binary_tree::recursion_symmetrical_bypass(Note *el, int what_pr) {
    if (el->left) {
        recursion_symmetrical_bypass(el->left, what_pr);
    }
    if (what_pr == pr_data) {
        cout << el->data << " ";
    } else if (what_pr == pr_height) {
        cout << el->height << "  ";
    }
    if (el->right) {
        recursion_symmetrical_bypass(el->right, what_pr);
    }
}

void Binary_tree::delete_tree() {
    recursion_delete_tree(root);
    set_hieght(root);
}

void Binary_tree::recursion_delete_tree(Note *el) {
    if (el->left) {
        recursion_delete_tree(el->left);
    } 
    if (el->right) {
        recursion_delete_tree(el->right);
    }
    if (el == root) {
        return;
    }
    if (el->parent->right) {
        if (el->parent->right == el) {
            el->parent->right = nullptr;
        }
    }
    if (el->parent->left) {
        if (el->parent->left == el) {
            el->parent->left = nullptr;
        }
    }
    delete el;
}

Binary_tree *Binary_tree::copy_tree() {
    Binary_tree *copy_bt = new Binary_tree(root->data);
    recursion_add_to_copy_tree(root, copy_bt);

    return copy_bt;
}

void Binary_tree::recursion_add_to_copy_tree(Note *el, Binary_tree *copy_bt){
    if (el != root) {
        copy_bt->add(el->data);
    }
    if (el->left) {
        recursion_add_to_copy_tree(el->left, copy_bt);
    }
    if (el->right) {
        recursion_add_to_copy_tree(el->right, copy_bt);
    }
}

void Binary_tree::set_hieght(Note *el) {
    if (!el->right && !el->left) {
        el->height = 1;
        return;
    }
    if (el->left) {
        set_hieght(el->left);
    }
    if (el->right) {
        set_hieght(el->right);
    }
    int h_left = el->left ? el->left->height : 0;
    int h_right = el->right ? el->right->height : 0;
    el->height = get_max(h_left, h_right) + 1;
}

int Binary_tree::get_max(int a1, int a2) {
    return (a1<a2) ? a2 : a1;
}

int Binary_tree::get_balance_for_tree() {
    return get_balance_for_el(root);
}

int Binary_tree::get_balance_for_el(Note *el) {
    if (el->right && el->left) {
        return el->right->height - el->left->height;
    } else if (el->right && !el->left) {
        return 2;
    } else if (!el->right && el->left) {
        return -2;
    }
    return 0;  
}

void Binary_tree::recursion_balance(Note *el) {
    int balance_val = get_balance_for_el(el);
    if (balance_val == 2) {
        if (el->right) {
            if (get_balance_for_el(el->right) == 1) {
                left_rotate(el->right);
            }
        }
        right_rotate(el);
    } else if (balance_val == -2) {
        if (el->left) {
            if (get_balance_for_el(el->left) == -1) {
                right_rotate(el->left);
            }
        }
        left_rotate(el);
    } else if (balance_val > 2) {
        left_rotate(el);
        recursion_balance(el);
    } else if (balance_val < -2) {
        right_rotate(el);
        recursion_balance(el);
    } else {
        return;
    }
    set_hieght(root);
    if (el->left) {
        get_balance_for_el(el->left);
    }
    if (el->right) {
        get_balance_for_el(el->right);
    }
}

void Binary_tree::left_rotate(Note *el){
    Note *tmp_new_right = new Note;
    tmp_new_right->data = el->data;
    tmp_new_right->right = el->right;
    tmp_new_right->height = el->height;
    el->right = tmp_new_right;
    tmp_new_right->parent = el->right;
    swap(el, el->left);
    Note *tmp_remove_left = new Note;
    tmp_remove_left = el->left;
    el->left = el->left->left;
    delete tmp_remove_left;
    set_hieght(el);
}

void Binary_tree::right_rotate(Note *el){
    Note *tmp_new_left = new Note;
    tmp_new_left->data = el->data;
    tmp_new_left->left = el->left;
    tmp_new_left->height = el->height;
    el->left = tmp_new_left;
    tmp_new_left->parent = el->left;
    swap(el, el->right);
    Note *tmp_remove_right = new Note;
    tmp_remove_right = el->right;
    el->right = el->right->right;
    delete tmp_remove_right;
    set_hieght(el);
}

void Binary_tree::swap(Note *el_parent, Note *el_chald) {
    int el_p_d = el_parent->data;
    int el_ch_d = el_chald->data;
    el_parent->data = el_ch_d;
    el_chald->data = el_p_d;
}






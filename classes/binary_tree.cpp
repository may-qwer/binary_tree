#include "binary_tree.h"

Binary_tree::Binary_tree(int first_val) {
    root->data = first_val;
    root->right = nullptr;
    root->left = nullptr;
}

int Binary_tree::add(int data) {
    return recursion_add(root, data); 
}

void Binary_tree::remove(int data) {

}

int Binary_tree::recursion_add(Note *el, int data) {
    if (el->data > data && el->left == nullptr) {
        Note *new_bt = new Note;
        new_bt->data = data;
        new_bt->left = nullptr;
        new_bt->right = nullptr;
        el->left = new_bt;
        return data;
    } else if (el->data < data && el->right == nullptr) {
        Note *new_bt = new Note;
        new_bt->data = data;
        new_bt->left = nullptr;
        new_bt->right = nullptr;
        el->right = new_bt;
        return data;
    } else if (el->data > data) {
        recursion_add(el->left, data);
        return -1;
    } else if (el->data < data) {
        recursion_add(el->right, data);
        return -1;
    }
    return -1;
}


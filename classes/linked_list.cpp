#include "linked_list.h"

L_list::L_list() {
    fst = new Node_ll;
    fst->data = -1;
    fst->next = nullptr;
}

void L_list::push(int d) {
    Node_ll *new_ll = new Node_ll;
    new_ll->data = d;
    new_ll->next = fst->next;
    fst->next = new_ll;
}

void L_list::pop() {
    if (fst->next == nullptr) {
        return;
    }
    Node_ll *tmp = fst->next;
    fst->next = fst->next->next;
    delete tmp;
}

void L_list::clean() {
    while (fst->next !=nullptr) {
        pop();
    }
}

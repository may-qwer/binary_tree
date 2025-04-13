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

int L_list::pop() {
    int res = 0;
    if (fst->next == nullptr) {
        return res;
    }
    Node_ll *tmp = fst->next;
    fst->next = fst->next->next;
    res = tmp->data;
    delete tmp;
    return res;
}


#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Node_ll {
public:
    int data;
    Node_ll *next;
};

class L_list {
public:
    Node_ll *fst;
    
    L_list();
    
    void push(int d);

    void pop();
};

#endif
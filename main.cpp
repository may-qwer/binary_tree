#include <iostream>
#include "./classes/binary_tree.h"
#include "./classes/linked_list.h"
using namespace std;

int main() {
    cout << "begin" << endl;

    Binary_tree bt(50); 
    bt.add(25);
    bt.add(75);
    bt.add(60);
    bt.add(80);
    bt.add(85);
    bt.add(90);

    bt.remove(60);

    L_list ll;
    cout << ll.fst->data << endl;
    cout << ll.fst->next << endl;
    ll.push(10);
    ll.push(10);
    ll.push(10);
    ll.push(10);
    ll.push(10);
    ll.push(10);

    ll.clean();

    cout << "end" << endl;

    return 0;
}
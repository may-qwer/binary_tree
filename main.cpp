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

    bt.remove(80);

    // L_list ll;
    // ll.push(10);
    // ll.push(11);
    // ll.push(12);
    // ll.push(13);
    // ll.push(14);
    // ll.push(15);

    // cout << ll.pop() << endl;
    // cout << ll.pop() << endl;
    // cout << ll.pop() << endl;
    // cout << ll.pop() << endl;
    // cout << ll.pop() << endl;
    // cout << ll.pop() << endl;
    // cout << ll.fst->next << endl;
    // cout << ll.pop() << endl;
    // cout << ll.pop() << endl;
    // cout << ll.pop() << endl;
    // cout << ll.pop() << endl;

    cout << "end" << endl;

    return 0;
}
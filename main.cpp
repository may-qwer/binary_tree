#include <iostream>
#include "./classes/binary_tree.h"
// #include "./classes/linked_list.h"
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


    cout << "end" << endl;

    return 0;
}
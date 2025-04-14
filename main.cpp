#include <iostream>
#include "./classes/binary_tree.h"
#include "./classes/linked_list.h"
using namespace std;

int main() {
    cout << "begin" << endl;

    Binary_tree bt(50); 
    bt.add(25);
    bt.add(75);
    bt.add(80);
    bt.add(77);
    bt.add(78);
    bt.add(79);
    bt.add(20);
    bt.add(10);

    bt.show_bt();

    bt.remove_add(80);
    
    cout << "end" << endl;

    return 0;
}
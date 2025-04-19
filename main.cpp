#include <iostream>
#include "./classes/binary_tree.h"
#include "./classes/linked_list.h"
using namespace std;

void add_els_to_tree(Binary_tree *bt) {
    bt->add(25);
    bt->add(75);
    bt->add(80);
    bt->add(90);
    bt->add(91);
    bt->add(77);
    bt->add(78);
    bt->add(79);
    bt->add(20);
    bt->add(10);
}

int main() {
    cout << "begin" << endl;
    cout << "===============" << endl;
    
    Binary_tree bt(50); 
    add_els_to_tree(&bt);

    bt.symmetrical_bypass();
    cout << "---------------" << endl;
    cout << "Serch existing el: " << bt.search(77) << endl;
    cout << "Serch non-existing el: "<< bt.search(1) << endl;
    cout << "---------------" << endl;
    cout << "Get max: " << bt.get_max() << endl;
    cout << "---------------" << endl;
    cout << "Get min: " << bt.get_min() << endl;
    cout << "---------------" << endl;
    cout << "Before removing:" << endl;
    bt.symmetrical_bypass();
    bt.remove(10);
    cout << "Remove note 10:" << endl;
    bt.symmetrical_bypass();
    bt.remove(20);
    cout << "Remove note 20:" << endl;
    bt.symmetrical_bypass();
    bt.remove(80);
    cout << "Remove note 80: " << endl;
    bt.symmetrical_bypass();
    cout << "---------------" << endl;
    cout << "Delete tree:" << endl;
    bt.delete_tree();
    bt.symmetrical_bypass();
    add_els_to_tree(&bt);    
    cout << "---------------" << endl;
    Binary_tree *copy_bt = bt.copy_tree();
    cout << "This tree: ";
    bt.symmetrical_bypass();
    cout << "\nCopy tree: ";
    copy_bt->symmetrical_bypass();
    cout << endl;
    cout << "---------------" << endl;
    cout << "Show height: " << endl;
    bt.symmetrical_bypass("h");

    cout << "===============" << endl;
    cout << "end" << endl;

    return 0;
}
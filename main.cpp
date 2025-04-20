#include <iostream>
#include "./classes/binary_tree.h"
using namespace std;

void add_els_to_tree(Binary_tree *bt) {
    bt->add(25);
    bt->add(75);
    bt->add(80);
    bt->add(90);
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
    cout << "Copy tree: ";
    copy_bt->symmetrical_bypass();
    cout << "---------------" << endl;
    cout << "Show height: " << endl;
    int p_hieght = 1;
    bt.symmetrical_bypass();
    bt.symmetrical_bypass(p_hieght);
    cout << "---------------" << endl;
    cout << "Balances for tree: ";
    cout << bt.get_balance_for_tree() << endl;
    cout << "---------------" << endl;
    cout << "Height:         ";
    bt.symmetrical_bypass(p_hieght);
    cout << "Before balance: ";
    bt.symmetrical_bypass();
    // bt.balance();
    bt.recursion_balance(bt.root->left);
    bt.recursion_balance(bt.root->right->right->left);
    cout << "After balance:  ";
    bt.symmetrical_bypass();


    cout << "===============" << endl;
    cout << "end" << endl;

    return 0;
}
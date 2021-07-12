#include <iostream>
#include "binary_tree.h"

using namespace std;

// @ref: http://alrightchiu.github.io/SecondRound/binary-tree-jian-li-yi-ke-binary-tree.html

int main()
{
    const char *tree_data = "A B C D E F x x x G H x I";
    binary_tree Tree(tree_data);
    Tree.in_order_by_parent();
    cout << endl;

    Tree.insert_level_order('K');
    Tree.insert_level_order('L');
    Tree.insert_level_order('M');
    Tree.insert_level_order('N');
    Tree.in_order_by_parent();
    cout << endl;
}
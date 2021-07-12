#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_

#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

class binary_tree;

class tree_node
{
    private:
        tree_node *left_child = nullptr;
        tree_node *right_child = nullptr;
        tree_node *parent = nullptr;
        char str = 'x';
    public:

        tree_node()
        {
            left_child = nullptr;
            right_child = nullptr;
            parent = nullptr;
            str = 'x';
        };

        tree_node(char _str)
        {
            left_child = nullptr;
            right_child = nullptr;
            parent = nullptr;
            str = _str;
        };

        friend class binary_tree;
};

class binary_tree
{
    private:
        tree_node *root = nullptr;
    public:
        binary_tree()
        {
            root = nullptr;
        };

        binary_tree(const char *str);

        void level_order_construct(stringstream &ss);
        void insert_level_order(char data);

        tree_node *left_most(tree_node *current);
        //tree_node *right_most(tree_node *current);

        tree_node *in_order_successor(tree_node *current);
        //tree_node *in_order_predecessor(tree_node *current);

        void in_order_by_parent();
        //void in_order_reverse(tree_node *root);
    
};

#endif
#include "binary_tree.h"
using namespace std;

binary_tree::binary_tree(const char *str)
{
    stringstream ss;
    ss << str;
    root = new tree_node;
    ss >> root->str;
    
    level_order_construct(ss);
}

    void binary_tree::level_order_construct(stringstream &ss)
    {
        queue<tree_node*> p_queue;
        tree_node *current = root;
        char str = 'x';

        while(ss >> str)
        {
            if(str >= 'A' && str <= 'Z')
            {
                tree_node *new_node = new tree_node(str);
                new_node->parent = current;
                current->left_child = new_node;
                p_queue.push(new_node);
            }

            if(!(ss >> str)) // odd number of data
            {
                break;
            }

            if(str >= 'A' && str <= 'Z')
            {
                tree_node *new_node = new tree_node(str);
                new_node->parent = current;
                current->right_child = new_node;
                p_queue.push(new_node);
            }

            current = p_queue.front();
            p_queue.pop();
        }
    }

    void binary_tree::insert_level_order(char data)
    {
        queue<tree_node*> p_queue;
        tree_node *current = root;

        while(current != nullptr)
        {
            if(current->left_child != nullptr)
            {
                p_queue.push(current->left_child);
            }
            else
            {
                tree_node *new_node = new tree_node(data);
                new_node->parent = current;
                current->left_child = new_node;
                break;
            }

            if(current->right_child != nullptr)
            {
                p_queue.push(current->right_child);
            }
            else
            {
                tree_node *new_node = new tree_node(data);
                new_node->parent = current;
                current->right_child = new_node;
                break;
            }

            current = p_queue.front();
            p_queue.pop();
        }
    }

    tree_node *binary_tree::left_most(tree_node *current)
    {
        while(current->left_child != nullptr)
        {
            current = current->left_child;
        }
        return current;
    }


    tree_node *binary_tree::in_order_successor(tree_node *current)
    {
        if(current->right_child != nullptr)
        {
            return left_most(current->right_child);
        }

        tree_node *successor = current->parent;
        while(successor != nullptr && current == successor->right_child)
        {
            current = successor;
            successor = current->parent;
        }

        return successor;
    }

    void binary_tree::in_order_by_parent()
    {
        tree_node *current = new tree_node;
        current = left_most(root);

        while(current != nullptr)
        {
            cout << current->str << " ";
            current = in_order_successor(current);
        }

    }
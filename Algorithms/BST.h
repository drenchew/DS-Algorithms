#pragma once
#include<stack>
#include<iostream>

#include"BST_node.hpp"
#include"BST_Iterator.h"

template<class T>
class BST
{
    BstNode<T>* root;

    void destroyer(BstNode<T>* curr)
    {
        if (curr == nullptr) { return; }
        destroyer(curr->left);
        destroyer(curr->right);
        delete curr;
    }

    BstNode<T>* insert_helper(BstNode<T>* curr, const T& val)
    {
        if (curr == nullptr)
        {
            return new BstNode<T>(val);
        }
        else if (val < curr->data)
        {
            curr->left = insert_helper(curr->left, val);
        }
        else
        {
            curr->right = insert_helper(curr->right, val);
        }
        return curr;
    }

    void in_order_traversal(BstNode<T>* curr) const
    {
        if (curr == nullptr) { return; }
        in_order_traversal(curr->left);
        std::cout << curr->data << ' ';
        in_order_traversal(curr->right);
    }

public:
    BST() : root(nullptr) {}
    ~BST() { destroyer(root); }

    BSTIterator<T> begin() { return BSTIterator<T>(root); }
    BSTIterator<T> end() { return BSTIterator<T>(nullptr); }

    void insert(const T& val)
    {
        root = insert_helper(root, val);
    }

    void print() const
    {
        in_order_traversal(root);
        std::cout << std::endl;
    }

    bool search(const T& val)
    {
        return searchHelper(val, root);
    }

    bool searchHelper(const T& val, BstNode<T>* node)
    {
        if (node == nullptr) { return false; }
         else if (val == node->data) { return true; }
         else if (val < node->data) { return searchHelper(val, node->left); }
        return searchHelper(val, node->right); 
    }
};
//#pragma once
//
//
//#include"BST_Iterator.h"
//#include"BST.h"
//#include"BST_node.hpp"
//
//
//
//template<class T>
//void BSTIterator::traverse_left(BstNode<T>*node){
//        if (node == nullptr) { return; }
//        stack_.push(node);
//        traverse_left(node->left);
//}
//
//template<class T>
//BSTIterator::BSTIterator(BstNode<T>* root) { traverse_left(root); }
//
// /*   const T& operator*() const
//    {
//        return stack_.top()->data;
//    }
//
//    BSTIterator& operator++()
//    {
//        BstNode<T>* topNode = stack_.top();
//        stack_.pop();
//
//        if (topNode->right != nullptr)
//        {
//            traverse_left(topNode->right);
//        }
//
//        return *this;
//    }
//
//    bool operator!=(const BSTIterator& other) const
//    {
//        return !stack_.empty() || !other.stack_.empty();
//    }
//};*/
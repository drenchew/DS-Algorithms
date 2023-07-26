#pragma once

#ifndef AVLNODE_
#define AVLNODE_


class AVLNode {
public:
    int key = 0;
    AVLNode* left = nullptr;
    AVLNode* right = nullptr;
    int height = 1; // Height of the node's subtree

    AVLNode() {}
    AVLNode(int key_) : key(key_){}
    AVLNode(int key_,AVLNode* l, AVLNode* r) : key(key_),left(l),right(r){}

};

#endif // !AVLNODE_

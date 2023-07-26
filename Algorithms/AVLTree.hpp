#pragma once
#include "AVLNode.h"

#include <iostream>
#include<algorithm>
#include<utility>
#include<vector>


#ifndef AVLTREE_HPP
#define AVLTREE_HPP




class AVL 
{
	AVLNode* root;
	int size=0;

	int getHeight(AVLNode* node) const {
		return node ? node->height : 0;
	}
	

	int getBalance(AVLNode* node) const {  // 					calculate the balance factor (-1,0,1) for balanced !
		if (!node)
			return 0;
		return getHeight(node->left) - getHeight(node->right);
	}

	/*																		   	 ROTATIONS
	*
	* 
	* 
	* 
	*
	*																			RIGHT ROTATIONG
	*
	*/

	AVLNode* rightRotate(AVLNode* y) {
		AVLNode* x = y->left;
		AVLNode* T2 = x->right;

		// Perform rotation
		x->right = y;
		y->left = T2;

		// Update heights
		y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
		x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

		return x;
	}

		//																		LEFT ROTATIONG
	AVLNode* leftRotate(AVLNode* x) {
		// Store the right child of x in a variable y
		AVLNode* y = x->right;

		// Store the left subtree of y in a variable T2
		AVLNode* T2 = y->left;

		// Perform the left rotation
		y->left = x;      // Make x the left child of y
		x->right = T2;    // Make T2 the right child of x

		// Update the heights of x and y
		x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
		y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

		// Return the new root of the subtree (y)
		return y;
	}

	AVLNode* insert(AVLNode* root, int key) {
		if (nullptr == root) { return new  AVLNode(key); }

		if (key < root->key) { root->left = insert(root->left, key); }

		else if (key > root->key) { root->right = insert(root->right, key); }
		else { // Duplicate keys are not allowed in AVL tree
			return root;
		}

		// Update height of the ancestor node
		root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;

		// Get the balance factor
		int balance = getBalance(root);

		// Left-Left case
		if (balance > 1 && key < root->left->key)
			return rightRotate(root);

		// Right-Right case
		if (balance < -1 && key > root->right->key)
			return leftRotate(root);

		// Left-Right case
		if (balance > 1 && key > root->left->key) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		// Right-Left case
		if (balance < -1 && key < root->right->key) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
		size++;
		return root;
	}

	void traverse_to_delete(AVLNode* curr) // in-order traversal
	{
		if (nullptr == curr) { return; }
		traverse_to_delete(curr->left);
		

		traverse_to_delete(curr->right);

		_data.push_back(curr);
	}

	std::vector<AVLNode*> _data;
public:

	~AVL()
	{
		_data.reserve(size);
		
		traverse_to_delete(root);
		for (size_t i = 0; i < _data.size(); i++)
		{
			delete	_data[i];
		}
	}
		

	void Insert(int val)
	{
		root = insert(root, val);
	}

};






#endif // !AVLTREE_HPP

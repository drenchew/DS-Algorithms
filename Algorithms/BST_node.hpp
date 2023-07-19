#pragma once


template<class T>
class BstNode
{
public:
	T data;
	BstNode* left;
	BstNode* right;

	BstNode() : data(T()), left(nullptr), right(nullptr) {}
	BstNode(const T& data) : data(data), left(nullptr), right(nullptr) {}
	BstNode(const T& data, const BstNode<T>& l, const BstNode<T>& r) : data(data), left(l), right(r) {}
};
#pragma once

template<class T>
class BSTIterator
{
    std::stack<BstNode<T>*> stack_;

    void traverse_left(BstNode<T>* node)
    {
        if (node == nullptr) { return; }
               stack_.push(node);
               traverse_left(node->left);
    }

public:
    BSTIterator(BstNode<T>* root) { traverse_left(root); }

    const T& operator*() const
    {
        return stack_.top()->data;
    }

    BSTIterator& operator++()
    {
        BstNode<T>* topNode = stack_.top();
        stack_.pop();

        if (topNode->right != nullptr)
        {
            traverse_left(topNode->right);
        }

        return *this;
    }

    bool operator!=(const BSTIterator& other) const
    {
        return !stack_.empty() || !other.stack_.empty();
    }
};
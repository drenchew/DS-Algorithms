#include<iostream>
#include <stack>
#include<string>

#include"BST.h"


using namespace std;


int main()
{
	//while (true)
	{
		BST<string> tree;

		//BST<int> bs;
		

		for (int i = 10; i > 0; --i)
		{
			tree.insert(to_string(i));

		}
		for (auto it : tree)
		{
			cout << it;
		}
		///tree.print();
	}

	return 0;
}

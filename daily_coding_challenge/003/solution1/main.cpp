#include <iostream>
#include <queue>
#include "ds/bst/bst.hpp"

template<typename T>
std::string serilaize(const ds::bst<T> &tree);

int main()
{
	ds::bst<int> tree;
	int arr[]{5, 4, 7, 6, 8};
	int size = sizeof(arr)/sizeof(int);

	for(int i = 0; i < size; ++i)
	{
		tree.insert(arr[i]);
	}

	serilaize(tree);
}

template<typename T>
std::string serilaize(const ds::bst<T> &tree)
{
	std::queue<typename ds::bst<T>::cnode_ptr> queue;

	queue.push(tree.croot());

	typename ds::bst<T>::cnode_ptr curr(nullptr);

	while(!queue.empty())
	{
		curr = queue.front();
		queue.pop();

		if(curr)
		{
			std::cout << curr->value << " ";
			queue.push(curr->left);
			queue.push(curr->right);
		}
		else
		{
			std::cout << "X ";
		}

	}


	return "";
}

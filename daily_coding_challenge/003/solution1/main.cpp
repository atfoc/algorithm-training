#include <iostream>
#include <queue>
#include <sstream>
#include <algorithm>
#include "ds/bst/bst.hpp"

template<typename T>
std::string serilize(const ds::bst<T> &tree);
template<typename T, typename Callable>
ds::bst<T> deserilize(const std::string &str, Callable &&converter);

int main()
{
	ds::bst<int> tree;
	ds::bst<int> after;
	ds::bst<std::string> tree1;
	ds::bst<std::string> after1;
	ds::bst<int> a;
	int arr[]{5, 4, 72, 63, 888};
	int size = sizeof(arr)/sizeof(int);

	std::string arr1[]{"hi", "it's mine", "some escape\\here", "63", "X here"};
	int size1 = sizeof(arr)/sizeof(int);

	for(int i = 0; i < size; ++i)
	{
		tree.insert(arr[i]);
	}

	for(int i = 0; i < size; ++i)
	{
		tree1.insert(arr1[i]);
	}

	auto string = serilize(tree);
	std::cout << string  << std::endl;
	after = deserilize<int>(string, [](auto s)
	{
		return std::atoi(s.c_str());
	});
	std::cout << serilize(after) << std::endl;
	auto string1 = serilize(tree1);
	std::cout << string1 << std::endl;
	after1 = deserilize<std::string>(string1, [](auto &&s)
	{
		return s;
	});
	std::cout << serilize(after1) << std::endl;
}

/*Figure out more efective way. Maybe overload for move semantics*/
std::string escape(const std::string& str)
{
	std::string res;

	std::for_each(str.begin(), str.end(), [&](const auto &ch)
	{
		if(ch == '\'' || ch == '\\')
		{
			res.push_back('\\');
			res.push_back(ch);
		}
		else
		{
			res.push_back(ch);
		}
	});
	return res;
}

template<typename T>
std::string serilize(const ds::bst<T> &tree)
{
	std::queue<typename ds::bst<T>::cnode_ptr> queue;
	/*Find better way to convert generic type to string*/
	std::stringstream word;
	std::stringstream res;

	queue.push(tree.croot());

	typename ds::bst<T>::cnode_ptr curr(nullptr);

	while(!queue.empty())
	{
		curr = queue.front();
		queue.pop();

		if(curr)
		{
			word << curr->value;
			res << "'" << escape(word.str()) << "' ";
			word.str("");


			queue.push(curr->left);
			queue.push(curr->right);
		}
		else
		{
			res << "X ";
		}

	}

	return res.str();
}

/*Converter from beg and end iterator returns right type*/
template<typename T, typename Callable>
ds::bst<T> deserilize(const std::string &str, Callable &&converter)
{
	ds::bst<T> tree;
	tree.insert(T());
	std::queue<std::pair<typename ds::bst<T>::node_ptr, int>> queue;
	queue.push(std::make_pair(tree.root(), 0));
	std::pair<typename ds::bst<T>::node_ptr, int> current;
	bool parsing_value = false;
	std::stringstream word;

	for(auto it = str.cbegin(), end = str.cend(); it != end; ++it)
	{
		if(*it == '\'')
		{
			if(!parsing_value)
			{
				word.str("");
				current = queue.front();
				queue.pop();
			}
			else
			{

				if(current.second == 0)
				{
					current.first->value = converter(word.str());
					queue.push(std::make_pair(current.first, -1));
					queue.push(std::make_pair(current.first, 1));
				}
				else if(current.second == -1)
				{
					current.first->left =
							std::make_shared<typename ds::bst<T>::node_type>(converter(word.str()));
					queue.push(std::make_pair(current.first->left, -1));
					queue.push(std::make_pair(current.first->left, 1));
				}
				else
				{
					current.first->right=
							std::make_shared<typename ds::bst<T>::node_type>(converter(word.str()));
					queue.push(std::make_pair(current.first->right, -1));
					queue.push(std::make_pair(current.first->right, 1));
				}
				++it;
			}
			parsing_value = !parsing_value;
		}
		else if(*it == '\\')
		{
			++it;
			word << *it;
		}
		else if(!parsing_value && *it == 'X')
		{
			if(queue.empty())
			{
				queue.pop();
			}
		}
		else
		{
			word << *it;
		}
	}
	return tree;
}

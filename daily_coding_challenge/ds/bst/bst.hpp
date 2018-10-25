#ifndef __BST_HPP__
#define __BST_HPP__

#include <memory>
#include <libdevmapper.h>

namespace ds
{

	template<typename T>
	struct bst_node
	{
		/*Type alias*/
		using value_type = T;
		using node_type = bst_node<value_type>;
		using node_ptr = std::shared_ptr<node_type>;

		T value;
		node_ptr left;
		node_ptr right;

		template<typename T1>
		explicit bst_node(T1 &&val, node_ptr left = nullptr, node_ptr right = nullptr);
	};

	/*TODO: implement ability to add template parameter for comparesent*/
	template<typename T>
	class bst
	{
		/*Type alias*/
		public:
			using value_type = T;
			using node_type = bst_node<value_type>;
			using cnode_type = const bst_node<value_type>;
			using node_ptr = std::shared_ptr<node_type>;
			using cnode_ptr = std::shared_ptr<cnode_type>;

		private:
			node_ptr root_;
			int size_;
		
		public:
			bst();

			/*Is this smart*/
			template<typename T1>
			void insert(T1 &&v);
			inline int size() const;
			inline node_ptr root();
			inline cnode_ptr croot() const;
	};

	template<typename T>
	template<typename T1>
	bst_node<T>::bst_node(T1 &&val, node_ptr left, node_ptr right)
		:	value(std::forward<T1>(val)), left(std::move(left)),
			right(std::move(right))
	{}

	template<typename T>
	bst<T>::bst()
		:	root_(nullptr), size_(0)
	{}

	template<typename T>
	template<typename T1>
	void bst<T>::insert(T1 &&v)
	{
		if(!root_)
		{
			root_ = std::make_shared<node_type>(std::forward<T1>(v));
			++size_;
			return ;
		}

		/*Because first run on a loop should be nullptr*/
		node_ptr prev(nullptr);
		node_ptr curr(root_);

		while(curr)
		{
			if(v <= curr->value)			
			{
				prev = curr;
				curr = curr->left;
			}
			else
			{
				prev = curr;
				curr = curr->right;
			}
		}

		if(v <= prev->value)
		{
			prev->left = std::make_shared<node_type>(std::forward<T1>(v));
		}
		else
		{
			prev->right = std::make_shared<node_type>(std::forward<T1>(v));
		}

		++size_;
	}

	template<typename T>
	int bst<T>::size() const
	{
		return size_;
	}

	template<typename T>
	typename bst<T>::node_ptr bst<T>::root()
	{
		return root_;
	}

	template<typename T>
	typename bst<T>::cnode_ptr bst<T>::croot() const
	{
		return std::const_pointer_cast<cnode_type>(root_);
	}



}

#endif
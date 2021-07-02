#ifndef RBT_NODE_HPP
#define RBT_NODE_HPP

#include <cstdlib>

namespace ft
{
	template <class ValueType>
	class rbt_node
	{
	public:
		ValueType val;
		bool is_red;
		rbt_node* parent;
		rbt_node* left;
		rbt_node* right;

		rbt_node() :
			is_red(true),
			parent(NULL),
			left(NULL),
			right(NULL)
		{
			return;
		}

		rbt_node(rbt_node const& src) :
			is_red(src.is_red),
			parent(src.parent),
			left(src.left),
			right(src.right)
		{
			return;
		}

		~rbt_node()
		{
			return;
		}

		rbt_node& operator=(rbt_node const& rhs)
		{
			this->is_red = rhs.is_red;
			this->parent = rhs.parent;
			this->left = rhs.left;
			this->right = rhs.right;
			return *this;
		}

		rbt_node* get_grand_parent() const
		{
			if (this->parent == NULL) {
				return NULL;
			}
			return this->parent->parent;
		}

		rbt_node* get_uncle() const
		{
			rbt_node* grand_parent = get_grand_parent();
			if (grand_parent == NULL) {
				return NULL;
			}
			if (grand_parent->left == this->parent) {
				return grand_parent->right;
			}
			else {
				return grand_parent->left;
			}
		}

		rbt_node* get_relative_max()
		{
			rbt_node* max = this;
			while (max->right->right && max != max->right->left) {
				max = max->right;
			}
			return max;
		}
	};
}

#endif

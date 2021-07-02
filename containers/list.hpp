#ifndef LIST_HPP
#define LIST_HPP

#include <iterator>
#include <cstddef>
#include <memory>

#include "enable_if.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "comparaison.hpp"

namespace ft
{
	template < class T >
	struct doubly_linked_list
	{
		doubly_linked_list* prev;
		T val;
		doubly_linked_list* next;
	};

	template < class T, class Alloc = std::allocator<T> >
	class list
	{
	protected:
		typedef doubly_linked_list<T> doubly_linked_list;

	public:
		// Member types

		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		// Iterators
		class const_iterator;

		class iterator : std::bidirectional_iterator_tag
		{
		public:
			typedef typename ft::iterator_traits<pointer>::value_type value_type;
			typedef typename ft::iterator_traits<pointer>::difference_type difference_type;
			typedef pointer pointer;
			typedef typename ft::iterator_traits<pointer>::reference reference;
			typedef std::bidirectional_iterator_tag iterator_category;

			doubly_linked_list* node_;

			iterator() :
				node_(NULL)
			{
				return;
			}

			iterator(doubly_linked_list* node) :
				node_(node)
			{
				return;
			}

			iterator(iterator const& src) :
				node_(src.node_)
			{
				return;
			}

			virtual ~iterator()
			{
				return;
			}

			iterator& operator=(iterator const& rhs)
			{
				this->node_ = rhs.node_;
				return *this;
			}

			bool operator==(const_iterator const& rhs) const
			{
				return this->node_ == rhs.node_;
			}

			bool operator!=(const_iterator const& rhs) const
			{
				return this->node_ != rhs.node_;
			}

			iterator& operator++()
			{
				this->node_ = this->node_->next;
				return *this;
			}

			iterator operator++(int)
			{
				iterator tmp = *this;
				++(*this);
				return tmp;
			}

			iterator& operator--()
			{
				this->node_ = this->node_->prev;
				return *this;
			}

			iterator operator--(int)
			{
				iterator tmp = *this;
				--(*this);
				return tmp;
			}

			reference operator*() const
			{
				return this->node_->val;
			}

			pointer operator->() const
			{
				return &this->node_->val;
			}
		};

		class const_iterator : std::bidirectional_iterator_tag
		{
		public:
			typedef typename ft::iterator_traits<const_pointer>::value_type value_type;
			typedef typename ft::iterator_traits<const_pointer>::difference_type difference_type;
			typedef const_pointer pointer;
			typedef typename ft::iterator_traits<const_pointer>::reference reference;
			typedef std::bidirectional_iterator_tag iterator_category;

			doubly_linked_list const* node_;

			const_iterator() :
				node_(NULL)
			{
				return;
			}

			const_iterator(doubly_linked_list const* node) :
				node_(node)
			{
				return;
			}

			const_iterator(iterator const& src) :
				node_(src.node_)
			{
				return;
			}

			const_iterator(const_iterator const& src) :
				node_(src.node_)
			{
				return;
			}

			virtual ~const_iterator()
			{
				return;
			}

			const_iterator& operator=(iterator const& rhs)
			{
				this->node_ = rhs.node_;
				return *this;
			}

			const_iterator& operator=(const_iterator const& rhs)
			{
				this->node_ = rhs.node_;
				return *this;
			}

			bool operator==(const_iterator const& rhs) const
			{
				return this->node_ == rhs.node_;
			}

			bool operator!=(const_iterator const& rhs) const
			{
				return this->node_ != rhs.node_;
			}

			bool operator==(iterator const& rhs) const
			{
				return this->node_ == rhs.node_;
			}

			bool operator!=(iterator const& rhs) const
			{
				return this->node_ != rhs.node_;
			}

			const_iterator& operator++()
			{
				this->node_ = this->node_->next;
				return *this;
			}

			const_iterator operator++(int)
			{
				const_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			const_iterator& operator--()
			{
				this->node_ = this->node_->prev;
				return *this;
			}

			const_iterator operator--(int)
			{
				const_iterator tmp = *this;
				--(*this);
				return tmp;
			}

			reference operator*() const
			{
				return this->node_->val;
			}

			pointer operator->() const
			{
				return &this->node_->val;
			}
		};

		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef std::size_t size_type;

		explicit list(allocator_type const& alloc = allocator_type()) :
			allocator_(alloc),
			ghost_node_(this->allocator_node_.allocate(1))
		{
			this->ghost_node_->prev = this->ghost_node_;
			this->ghost_node_->next = this->ghost_node_;
			return;
		}

		explicit list(size_type n, value_type const& val = value_type(),
                allocator_type const& alloc = allocator_type()) :
			allocator_(alloc),
			ghost_node_(this->allocator_node_.allocate(1))
		{
			this->ghost_node_->prev = this->ghost_node_;
			this->ghost_node_->next = this->ghost_node_;
			this->assign(n, val);
			return;
		}

		template <class InputIterator>
		list(InputIterator first, InputIterator last,
				allocator_type const& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				bool>::type = true) :
			allocator_(alloc),
			ghost_node_(this->allocator_node_.allocate(1))
		{
			this->ghost_node_->prev = this->ghost_node_;
			this->ghost_node_->next = this->ghost_node_;
			this->assign<InputIterator>(first, last);
			return;
		}

		list(list const& x) :
			allocator_(x.allocator_), 
			ghost_node_(this->allocator_node_.allocate(1))
		{
			this->ghost_node_->prev = this->ghost_node_;
			this->ghost_node_->next = this->ghost_node_;
			*this = x;
			return;
		}

		~list()
		{
			this->clear();
			this->allocator_node_.deallocate(this->ghost_node_, 1);
			return;
		}

		list& operator=(list const& x)
		{
			this->clear();
			this->assign(x.begin(), x.end());
			return *this;
		}

		iterator begin()
		{
			return iterator(this->ghost_node_->next);
		}

		const_iterator begin() const
		{
			return const_iterator(this->ghost_node_->next);
		}

		iterator end()
		{
			return iterator(this->ghost_node_);
		}

		const_iterator end() const
		{
			return const_iterator(this->ghost_node_);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(this->ghost_node_);
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(this->ghost_node_);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(this->ghost_node_->next);
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(this->ghost_node_->next);
		}

		bool empty() const
		{
			return this->ghost_node_->next == this->ghost_node_;
		}

		size_type size() const
		{
			size_type size = 0;
			
			for (const_iterator it = this->begin(), ite = this->end(); it != ite;
					++it) {
				size++;
			}
			return size;
		}

		size_type max_size() const
		{
			return this->allocator_node_.max_size();
		}

		reference front()
		{
			return this->ghost_node_->next->val;
		}

		const_reference front() const
		{
			return this->ghost_node_->next->val;
		}

		reference back()
		{
			return this->ghost_node_->prev->val;
		}

		const_reference back() const
		{
			return this->ghost_node_->prev->val;
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
		{
			this->clear();
			for (InputIterator it = first, ite = last; it != ite; ++it) {
				this->push_back(*it);
			}
			return;
		}

		void assign(size_type n, value_type const& val)
		{
			this->clear();
			while (n > 0) {
				this->push_back(val);
				n--;
			}
			return;
		}

		void push_front(value_type const& val)
		{
			doubly_linked_list* new_elem = this->allocator_node_.allocate(1);
			this->allocator_.construct(&new_elem->val, val);
			new_elem->prev = this->ghost_node_;
			new_elem->next = this->ghost_node_->next;
			this->ghost_node_->next->prev = new_elem;
			this->ghost_node_->next = new_elem;
			return;
		}

		void pop_front()
		{
			this->allocator_.destroy(&this->ghost_node_->next->val);
			doubly_linked_list* old_front = this->ghost_node_->next;
			this->ghost_node_->next = old_front->next;
			old_front->next->prev = this->ghost_node_;
			this->allocator_node_.deallocate(old_front, 1);
			return;
		}

		void push_back(value_type const& val)
		{
			doubly_linked_list* new_elem = this->allocator_node_.allocate(1);
			this->allocator_.construct(&new_elem->val, val);
			new_elem->prev = this->ghost_node_->prev;
			new_elem->next = this->ghost_node_;
			this->ghost_node_->prev->next = new_elem;
			this->ghost_node_->prev = new_elem;
			return;
		}

		void pop_back()
		{
			this->allocator_.destroy(&this->ghost_node_->prev->val);
			doubly_linked_list* old_back = this->ghost_node_->prev;
			this->ghost_node_->prev = old_back->prev;
			old_back->prev->next = this->ghost_node_;
			this->allocator_node_.deallocate(old_back, 1);
			return;
		}

		iterator insert(iterator position, value_type const& val)
		{
			doubly_linked_list* node = position.node_;
			doubly_linked_list* new_elem = this->allocator_node_.allocate(1);
			this->allocator_.construct(&new_elem->val, val);
			new_elem->prev = node->prev;
			new_elem->next = node;
			node->prev->next = new_elem;
			node->prev = new_elem;
			return --position;
		}

		void insert(iterator position, size_type n, value_type const& val)
		{
			while (n) {
				this->insert(position, val);
				n--;
			}
			return;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
		{
			for (InputIterator it = first, ite = last; it != ite; ++it) {
				this->insert(position, *it);
			}
			return;
		}

		iterator erase(iterator position)
		{
			doubly_linked_list* node = position.node_;
			node->prev->next = node->next;
			node->next->prev = node->prev;
			this->allocator_.destroy(&node->val);
			++position;
			this->allocator_node_.deallocate(node, 1);
			return position;
		}

		iterator erase(iterator first, iterator last)
		{
			iterator it = first;
			while (it != last) {
				iterator next(it.node_->next);
				this->erase(it);
				it = next;
			}
			return last;
		}

		void swap(list& x)
		{
			doubly_linked_list* tmp;
			tmp = this->ghost_node_;
			this->ghost_node_ = x.ghost_node_;
			x.ghost_node_ = tmp;
			return;
		}

		void resize(size_type n, value_type val = value_type())
		{
			size_type size = this->size();
			while (n < size) {
				this->pop_back();
				size--;
			}
			while (n > size) {
				this->push_back(val);
				size++;
			}
			return;
		}

		void clear()
		{
			doubly_linked_list* current = this->ghost_node_->next;
			while (current != this->ghost_node_)
			{
				doubly_linked_list* next = current->next;
				this->allocator_.destroy(&current->val);
				this->allocator_node_.deallocate(current, 1);
				current = next;
			}
			this->ghost_node_->prev = this->ghost_node_;
			this->ghost_node_->next = this->ghost_node_;
			return;
		}

		void splice(iterator position, list& x)
		{
			doubly_linked_list* node = position.node_;
			node->prev->next = x.ghost_node_->next;
			x.ghost_node_->next->prev = node->prev;
			x.ghost_node_->prev->next = node;
			node->prev = x.ghost_node_->prev;
			x.ghost_node_->prev = x.ghost_node_;
			x.ghost_node_->next = x.ghost_node_;
			return;
		}

		void splice(iterator position, list& x, iterator i)
		{
			static_cast<void>(x);
			this->move(position.node_, i.node_);
			return;
		}

		void splice(iterator position, list& x, iterator first, iterator last)
		{
			static_cast<void>(x);
			while (first != last) {
				iterator next(first.node_->next);
				this->move(position.node_, first.node_);
				first = next;
			}
			return;
		}

		void remove(value_type const& val)
		{
			for (iterator it = this->begin(), ite = this->end(); it != ite;
					++it) {
				if (*it == val) {
					--it;
					this->erase(iterator(it.node_->next));
				}
			}
			return;
		}

		template <class Predicate>
		void remove_if(Predicate pred)
		{
			for (iterator it = this->begin(), ite = this->end(); it != ite;
					++it) {
				if (pred(*it) == true) {
					--it;
					this->erase(iterator(it.node_->next));
				}
			}
			return;
		}

		void unique()
		{
			unique(this->is_equal_to);
			return;
		}

		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred)
		{
			for (iterator it = ++this->begin(), ite = this->end(); it != ite;
					++it) {
				iterator prev_it(it.node_->prev);
				if (binary_pred(*it, *prev_it) == true) {
					this->erase(it);
					it = prev_it;
				}
			}
			return;
		}

		void merge(list& x)
		{
			merge(x, this->is_less_than);
			return;
		}

		template <class Compare>
		void merge(list& x, Compare comp)
		{
			if (&x == this) {
				return;
			}
			iterator it_this = this->begin();
			iterator ite_this = this->end();
			iterator it = x.begin();
			iterator ite = x.end();
			while (it != ite && it_this != ite_this) {
				if (comp(*it, *it_this) == true) {
					++it;
					move(it_this.node_, it.node_->prev);
				}
				else {
					++it_this;
				}
			}
			while (it != ite) {
				++it;
				move(it_this.node_, it.node_->prev);
			}
			return;
		}

		void sort()
		{
			sort(this->is_less_than);
			return;
		}

		template <class Compare>
		void sort(Compare comp)
		{
			merge_sort(0, this->size(), comp);
			return;
		}

		void reverse()
		{
			size_type nb_exchange = this->size() / 2;
			iterator it = this->begin();
			iterator ite = this->end();
			ite--;
			while (nb_exchange > 0) {
				++it;
				--ite;
				this->exchange(it.node_->prev, ite.node_->next);
				--nb_exchange;
			}
			return;
		}

		allocator_type get_allocator() const
		{
			return this->allocator_;
		}

	protected:
		// Attributes

		allocator_type allocator_;
		typename allocator_type::template rebind<doubly_linked_list>::other allocator_node_;
		doubly_linked_list* ghost_node_;

		static bool is_less_than(value_type const& val1, value_type const& val2)
		{
			return val1 < val2;
		}

		static bool is_equal_to(value_type const& val1, value_type const& val2)
		{
			return val1 == val2;
		}

		void exchange(doubly_linked_list* first_node,
				doubly_linked_list* second_node)
		{
			doubly_linked_list* first_node_prev = first_node->prev;
			doubly_linked_list* first_node_next = first_node->next;
			doubly_linked_list* second_node_prev = second_node->prev;
			doubly_linked_list* second_node_next = second_node->next;
			first_node_prev->next = second_node;
			first_node_next->prev = second_node;
			second_node_prev->next = first_node;
			second_node_next->prev = first_node;
			if (first_node_next == second_node) {
				first_node->prev = second_node;
				first_node->next = second_node_next;
				second_node->prev = first_node_prev;
				second_node->next = first_node;
			}
			else if (second_node_next == first_node) {
				first_node->prev = second_node_prev;
				first_node->next = second_node;
				second_node->prev = first_node;
				second_node->next = first_node_next;
			}
			else {
				first_node->prev = second_node_prev;
				first_node->next = second_node_next;
				second_node->prev = first_node_prev;
				second_node->next = first_node_next;
			}
			return;
		}

		void move(doubly_linked_list* position,
				doubly_linked_list* elem)
		{
			elem->prev->next = elem->next;
			elem->next->prev = elem->prev;
			elem->prev = position->prev;
			elem->next = position;
			position->prev->next = elem;
			position->prev = elem;
			return;
		}

		template <class Compare>
		void merge_halves(doubly_linked_list* left_first_node,
				doubly_linked_list* right_first_node, size_type size,
				Compare comp)
		{
			size_type right_node_left = size / 2;
			for (size_type i = 0; i < size && right_node_left > 0; i++) {
				if (comp(right_first_node->val, left_first_node->val) == true) {
					right_first_node = right_first_node->next;
					move(left_first_node, right_first_node->prev);
					right_node_left--;
				}
				else {
					left_first_node = left_first_node->next;
				}
			}
			return;
		}

		template <class Compare>
		void merge_sort(size_type index_first_node, size_type size, Compare comp)
		{
			if (size < 2) {
				return;
			}
			size_type left_size = size / 2 + size % 2;
			doubly_linked_list* first_node = this->begin().node_;
			for (size_type i = 0; i < index_first_node; i++) {
				first_node = first_node->next;
			}
			doubly_linked_list* right_first_node = first_node;
			for (size_type i = 0; i < left_size; i++) {
				right_first_node = right_first_node->next;
			}
			merge_sort(index_first_node, left_size, comp);
			merge_sort(index_first_node + left_size, size / 2, comp);
			first_node = this->begin().node_;
			for (size_type i = 0; i < index_first_node; i++) {
				first_node = first_node->next;
			}
			right_first_node = first_node;
			for (size_type i = 0; i < left_size; i++) {
				right_first_node = right_first_node->next;
			}
			merge_halves(first_node, right_first_node, size, comp);
			return;
		}
	};

	template <class T, class Alloc>
	bool operator==(ft::list<T,Alloc> const& lhs, ft::list<T,Alloc> const& rhs)
	{
		if (lhs.size() != rhs.size()) {
			return false;
		}
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool operator!=(ft::list<T,Alloc> const& lhs, ft::list<T,Alloc> const& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(ft::list<T,Alloc> const& lhs, ft::list<T,Alloc> const& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(),
				rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<=(ft::list<T,Alloc> const& lhs, ft::list<T,Alloc> const& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>(ft::list<T,Alloc> const& lhs, ft::list<T,Alloc> const& rhs)
	{
		return rhs < lhs;
	}

	template <class T, class Alloc>
	bool operator>=(ft::list<T,Alloc> const& lhs, ft::list<T,Alloc> const& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap(list<T,Alloc>& x, list<T,Alloc>& y)
	{
		x.swap(y);
		return;
	}
}

#endif

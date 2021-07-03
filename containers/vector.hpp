#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <sstream>

#include "enable_if.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "comparaison.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		class iterator;
		class const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef std::size_t size_type;

		class iterator : std::random_access_iterator_tag
		{
		public:
			typedef typename ft::iterator_traits<pointer>::value_type value_type;
			typedef typename ft::iterator_traits<pointer>::difference_type difference_type;
			typedef pointer pointer;
			typedef typename ft::iterator_traits<pointer>::reference reference;
			typedef std::random_access_iterator_tag iterator_category;

			pointer ptr_;

			iterator() :
				ptr_(NULL)
			{
				return;
			}

			iterator(pointer ptr) :
				ptr_(ptr)
			{
				return;
			}

			iterator(iterator const& src) :
				ptr_(src.ptr_)
			{
				return;
			}

			virtual ~iterator()
			{
				return;
			}

			iterator& operator=(iterator const& rhs)
			{
				this->ptr_ = rhs.ptr_;
				return *this;
			}

			bool operator==(const_iterator const& rhs) const
			{
				return this->ptr_ == rhs.ptr_;
			}

			bool operator!=(const_iterator const& rhs) const
			{
				return this->ptr_ != rhs.ptr_;
			}

			reference operator*() const
			{
				return *this->ptr_;
			}

			pointer operator->() const
			{
				return this->ptr_;
			}

			iterator& operator++()
			{
				this->ptr_++;
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
				this->ptr_--;
				return *this;
			}

			iterator operator--(int)
			{
				iterator tmp = *this;
				--(*this);
				return tmp;
			}

			iterator operator+(difference_type const& n) const
			{
				return this->ptr_ + n;
			}

			friend iterator operator+(difference_type const& n,
					iterator const& rhs)
			{
				return rhs.ptr_ + n;
			}

			iterator operator-(difference_type const& n) const
			{
				return this->ptr_ - n;
			}

			difference_type operator-(const_iterator const& rhs) const
			{
				return this->ptr_ - rhs.ptr_;
			}

			bool operator<(const_iterator const& rhs) const
			{
				return this->ptr_ < rhs.ptr_;
			}

			bool operator>(const_iterator const& rhs) const
			{
				return this->ptr_ > rhs.ptr_;
			}

			bool operator<=(const_iterator const& rhs) const
			{
				return this->ptr_ <= rhs.ptr_;
			}

			bool operator>=(const_iterator const& rhs) const
			{
				return this->ptr_ >= rhs.ptr_;
			}

			iterator& operator+=(difference_type const& n)
			{
				this->ptr_ += n;
				return *this;
			}

			iterator& operator-=(difference_type const& n)
			{
				this->ptr_ -= n;
				return *this;
			}

			reference operator[](difference_type const& i)
			{
				return this->ptr_[i];
			}
		};

		class const_iterator : std::random_access_iterator_tag
		{
		public:
			typedef typename ft::iterator_traits<const_pointer>::value_type value_type;
			typedef typename ft::iterator_traits<const_pointer>::difference_type difference_type;
			typedef const_pointer pointer;
			typedef typename ft::iterator_traits<const_pointer>::reference reference;
			typedef std::random_access_iterator_tag iterator_category;

			pointer ptr_;

			const_iterator() :
				ptr_(NULL)
			{
				return;
			}

			const_iterator(pointer ptr) :
				ptr_(ptr)
			{
				return;
			}

			const_iterator(const_iterator const& src) :
				ptr_(src.ptr_)
			{
				return;
			}

			const_iterator(iterator const& src) :
				ptr_(src.ptr_)
			{
				return;
			}

			virtual ~const_iterator()
			{
				return;
			}

			const_iterator& operator=(const_iterator const& rhs)
			{
				this->ptr_ = rhs.ptr_;
				return *this;
			}

			bool operator==(const_iterator const& rhs) const
			{
				return this->ptr_ == rhs.ptr_;
			}

			bool operator!=(const_iterator const& rhs) const
			{
				return this->ptr_ != rhs.ptr_;
			}

			reference operator*() const
			{
				return *this->ptr_;
			}

			pointer operator->() const
			{
				return this->ptr_;
			}

			const_iterator& operator++()
			{
				this->ptr_++;
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
				this->ptr_--;
				return *this;
			}

			const_iterator operator--(int)
			{
				const_iterator tmp = *this;
				--(*this);
				return tmp;
			}

			const_iterator operator+(difference_type const& n) const
			{
				return this->ptr_ + n;
			}

			friend const_iterator operator+(difference_type const& n,
					const_iterator const& rhs)
			{
				return rhs.ptr_ + n;
			}

			const_iterator operator-(difference_type const& n) const
			{
				return this->ptr_ - n;
			}

			difference_type operator-(const_iterator const& rhs) const
			{
				return this->ptr_ - rhs.ptr_;
			}


			bool operator<(const_iterator const& rhs) const
			{
				return this->ptr_ < rhs.ptr_;
			}

			bool operator>(const_iterator const& rhs) const
			{
				return this->ptr_ > rhs.ptr_;
			}

			bool operator<=(const_iterator const& rhs) const
			{
				return this->ptr_ <= rhs.ptr_;
			}

			bool operator>=(const_iterator const& rhs) const
			{
				return this->ptr_ >= rhs.ptr_;
			}

			const_iterator& operator+=(difference_type const& n)
			{
				this->ptr_ += n;
				return *this;
			}

			const_iterator& operator-=(difference_type const& n)
			{
				this->ptr_ -= n;
				return *this;
			}

			reference operator[](difference_type const& i) const
			{
				return this->ptr_[i];
			}
		};

		explicit vector(allocator_type const& alloc = allocator_type()) :
			alloc_(alloc),
			size_(0),
			capacity_(0),
			array_(this->alloc_.allocate(this->capacity_))
		{
			return;
		}

		explicit vector(size_type n, value_type const& val = value_type(),
				allocator_type const& alloc = allocator_type()) :
			alloc_(alloc),
			size_(n),
			capacity_(n),
			array_(this->alloc_.allocate(this->capacity_))
		{
			for (size_type i = 0; i < n; i++) {
				this->alloc_.construct(this->array_ + i, val);
			}
			return;
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
				allocator_type const& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				bool>::type = true) :
			alloc_(alloc),
			size_(0),
			capacity_(0),
			array_(NULL)
		{
			size_type size = iteration_size(first, last);
			this->size_ = size;
			this->capacity_ = size;
			this->array_ = this->alloc_.allocate(this->capacity_);
			pointer it = this->array_;
			while (first != last) {
				this->alloc_.construct(it, *first);
				it++;
				first++;
			}
			return;
		}

		vector(vector const& x) :
			alloc_(x.alloc_),
			size_(x.size_),
			capacity_(x.size_),
			array_(this->alloc_.allocate(this->capacity_))
		{
			for (size_type i = 0, size = x.size_; i < size; ++i) {
				this->alloc_.construct(this->array_ + i, x.array_[i]);
			}
			return;
		}

		~vector()
		{
			this->clear();
			this->alloc_.deallocate(this->array_, this->capacity_);
		}

		vector& operator=(vector const& x)
		{
			this->clear();
			if (this->capacity_ < x.size_) {
				this->alloc_.deallocate(this->array_, this->capacity_);
				this->capacity_ = x.size_;
				this->array_ = this->alloc_.allocate(this->capacity_);
			}
			this->size_ = x.size_;
			for (size_type i = 0, size = x.size_; i < size; ++i) {
				this->alloc_.construct(this->array_ + i, x.array_[i]);
			}
			return *this;
		}

		iterator begin()
		{
			return iterator(this->array_);
		}

		const_iterator begin() const
		{
			return const_iterator(this->array_);
		}

		iterator end()
		{
			return iterator(this->array_ + this->size_);
		}

		const_iterator end() const
		{
			return const_iterator(this->array_ + this->size_);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(this->array_ + this->size_);
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(this->array_ + this->size_);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(this->array_);
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(this->array_);
		}

		size_type size() const
		{
			return this->size_;
		}

		size_type max_size() const
		{
			return this->alloc_.max_size();
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n < this->size_) {
				this->size_ = n;
			}
			else {
				this->insert(this->end(), n - this->size_, val);
			}
			return;
		}

		size_type capacity() const
		{
			return this->capacity_;
		}

		bool empty() const
		{
			return this->size_ == 0;
		}

		void reserve(size_type n)
		{
			if (n > this->max_size()) {
				throw std::length_error("vector::reserve");
			}
			else if (n <= this->capacity_) {
				return;
			}
			pointer old = this->array_;
			this->array_ = this->alloc_.allocate(n);
			for (pointer it = this->array_,
					old_it = old, old_ite = old + this->size_;
					old_it != old_ite; ++it, ++old_it) {
				this->alloc_.construct(it, *old_it);
				this->alloc_.destroy(old_it);
			}
			this->alloc_.deallocate(old, this->capacity_);
			this->capacity_ = n;
			return;
		}

		reference operator[](size_type n)
		{
			return this->array_[n];
		}

		const_reference operator[](size_type n) const
		{
			return this->array_[n];
		}

		reference at(size_type n)
		{
			if (n >= this->size_) {
				std::ostringstream oss;
				oss << "vector::_M_range_check: __n (which is " << n
					<< ") >= this->size() (which is " << this->size_ << ")";
				throw std::out_of_range(oss.str());
			}
			return this->array_[n];
		}

		const_reference at(size_type n) const
		{
			if (n >= this->size_) {
				std::ostringstream oss;
				oss << "vector::_M_range_check: __n (which is " << n
					<< ") >= this->size() (which is " << this->size_ << ")";
				throw std::out_of_range(oss.str());
			}
			return this->array_[n];
		}

		reference front()
		{
			return this->array_[0];
		}

		const_reference front() const
		{
			return this->array_[0];
		}

		reference back()
		{
			return this->array_[this->size_ - 1];
		}

		const_reference back() const
		{
			return this->array_[this->size_ - 1];
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				bool>::type = true)
		{
			this->clear();
			size_type size = iteration_size(first, last);
			this->size_ = size;
			if (this->capacity_ < size) {
				this->alloc_.deallocate(this->array_, this->capacity_);
				this->capacity_ = size;
				this->array_ = this->alloc_.allocate(this->capacity_);
			}
			pointer it = this->array_;
			while (first != last) {
				this->alloc_.construct(it, *first);
				it++;
				first++;
			}
			return;
		}

		void assign(size_type n, const value_type& val)
		{
			this->clear();
			this->size_ = n;
			if (this->capacity_ < n) {
				this->alloc_.deallocate(this->array_, this->capacity_);
				this->capacity_ = n;
				this->array_ = this->alloc_.allocate(this->capacity_);
			}
			for (size_type i = 0; i < n; ++i) {
				this->alloc_.construct(this->array_ + i, val);
			}
			return;
		}

		void push_back(value_type const& val)
		{
			if (this->capacity_ == 0) {
				this->reserve(1);
			}
			else if (this->size_ == this->capacity_) {
				this->reserve(this->capacity_ * 2);
			}
			this->alloc_.construct(this->array_ + this->size_, val);
			this->size_++;
			return;
		}

		void pop_back()
		{
			this->size_--;
			this->alloc_.destroy(this->array_ + this->size_);
			return;
		}

		iterator insert(iterator position, value_type const& val)
		{
			difference_type index = position.ptr_ - this->array_;
			if (this->capacity_ == 0) {
				this->reserve(1);
			}
			else if (this->size_ == this->capacity_) {
				this->reserve(this->capacity_ * 2);
			}
			for (pointer it = this->array_ + this->size_,
					ite = this->array_ + index; it != ite; --it) {
				this->alloc_.construct(it, *(it - 1));
				this->alloc_.destroy(it - 1);
			}
			this->alloc_.construct(this->array_ + index, val);
			this->size_++;
			return iterator(this->array_ + index);
		}

		void insert(iterator position, size_type n, value_type const& val)
		{
			if (n == 0) {
				return;
			}

			difference_type index = position.ptr_ - this->array_;
			if (this->size_ + n > this->size_ * 2) {
				this->reserve(this->size_ + n);
			}
			else if (this->size_ + n > this->capacity_) {
				this->reserve(this->size_ * 2);
			}
			for (pointer it = this->array_ + this->size_ - 1 + n,
					ite = this->array_ + index - 1 + n; it != ite; --it) {
				this->alloc_.construct(it, *(it - n));
				this->alloc_.destroy(it - n);
			}
			this->size_ += n;
			while (n > 0) {
				this->alloc_.construct(this->array_ + index - 1 + n, val);
				n--;
			}
			return;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				bool>::type = true)
		{
			if (first == last) {
				return;
			}

			difference_type index = position.ptr_ - this->array_;
			size_type n = iteration_size(first, last);
			if (this->size_ + n > this->size_ * 2) {
				this->reserve(this->size_ + n);
			}
			else if (this->size_ + n > this->capacity_) {
				this->reserve(this->size_ * 2);
			}
			for (pointer it = this->array_ + this->size_ - 1 + n,
					ite = this->array_ + index - 1 + n; it != ite; --it) {
				this->alloc_.construct(it, *(it - n));
				this->alloc_.destroy(it - n);
			}
			this->size_ += n;
			while (n > 0) {
				last--;
				this->alloc_.construct(this->array_ + index - 1 + n, *last);
				n--;
			}
			return;
		}

		iterator erase(iterator position)
		{
			this->alloc_.destroy(position.ptr_);
			for (pointer it = position.ptr_, ite = this->end().ptr_ - 1;
					it != ite; ++it) {
				this->alloc_.construct(it, *(it + 1));
				this->alloc_.destroy(it + 1);
			}
			this->size_--;
			return position;
		}

		iterator erase(iterator first, iterator last)
		{
			if (first == last) {
				return first;
			}

			size_type n = 0;
			for (pointer it = first.ptr_; it != last.ptr_; ++it) {
				this->alloc_.destroy(first.ptr_);
				n++;
			}
			for (pointer it = first.ptr_, ite = this->end().ptr_ - n;
					it != ite; ++it) {
				this->alloc_.construct(it, *(it + n));
				this->alloc_.destroy(it + n);
			}
			this->size_ -= n;
			return first;
		}

		void swap(vector& x)
		{
			size_type st_tmp = this->size_;
			this->size_ = x.size_;
			x.size_ = st_tmp;
			st_tmp = this->capacity_;
			this->capacity_ = x.capacity_;
			x.capacity_ = st_tmp;
			pointer p_tmp = this->array_;
			this->array_ = x.array_;
			x.array_ = p_tmp;
			return;
		}

		void clear()
		{
			for (size_type i = 0, size = this->size_; i < size; ++i) {
				this->alloc_.destroy(this->array_ + i);
			}
			this->size_ = 0;
			return;
		}

		allocator_type get_allocator() const
		{
			return this->alloc_;
		}

	protected:
		allocator_type alloc_;
		size_type size_;
		size_type capacity_;
		pointer array_;

		template <class InputIterator>
		size_type iteration_size(InputIterator it, InputIterator ite)
		{
			size_type size = 0;
			while (it != ite) {
				size++;
				it++;
			}
			return size;
		}
	};

	template <class T, class Alloc>
	bool operator==(vector<T,Alloc> const& lhs, vector<T,Alloc> const& rhs)
	{
		if (lhs.size() != rhs.size()) {
			return false;
		}
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool operator!=(vector<T,Alloc> const& lhs, vector<T,Alloc> const& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(vector<T,Alloc> const& lhs, vector<T,Alloc> const& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(),
				rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<=(vector<T,Alloc> const& lhs, vector<T,Alloc> const& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>(vector<T,Alloc> const& lhs, vector<T,Alloc> const& rhs)
	{
		return rhs < lhs;
	}

	template <class T, class Alloc>
	bool operator>=(vector<T,Alloc> const& lhs, vector<T,Alloc> const& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
		return;
	}
}

#endif

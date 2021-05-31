#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iterator>

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;

		reverse_iterator() :
			iterator()
		{
			return;
		}

		explicit reverse_iterator(iterator_type it) :
			iterator(it)
		{
			return;
		}

		template <class Iter>
		reverse_iterator(reverse_iterator<Iter> const& rev_it) :
			iterator(rev_it.base())
		{
			return;
		}

		iterator_type base() const
		{
			return this->iterator;
		}

		reference operator*() const
		{
			iterator_type tmp(iterator);
			tmp--;
			return *tmp;
		}

		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(this->iterator - n);
		}

		reverse_iterator& operator++()
		{
			this->iterator--;
			return *this;
		}

		reverse_iterator  operator++(int)
		{
			reverse_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		reverse_iterator& operator+=(difference_type n)
		{
			this->iterator -= n;
			return *this;
		}

		reverse_iterator& operator--()
		{
			this->iterator++;
			return *this;
		}

		reverse_iterator  operator--(int)
		{
			reverse_iterator tmp = *this;
			--(*this);
			return tmp;
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(this->iterator + n);
		}

		reverse_iterator& operator-=(difference_type n)
		{
			this->iterator += n;
			return *this;
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		reference operator[](difference_type n)
		{
			iterator_type tmp(iterator);
			tmp--;
			return tmp.operator[](-n);
		}

	private:
		iterator_type iterator;
	};

	template <class IteratorL, class IteratorR>
	bool operator==(reverse_iterator<IteratorL> const& lhs,
			reverse_iterator<IteratorR> const& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class IteratorL, class IteratorR>
	bool operator!=(reverse_iterator<IteratorL> const& lhs,
			reverse_iterator<IteratorR> const& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class IteratorL, class IteratorR>
	bool operator<(reverse_iterator<IteratorL> const& lhs,
			reverse_iterator<IteratorR> const& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class IteratorL, class IteratorR>
	bool operator<=(reverse_iterator<IteratorL> const& lhs,
			reverse_iterator<IteratorR> const& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class IteratorL, class IteratorR>
	bool operator>(reverse_iterator<IteratorL> const& lhs,
			reverse_iterator<IteratorR> const& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class IteratorL, class IteratorR>
	bool operator>=(reverse_iterator<IteratorL> const& lhs,
			reverse_iterator<IteratorR> const& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(
			typename reverse_iterator<Iterator>::difference_type n,
			reverse_iterator<Iterator> const& rev_it)
	{
		return rev_it + n;
	}

	template <class IteratorL, class IteratorR>
	typename reverse_iterator<IteratorL>::difference_type operator-(
			reverse_iterator<IteratorL> const& lhs,
			reverse_iterator<IteratorR> const& rhs)
	{
		return rhs.base() - lhs.base();
	}
}

#endif

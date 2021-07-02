#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template < class T, class Container = vector<T> >
	class stack;

	template <class T, class Container>
	bool operator==(stack<T,Container> const& lhs, stack<T,Container> const& rhs)
	{
		return lhs.ctnr_ == rhs.ctnr_;
	}

	template <class T, class Container>
	bool operator!=(stack<T,Container> const& lhs, stack<T,Container> const& rhs)
	{
		return lhs.ctnr_ != rhs.ctnr_;
	}

	template <class T, class Container>
	bool operator<(stack<T,Container> const& lhs, stack<T,Container> const& rhs)
	{
		return lhs.ctnr_ < rhs.ctnr_;
	}

	template <class T, class Container>
	bool operator<=(stack<T,Container> const& lhs, stack<T,Container> const& rhs)
	{
		return lhs.ctnr_ <= rhs.ctnr_;
	}

	template <class T, class Container>
	bool operator>(stack<T,Container> const& lhs, stack<T,Container> const& rhs)
	{
		return lhs.ctnr_ > rhs.ctnr_;
	}

	template <class T, class Container>
	bool operator>=(stack<T,Container> const& lhs, stack<T,Container> const& rhs)
	{
		return lhs.ctnr_ >= rhs.ctnr_;
	}

	template <class T, class Container>
	class stack
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef std::size_t size_type;

	protected:
		container_type ctnr_;

	public:
		explicit stack(container_type const& ctnr = container_type()) :
			ctnr_(ctnr)
		{
			return;
		}

		bool empty() const
		{
			return ctnr_.empty();
		}

		size_type size() const
		{
			return ctnr_.size();
		}

		value_type& top()
		{
			return ctnr_.back();
		}

		value_type const& top() const
		{
			return ctnr_.back();
		}

		void push(value_type const& val)
		{
			return ctnr_.push_back(val);
		}

		void pop()
		{
			return ctnr_.pop_back();
		}

		friend bool operator== <T, Container>(stack const& lhs, stack const& rhs);
		friend bool operator!= <T, Container>(stack const& lhs, stack const& rhs);
		friend bool operator< <T, Container>(stack const& lhs, stack const& rhs);
		friend bool operator<= <T, Container>(stack const& lhs, stack const& rhs);
		friend bool operator> <T, Container>(stack const& lhs, stack const& rhs);
		friend bool operator>= <T, Container>(stack const& lhs, stack const& rhs);
	};
}

#endif

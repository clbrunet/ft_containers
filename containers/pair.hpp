#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair() :
			first(),
			second()
		{
			return;
		}

		template <class U, class V>
		pair(pair<U,V> const& pr) :
			first(pr.first),
			second(pr.second)
		{
			return;
		}

		pair(first_type const& a, second_type const& b) :
			first(a),
			second(b)
		{
			return;
		}

		~pair()
		{
			return;
		}


		pair& operator=(pair const& pr)
		{
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		}
	};

	template <class T1, class T2>
	bool operator==(ft::pair<T1,T2> const& lhs, ft::pair<T1,T2> const& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(ft::pair<T1,T2> const& lhs, ft::pair<T1,T2> const& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(ft::pair<T1,T2> const& lhs, ft::pair<T1,T2> const& rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(ft::pair<T1,T2> const& lhs, ft::pair<T1,T2> const& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(ft::pair<T1,T2> const& lhs, ft::pair<T1,T2> const& rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(ft::pair<T1,T2> const& lhs, ft::pair<T1,T2> const& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return pair<T1,T2>(x,y);
	}
}

#endif

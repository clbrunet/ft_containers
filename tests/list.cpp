#include "tests.hpp"

namespace tests { namespace list
{
	void member_types()
	{
		std::cout << "Member Types tests : OK if you see this" << std::endl;
		ft::list<int>::value_type vt;
		static_cast<void>(vt);
		ft::list<int>::allocator_type at;
		static_cast<void>(at);
		ft::list<int>::reference ref = vt;
		static_cast<void>(ref);
		ft::list<int>::const_reference cref = vt;
		static_cast<void>(cref);
		ft::list<int>::pointer ptr;
		static_cast<void>(ptr);
		ft::list<int>::const_pointer cptr;
		static_cast<void>(cptr);
		ft::list<int>::iterator it;
		ft::list<int>::const_iterator cit;
		ft::list<int>::reverse_iterator rit;
		ft::list<int>::const_reverse_iterator crit;
		ft::list<int>::difference_type dt;
		static_cast<void>(dt);
		ft::list<int>::size_type st;
		static_cast<void>(st);
	}

	void constructors()
	{
		std::cout << "Constructors tests :\n";

		ft::list<int> default_lst;
		std::cout << "- default constructor, empty() : " << std::boolalpha
			<< default_lst.empty() << "\n";

		ft::list<int> fill(4, 42);
		std::cout << "- fill constructor, values :";
		for (ft::list<int>::const_iterator cit = fill.begin(),
				cite = fill.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		ft::list<int> util;
		util.push_back(1);
		util.push_back(2);
		util.push_back(3);
		util.push_back(4);
		util.push_back(5);

		ft::list<int> range(++util.begin(), --util.end());
		std::cout << "- range constructor, values :";
		for (ft::list<int>::const_iterator cit = range.begin(),
				cite = range.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		ft::list<int> copy(util);
		std::cout << "- copy constructor, values :";
		for (ft::list<int>::const_iterator cit = copy.begin(),
				cite = copy.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void assignment_operator()
	{
		std::cout << "Assignment operator tests :\n";

		ft::list<int> util;
		util.push_back(1);
		util.push_back(2);
		util.push_back(3);
		util.push_back(4);
		util.push_back(5);

		ft::list<int> copy;
		copy.push_back(42);

		copy = util;
		std::cout << "- after assignment operator values :";
		for (ft::list<int>::const_iterator cit = copy.begin(),
				cite = copy.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void begin()
	{
		std::cout << "begin tests :\n";

		ft::list<std::string> lst;
		lst.push_back("first");
		lst.push_back("second");
		lst.push_back("last");

		std::cout << "- *begin() : " << *lst.begin() << "\n";

		std::cout << std::flush;
	}

	void end()
	{
		std::cout << "end tests :\n";

		ft::list<std::string> lst;
		lst.push_back("first");
		lst.push_back("second");
		lst.push_back("last");

		std::cout << "- *--end() : " << *--lst.end() << "\n";

		std::cout << std::flush;
	}

	void rbegin()
	{
		std::cout << "rbegin tests :\n";

		ft::list<std::string> lst;
		lst.push_back("first");
		lst.push_back("second");
		lst.push_back("last");

		std::cout << "- *rbegin() : " << *lst.rbegin() << "\n";

		std::cout << std::flush;
	}

	void rend()
	{
		std::cout << "rend tests :\n";

		ft::list<std::string> lst;
		lst.push_back("first");
		lst.push_back("second");
		lst.push_back("last");

		std::cout << "- *--rend() : " << *--lst.rend() << "\n";

		std::cout << std::flush;
	}
	
	void empty()
	{
		std::cout << "empty tests :\n";

		ft::list<bool> lst;

		std::cout << "- empty list, empty() : " << std::boolalpha
			<< lst.empty() << "\n";

		lst.push_back(true);
		std::cout << "- non empty list, empty() : " << std::boolalpha
			<< lst.empty() << "\n";

		lst.clear();
		std::cout << "- clear list, empty() : " << std::boolalpha
			<< lst.empty() << "\n";

		std::cout << std::flush;
	}

	void size()
	{
		std::cout << "size tests :\n";

		ft::list<float> lst;

		std::cout << "- empty list, size() : " << lst.size() << "\n";

		lst.push_back(42.42);
		std::cout << "- 1 elem list, size() :" << lst.size() << "\n";

		lst.insert(lst.end(), 20, 21.21);
		std::cout << "- 21 elems list, size() : " << lst.size() << "\n";

		lst.clear();
		std::cout << "- clear list, size() : " << lst.size() << "\n";

		std::cout << std::flush;
	}

	void max_size()
	{
		std::cout << "max_size tests :\n";

		ft::list<std::string> string_lst;
		std::cout << "- string_lst list, max_size() : "
			<< string_lst.max_size() << "\n";

		ft::list<char> char_lst;
		std::cout << "- char_lst list, max_size() : "
			<< char_lst.max_size() << "\n";

		std::cout << std::flush;
	}

	void front()
	{
		std::cout << "front tests :\n";

		ft::list<std::string> lst;
		lst.push_back("first");
		lst.push_back("second");
		lst.push_back("last");

		std::cout << "- front() : " << lst.front() << "\n";

		std::cout << std::flush;
	}

	void back()
	{
		std::cout << "back tests :\n";

		ft::list<std::string> lst;
		lst.push_back("first");
		lst.push_back("second");
		lst.push_back("last");

		std::cout << "- back() : " << lst.back() << "\n";

		std::cout << std::flush;
	}

	void assign()
	{
		std::cout << "assign tests :\n";

		ft::list<int> util;
		util.push_back(1);
		util.push_back(2);
		util.push_back(3);
		util.push_back(4);
		util.push_back(5);

		ft::list<int> range(10);

		range.assign(++util.begin(), --util.end());
		std::cout << "- range assign, values :";
		for (ft::list<int>::const_iterator cit = range.begin(),
				cite = range.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		ft::list<int> fill(4, 42);

		fill.assign(2, 21);
		std::cout << "- fill assign, values :";
		for (ft::list<int>::const_iterator cit = fill.begin(),
				cite = fill.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void push_front()
	{
		std::cout << "push_front tests :\n";

		ft::list<int> lst(2);

		lst.push_front(42);
		std::cout << "- after push_front, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void pop_front()
	{
		std::cout << "pop_front tests :\n";

		ft::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);

		lst.pop_front();
		std::cout << "- after pop_front, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void push_back()
	{
		std::cout << "push_back tests :\n";

		ft::list<int> lst(2);

		lst.push_back(42);
		std::cout << "- after push_back, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void pop_back()
	{
		std::cout << "pop_back tests :\n";

		ft::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);

		lst.pop_back();
		std::cout << "- after pop_back, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void insert()
	{
		std::cout << "insert tests :\n";

		ft::list<int> lst;

		lst.insert(lst.end(), 42);
		std::cout << "- after single element insert, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		lst.insert(lst.begin(), 2, 21);
		std::cout << "- after fill insert, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		ft::list<int> util;
		util.push_back(1);
		util.push_back(2);
		util.push_back(3);
		util.push_back(4);
		util.push_back(5);

		lst.insert(--lst.end(), ++util.begin(), --util.end());
		std::cout << "- after range insert, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void erase()
	{
		std::cout << "erase tests :\n";

		ft::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);

		lst.erase(++(++lst.begin()));
		std::cout << "- after single element erase, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		lst.erase(++lst.begin(), lst.end());
		std::cout << "- after range erase, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void swap()
	{
		std::cout << "swap tests :\n";

		ft::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);
		ft::list<int> lst2(3, 42);

		std::cout << "- before swap, lst values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "- before swap, lst2 values :";
		for (ft::list<int>::const_iterator cit = lst2.begin(),
				cite = lst2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		lst.swap(lst2);
		std::cout << "- after member function swap, lst values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "- after member function swap, lst2 values :";
		for (ft::list<int>::const_iterator cit = lst2.begin(),
				cite = lst2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		swap(lst, lst2);
		std::cout << "- after non member function swap, lst values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "- after non member function swap, lst2 values :";
		for (ft::list<int>::const_iterator cit = lst2.begin(),
				cite = lst2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void resize()
	{
		std::cout << "resize tests :\n";

		ft::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);

		lst.resize(3, 42);
		std::cout << "- after smaller resize, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		lst.resize(5, 42);
		std::cout << "- after greater resize, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void clear()
	{
		std::cout << "clear tests :\n";

		ft::list<int> lst(4, 42);

		lst.clear();
		std::cout << "- after clear, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void splice()
	{
		std::cout << "splice tests :\n";

		ft::list<int> lst(2, 42);
		ft::list<int> lst2(2, 21);

		lst.splice(++lst.begin(), lst2);
		std::cout << "- after entire list splice, lst values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "- after entire list splice, lst2 values :";
		for (ft::list<int>::const_iterator cit = lst2.begin(),
				cite = lst2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		lst2.push_back(1);
		lst2.push_back(2);
		lst2.push_back(3);
		lst2.push_back(4);
		lst2.push_back(5);
		lst.splice(lst.end(), lst2, ++lst2.begin());
		std::cout << "- after single element splice, lst values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "- after single element splice, lst2 values :";
		for (ft::list<int>::const_iterator cit = lst2.begin(),
				cite = lst2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		lst.splice(lst.begin(), lst2, ++lst2.begin(), --lst2.end());
		std::cout << "- after range splice, lst values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "- after range splice, lst2 values :";
		for (ft::list<int>::const_iterator cit = lst2.begin(),
				cite = lst2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void remove()
	{
		std::cout << "remove tests :\n";

		ft::list<int> lst(2, 42);
		lst.push_back(42);
		lst.push_back(1);
		lst.push_back(42);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(42);

		lst.remove(42);
		std::cout << "- after remove, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	static bool is_even(int val)
	{
		return val % 2 == 0;
	}

	void remove_if()
	{
		std::cout << "remove_if tests :\n";

		ft::list<int> lst(2, 42);
		lst.push_back(42);
		lst.push_back(1);
		lst.push_back(42);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(42);


		lst.remove_if(is_even);
		std::cout << "- after remove_if(is_even), values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	static bool same_units(int first, int second)
	{
		return first % 10 == second % 10;
	}

	void unique()
	{
		std::cout << "unique tests :\n";

		ft::list<int> lst(2, 42);
		lst.push_back(42);
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(2);
		lst.push_back(2);
		lst.push_back(42);
		lst.push_back(11112);
		lst.push_back(3);
		lst.push_back(222);
		lst.push_back(222);
		lst.push_back(42);

		lst.unique();
		std::cout << "- after unique, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		lst.unique(same_units);
		std::cout << "- after unique(same_units), values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void merge()
	{
		std::cout << "merge tests :\n";

		ft::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(42);
		ft::list<int> lst2;
		lst2.push_back(2);
		lst2.push_back(2);
		lst2.push_back(5);
		lst2.push_back(50);

		lst.merge(lst2);
		std::cout << "- after merge, lst values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "- after merge, lst2 values :";
		for (ft::list<int>::const_iterator cit = lst2.begin(),
				cite = lst2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void sort()
	{
		std::cout << "sort tests :\n";

		ft::list<int> lst;
		lst.push_back(10);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(0);

		lst.sort();
		std::cout << "- after sort, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void reverse()
	{
		std::cout << "reverse tests :\n";

		ft::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);

		lst.reverse();
		std::cout << "- after odd reverse, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		lst.push_back(0);
		lst.reverse();
		std::cout << "- after even reverse, values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void relational_operators()
	{
		std::cout << "Relational operators tests :\n";

		ft::list<int> lst(2);
		ft::list<int> lst2(3);

		std::cout << "  lst values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "  lst2 values :";
		for (ft::list<int>::const_iterator cit = lst2.begin(),
				cite = lst2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "  lst == lst2 : " << std::boolalpha << (lst == lst2)
			<< "\n";
		std::cout << "  lst < lst2 : " << std::boolalpha << (lst < lst2)
			<< "\n";
		std::cout << "  lst >= lst2 : " << std::boolalpha << (lst >= lst2)
			<< "\n";

		std::cout << "\n";
		lst.push_back(1);
		std::cout << "  lst values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "  lst2 values :";
		for (ft::list<int>::const_iterator cit = lst2.begin(),
				cite = lst2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "  lst == lst2 : " << std::boolalpha << (lst == lst2)
			<< "\n";
		std::cout << "  lst < lst2 : " << std::boolalpha << (lst < lst2)
			<< "\n";
		std::cout << "  lst >= lst2 : " << std::boolalpha << (lst >= lst2)
			<< "\n";

		std::cout << "\n";
		lst.back() = 0;
		std::cout << "  lst values :";
		for (ft::list<int>::const_iterator cit = lst.begin(),
				cite = lst.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "  lst2 values :";
		for (ft::list<int>::const_iterator cit = lst2.begin(),
				cite = lst2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "  lst == lst2 : " << std::boolalpha << (lst == lst2)
			<< "\n";
		std::cout << "  lst < lst2 : " << std::boolalpha << (lst < lst2)
			<< "\n";
		std::cout << "  lst >= lst2 : " << std::boolalpha << (lst >= lst2)
			<< "\n";

		std::cout << std::flush;
	}

	void launch()
	{
		member_types();
		std::cout << "\n";
		constructors();
		std::cout << "\n";
		assignment_operator();
		std::cout << "\n";
		begin();
		std::cout << "\n";
		end();
		std::cout << "\n";
		rbegin();
		std::cout << "\n";
		rend();
		std::cout << "\n";
		empty();
		std::cout << "\n";
		size();
		std::cout << "\n";
		max_size();
		std::cout << "\n";
		front();
		std::cout << "\n";
		back();
		std::cout << "\n";
		assign();
		std::cout << "\n";
		push_front();
		std::cout << "\n";
		pop_front();
		std::cout << "\n";
		push_back();
		std::cout << "\n";
		pop_back();
		std::cout << "\n";
		insert();
		std::cout << "\n";
		erase();
		std::cout << "\n";
		swap();
		std::cout << "\n";
		resize();
		std::cout << "\n";
		clear();
		std::cout << "\n";
		splice();
		std::cout << "\n";
		remove();
		std::cout << "\n";
		remove_if();
		std::cout << "\n";
		unique();
		std::cout << "\n";
		merge();
		std::cout << "\n";
		sort();
		std::cout << "\n";
		reverse();
		std::cout << "\n";
		relational_operators();
	}
} }
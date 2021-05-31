#include "tests.hpp"

namespace tests { namespace vector
{
	void member_types()
	{
		std::cout << "Member Types tests : OK if you see this" << std::endl;
		ft::vector<int>::value_type vt;
		static_cast<void>(vt);
		ft::vector<int>::allocator_type at;
		static_cast<void>(at);
		ft::vector<int>::reference ref = vt;
		static_cast<void>(ref);
		ft::vector<int>::const_reference cref = vt;
		static_cast<void>(cref);
		ft::vector<int>::pointer ptr;
		static_cast<void>(ptr);
		ft::vector<int>::const_pointer cptr;
		static_cast<void>(cptr);
		ft::vector<int>::iterator it;
		ft::vector<int>::const_iterator cit;
		ft::vector<int>::reverse_iterator rit;
		ft::vector<int>::const_reverse_iterator crit;
		ft::vector<int>::difference_type dt;
		static_cast<void>(dt);
		ft::vector<int>::size_type st;
		static_cast<void>(st);
	}

	void constructors()
	{
		std::cout << "Constructors tests :\n";

		ft::vector<int> default_vec;
		std::cout << "- default constructor, empty() : " << std::boolalpha
			<< default_vec.empty() << "\n";

		ft::vector<int> fill(4, 42);
		std::cout << "- fill constructor, values :";
		for (ft::vector<int>::const_iterator cit = fill.begin(),
				cite = fill.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		ft::vector<int> util;
		util.push_back(1);
		util.push_back(2);
		util.push_back(3);
		util.push_back(4);
		util.push_back(5);

		ft::vector<int> range(util.begin() + 1, util.end() - 1);
		std::cout << "- range constructor, values :";
		for (ft::vector<int>::const_iterator cit = range.begin(),
				cite = range.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		ft::vector<int> copy(util);
		std::cout << "- copy constructor, values :";
		for (ft::vector<int>::const_iterator cit = copy.begin(),
				cite = copy.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void assignment_operator()
	{
		std::cout << "Assignment operator tests :\n";

		ft::vector<int> util;
		util.push_back(1);
		util.push_back(2);
		util.push_back(3);
		util.push_back(4);
		util.push_back(5);

		ft::vector<int> copy;
		copy.push_back(42);

		copy = util;
		std::cout << "- after assignment operator values :";
		for (ft::vector<int>::const_iterator cit = copy.begin(),
				cite = copy.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void begin()
	{
		std::cout << "begin tests :\n";

		ft::vector<std::string> vec;
		vec.push_back("first");
		vec.push_back("second");
		vec.push_back("last");

		std::cout << "- *begin() : " << *vec.begin() << "\n";

		std::cout << std::flush;
	}

	void end()
	{
		std::cout << "end tests :\n";

		ft::vector<std::string> vec;
		vec.push_back("first");
		vec.push_back("second");
		vec.push_back("last");

		std::cout << "- *--end() : " << *--vec.end() << "\n";

		std::cout << std::flush;
	}

	void rbegin()
	{
		std::cout << "rbegin tests :\n";

		ft::vector<std::string> vec;
		vec.push_back("first");
		vec.push_back("second");
		vec.push_back("last");

		std::cout << "- *rbegin() : " << *vec.rbegin() << "\n";

		std::cout << std::flush;
	}

	void rend()
	{
		std::cout << "rend tests :\n";

		ft::vector<std::string> vec;
		vec.push_back("first");
		vec.push_back("second");
		vec.push_back("last");

		std::cout << "- *--rend() : " << *--vec.rend() << "\n";

		std::cout << std::flush;
	}
	
	void size()
	{
		std::cout << "size tests :\n";

		ft::vector<float> vec;

		std::cout << "- empty vector, size() : " << vec.size() << "\n";

		vec.push_back(42.42);
		std::cout << "- 1 elem vector, size() : " << vec.size() << "\n";

		vec.insert(vec.end(), 20, 21.21);
		std::cout << "- 21 elems vector, size() : " << vec.size() << "\n";

		vec.clear();
		std::cout << "- clear vector, size() : " << vec.size() << "\n";

		std::cout << std::flush;
	}

	void max_size()
	{
		std::cout << "max_size tests :\n";

		ft::vector<std::string> string_vec;
		std::cout << "- string_vec vector, max_size() : "
			<< string_vec.max_size() << "\n";

		ft::vector<char> char_vec;
		std::cout << "- char_vec vector, max_size() : "
			<< char_vec.max_size() << "\n";

		std::cout << std::flush;
	}

	void resize()
	{
		std::cout << "resize tests :\n";

		ft::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

		vec.resize(3, 42);
		std::cout << "- after smaller resize, values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		vec.resize(5, 42);
		std::cout << "- after greater resize, values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void capacity()
	{
		std::cout << "capacity tests :\n";

		ft::vector<float> vec;

		std::cout << "- empty vector, capacity() : " << vec.capacity() << "\n";

		vec.push_back(42.42);
		std::cout << "- 1 elem vector, capacity() : " << vec.capacity() << "\n";

		vec.push_back(21.21);
		std::cout << "- 2 elem vector, capacity() : " << vec.capacity() << "\n";

		vec.push_back(105.105);
		std::cout << "- 3 elem vector, capacity() : " << vec.capacity() << "\n";

		vec.insert(vec.end(), 2, 525.525);
		std::cout << "- 5 elems vector, capacity() : " << vec.capacity() << "\n";

		vec.clear();
		std::cout << "- clear vector, capacity() : " << vec.capacity() << "\n";

		std::cout << std::flush;
	}

	void empty()
	{
		std::cout << "empty tests :\n";

		ft::vector<bool> vec;

		std::cout << "- empty vector, empty() : " << std::boolalpha
			<< vec.empty() << "\n";

		vec.push_back(false);
		std::cout << "- non empty vector, empty() : " << std::boolalpha
			<< vec.empty() << "\n";

		vec.clear();
		std::cout << "- clear vector, empty() : " << std::boolalpha
			<< vec.empty() << "\n";

		std::cout << std::flush;
	}

	void reserve()
	{
		std::cout << "reserve tests :\n";

		ft::vector<float> vec;

		std::cout << "- empty vector, capacity() : " << vec.capacity() << "\n";

		vec.reserve(42);
		std::cout << "- after reserve(42), capacity() : " << vec.capacity() << "\n";

		vec.reserve(21);
		std::cout << "- after reserve(21), capacity() : " << vec.capacity() << "\n";

		try {
			vec.reserve(ULONG_MAX);
		}
		catch (std::length_error const& e) {
			std::cout << "- execption catch in reserve(ULONG_MAX), e.what() : "
				<< e.what() << "\n";
		}

		std::cout << std::flush;
	}

	void subscript_operator()
	{
		std::cout << "operator[] tests :\n";

		ft::vector<std::string> vec;
		vec.push_back("first");
		vec.push_back("second");
		vec.push_back("last");

		std::cout << "- values accessed with [] :";
		for (std::size_t i = 0, size = vec.size(); i < size; ++i) {
			std::cout << " " << vec[i];
		}
		std::cout << "\n";


		std::cout << std::flush;
	}

	void at()
	{
		std::cout << "at tests :\n";

		ft::vector<std::string> vec;
		vec.push_back("first");
		vec.push_back("second");
		vec.push_back("last");

		std::cout << "- values accessed with at :";
		for (std::size_t i = 0, size = vec.size(); i < size; ++i) {
			std::cout << " " << vec.at(i);
		}
		std::cout << "\n";

		try {
			vec.at(ULONG_MAX);
		}
		catch (std::out_of_range const& e) {
			std::cout << "- execption catch in at(ULONG_MAX), e.what() : "
				<< e.what() << "\n";
		}

		std::cout << std::flush;
	}

	void front()
	{
		std::cout << "front tests :\n";

		ft::vector<std::string> vec;
		vec.push_back("first");
		vec.push_back("second");
		vec.push_back("last");

		std::cout << "- front() : " << vec.front() << "\n";

		std::cout << std::flush;
	}

	void back()
	{
		std::cout << "back tests :\n";

		ft::vector<std::string> vec;
		vec.push_back("first");
		vec.push_back("second");
		vec.push_back("last");

		std::cout << "- back() : " << vec.back() << "\n";

		std::cout << std::flush;
	}

	void assign()
	{
		std::cout << "assign tests :\n";

		ft::vector<int> util;
		util.push_back(1);
		util.push_back(2);
		util.push_back(3);
		util.push_back(4);
		util.push_back(5);

		ft::vector<int> range(10);

		range.assign(++util.begin(), --util.end());
		std::cout << "- range assign, values :";
		for (ft::vector<int>::const_iterator cit = range.begin(),
				cite = range.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		ft::vector<int> fill(4, 42);

		fill.assign(2, 21);
		std::cout << "- fill assign, values :";
		for (ft::vector<int>::const_iterator cit = fill.begin(),
				cite = fill.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void push_back()
	{
		std::cout << "push_back tests :\n";

		ft::vector<int> vec(2);

		vec.push_back(42);
		std::cout << "- after push_back, values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void pop_back()
	{
		std::cout << "pop_back tests :\n";

		ft::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);

		vec.pop_back();
		std::cout << "- after pop_back, values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void insert()
	{
		std::cout << "insert tests :\n";

		ft::vector<int> vec;

		vec.insert(vec.end(), 42);
		std::cout << "- after single element insert, values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		vec.insert(vec.begin(), 2, 21);
		std::cout << "- after fill insert, values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		ft::vector<int> util;
		util.push_back(1);
		util.push_back(2);
		util.push_back(3);
		util.push_back(4);
		util.push_back(5);

		vec.insert(--vec.end(), ++util.begin(), --util.end());
		std::cout << "- after range insert, values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void erase()
	{
		std::cout << "erase tests :\n";

		ft::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

		vec.erase(++(++vec.begin()));
		std::cout << "- after single element erase, values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		vec.erase(++vec.begin(), vec.end());
		std::cout << "- after range erase, values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void swap()
	{
		std::cout << "swap tests :\n";

		ft::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		ft::vector<int> vec2(3, 42);

		std::cout << "- before swap, vec values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "- before swap, vec2 values :";
		for (ft::vector<int>::const_iterator cit = vec2.begin(),
				cite = vec2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		vec.swap(vec2);
		std::cout << "- after member function swap, vec values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "- after member function swap, vec2 values :";
		for (ft::vector<int>::const_iterator cit = vec2.begin(),
				cite = vec2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		swap(vec, vec2);
		std::cout << "- after non member function swap, vec values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "- after non member function swap, vec2 values :";
		for (ft::vector<int>::const_iterator cit = vec2.begin(),
				cite = vec2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void clear()
	{
		std::cout << "clear tests :\n";

		ft::vector<int> vec(4, 42);

		vec.clear();
		std::cout << "- after clear, values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void relational_operators()
	{
		std::cout << "Relational operators tests :\n";

		ft::vector<int> vec(2);
		ft::vector<int> vec2(3);

		std::cout << "  vec values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "  vec2 values :";
		for (ft::vector<int>::const_iterator cit = vec2.begin(),
				cite = vec2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "  vec == vec2 : " << std::boolalpha << (vec == vec2)
			<< "\n";
		std::cout << "  vec < vec2 : " << std::boolalpha << (vec < vec2)
			<< "\n";
		std::cout << "  vec >= vec2 : " << std::boolalpha << (vec >= vec2)
			<< "\n";

		std::cout << "\n";
		vec.push_back(1);
		std::cout << "  vec values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "  vec2 values :";
		for (ft::vector<int>::const_iterator cit = vec2.begin(),
				cite = vec2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "  vec == vec2 : " << std::boolalpha << (vec == vec2)
			<< "\n";
		std::cout << "  vec < vec2 : " << std::boolalpha << (vec < vec2)
			<< "\n";
		std::cout << "  vec >= vec2 : " << std::boolalpha << (vec >= vec2)
			<< "\n";

		std::cout << "\n";
		vec.back() = 0;
		std::cout << "  vec values :";
		for (ft::vector<int>::const_iterator cit = vec.begin(),
				cite = vec.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "  vec2 values :";
		for (ft::vector<int>::const_iterator cit = vec2.begin(),
				cite = vec2.end(); cit != cite; ++cit) {
			std::cout << " " << *cit;
		}
		std::cout << "\n";
		std::cout << "  vec == vec2 : " << std::boolalpha << (vec == vec2)
			<< "\n";
		std::cout << "  vec < vec2 : " << std::boolalpha << (vec < vec2)
			<< "\n";
		std::cout << "  vec >= vec2 : " << std::boolalpha << (vec >= vec2)
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
		size();
		std::cout << "\n";
		max_size();
		std::cout << "\n";
		resize();
		std::cout << "\n";
		capacity();
		std::cout << "\n";
		empty();
		std::cout << "\n";
		reserve();
		std::cout << "\n";
		subscript_operator();
		std::cout << "\n";
		at();
		std::cout << "\n";
		front();
		std::cout << "\n";
		back();
		std::cout << "\n";
		assign();
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
		clear();
		std::cout << "\n";
		relational_operators();
	}
} }
#include "tests.hpp"
#include <map>

namespace tests { namespace map
{
	void member_types()
	{
		std::cout << "Member Types tests : OK if you see this" << std::endl;
		ft::map<int, int>::key_type kt;
		static_cast<void>(kt);
		ft::map<int, int>::mapped_type mt;
		static_cast<void>(mt);
		ft::map<int, int>::value_type vt;
		static_cast<void>(vt);
		ft::map<int, int>::key_compare kc;
		static_cast<void>(kc);
		ft::map<int, int>::value_compare vc(ft::less<int>);
		static_cast<void>(vc);
		ft::map<int, int>::allocator_type at;
		static_cast<void>(at);
		ft::map<int, int>::reference ref = vt;
		static_cast<void>(ref);
		ft::map<int, int>::const_reference cref = vt;
		static_cast<void>(cref);
		ft::map<int, int>::pointer ptr;
		static_cast<void>(ptr);
		ft::map<int, int>::const_pointer cptr;
		static_cast<void>(cptr);
		ft::map<int, int>::iterator it;
		ft::map<int, int>::const_iterator cit;
		ft::map<int, int>::reverse_iterator rit;
		ft::map<int, int>::const_reverse_iterator crit;
		ft::map<int, int>::difference_type dt;
		static_cast<void>(dt);
		ft::map<int, int>::size_type st;
		static_cast<void>(st);
	}

	void constructors()
	{
		std::cout << "Constructors tests :\n";

		ft::map<int, int> default_map;
		std::cout << "- default constructor, empty() : " << std::boolalpha
			<< default_map.empty() << "\n";

		ft::map<int, int> util;
		util[1] = 11;
		util[2] = 22;
		util[3] = 33;
		util[4] = 44;
		util[5] = 55;

		ft::map<int, int> range(++util.begin(), --util.end());
		std::cout << "- range constructor, values :";
		for (ft::map<int, int>::const_iterator cit = range.begin(),
				cite = range.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		ft::map<int, int> copy(util);
		std::cout << "- copy constructor, values :";
		for (ft::map<int, int>::const_iterator cit = copy.begin(),
				cite = copy.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void assignment_operator()
	{
		std::cout << "Assignment operator tests :\n";

		ft::map<int, int> util;
		util[1] = 11;
		util[2] = 22;
		util[3] = 33;
		util[4] = 44;
		util[5] = 55;

		ft::map<int, int> copy;
		copy[42] = 4242;

		copy = util;
		std::cout << "- after assignment operator values :";
		for (ft::map<int, int>::const_iterator cit = copy.begin(),
				cite = copy.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void begin()
	{
		std::cout << "begin tests :\n";

		ft::map<int, std::string> map;
		map[1] = "first";
		map[2] = "second";
		map[3] = "last";

		std::cout << "- begin()->first : " << map.begin()->first
			<< ", begin()->second : " << map.begin()->second << "\n";

		std::cout << std::flush;
	}

	void end()
	{
		std::cout << "end tests :\n";

		ft::map<int, std::string> map;
		map[1] = "first";
		map[2] = "second";
		map[3] = "last";

		std::cout << "- --end()->first : " << (--map.end())->first
			<< ", --end()->second : " << (--map.end())->second << "\n";

		std::cout << std::flush;
	}

	void rbegin()
	{
		std::cout << "rbegin tests :\n";

		ft::map<int, std::string> map;
		map[1] = "first";
		map[2] = "second";
		map[3] = "last";

		std::cout << "- rbegin()->first : " << map.rbegin()->first
			<< ", rbegin()->second : " << map.rbegin()->second << "\n";

		std::cout << std::flush;
	}

	void rend()
	{
		std::cout << "rend tests :\n";

		ft::map<int, std::string> map;
		map[1] = "first";
		map[2] = "second";
		map[3] = "last";

		std::cout << "- --rend()->first : " << (--map.rend())->first
			<< ", --rend()->second : " << (--map.rend())->second << "\n";

		std::cout << std::flush;
	}

	void empty()
	{
		std::cout << "empty tests :\n";

		ft::map<int, bool> map;

		std::cout << "- empty map, empty() : " << std::boolalpha
			<< map.empty() << "\n";

		map[42] = false;
		std::cout << "- non empty map, empty() : " << std::boolalpha
			<< map.empty() << "\n";

		map.clear();
		std::cout << "- clear map, empty() : " << std::boolalpha
			<< map.empty() << "\n";

		std::cout << std::flush;
	}
	
	void size()
	{
		std::cout << "size tests :\n";

		ft::map<float, int> map;

		std::cout << "- empty map, size() : " << map.size() << "\n";

		map[42.42] = 4242;
		std::cout << "- 1 elem map, size() : " << map.size() << "\n";

		ft::map<float, int> util;
		util[1.1] = 11;
		util[2.2] = 22;
		util[3.3] = 33;
		util[4.4] = 44;
		util[5.5] = 55;
		map.insert(util.begin(), util.end());
		std::cout << "- 6 elems map, size() : " << map.size() << "\n";

		map.clear();
		std::cout << "- clear map, size() : " << map.size() << "\n";

		std::cout << std::flush;
	}

	void max_size()
	{
		std::cout << "max_size tests :\n";

		ft::map<std::string, std::string> string_map;
		std::cout << "- string_map map, max_size() : "
			<< string_map.max_size() << "\n";

		ft::map<char, char> char_map;
		std::cout << "- char_map map, max_size() : "
			<< char_map.max_size() << "\n";

		std::cout << std::flush;
	}

	void subscript_operator()
	{
		std::cout << "operator[] tests :\n";

		ft::map<int, std::string> map;
		map[1] = "first";
		map[2] = "sec";
		map[2] = "second";
		map[3] = "last";

		std::cout << "- values accessed with [] :";
		for (ft::map<int, std::string>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " " << map[cit->first];
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void insert()
	{
		std::cout << "insert tests :\n";

		ft::map<int, int> map;
		ft::pair<ft::map<int, int>::iterator, bool> pair;
		ft::map<int, int>::iterator it;

		pair = map.insert(ft::pair<int, int>(21, 2121));
		std::cout << "- new single element insert return : ["
			<< pair.first->first << ", " << pair.first->second << "], "
			<< std::boolalpha << pair.second << "\n";
		pair = map.insert(ft::pair<int, int>(21, 212121));
		std::cout << "- single element already insert return : ["
			<< pair.first->first << ", " << pair.first->second << "], "
			<< std::boolalpha << pair.second << "\n";
		std::cout << "- after single element insert, values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		it = map.insert(map.begin(), ft::pair<int, int>(42, 4242));
		std::cout << "- hint insert return : ["
			<< it->first << ", " << it->second << "]" << "\n";
		std::cout << "- after hint insert, values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		ft::map<float, int> util;
		util[1.1] = 11;
		util[2.2] = 22;
		util[3.3] = 33;
		util[4.4] = 44;
		util[5.5] = 55;

		map.insert(++util.begin(), --util.end());
		std::cout << "- after range insert, values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void erase()
	{
		std::cout << "erase tests :\n";

		ft::map<int, int> map;
		map[1] = 11;
		map[2] = 22;
		map[3] = 33;
		map[4] = 44;
		map[5] = 55;

		map.erase(++(++map.begin()));
		std::cout << "- after iterator erase, values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		ft::map<int, int>::size_type st;
		st = map.erase(42);
		std::cout << "- unknown key erase return : " << st << "\n";
		st = map.erase(5);
		std::cout << "- known key erase return : " << st << "\n";
		std::cout << "- after key erase, values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		map.erase(++map.begin(), map.end());
		std::cout << "- after range erase, values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void swap()
	{
		std::cout << "swap tests :\n";

		ft::map<int, int> map;
		map[1] = 11;
		map[2] = 22;
		map[3] = 33;
		map[4] = 44;
		map[5] = 55;
		ft::map<int, int> map2;
		map2[1] = 42;
		map2[2] = 42;
		map2[3] = 42;

		std::cout << "- before swap, map values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";
		std::cout << "- before swap, map2 values :";
		for (ft::map<int, int>::const_iterator cit = map2.begin(),
				cite = map2.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		map.swap(map2);
		std::cout << "- after member function swap, map values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";
		std::cout << "- after member function swap, map2 values :";
		for (ft::map<int, int>::const_iterator cit = map2.begin(),
				cite = map2.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		swap(map, map2);
		std::cout << "- after non member function swap, map values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";
		std::cout << "- after non member function swap, map2 values :";
		for (ft::map<int, int>::const_iterator cit = map2.begin(),
				cite = map2.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	void clear()
	{
		std::cout << "clear tests :\n";

		ft::map<int, int> map;
		map[1] = 0;
		map[2] = 0;
		map[3] = 0;

		map.clear();
		std::cout << "- after clear, values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	template <class T>
	struct comp_util
	{
		typedef T first_argument_type;
		typedef T second_argument_type;
		typedef bool result_type;

		bool operator()(T const& x, T const& y) const
		{
			std::cout << "OK if you see this";
			return x < y;
		}
	};

	void key_comp()
	{
		std::cout << "key_comp tests : ";

		ft::map<int, int, comp_util<int> > map;
		ft::map<int, int, comp_util<int> >::key_compare key_compare;

		key_compare = map.key_comp();
		key_compare(1, 2);

		std::cout << std::endl;
	}

	void value_comp()
	{
		std::cout << "value_comp tests : ";

		ft::map<int, int, comp_util<int> > map;
		map[0] = 0;
		map.value_comp()(*map.begin(), *map.begin());

		std::cout << std::endl;
	}

	void find()
	{
		std::cout << "find tests :\n";

		ft::map<int, int> map;
		map[42] = 4242;

		ft::map<int, int>::iterator it;
		it = map.find(42);
		std::cout << "- present key find return : [" << it->first << ", "
			<< it->second << "]\n";
		it = map.find(21);
		std::cout << "- non present key find return == map::end() : "
			<< std::boolalpha << (it == map.end()) << "\n";

		std::cout << std::flush;
	}

	void count()
	{
		std::cout << "count tests :\n";

		ft::map<int, int> map;
		map[42] = 4242;

		ft::map<int, int>::size_type st;
		st = map.count(42);
		std::cout << "- present key count return : " << st << "\n";
		st = map.count(21);
		std::cout << "- non present key count return : " << st << "\n";

		std::cout << std::flush;
	}

	void lower_bound()
	{
		std::cout << "lower_bound tests :\n";

		ft::map<int, int> map;
		ft::map<int, int>::iterator it;
		map[2] = 22;
		map[4] = 44;
		map[8] = 88;

		std::cout << "  map values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		it = map.lower_bound(3);
		std::cout << "- lower_bound(3) : [" << it->first << ", "
			<< it->second << "]\n";

		it = map.lower_bound(4);
		std::cout << "- lower_bound(4) : [" << it->first << ", "
			<< it->second << "]\n";

		it = map.lower_bound(5);
		std::cout << "- lower_bound(5) : [" << it->first << ", "
			<< it->second << "]\n";

		std::cout << std::flush;
	}

	void upper_bound()
	{
		std::cout << "upper_bound tests :\n";

		ft::map<int, int> map;
		ft::map<int, int>::iterator it;
		map[2] = 22;
		map[4] = 44;
		map[8] = 88;

		std::cout << "  map values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		it = map.upper_bound(3);
		std::cout << "- upper_bound(3) : [" << it->first << ", "
			<< it->second << "]\n";

		it = map.upper_bound(4);
		std::cout << "- upper_bound(4) : [" << it->first << ", "
			<< it->second << "]\n";

		it = map.upper_bound(5);
		std::cout << "- upper_bound(5) : [" << it->first << ", "
			<< it->second << "]\n";

		std::cout << std::flush;
	}

	void equal_range()
	{
		std::cout << "equal_range tests :\n";

		ft::map<int, int> map;
		ft::pair<ft::map<int, int>::const_iterator,
			ft::map<int, int>::const_iterator> it_pair;
		map[1] = 11;

		std::cout << "  map values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		it_pair = map.equal_range(1);
		std::cout << "- equal_range(1) values :";
		for (ft::map<int, int>::const_iterator cit = it_pair.first,
				cite = it_pair.second; cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		it_pair = map.equal_range(42);
		std::cout << "- equal_range(42) values :";
		for (ft::map<int, int>::const_iterator cit = it_pair.first,
				cite = it_pair.second; cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";

		std::cout << std::flush;
	}

	static void print_maps_comparaison(ft::map<int, int> const& map,
			ft::map<int, int> const& map2)
	{
		std::cout << "  map values :";
		for (ft::map<int, int>::const_iterator cit = map.begin(),
				cite = map.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";
		std::cout << "  map2 values :";
		for (ft::map<int, int>::const_iterator cit = map2.begin(),
				cite = map2.end(); cit != cite; ++cit) {
			std::cout << " [" << cit->first << ", " << cit->second << "]";
		}
		std::cout << "\n";
		std::cout << "- map == map2 : " << std::boolalpha << (map == map2)
			<< "\n";
		std::cout << "- map < map2 : " << std::boolalpha << (map < map2)
			<< "\n";
		std::cout << "- map >= map2 : " << std::boolalpha << (map >= map2)
			<< "\n";
	}

	void relational_operators()
	{
		std::cout << "Relational operators tests :\n";

		ft::map<int, int> map;
		map[1] = 11;
		map[2] = 22;
		ft::map<int, int> map2;
		map2[1] = 11;
		map2[2] = 22;
		map2[3] = 33;

		print_maps_comparaison(map, map2);

		std::cout << "\n";
		map[3] = 33;
		print_maps_comparaison(map, map2);

		std::cout << "\n";
		map[3] = 333;
		print_maps_comparaison(map, map2);

		std::cout << "\n";
		map[3] = 3;
		print_maps_comparaison(map, map2);

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
		subscript_operator();
		std::cout << "\n";
		insert();
		std::cout << "\n";
		erase();
		std::cout << "\n";
		swap();
		std::cout << "\n";
		clear();
		std::cout << "\n";
		key_comp();
		std::cout << "\n";
		value_comp();
		std::cout << "\n";
		find();
		std::cout << "\n";
		count();
		std::cout << "\n";
		lower_bound();
		std::cout << "\n";
		upper_bound();
		std::cout << "\n";
		equal_range();
		std::cout << "\n";
		relational_operators();

		std::cout << std::flush;
	}
} }

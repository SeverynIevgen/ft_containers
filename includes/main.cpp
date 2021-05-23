// #include "list.hpp"
// #include "vector.hpp"
#include "map.hpp"
// #include <iostream>
// #include <list>
// #include <vector>
#include <map>
#include <cmath>

// // std::relational operators (vector)
// int main () {
//   ft::vector<int> foo(3,100);   // three ints with a value of 100
//   ft::vector<int> bar(2,200);   // two ints with a value of 200

//   if (foo == bar) std::cout << "foo and bar are equal\n";
//   if (foo != bar) std::cout << "foo and bar are not equal\n";
//   if (foo < bar) std::cout << "foo is less than bar\n";
//   if (foo > bar) std::cout << "foo is greater than bar\n";
//   if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;
// }

// // --------------map::lower_bound--------------
int main()
{
    ft::map<char, int> mymap;
    ft::map<char, int>::iterator itlow, itup;

    mymap['a'] = 20;
    mymap['b'] = 40;
    mymap['c'] = 60;
    mymap['d'] = 80;
    mymap['e'] = 100;

    // itlow = mymap.lower_bound('b'); // itlow points to b
    itup = mymap.upper_bound('d');  // itup points to e (not d!)

    // mymap.erase(itlow, itup); // erases [itlow,itup)
    mymap.erase(itlow);

    // print content:
    for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    return 0;
}

// // --------------map::count--------------
// int main()
// {
//     ft::map<char, int> mymap;
//     char c;

//     mymap['a'] = 101;
//     mymap['c'] = 202;
//     mymap['f'] = 303;

//     for (c = 'a'; c < 'h'; c++)
//     {
//         std::cout << c;
//         if (mymap.count(c) > 0)
//             std::cout << " is an element of mymap.\n";
//         else
//             std::cout << " is not an element of mymap.\n";
//     }

//     return 0;
// }

// // --------------map::find--------------
// int main()
// {
//     ft::map<char, int> mymap;
//     ft::map<char, int>::iterator it;

//     mymap['a'] = 50;
//     mymap['b'] = 100;
//     mymap['c'] = 150;
//     mymap['d'] = 200;

//     it = mymap.find('b');
//     if (it != mymap.end())
//         mymap.erase(it);

//     // print content:
//     std::cout << "elements in mymap:" << '\n';
//     std::cout << "a => " << mymap.find('a')->second << '\n';
//     std::cout << "c => " << mymap.find('c')->second << '\n';
//     std::cout << "d => " << mymap.find('d')->second << '\n';

//     return 0;
// }

// // --------------map::value_comp--------------
// int main()
// {
//     ft::map<char, int> mymap;

//     mymap['x'] = 1001;
//     mymap['y'] = 2002;
//     mymap['z'] = 3003;

//     std::cout << "mymap contains:\n";

//     std::pair<char, int> highest = *mymap.rbegin(); // last element

//     ft::map<char, int>::iterator it = mymap.begin();
//     do
//     {
//         std::cout << it->first << " => " << it->second << '\n';
//     } while (mymap.value_comp()(*it++, highest));

//     return 0;
// }

// // --------------map::key_comp--------------
// int main()
// {
//     ft::map<char, int> mymap;

//     ft::map<char, int>::key_compare mycomp = mymap.key_comp();

//     mymap['a'] = 100;
//     mymap['b'] = 200;
//     mymap['c'] = 300;

//     std::cout << "mymap contains:\n";

//     char highest = mymap.rbegin()->first; // key value of last element

//     ft::map<char, int>::iterator it = mymap.begin();
//     do
//     {
//         std::cout << it->first << " => " << it->second << '\n';
//     } while (mycomp((*it++).first, highest));

//     return 0;
// }

// // --------------map::clear--------------
// int main()
// {
//     ft::map<char, int> mymap;

//     mymap['x'] = 100;
//     mymap['y'] = 200;
//     mymap['z'] = 300;

//     std::cout << "mymap contains:\n";
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     mymap.clear();
//     mymap['a'] = 1101;
//     mymap['b'] = 2202;

//     std::cout << "mymap contains:\n";
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     return 0;
// }

// // --------------swap(vector)--------------
// // --------------map::swap--------------
// int main()
// {
//     ft::map<char, int> foo, bar;

//     foo['x'] = 100;
//     foo['y'] = 200;

//     bar['a'] = 11;
//     bar['b'] = 22;
//     bar['c'] = 33;

//     foo.swap(bar);

//     std::cout << "foo contains:\n";
//     for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     std::cout << "bar contains:\n";
//     for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     swap(foo, bar);
//     std::cout << "foo contains:\n";
//     for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     std::cout << "bar contains:\n";
//     for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     return 0;
// }

// // --------------map::erase--------------
// int main()
// {
//     ft::map<char, int> mymap;
//     ft::map<char, int>::iterator it;

//     // insert some values:
//     mymap['a'] = 10;
//     mymap['b'] = 20;
//     mymap['c'] = 30;
//     mymap['d'] = 40;
//     mymap['e'] = 50;
//     mymap['f'] = 60;

//     it = mymap.find('b');
//     mymap.erase(it); // erasing by iterator

//     mymap.erase('c'); // erasing by key

//     it = mymap.find('e');
//     mymap.erase(it, mymap.end()); // erasing by range

//     // show content:
//     for (it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     return 0;
// }

// // --------------map::insert--------------
// int main()
// {
//     ft::map<char, int> mymap;

//     // first insert function version (single parameter):
//     mymap.insert(std::pair<char, int>('a', 100));
//     mymap.insert(std::pair<char, int>('z', 200));
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";
//     mymap.insert(std::pair<char, int>('z', 500));
//     std::cout << "\nMap after new insert is not changed:\n";
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     // second insert function version (with hint position):
//     ft::map<char, int>::iterator it = mymap.begin();
//     mymap.insert(it, std::pair<char, int>('b', 300)); // max efficiency inserting
//     mymap.insert(it, std::pair<char, int>('c', 400)); // no max efficiency inserting
//     std::cout << "\nMap after new insertions:\n";
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     // third insert function version (range insertion):
//     ft::map<char, int> anothermap;
//     anothermap.insert(mymap.begin(), mymap.find('c'));
//     std::cout << "\nAnothermap contains:\n";
//     for (ft::map<char, int>::iterator it = anothermap.begin(); it != anothermap.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     return 0;
// }

// // --------------map::operator[]--------------
// int main()
// {
//     ft::map<char, std::string> mymap;

//     mymap['a'] = "an element";
//     mymap['b'] = "another element";
//     mymap['c'] = mymap['b'];

//     std::cout << "mymap['a'] is " << mymap['a'] << '\n';
//     std::cout << "mymap['b'] is " << mymap['b'] << '\n';
//     std::cout << "mymap['c'] is " << mymap['c'] << '\n';
//     std::cout << "mymap['d'] is " << mymap['d'] << '\n';

//     std::cout << "mymap now contains " << mymap.size() << " elements.\n";

//     return 0;
// }

// // --------------map::max_size--------------
// int main()
// {
//     int i;
//     ft::map<int, int> mymap;

//     if (mymap.max_size() > 1000)
//     {
//         for (i = 0; i < 1000; i++)
//             mymap[i] = 0;
//         std::cout << "The map contains 1000 elements.\n";
//     }
//     else
//         std::cout << "The map could not hold 1000 elements.\n";
//     std::cout << "max_size: " << mymap.max_size() << "\n";

//     return 0;
// }

// // --------------map::empty--------------
// // --------------map::size--------------
// int main()
// {
//     ft::map<char, int> mymap;
//     std::cout << "mymap.size() is " << mymap.size() << '\n';
//     mymap['g'] = 101;
//     mymap['b'] = 202;
//     mymap['d'] = 300;
//     mymap['c'] = 302;
//     mymap['f'] = 202;
//     mymap['j'] = 300;
//     mymap['n'] = 302;

//     std::cout << "mymap.size() is " << mymap.size() << '\n';

//     while (!mymap.empty())
//     {
//         std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
//         mymap.erase(mymap.begin());
//     }
//     std::cout << "mymap.size() is " << mymap.size() << '\n';
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     return 0;
// }

// // --------------map::rend--------------
// // --------------map::rbegin--------------
// int main()
// {
//     ft::map<char, int> mymap;

//     mymap['y'] = 100;
//     mymap['z'] = 200;
//     mymap['x'] = 300;

//     // show content:
//     ft::map<char, int>::reverse_iterator rit;
//     for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
//         std::cout << rit->first << " => " << rit->second << '\n';

//     return 0;
// }

// // --------------map::end--------------
// // --------------map::begin--------------
// int main()
// {
//     ft::map<char, int> mymap;
//     mymap['c'] = 100;
//     mymap['a'] = 200;
//     mymap['b'] = 300;

//     // show content:
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';
//     ft::map<char, int>::iterator it = mymap.begin();
//     std::cout << it->first << " => " << it->second << '\t';
//     it++;
//     std::cout << it->first << " => " << it->second << '\t';
//     ++it;
//     std::cout << it->first << " => " << it->second << '\n';

//     return 0;
// }

// // --------------map::size--------------
// // --------------map::operator=--------------
// int main()
// {
//     ft::map<char, int> first;
//     ft::map<char, int> second;

//     first['x'] = 12;
//     first['a'] = 16;
//     first['z'] = 32;

//     second = first;               // second now contains 3 ints
//     first = ft::map<char, int>(); // and first is now empty

//     std::cout << "Size of first: " << first.size() << '\n';
//     std::cout << "Size of second: " << second.size() << '\n';
//     for (ft::map<char, int>::iterator it = second.begin(); it != second.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";
//     return 0;
// }

// // --------------map::map--------------
// int main()
// {
//     ft::map<char, int> first; // empty constructor (default constructor)
//     first['b'] = 10;
//     first['a'] = 30;
//     first['c'] = 50;
//     first['c'] = 60;
//     first['d'] = 70;
//     std::cout << "The contents of the first map are:\n";
//     for (ft::map<char, int>::iterator it = first.begin(); it != first.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     ft::map<char, int> second(first.begin(), first.end()); // range constructor
//     std::cout << "\nThe contents of the second map are:\n";
//     for (ft::map<char, int>::iterator it = second.begin(); it != second.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     ft::map<char, int> third(second); // copy constructor
//     std::cout << "\nThe contents of the third map are:\n";
//     for (ft::map<char, int>::iterator it = third.begin(); it != third.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     return 0;
// }

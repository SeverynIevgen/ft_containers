#include "list.hpp"
#include <list>
// #include <iostream>
#include <vector>
#include <cmath>

// // std::relational operators (list)
// int main () {
//   ft::list<int> a;
//   a.push_back(10); a.push_back(20); a.push_back(30);
//   ft::list<int> b;
//   b.push_back(10); b.push_back(20); b.push_back(30);
//   ft::list<int> c;
//   c.push_back(30); c.push_back(20); c.push_back(10);

//   if (a == b) std::cout << "a and b are equal\n";
//   if (b != c) std::cout << "b and c are not equal\n";
//   if (b < c) std::cout << "b is less than c\n";
//   if (c > b) std::cout << "c is greater than b\n";
//   if (a <= b) std::cout << "a is less than or equal to b\n";
//   if (a >= b) std::cout << "a is greater than or equal to b\n";

//   return 0;
// }

// // --------------list::sort--------------
// // comparison, not case sensitive.
// bool compare_nocase (const std::string& first, const std::string& second) {
//   unsigned int i=0;
//   while ( (i < first.length()) && (i < second.length()) ) {
//     if (tolower(first[i]) < tolower(second[i])) return true;
//     else if (tolower(first[i]) > tolower(second[i])) return false;
//     ++i;
//   }
//   return ( first.length() < second.length() );
// }

// int main () {
//   ft::list<std::string> mylist;
//   ft::list<std::string>::iterator it;
//   mylist.push_back ("one");
//   mylist.push_back ("two");
//   mylist.push_back ("Three");

//   mylist.sort();

//   std::cout << "mylist contains:";
//   for (it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   mylist.sort(compare_nocase);

//   std::cout << "mylist contains:";
//   for (it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------list::reverse--------------
// int main () {
//   ft::list<int> mylist;

//   for (int i = 1; i < 10; ++i) mylist.push_back(i);

//   mylist.reverse();

//   std::cout << "mylist contains:";
//   for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;

//   std::cout << '\n';

//   return 0;
// }

// // --------------list::merge--------------
// // compare only integral part:
// bool mycomparison (double first, double second) {
//     return ( int(first) < int(second) );
// }

// int main () {
//   ft::list<double> first, second;

//   first.push_back (3.9);
//   first.push_back (2.2);
//   first.push_back (2.9);

//   second.push_back (3.7);
//   second.push_back (7.1);
//   second.push_back (1.4);

//   first.sort();
// //   second.sort();

//   first.merge(second);

//   // (second is now empty)

//   second.push_back(2.1);

//   first.merge(second, mycomparison);

//   std::cout << "first contains:";
//   for (ft::list<double>::iterator it = first.begin(); it != first.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------list::unique--------------
// // a binary predicate implemented as a function:
// bool same_integral_part (double first, double second) {
//   return ( int(first)==int(second) );
// }

// // a binary predicate implemented as a class:
// struct is_near {
//   bool operator() (double first, double second)
//   { return (fabs(first - second) < 5.0); }
// };

// int main () {
//   double mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25};
//   ft::list<double> mylist(mydoubles, mydoubles + 10);

//   mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
//                              // 15.3,  72.25, 72.25, 73.0,  73.35

//   mylist.unique();           //  2.72,  3.14, 12.15, 12.77
//                              // 15.3,  72.25, 73.0,  73.35

//   mylist.unique(same_integral_part);  //  2.72,  3.14, 12.15
//                                        // 15.3,  72.25, 73.0

//   mylist.unique(is_near());           //  2.72, 12.15, 72.25

//   std::cout << "mylist contains:";
//   for (ft::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // list::remove_if
// // a predicate implemented as a function:
// bool single_digit (const int& value) { return (value < 10); }

// // a predicate implemented as a class:
// struct is_odd {
//   bool operator() (const int& value) { return (value % 2) == 1; }
// };

// int main () {
//   int myints[] = {15, 36, 7, 17, 20, 39, 4, 1};
//   ft::list<int> mylist (myints, myints + 8);   // 15 36 7 17 20 39 4 1

//   mylist.remove_if (single_digit);           // 15 36 17 20 39

//   mylist.remove_if(is_odd());               // 36 20

//   std::cout << "mylist contains:";
//   for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------list::remove--------------
// int main ()
// {
//   int myints[]= {17, 89, 20, 14};
//   ft::list<int> mylist(myints, myints + 4);

//   mylist.remove(20);
//   mylist.remove(25);

//   std::cout << "mylist contains:";
//   for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------list::splice--------------
// int main () {
//   std::list<int> mylist1, mylist2;
//   std::list<int>::iterator it;

//   // set some initial values:
//   for (int i = 1; i <= 4; ++i)
//      mylist1.push_back(i);      // mylist1: 1 2 3 4

//   for (int i = 1; i <= 3; ++i)
//      mylist2.push_back(i * 10);   // mylist2: 10 20 30

//   it = mylist1.begin();
//   ++it;                         // points to 2

//   mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
//                                 // mylist2 (empty)
//                                 // "it" still points to 2 (the 5th element)
                                          
//   mylist2.splice(mylist2.begin(), mylist1, it);
//                                 // mylist1: 1 10 20 30 3 4
//                                 // mylist2: 2
//                                 // "it" is now invalid.
//   std::cout << "*it: " << *it << std::endl;
//   it = mylist1.begin();
//   ++it; ++it; ++it;
//   std::cout << "*it: " << *it << std::endl; // "it" points now to 30
//   // std::advance(it, 3);

//   mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
//                                 // mylist1: 30 3 4 1 10 20

//   std::cout << "mylist1 contains:";
//   for (it = mylist1.begin(); it != mylist1.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   std::cout << "mylist2 contains:";
//   for (it = mylist2.begin(); it != mylist2.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------list::resize--------------
// int main () {
//   ft::list<int> mylist;

//   // set some initial content:
//   for (int i = 1; i < 10; ++i) mylist.push_back(i);

//   mylist.resize(5);
//   mylist.resize(8, 100);
//   mylist.resize(12);

//   std::cout << "mylist contains:";
//   for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;

//   std::cout << '\n';

//   return 0;
// }

// // --------------swap(list)--------------
// int main () {
//   ft::list<int> foo(3,100);   // three ints with a value of 100
//   ft::list<int> bar(5,200);   // five ints with a value of 200

//   ft::swap(foo, bar);

//   std::cout << "foo contains:";
//   for (ft::list<int>::iterator it = foo.begin(); it != foo.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (ft::list<int>::iterator it = bar.begin(); it != bar.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------list::swap--------------
// int main () {
//   ft::list<int> first(3, 100);   // three ints with a value of 100
//   ft::list<int> second(5, 200);  // five ints with a value of 200

//     std::cout << "first contains:";
//   for (ft::list<int>::iterator it = first.begin(); it != first.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   std::cout << "second contains:";
//   for (ft::list<int>::iterator it = second.begin(); it != second.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   first.swap(second);

//   std::cout << "first contains:";
//   for (ft::list<int>::iterator it = first.begin(); it != first.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   std::cout << "second contains:";
//   for (ft::list<int>::iterator it = second.begin(); it != second.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------list::erase--------------
// int main() {
//     std::list<int> mylist;
//     std::list<int>::iterator it1, it2;

//   // set some values:
//   for (int i = 1; i < 10; ++i) mylist.push_back(i * 10);

//                               // 10 20 30 40 50 60 70 80 90
//   it1 = mylist.begin();       // ^                          ^
//   it2 = mylist.end();
//   --it2;  --it2;  --it2;      // ^                 ^
//   ++it1;                      //    ^              ^

//   it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
//                               //    ^           ^

//   it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
//                               //    ^           ^

//   ++it1;                      //       ^        ^
//   --it2;                      //       ^     ^

//   mylist.erase(it1, it2);     // 10 30 60 80 90
//                               //        ^

//   std::cout << "mylist contains:";
//   for (it1 = mylist.begin(); it1 != mylist.end(); ++it1)
//     std::cout << ' ' << *it1;
//   std::cout << '\n';
//     return 0;
// }

// // --------------list::insert--------------
// int main () {
//   ft::list<int> mylist;
//   ft::list<int>::iterator it;

//   // set some initial values:
//   for (int i = 1; i <= 5; ++i) mylist.push_back(i); // 1 2 3 4 5

//   it = mylist.begin();
//   ++it;       // it points now to number 2               ^

//   mylist.insert (it, 10);                        // 1 10 2 3 111 4 5
//   ++it;    ++it;
//   mylist.insert (it, 111);
//   // "it" points to number 111 now                            ^
//   mylist.insert (it, 2, 20);                      // 1 10 2 3 111 20 20 4 5

//   --it;       // it points now to the second 20                      ^

//   std::vector<int> myvector (2, 30);
//   mylist.insert(it, myvector.begin(), myvector.end());
//                                                 // 1 10 2 3 111 20 30 30 20 4 5
//                                                 //                       ^
//   std::cout << "mylist contains:";
//   for (it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------list::pop_front--------------
// int main () {
//   ft::list<int> mylist;
//   mylist.push_back(100);
//   mylist.push_back(200);
//   mylist.push_back(300);

//   std::cout << "Popping out the elements in mylist:";
//   while (!mylist.empty()) {
//     std::cout << ' ' << mylist.front();
//     mylist.pop_front();
//   }
//   std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';
//   return 0;
// }

// // --------------list::push_front--------------
// int main () {
//   ft::list<int> mylist (2, 100);         // two ints with a value of 100
//   mylist.push_front(200);
//   mylist.push_front(300);

//   std::cout << "mylist contains:";
//   for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;

//   std::cout << '\n';
//   return 0;
// }

// // --------------list::pop_back--------------
// int main () {
//   ft::list<int> mylist;
//   int sum = 0;
//   mylist.push_back(100);
//   mylist.push_back(200);
//   mylist.push_back(300);
//   mylist.push_back(5);
//   mylist.pop_back();
//   mylist.push_back(55);

//   while (!mylist.empty()) {
//     sum += mylist.back();
//     std::cout << mylist.back() << "--";
//     mylist.pop_back();
//   }
//   mylist.pop_back();
//   mylist.push_back(1000);

//   std::cout << "\nThe elements of mylist summed " << sum << "\nmylist = { ";
//     for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++) {
//         std::cout << *it << " ";
//     }
//     std::cout << "};\n";
//     std::cout << "Size of mylist: " << mylist.size() << std::endl;
//   return 0;
// }

// // --------------list::clear--------------
// // --------------list::push_back--------------
// int main () {
//   std::list<int> mylist;
//   std::list<int>::iterator it;

//   mylist.push_back (100);
//   mylist.push_back (200);
//   mylist.push_back (300);

//   std::cout << "mylist contains:";
//   for (it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   mylist.clear();
//   mylist.push_back (1101);
//   mylist.push_back (2202);

//   std::cout << "mylist contains:";
//   for (it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------list::assign--------------
// int main () {
//   ft::list<int> first;
//   ft::list<int> second;
//   ft::list<int> third;

//     first.assign(7, 100);                      // 7 ints with value 100
//     ft::list<int>::iterator it1, it2;
//     it1 = first.begin();
//     it1++;
//     it1++;
//     it2 = first.end();
//     it2--;
//     third.assign(it1, it2);
//     second.assign(++first.begin(), --first.end()); // a copy of first

//   int myints[] = {1776, 7, 4};
//   first.assign(myints, myints + 3);            // assigning from array

//   std::cout << "Size of first: " << int (first.size()) << '\n';
//   std::cout << "Size of second: " << int (second.size()) << '\n';
//   std::cout << "Size of third: " << int (third.size()) << '\n';
//     std::cout << "third contains:";
//     for (it1 = third.begin(); it1 != third.end(); ++it1)
//         std::cout << ' ' << *it1;
//   std::cout << '\n';
//   return 0;
// }

// // --------------list::back--------------
// int main () {
//   ft::list<int> mylist;

//   mylist.push_back(10);

//   while (mylist.back() != 0)
//     mylist.push_back (mylist.back() - 1);

//   std::cout << "mylist contains:";
//   for (std::list<int>::iterator it = mylist.begin(); it != mylist.end() ; ++it)
//     std::cout << ' ' << *it;

//   std::cout << '\n';

//   return 0;
// }

// // --------------list::front--------------
// int main () {
//   ft::list<int> mylist;

//   mylist.push_back(77);
//   mylist.push_back(22);

//   // now front equals 77, and back 22

//   mylist.front() -= mylist.back();

//   std::cout << "mylist.front() is now " << mylist.front() << '\n';

//   return 0;
// }

// // list::max_size
// int main () {
//   std::list<int> mylist1;
//   ft::list<int> mylist2;

//   std::cout << "Max size of std_list: " << mylist1.max_size() << std::endl;
//   std::cout << "Max size of ft_list:  " << mylist2.max_size() << std::endl;

//   return 0;
// }

// // --------------list::empty--------------
// int main () {
//   std::list<int> mylist;
//   int sum (0);

//   for (int i = 1; i <= 10; ++i) mylist.push_back(i);

//   while (!mylist.empty()) {
//      sum += mylist.front();
//      mylist.pop_front();
//   }

//   std::cout << "total: " << sum << '\n';
  
//   return 0;
// }

// // --------------list::rend--------------
// // --------------list::rbegin--------------
// int main () {
//   std::list<int> mylist;
//   for (int i = 1; i <= 5; ++i) mylist.push_back(i);

//   std::cout << "mylist backwards:";
//   for (std::list<int>::reverse_iterator rit = mylist.rbegin(); rit != mylist.rend(); ++rit)
//     std::cout << ' ' << *rit;

//   std::cout << '\n';

//   return 0;
// }

// // --------------list::end--------------
// // --------------list::begin--------------
// int main () {
//   int myints[] = {75, 23, 65, 42, 13};
//   ft::list<int> mylist(myints, myints + 5);

//   std::cout << "mylist contains:";
//   for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;

//   std::cout << '\n';

//   return 0;
// }

// // --------------list::operator=--------------
// int main () {
//   ft::list<int> first (3);      // list of 3 zero-initialized ints
//   ft::list<int> second (5);     // list of 5 zero-initialized ints

//   second = first;
//   first = ft::list<int>();

//   std::cout << "Size of first: " << int(first.size()) << '\n';
//   std::cout << "Size of second: " << int(second.size()) << '\n';
//   return 0;
// }

// --------------list::list--------------
int main () {
  // constructors used in the same order as described above:
  ft::list<int> first;                                // empty list of ints
  ft::list<int> second(4, 100);                       // four ints with value 100
  ft::list<int> third(second.begin(), second.end());  // iterating through second
  ft::list<int> fourth(third);                        // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16, 2, 77, 29};
  ft::list<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

  std::cout << "The contents of the first are: ";
  for (ft::list<int>::iterator it = first.begin(); it != first.end(); it++)
    std::cout << *it << ' ';
  std::cout << '\n';

  std::cout << "The contents of the second are: ";
  for (ft::list<int>::iterator it = second.begin(); it != second.end(); it++)
    std::cout << *it << ' ';
  std::cout << '\n';

  std::cout << "The contents of the third are: ";
  for (ft::list<int>::iterator it = third.begin(); it != third.end(); it++)
    std::cout << *it << ' ';
  std::cout << '\n';

  std::cout << "The contents of the fourth are: ";
  for (ft::list<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
    std::cout << *it << ' ';
  std::cout << '\n';

  std::cout << "The contents of the fifth are: ";
  for (ft::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
    std::cout << *it << ' ';
  std::cout << '\n';

  return 0;
}

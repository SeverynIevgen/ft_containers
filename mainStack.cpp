// #include "list.hpp"
#include "includes/vector.hpp"
#include "includes/stack.hpp"

#include <cmath>
#include <iostream> // std::cout
#include <stack>    // std::stack
#include <vector>   // std::vector
#include <deque>    // std::deque

// // --------------stack::top--------------
// int main()
// {
//     ft::stack<int> mystack;

//     mystack.push(10);
//     mystack.push(20);

//     mystack.top() -= 5;

//     std::cout << "mystack.top() is now " << mystack.top() << '\n';

//     return 0;
// }

// // --------------stack::pop--------------
// // --------------stack::push--------------
// // --------------stack::empty--------------
// int main()
// {
//     ft::stack<int> mystack;
//     int sum(0);

//     for (int i = 1; i <= 10; i++)
//         mystack.push(i);

//     while (!mystack.empty())
//     {
//         sum += mystack.top();
//         mystack.pop();
//     }

//     std::cout << "total: " << sum << '\n';

//     return 0;
// }

// // --------------stack::size--------------
// int main()
// {
//     std::stack<int> myints;
//     std::cout << "0. size: " << myints.size() << '\n';

//     for (int i = 0; i < 5; i++)
//         myints.push(i);
//     std::cout << "1. size: " << myints.size() << '\n';

//     myints.pop();
//     std::cout << "2. size: " << myints.size() << '\n';

//     return 0;
// }

// --------------stack::stack--------------
int main()
{
    std::deque<int> mydeque(3, 100);   // deque with 3 elements
    std::vector<int> myvector(2, 200); // vector with 2 elements

    std::stack<int> first;           // empty stack
    std::stack<int> second(mydeque); // stack initialized to copy of deque

    ft::stack<int, std::vector<int>> third; // empty stack using vector
    ft::stack<int, std::vector<int>> fourth(myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';

    return 0;
}

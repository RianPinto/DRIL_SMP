#include <iostream>
using namespace std;

template<int n> 
struct factorial
{
	static const int val = n*factorial<n-1>::val ;
};

//specialisation for base case
template<> 
struct factorial<1>
{
	static const int val = 1 ;
};

int main()
{
	cout << factorial<5>::val << endl;
	return 0;
}
//static is used because we want the same copy of val in all instantionts of the template
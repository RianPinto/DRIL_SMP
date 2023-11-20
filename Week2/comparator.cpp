#include <iostream>
#include <cmath>
#define error 0.1
using namespace std;

template <typename T>
bool equalcheck(T a, T b) {
    return a == b;
}
template <typename T>       // needed for variadic template, sometimes only one number is sent as parameter(when odd number of numbers are compared)
bool equalcheck(T a) {
    return 1;
}
template <>
bool equalcheck(float a,float b) {
    return abs(a - b) < error;
}

template <>
bool equalcheck(double a, double b) {
    return abs(a - b) < error;
}

template <typename T, typename... Args>
bool equalcheck(T first, T second, Args... args) {
    return equalcheck(first, second) && equalcheck(args...);
}

int main() {
    cout << equalcheck(1, 1, 1, 1, 1, 1, 1) << endl;
    cout << equalcheck(2.829f, 2.719f) << endl; // error is 0.1, they arent equal
    cout << equalcheck(2.729f, 2.719f) << endl; //withing error range
    cout << equalcheck(2.10, 2.11,2.12); //within error range
}

#include <iostream>
#include <cmath>
#define error 0.1
using namespace std;

template <typename T>
bool areEqual(T a, T b) {
    return a == b;
}
template <typename T>       // needed for variadic template, sometimes only one number is sent as parameter(when odd number of numbers are compared)
bool areEqual(T a) {
    return 1;
}
template <>
bool areEqual(float a,float b) {
    return abs(a - b) < error;
}

template <>
bool areEqual(double a, double b) {
    return abs(a - b) < error;
}

template <typename T, typename... Args>
bool areEqual(T first, T second, Args... args) {
    return areEqual(first, second) && areEqual(args...);
}

int main() {
    cout << areEqual(1, 1, 1, 1, 1, 1, 1) << endl;
    cout << areEqual(2.829f, 2.719f) << endl; // error is 0.1, they arent equal
    cout << areEqual(2.729f, 2.719f) << endl; //withing error range
    cout << areEqual(2.10, 2.11,2.12); //within error range
}

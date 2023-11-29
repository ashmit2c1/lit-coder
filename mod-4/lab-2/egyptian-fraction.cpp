/*
Problem Statement
Egyptian Fraction
You are an ancient Egyptian mathematician, and you have been 
tasked with representing the fraction 6/14 as a sum of unique unit 
fractions. You know that a unit fraction is a fraction with a numerator 
of 1 and a denominator of a positive integer. You also know that the
 sum of any number of unit fractions is always a rational number.

Example:

The first step is to find the largest possible unit fraction 
that is less than or equal to 6/14. This fraction is 1/3. 
The remaining fraction is 6/14 - 1/3 = 4/42. The largest possible
 unit fraction that is less than or equal to 4/42 is 1/11. 
 The remaining fraction is 4/42 - 1/11 = 1/231.

Therefore, the Egyptian fraction representation of 6/14 is 1/3 + 1/11 + 1/231.

Exercise-1

Input:
6
14

Output:
3
11
231

Exercise-2

Input:
3
4

Output:
2
4
*/
#include <bits/stdc++.h>
using namespace std;
void egyptianFraction(int n, int d)
{
    if (d == 0 || n == 0)
        return;
    if (d % n == 0) {
        cout << d / n;
        return;
    }
    if (n % d == 0) {
        cout << d;
        return;
    }
    if (n > d) {
        cout << d << endl;
        egyptianFraction(n % d, d);
        return;
    }
    int x = d / n + 1;
    cout << x << endl;
    egyptianFraction(n * x - d, d * x);
}
int main()
{
    int numerator , denominator ;
    cin >> numerator;
    cin >> denominator;
    egyptianFraction(numerator, denominator);
    return 0;
}
/*
Check string prefix
You are given a list of passwords, where each password 
consists of lowercase letters from 'a' to 'z' inclusive. 
The set of passwords is said to be a 'GOOD PASSWORD' if no password is a 
prefix of another password in the set, except for identical passwords
 (which are considered prefixes of each other). In this case, print 'GOOD PASSWORD'. 
 Otherwise, print 'BAD PASSWORD' on the first line, followed by the first pair of 
 passwords where one password is a prefix of the other.
Consider the following list of words:
['apple', 'banana', 'application', 'bananas'].
In this case, the word 'banana' is a prefix of 'bananas'.

So we would print: 'BAD PASSWORD'

Now let's take another example with a different set of words: ['cat', 'dog', 'elephant'].
 In this scenario, none of the strings are prefixes of each other.

Therefore, we can conclude that: GOOD PASSWORD

Exercise-1

Input:
abc zxy pqr

Output:
GOOD PASSWORD
Exercise-2

Input:
abc abczxy abcpqr

Output:
BAD PASSWORD

*/
#include<bits/stdc++.h>
using namespace std;

bool isPrefix(const string& str1, const string& str2) {
    return str2.compare(0, str1.length(), str1) == 0;
}

int main() {
    vector<string> passwords;
    string password;
    while (cin >> password) {
        passwords.push_back(password);
    }

    for (size_t i = 0; i < passwords.size(); ++i) {
        for (size_t j = i + 1; j < passwords.size(); ++j) {
            if (isPrefix(passwords[i], passwords[j]) || isPrefix(passwords[j], passwords[i])) {
                cout << "BAD PASSWORD\n" << endl;
                return 0;
            }
        }
    }

    cout << "GOOD PASSWORD" << endl;

    return 0;
}

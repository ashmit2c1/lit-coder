/*
You are tasked with developing a function that finds the length of the longest substring 
without repeating characters in a given string s. Consider different scenarios involving 
various characters in the input string.

Scenario: String with No Repeating Characters
Input: "abcdef"
Expected Output: 6
Explanation: In this scenario, the input string contains no repeating characters,
 so the entire string itself is the longest substring without repeating characters.

Scenario: String with Repeating Characters
Input: "abccba"
Expected Output: 3
Explanation: In this case, the longest substring without repeating characters 
is "abc" with a length of 3. The characters 'c' and 'b' are repeated, 
so the substring ends at the first occurrence of the repeated character

Important Note:
Ensure that you save your solution before progressing to the next question and before submitting your answer.

Exercise-1
Input :
pqrsstu

Output :
4

Exercise-2

Input:
abbedfgi

Output:
6
*/
#include <bits/stdc++.h>
using namespace std;

bool areDistinct(string str, int i, int j)
{

	vector<bool> visited(256);

	for (int k = i; k <= j; k++) {
		if (visited[str[k]] == true)
			return false;
		visited[str[k]] = true;
	}
	return true;
}

int longestUniqueSubsttr(string str)
{
	int n = str.size();
	int res = 0; // result
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (areDistinct(str, i, j))
				res = max(res, j - i + 1);
	return res;
}

int main()
{
    string str;
    cin >> str;

	int len = longestUniqueSubsttr(str);
    cout << len << endl;
	return 0;
}

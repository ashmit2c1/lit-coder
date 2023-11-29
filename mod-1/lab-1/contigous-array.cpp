/*
Contiguous Array
Given a binary array 'nums', you are required to find 
the maximum length of a contiguous subarray that contains an equal number of 0s and 1s.

Explanation:

A binary array is an array that contains only 0s and 1s.
A subarray is any subset of the indices of the original array.
A contiguous subarray is a subarray in which all the 
elements are consecutive, i.e., any element between the first and last
 element of the subarray is also part of it.
Examples:
Input :nums = [0, 1]
Output : 2
Explanation: The longest contiguous subarray with an 
equal number of 0s and 1s is [0, 1] with a length of 2.
Input : nums = [0, 1, 0]
Output : 2
Explanation: The longest contiguous subarray with an
 equal number of 0s and 1s is either [0, 1] or [1, 0], both with a length of 2.
Input : nums = [0, 0, 0, 1, 1, 1]
Output : 6
Explanation: The longest contiguous subarray with an 
equal number of 0s and 1s is [0, 0, 0, 1, 1, 1] with a length of 6.
The problem requires finding the maximum length of a
 contiguous subarray in the binary array 'nums' that contains an equal number of 0s and 1s.

Important Note: Ensure that you save your solution before progressing 
to the next question and before submitting your answer.

Exercise-1

Input : 
0 0 0 1 1 1 1 0

Output :
8
Exercise-2

Input:
1 0 0 1 1 1 1 0

Output:
4

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        int sum = 0;
        map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if (m.count(sum)) {
                ret = max(ret, i - m[sum]);
            }
            else {
                m[sum] = i;
            }
        }
        return ret;
    }
};

int main() {
    vector<int> v(8);
    for (int i = 0; i < 7; i++) {
        cin >> v[i];
    }

    Solution ob;
    cout << ob.findMaxLength(v) << endl;

    return 0;
}

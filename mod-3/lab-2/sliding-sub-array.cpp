/*
You are given an array of integers arr and an integer k. 
Your task is to find the given n th position of the smallest 
integer in each contiguous subarray of size k and print these smallest integers.
A subarray is a contiguous non-empty sequence of elements within the original array.
For each subarray of size k, you need to find the given n th position of 
the smallest integer within that subarray.
The given n th position of the smallest integer in a subarray 
is the integer that appears at the given n th position when 
the subarray is sorted in ascending order.
.
Your task is to return an integer array containing n - k + 1 elements,
 denoting the beauty of the subarrays in order from the first index in the array.

Exercise-1

Input: 
1 2 3 4 5 6 7 8 9 10
3
2
Note: 
Line 1: input array
Line 2: sub array length
Line 3: position of the smallest value

Output:
2 3 4 5 6 7 8 9
Exercise-2

Input:
1 2 3 4 5 6 7 8 9 10
4
2

Output:
2 3 4 5 6 7 8

*/
#include <iostream>
#include <vector>

using namespace std;

// Method to find the maximum for each
// and every contiguous subarray of size K.
void printKMax(const vector<int>& arr, int N, int K) {
    int max;

    for (int i = 0; i <= N - K; i++) {
        max = arr[i];

        for (int j = 1; j < K; j++) {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        cout << max << " ";
    }
}

int main() {

    vector<int> arr(10);
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    int N, K;
    cin >> N;

    cin >> K;

    // Function call
    printKMax(arr, N, K);

    return 0;
}

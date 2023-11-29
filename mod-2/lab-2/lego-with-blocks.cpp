/*
How many different ways can you build a wall of height 'n' and width 'm' using 
an infinite number of Lego bricks of four types, each with different dimensions 
(depth x height x width)? The types of Lego bricks available are:

Depth: 1, Height: 1, Width: 1
Depth: 1, Height: 1, Width: 2
Depth: 1, Height: 1, Width: 3
Depth: 1, Height: 1, Width: 4
The wall should satisfy the following conditions:

There should be no holes in the wall.
The wall should be a single solid structure without a straight vertical break across all rows of bricks.
The bricks must be laid horizontally.
Provide the number of ways to build the wall, considering that the result should be output modulo 1000000007.

Example:

For n = 2 and m = 2, the output should be legoWall(n, m) = 3.
For n = 3 and m = 2, the output should be legoWall(n, m) = 7.
For n = 2 and m = 3, the output should be legoWall(n, m) = 9.

Input/Output:

1.The input consists of two integers: n and m, representing the desired height and width of 
the wall, respectively.
2.The output is a long integer representing the number of ways to 
build the wall, modulo 1000000007.

Exercise-1
Input:
2
2

Here
First row - n value
Second row - m value

Output:
3

Exercise-2
Input:
4
4

Output:
3375
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int legoWall(int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize base cases
    for (int j = 0; j <= m; ++j) {
        dp[1][j] = 1;
    }

    // Fill the DP array
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }

    // Calculate the result based on the given Lego brick types
    for (int i = 2; i <= n; ++i) {
        for (int j = 4; j <= m; ++j) {
            dp[i][j] += dp[i - 2][j - 4];
            dp[i][j] %= MOD;
        }
    }

    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;

    int result = legoWall(n, m);
    cout << result << endl;

    return 0;
}

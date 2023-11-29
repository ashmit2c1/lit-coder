/* You have a collection of candies, and each candy has a 
certain sweetness value. Your goal is to combine the candies to create
 new candies until you reach a specific target sweetness level.
  Find how many steps need to reach candies sweetness target.

To achieve this, you can select any two candies with the 
least sweetness and combine them into a new candy with sweetness calculated as follows:

sweetness = (least sweet candy + 2 * second least sweet candy)

For example, consider the following scenario:

You are given a target sweetness level of 12, and you 
have the following candies: [2, 8, 3, 7, 4, 6]. To reach the target sweetness of 12.

you can perform the following steps:
Ascending order = 2,3,4,6,7,8

Combine the two least sweet candies: 2 + 2*3 = 8. Updated candies: [ 8, 4, 6, 7, 8].
Combine the two least sweet candies: 4 + 2*6 = 16. Updated candies: [8, 16, 7, 8].
Combine the two least sweet candies: 7 + 2*8 = 23. Updated candies: [8,16,23].
Combine the two least sweet candies: 8 + 2*16 = 17. Updated candies: [40,23].
The sweetness of the first candy in the updated candies array is now 40, 
which exceeds the target sweetness of 12.

Exercise-1
Input:
7
1 2 3 4 5
Note:

Line 1 : Target of the sweetness
Line 2 Each candies sweetness

output:
3

Exercise-2
input:
11
2 5 3 7 6 1
output:
4*/

#include<bits/stdc++.h>
using namespace std;

int stepsToReachTargetSweetness(int target, vector<int>& candies) {
    sort(candies.begin(), candies.end());

    int steps = 0;

    while (candies.size() > 1 && candies[0] < target) {
        int newSweetness = candies[0] + 2 * candies[1];
        candies.erase(candies.begin(), candies.begin() + 2);
        candies.insert(lower_bound(candies.begin(), candies.end(), newSweetness), newSweetness);
        steps++;
    }

    return steps;
}

int main() {
    int target;
    cin >> target;

    // Consume the newline character from the previous input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> candies;
    int candy;
    while (cin >> candy) {
        candies.push_back(candy);
    }

    int result = stepsToReachTargetSweetness(target, candies);

    cout <<  result << endl;

    return 0;
}

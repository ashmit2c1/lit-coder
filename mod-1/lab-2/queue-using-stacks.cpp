/*
Problem Statement
Queue
Write a program to implement a custom queue using two stacks. 
The queue should support the following three types of queries:
Enqueue: This query type is denoted by "1 x", where x is an
 element to be enqueued. It means that you need to insert element x at the end of the queue.
Dequeue: This query type is denoted by "2". It indicates 
that you should remove the element at the front of the queue.
Print Front: This query type is denoted by "3". It instructs you
 to print the element at the front of the queue without removing it.

Exercise-1
input:
1 42,2,1 14,3

output:
14

Exercise-2
input:
1 23,2,1 14,3,2,1 78,3

Output:
14
78
*/
#include<bits/stdc++.h>
using namespace std;

class CustomQueue {
private:
    stack<int> s1;
    stack<int> s2; 

public:

    void enqueue(int x) {
        s1.push(x);
    }


    void dequeue() {

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (s2.empty()) {
            cout << "Queue is empty.\n";
            return;
        }


        s2.pop();
    }

    void printFront() {

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (s2.empty()) {
            cout << "Queue is empty.\n";
            return;
        }


        cout << s2.top() << "\n";
    }
};

int main() {
    CustomQueue customQueue;

    cout << "Enter the number of queries: ";
    int numQueries;
    cin >> numQueries;
    cin.ignore(); 

    cout << "Enter the queries:\n";
    for (int i = 0; i < numQueries; ++i) {
        string query;
        getline(cin, query);

        stringstream ss(query);
        string type, value;
        getline(ss, type, ' ');
        getline(ss, value, ',');

        if (type == "1") {
            int x = stoi(value);
            customQueue.enqueue(x);
        } else if (type == "2") {
            customQueue.dequeue();
        } else if (type == "3") {
            customQueue.printFront();
        }
    }

    return 0;
}

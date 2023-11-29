/*
You are developing a text editor that allows users to perform
 various operations on the text using the "CustomStack" class. 
 The class supports the following operations:

insert(value): Inserts a string of characters at the current cursor position in the text.
delete(value): Deletes the last value characters from the text starting from the current cursor position.
get(value): Retrieves the character at index value from the text and displays it.
undo(): Reverts the last executed command on the text.
Each command is represented by a string in the following format:

1.Command 1: '1 value' - Inserts the string value at the current cursor position in the text.
2.Command 2: '2 value' - Deletes the last value characters from 
the text starting from the current cursor position.
3.Command 3: '3 value' - Retrieves the character at index value from the text and displays it.
4.Command 4: '4' - Reverts the last executed command on the text.

Consider a scenario where you have a text editor with a "CustomStack" 
class that implements the required operations. Assume the initial text is empty.

Important Note: Ensure that you save your solution before progressing to 
the next question and before submitting your answer.

Exercise-1
input:
1 abc,3 3,2 2,3 1

Here
1 abc -> command and input text
3 3 -> command and index of the stack
Output:
c
a

Exercise-2
Input:

1 zxy,3 3,2 2,1 def,3 2

Output:
y
d
*/

#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

class CustomStack {
public:
    string text;
    stack<string> operations;

    void insert(const string& value) {
        text.insert(cursor, value);
        operations.push("1 " + value);
    }

    void deleteText(int value) {
        if (cursor >= value) {
            text.erase(cursor - value, value);
        }
        operations.push("2 " + to_string(value));
    }

    void get(int value) {
        if (value < text.size()) {
            cout << text[value] << endl;
        }
    }

    void undo() {
        if (!operations.empty()) {
            string operation = operations.top();
            operations.pop();

            istringstream iss(operation);
            int command;
            iss >> command;

            switch (command) {
                case 1:
                    text.erase(cursor, operation.length() - 2); // Length of "1 " prefix
                    break;
                case 2:
                    text.insert(cursor, operation.substr(2)); // Skip "2 " prefix
                    break;
            }
        }
    }

private:
    size_t cursor = 0;
};

int main() {
    CustomStack customStack;

    string input;
    getline(cin, input);

    istringstream iss(input);
    string command;
    while (iss >> command) {
        if (command == "1") {
            string value;
            iss >> value;
            customStack.insert(value);
        } else if (command == "2") {
            int value;
            iss >> value;
            customStack.deleteText(value);
        } else if (command == "3") {
            int value;
            iss >> value;
            customStack.get(value);
        } else if (command == "4") {
            customStack.undo();
        }
    }

    return 0;
}

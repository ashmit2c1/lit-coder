/*
String Analysis
You are given a string that represents an email address: 
"My e-mail: eMail_Address321@anymail.com". Your task is 
to analyze the composition of the characters in the string 
and determine the percentage of uppercase letters, lowercase letters, 
digits, and other characters such as symbols (#$., etc).

To accomplish this, you need to break down the string
 and calculate the percentage for each category. The results are as follows:

Uppercase letters: 7.5%
Lowercase letters: 65%
Digits: 7.5%
Other characters (symbols): 20%

Important Note: Ensure that you save your solution before progressing 
to the next question and before submitting your answer.

Exercise-1

Input :

Support1@litwork.in

Output :

5.263%
78.947%
5.263%
10.526%

Exercise-2

Input:

Client.1234@litwork.in

Output:

4.545%
63.636%
18.182%
13.636%

*/
#include <iostream>
#include <string>

using namespace std;
// function to analyze the given input
void analyzeEmailComposition(const string& email) {
    // creating variables for different composition and initializing them with value 0 
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int digitCount = 0;
    int otherCount = 0;
    // for each entry in the string, the valur will be incremeneted 
    for (char ch : email) {
        if (isupper(ch)) {
            uppercaseCount++;
        } else if (islower(ch)) {
            lowercaseCount++;
        } else if (isdigit(ch)) {
            digitCount++;
        } else {
            otherCount++;
        }
    }
    // calculating the percentage for each character
    int totalCharacters = email.length();
    double uppercasePercentage = (double(uppercaseCount) / totalCharacters) * 100;
    double lowercasePercentage = (double(lowercaseCount) / totalCharacters) * 100;
    double digitPercentage = (double(digitCount) / totalCharacters) * 100;
    double otherPercentage = (double(otherCount) / totalCharacters) * 100;

    cout << uppercasePercentage << "% " << lowercasePercentage << "% " << digitPercentage << "% "<< otherPercentage << "%" << endl;
}
// main function 
int main() {
    string email;
    cin >> email;
    analyzeEmailComposition(email);
    return 0;
}

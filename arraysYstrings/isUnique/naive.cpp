/**
First Approach:
When we take in a string, we must check if each character inside the string is seen in the rest of the string. Therefore, I will have two for loops that 
check each character against the rest of the string to see if there is a duplicate character. This apporach will be O(N^2) run time because we check each 
character inside of string against the rest of the string.

***Assumes uppercase and lowercase characters are different.

**/

#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

bool isUniqueTwoForLoops(string userString)
{
    for (int i = 0; i < userString.size(); i++)
    {
        for (int j = i + 1; j < userString.size(); j++)
        {
            if (userString.at(i) == userString.at(j))
            {
                cout << "False" << endl;
                return false;
            }
        }
    }
    return true;
}

int main()
{

    cout << "Testing with string \"a\", should return: True/1" << endl;
    bool testResultOne = isUniqueTwoForLoops("a");
    cout << "Function returned: " << testResultOne << endl
         << endl;

    cout << "Testing with string \"aa\", should return: False/0" << endl;
    bool testResultTwo = isUniqueTwoForLoops("aa");
    cout << "Function returned: " << testResultTwo << endl;

    cout << "Testing with string \"arturo\", should return: False/0" << endl;
    bool testResultThree = isUniqueTwoForLoops("arturo");
    cout << "Function returned: " << testResultThree << endl
         << endl;

    cout << "Testing with string \"ArtuRo\", should return: True/1" << endl;
    bool testResultFour = isUniqueTwoForLoops("ArtuRo");
    cout << "Function returned: " << testResultFour << endl
         << endl;
}

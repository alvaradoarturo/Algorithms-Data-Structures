/**
Second Approach:
I know I can create a solution that has O(N^2) runtime. However, since we must check every character in the input string, I believe the best conceivable 
runtime is O(N). I can optimize this algorithm by creating a seperate array that contains every character that has been seen thus far. The lookup time 
for this array will take at most O(N) time because we must check every character to make sure it is unique. Therefore we can create an algorithm with 
O(N) runtime. 

***Assumes uppercase and lowercase characters are different.

**/

#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

bool isUniqueStoreMethod(string userString)
{
    int charactersSeen[256] = {0};
    for (int i = 0; i < userString.size(); i++)
    {
        if ((charactersSeen[userString.at(i)]) == 0)
        {
            charactersSeen[userString.at(i)] = 1;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{

    cout << "Testing with string \"a\", should return: True/1" << endl;
    bool testResultOne = isUniqueStoreMethod("a");
    cout << "Function returned: " << testResultOne << endl
         << endl;

    cout << "Testing with string \"aa\", should return: False/0" << endl;
    bool testResultTwo = isUniqueStoreMethod("aa");
    cout << "Function returned: " << testResultTwo << endl;

    cout << "Testing with string \"arturo\", should return: False/0" << endl;
    bool testResultThree = isUniqueStoreMethod("arturo");
    cout << "Function returned: " << testResultThree << endl
         << endl;

    cout << "Testing with string \"ArtuRo\", should return: True/1" << endl;
    bool testResultFour = isUniqueStoreMethod("ArtuRo");
    cout << "Function returned: " << testResultFour << endl
         << endl;
}

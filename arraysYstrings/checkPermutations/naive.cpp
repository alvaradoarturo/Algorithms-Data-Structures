/**
First Approach:
We know a permutation of a string is simply having the same characters but rearranged in a 
random order. To simplifiy the problem, all we need to know if the number of characters in the first string, also appear in the 
second string. My inital approach is to first sort each string. Then we can find the occurance
of each character in the first string, then verify the same number in the second string. 
Sorting the strings will take O(N log N) time. Once it is sorting the checking of each character
will take O(N) time. Leaving us with an algorithm of O(N log N) time.

**/
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h>

using namespace std;

string stringSorter(string &stringToSort)
{
    sort(stringToSort.begin(), stringToSort.end());
    return stringToSort;
}

int numberOfOccurences(char characterToCheck, string stringToTally)
{
    int occurencesOfChar;
    for (int i = 0; i < stringToTally.length(); i++)
    {
        if (stringToTally.at(i) == characterToCheck)
        {
            occurencesOfChar++;
        }
    }
    return occurencesOfChar;
}

bool isPermutation(string testString, string baseString)
{
    for (int i = 0; i < testString.length(); i++)
    {
        char currChar = testString.at(i);
        if (numberOfOccurences(currChar, testString) > numberOfOccurences(currChar, baseString))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string testingString1 = "aba";
    string testingString2 = "abaaaaaaaaa";

    testingString1 = stringSorter(testingString1);
    testingString2 = stringSorter(testingString2);

    cout << "Testing with string: \"aba\" and \"abaaaaaaaaa\". Should return true/1" << endl;
    cout << "Method returned: " << isPermutation(testingString1, testingString2) << endl;

    string testingString3 = "hello";
    string testingString4 = "mynameisArturohello";

    testingString3 = stringSorter(testingString3);
    testingString4 = stringSorter(testingString4);

    cout << "Testing with string: \"hello\" and \"mynameisArturohello\". Should return true/1" << endl;
    cout << "Method returned: " << isPermutation(testingString3, testingString4) << endl;

    string testingString5 = "arturo";
    string testingString6 = "workofartyou";

    testingString5 = stringSorter(testingString5);
    testingString6 = stringSorter(testingString6);

    cout << "Testing with string: \"arturo\" and \"workofartyou\". Should return true/1" << endl;
    cout << "Method returned: " << isPermutation(testingString5, testingString6) << endl;

    string testingString7 = "notapermutation";
    string testingString8 = "nowayjose";

    testingString7 = stringSorter(testingString7);
    testingString8 = stringSorter(testingString8);

    cout << "Testing with string: \"notapermutation\" and \"nowayjose\". Should return true/1" << endl;
    cout << "Method returned: " << isPermutation(testingString7, testingString8) << endl;
}

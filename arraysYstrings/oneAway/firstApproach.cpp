/*
Initial: If we first solve this problem by hand, we would realize the way to begin is first starting either in the front or end of the string. Then one by one, 
we check if the two string at each position match. If they do, we proceed to the next char, if they dont, then we will keep a running total of number of edits.
We know if the difference between the two strings(in terms of string length) is greater than two, then these two strings can never be one change away. Since we
will have to check every char in each string once, then our runtime will be O(N).
*/

#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void isOneAway(string string1, string string2)
{
    int changesNeeded = 0;
    int longestString = string1.length() > string2.length() ? string1.length() : string2.length();
    if (abs((string1.length() - string2.length()) > 1))
    {
        cout << "Strings are not one change away" << endl;
        return;
    }
    for (int i = 0; i < longestString; i++)
    {
        try
        {
            if (string1.at(i) != string2.at(i))
                changesNeeded++;
        }
        catch (...)
        {
            changesNeeded++;
        }
    }
    if (changesNeeded > 1)
    {
        cout << "Strings are not one change away" << endl;
    }
    else
    {
        cout << "Strings ARE one change away or less" << endl;
    }
}

int main()
{
    string firstTest = "arturo";
    string secondTest = "art";
    isOneAway(firstTest, secondTest);

    string thirdTest = "arturo";
    string fourthTest = "artur";
    isOneAway(thirdTest, fourthTest);

    string fifthTest = "churro";
    string sixthTest = "arturo";
    isOneAway(fifthTest, sixthTest);
}
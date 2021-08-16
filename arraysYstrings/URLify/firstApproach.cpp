/**
Inital Approach: It is clear that we have to visit every character in the string in order to determine whether or not it is a space. This
search will have a runtime of O(N). Then for every space we find, we must do a replace operation. Using a STD library, we can
make the replace take O(1) time. Leaving us with a search algorithm that will take O(N) time. 
**/

#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

class mutatableString
{
private:
    string stringToChange;

public:
    mutatableString(string userString)
    {
        stringToChange = userString;
    }
    void replaceChar(char, string);
};

void mutatableString::replaceChar(char findChar, string replacementChar)
{
    if (this->stringToChange.length() == 0)
    {
        cout << "No replacements necessary" << endl;
    }
    else
    {
        for (int i = 0; i < this->stringToChange.length(); i++)
        {
            if (this->stringToChange.at(i) == findChar)
            {
                this->stringToChange.replace(i, replacementChar.length() - 1, replacementChar);
            }
        }
    }
    cout << this->stringToChange << endl;
}

int main()
{
    string firstString = "";
    string secondString = "Hello, my name is Arturo";
    string thirdString = "Testing this function to see if it hides all spaces";

    mutatableString firstTestString(firstString);
    cout << "Testing function with: " << firstString << endl;
    firstTestString.replaceChar('a', "aa");

    mutatableString secondTestString(secondString);
    cout << "Testing function with: " << secondString << endl;
    secondTestString.replaceChar(' ', "OK");

    mutatableString thirdTestString(thirdString);
    cout << "Testing function with: " << thirdString << endl;
    thirdTestString.replaceChar(' ', "YES");
}

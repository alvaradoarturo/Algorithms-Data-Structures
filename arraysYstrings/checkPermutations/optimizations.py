# Optimized Approach:
# Instead of sorting the strings, I can instead count how many times each character
# appears in each string. If one string has less than the other, then we know
# these strings are not permutations. I will use python in order to take advantage of some
# of the built in functions like 'ord' that will convert to each character into it's
# unicode equivilance
#
# Counting the number of times each character appears will take O(N) time. Also, the comparison
# will also take O(N) time. Leaving us with a runtime of O(N).

import ast
import os
import sys


def checkPermutation(testString, baseString):
    if(len(testString) != len(baseString)):
        print("Non Permutation")
        return
    char_count = [0] * 256
    for char in testString:
        char_count[ord(char)] += 1
    for element in baseString:
        if(char_count[ord(element)] == 0):
            print("Non Permutation")
            return
        char_count[ord(element)] -= 1
    print("!Permutation!")
    return


def main():

    testStringOne = "workhard"
    testStringTwo = "hardwork"

    print("Checking with strings 'work hard' & 'hardwork'")
    checkPermutation(testStringOne, testStringTwo)

    testStringThree = "nunun"
    testStringFour = "nnuun"
    print("Checking with strings 'nunun' & 'nnuun'")
    checkPermutation(testStringThree, testStringFour)

    testString5 = "yomomma"
    testString6 = "yodaddy"
    print("Checking with strings 'yomomma' & 'yodaddy'")
    checkPermutation(testString5, testString6)


if __name__ == '__main__':
    main()

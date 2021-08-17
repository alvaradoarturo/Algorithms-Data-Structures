# We are checking for palindromes permutations in this problem, therefore it is a good idea to
# keep track of how many times each letter appears in the palindrome string. After this, we can
# use this to check against the string in question. If there is an equal amount of character counts
# we know the two strings are not permutations. The first counting of characters will take O(N) time.
# Then the check will also take O(N) time. Leaving us with a function that will run in O(N) time.

import ast
import os
import sys
import unittest
from collections import Counter


def check_Palindrome_Permutaion(testString, palindromeString):
    if(len(testString) != len(palindromeString)):
        print("Not a permutation")
        return False
    char_count = [0] * 256
    for char in palindromeString:
        char_count[ord(char)] += 1
    for element in testString:
        if(char_count[ord(element)] == 0):
            print("Not a permutation")
            return False
        char_count[ord(element)] -= 1
    print("We have a permutation")
    return True


class Test(unittest.TestCase):
    # str1, str2, is_pe
    test_cases = (
        ("a", "a", True),
        ("ab", "ba", True),
        ("bab", "abb", True),
        ("aaaaa", "aaa", False),
        ("arturo", "arturoa", False),
        ("$$$&", "$&$$", True),
        ("____", "____", True),
        ("ab-a", "ba-a", True),
    )

    def test_cp(self):
        # true check
        for str1, str2, expected in self.test_cases:
            assert check_Palindrome_Permutaion(str1, str2) == expected


if __name__ == '__main__':
    unittest.main()

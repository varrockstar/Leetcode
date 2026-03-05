/*
Leetcode: Minimum Changes To Make Alternating Binary String
Difficulty: Easy
Language: C

After a lot of fiddling around with this problem, the obvious
dawned on me.

Intuition:
1) There are only two possible alternating strings
for any given length: The one starting with 1 and the one
starting with 0.

2) When comparing string s to the alternating bit string which starts
with 1 and is of the same length as s (ie. "010101..."), if the number of bits
that would need to be flipped to make the strings equal is less
than half the length of s, this is the answer. If the number
of bits that would need to be flipped is more than half the length,
then it would be easier to generate the string that starts with 0
(ie. "101010..."). Therefore in this case the number of bits to be
flipped is the difference between the length of the string and number we found
earlier.

Implementation:
1) Find the length of s

2) Compare s with the string ("010101...") which is of the same length as s

3) If the number of differences between s and "010101..." is less than half
the length of s, return that number. Otherwise return (length - differences)
*/

#include <stdio.h>

int minOperations(char *s) {
  int length = 0;
  int differences = 0;

  while (s[length] != '\0') {
    if (length % 2 != s[length] - '0')
      differences++;
    length++;
  }

  if (differences < length - differences)
    return differences;
  else
    return length - differences;
}

int main() {
  char* inputString = "10011001001010";
  printf("Min operations: %d\n", minOperations(inputString));
}
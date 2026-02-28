/*
Leetcode: Concatenation of Consecutive Binary Numbers
Difficulty: Medium
Language: C

Given a number in base 10, concatenate every whole number from 1 to n
and return the decimal representation of the resultant binary number (mod 10^9+7).

In this second attempt I tried to complete the task without creating a lengthy string
of binary. My strategy this time was to increment the total by the product
of each counting number and 2^k where k is the number of bits to the right of 
the counting number's binary representation. This time the string of bits
does not actually exist in memory, there is an abstract representation of where
the algorithm is in the calculation compared to the total length of the bitstring.

This attempt also was timed out and I am stuck for new ideas on how to do this more efficiently.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// To get the length of the concatenated binary
int getLength(int n) {
    int length = 0;
    for (int i = 1; i <= n; i++) {
        length += 1 + floor(log2(i));
    }
    return length;
}

int concatenatedBinary(int n){
    int length = getLength(n);
    int right = length; // How many bits to the right

    int total = 0;
    for (int i = 1; i <= n; i++) {
        right -= 1 + floor(log2(i));
        long long toAdd = 1;
        for (int e = 0; e < right; e++) {
            toAdd = (toAdd * 2) % 1000000007;
        }
        toAdd = (toAdd * i) % 1000000007;
        total = (total + toAdd) % 1000000007;
    }
    return total;
}

int main() {
  printf("%d", concatenatedBinary(8000));
}
/*
Leetcode: Concatenation of Consecutive Binary Numbers
Difficulty: Medium
Language: C

Given a number in base 10, concatenate every whole number from 1 to n
and return the decimal representation of the resultant binary number (mod 10^9+7).

This is my first attempt, which technically does work however I ran into space problems as
the input grew, I ran into issues with both storage and runtime as I was storing a string
of length nlogn.

Approach:
1) Get the binary represenation of the input and hold it in a string.

2) Use the string to calculate the final value (by converting it back to decimal).

   As it turned out, it was easier to keep the binary representation
   in reverse order, since this would render it unnecessary to get the length
   of the binary represenation of the number.

   As mentioned above, this code did not meet leetcode's time constraints so I
   am continuing on this problem to create a more elegant solution.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* toBinary(int x) {
    int index = 0;
    char* binary = malloc(sizeof(char) * 1000);

    for (int i = x; i >= 1; i--) {
        int quotient = i;
        int remainder = -1;
        while (quotient != 0) {
            remainder = quotient % 2;
            binary[index] = remainder + '0';
            quotient = quotient / 2;
            index++;
        }
    }

    //This loop was to put the string in order from 
    //most to least significant bit, however I determined
    //it was easier to just leave it in reverse order.
    /*for (int i = 0; i < index / 2; i++) {
        char temp = binary[index - i - 1];
        binary[index - i - 1] = binary[i];
        binary[i] = temp;
    }*/
    binary[index] = '\0';
    return binary;
}

int concatenatedBinary(int n){
    int total = 0;
    char* binary = toBinary(n);

    for (int i = 0; binary[i] != '\0'; i++) {
        if (binary[i] == '1') {
            int toAdd = 1;
            for (int e = 0; e < i; e++) {
                toAdd = (toAdd * 2) % 1000000007;
            }
            total = (total + toAdd) % 1000000007;
        }
    }
    free(binary);   
    return total;
}

int main() {
  for (int i = 0; i < 100; i++) {
    printf("%d: %d\n",i, concatenatedBinary(i));
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int LENGTH = 10; // Change if you want

int numSteps(char *s) {
  int length = 0;
  int steps = 0;
  while (s[length] != '\0') {
    length++;
  }
  // now length is the length of the string

  // index of the lsd is [length - 1]
  while (length > 1 || s[0] != '1') {
    if (s[length - 1] == '0') {
      s[length - 1] = '\0';
      length--;
      steps++;
    } else {            // lsb is 1
      int all_ones = 1; // check if number is 2^n-1 ie "1111" = 15

      // Starting from the least significant bit keep flipping bits
      // Until a 0 is flipped to a 1
      for (int i = length - 1; i >= 0; i--) {
        if (s[i] == '1') {
          s[i] = '0';
        } else {
          s[i] = '1';
          all_ones = 0;
          break; // out of the for loop as there is no more carry
        }
      }
      // If the string was all 1's, the above function changed them all to 0's
      // Need to prepend a 1
      if (all_ones) {
        s[length] = '0'; // Replace the string terminator with '0' (as the
                         // string is now 1 char longer)
        s[0] = '1';      // First bit is 1, as the num is now 2^n ("100000...0")
        length++;
        s[length] = '\0'; // String terminator moves 1 spot
      }
      steps++;
    }
  }
  return steps;
}

int main() {
  // Create a random input string
  srand(time(NULL));
  char inputString[LENGTH];
  for (int i = 0; i < LENGTH; i++) {
    inputString[i] = rand() % 2 + '0'; // '0' or '1' as char
  }
  inputString[LENGTH] = '\0';

  printf("Random binary input string: %s\n", inputString);

  printf("Number of steps: %d\n", numSteps(inputString));
}
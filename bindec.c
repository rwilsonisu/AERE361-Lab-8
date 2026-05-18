#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int validDec(char *s) {
  int count = 0;
  int start = 0;

  if(s[0] == '-') {
    start = 1; //checks to see if there is a negative sign at the start of the input
  } //end if

  for(int i = start; s[i] != '\0'; i++) { //increments by one until it finds null
    if(s[i] == '.') { //checks for decimal point
      count++;
      if(count > 1) return 0;
    } else if(!isdigit(s[i])) { //checks if input is not a digit
      return 0;
    } //end ifs
  } //end for
  return 1;
} // end validDec

int validBin(char *s) {
  int count = 0;
  int start = 0;

  if(s[0] == '-') {
    start = 1; //checks to see if there is a negative sign at the start of the input
  } //end if

  for(int i = start; s[i] != '\0'; i++) { //increments by one until it finds null
    if(s[i] == '.') { //checks for decimal point
      count++;
      if(count > 1) return 0;
    } else if(s[i] != '0' && s[i] != '1') { //checks if input is not a 0 or 1 (binary)
      return 0;
    } //end ifs
  } //end for
  return 1;
} //end validBin

void dtob(double num) {
  // decimal to binary function
  if(num < 0) {
    printf("-");
    num = -num; //converts num to negative if - is detected
  } //end if
  
  int numPart = (int)num; //integer for the whole number part
  double decPart = num - numPart; //integer for the decimal part

  char numBin[64];
  int i = 0;
  if(numPart == 0) {
    numBin[i++] = '0'; //records and stores binary
  } //end if
  else {
    while(numPart > 0) {
      numBin[i++] = (numPart % 2) + '0'; //records and stores the binary remainder
      numPart /= 2; //repeats division by 2 to minimize
    } //end while
  } //end else

  for(int j = i - 1; j >= 0; j--) {
    // reverse integer tech
    printf("%c", numBin[j]);
  } //end for

  if(decPart > 0) {
    printf(".");
    for(int k = 0; k < 10; k++) {
      decPart *= 2; //multiplies by 2
      int bit = (int)decPart; //takes out whole number binary part
      printf("%d", bit);
      decPart -= bit; // keeps only the remainder decimal
      if(decPart == 0) {
	break;
      } //end if
    } //end for
  } //end if
  printf("\n");
} //end dtob

void btod(char *bin) {
  int neg = 0;
  if(bin[0] == '-') {
    neg = 1; //converts bin to negative if - is detected
    bin++;
  } //end if
  
  double ans = 0.0;
  int l = strlen(bin);
  int pt = -1;

  for(int i = 0; i < l; i++) {
    // finds the decimal point
    if(bin[i] == '.') {
      pt = i; //sets new point equal to i location
      break;
    } //end if
  } //end for

  if(pt == -1) {
    pt = l; //sets point equal to the length if at -1
  } //end if

  for(int i = 0; i < pt; i++) {
    // whole number part of binary
    ans = ans*2 + (bin[i] - '0'); // uses base 2 to create answer
  } //end for

  double dec = 0.5; // first bit for decimal
  for(int i = pt + 1; i < l; i++) {
    // decimal part of binary
    if(bin[i] == '1') {
      ans += dec;
    } //end if
    dec /= 2; // next bit iteration
  } //end for

  if(neg) ans = -ans; //makes decimal negative if binary is negative

  printf("%f\n", ans);
} //end btod

int main(int argc, char *argv[]) {
  if(argc != 3) {
    // makes sure that the argc is in correct location in user input
    // terminates if not 
    printf("Type: ./bindec -d 'decimal num' OR -b 'binary num'\n");
    return 1;
  } //end if

  if(strcmp(argv[1], "-d") == 0) {
    //checks to see if decimal input is valid
    if(!validDec(argv[2])) {
      printf("Error: invalid decimal input.\n");
      return 1;
    } //end if
    dtob(atof(argv[2]));
  } else if(strcmp(argv[1], "-b") == 0) {
    //checks to see if binary input is valid
    if(!validBin(argv[2])) {
      printf("Error: invalid binary input.\n");
      return 1;
    } //end if
    btod(argv[2]);
  } else {
    printf("Flag is not correct.\n");
    return 1;
  }
  return 0;  
} //end main

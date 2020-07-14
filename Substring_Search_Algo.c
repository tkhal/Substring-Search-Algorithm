// Timothy Khal
// Substring Search Skeleton
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Find the location of the first occurrence of pattern in text
// or say that it does not occur if that is the case.
// If you find the pattern in the text, output the index of the
// first letter in text where the pattern first occurs.

// You must also print the total number of character compairsons that
// the program made.

// If the number of unchecked characters in the text is ever less than
// the length of the pattern the algorithm must stop.

// NOTE:  All test texts and patterns should not contain any white space
//        (e.g. blank space character, newline, tab, etc.) as scanf
//        will stop on such an input character.

// Function Prototypes
void initializeASCIIarray(int array[], char pattern[], int m);
int search(char pattern[], char text[], int p_ptr, int t_ptr, int m);
int smartSearch(int array[], char pattern[], char text[], int m, int n);

// Global variables
int timesFound = 0; // Number of times the pattern is found in the string
int numChecks = 0; // Number of comparisons the program made
int firstOccurance = 0; // The index of the first occurance of the string

int main()
{

  char text[10000];
  char pattern[200];
  int ASCII[128];
  int checks = 0;
  int m, n;

  printf("enter text : ");
  scanf("%s", text);
  printf("enter pattern you are searching for : ");
  scanf("%s", pattern);

  m = strlen(pattern);
  n = strlen(text);
  printf("The pattern has %d characters and the text has %d characters.\n", m, n);

  for (int i = 0; i < 128; ++i) // Init. ASCII Array with default values
    ASCII[i] = m;

  initializeASCIIarray(ASCII, pattern, m); // Initializes the ascii array with correct values based on pattern

  char p_ptr = pattern[m - 1];
  char t_ptr = text[m - 1];

  int value = smartSearch(ASCII, pattern, text, m, n);

  if (value == 0)
    printf("\n\nThe pattern did not appear in the text\n");
  else if (value == 1){
    printf("The pattern appears in the text %d time", value);
    printf("\nThe index of the first letter of the first occurance of the pattern is at text[%d]", firstOccurance);
  }
  else{
    printf("The pattern appears in the text %d times", value);
    printf("\nThe index of the first letter of the first occurance of the pattern is at text[%d]", firstOccurance);
  }

  if (numChecks == 1)
    printf("\nThe program made %d total comparison\n\n", numChecks);
  else
    printf("\nThe program made %d total comparison\n\n", numChecks);
}

int smartSearch(int ASCII[], char pattern[], char text[], int m, int n)
{
  int p_ptr = m - 1; // pattern pointer starts at m - 1, and stays there
  int t_ptr = m - 1; // text pointer starts at m - 1 and increments till >= n

  while (t_ptr <= n)
  {
    if (pattern[p_ptr] == text[t_ptr]) // If the first letter matches...
    {
      int check = search(pattern, text, p_ptr, t_ptr, m); // ...check the rest of the letters
      if (check == 1) // If the pattern occurs in the string, increment the number of times found
        ++timesFound;

      int temp = text[t_ptr];
      int increment = ASCII[temp];
      t_ptr += increment;
     //  t_ptr += 1;
    }
    else
    {
      int temp = text[t_ptr];
      int increment = ASCII[temp];

      t_ptr += increment;
    }
  }
  return timesFound;
}

int search(char pattern[], char text[], int p_ptr, int t_ptr, int m) // Function is called once two last letters of pattern and text are a match.
// Compare the rest of the strings. If it's a match, return 1. Otherwise, return -1. If it's the very first match, variable firstOccurance will be set to the index of the first occurance of the text
{
  int p = p_ptr;
  int t = t_ptr;
  for (int i = 0; i < m; ++i)
  {
    if (pattern[p] == text[t])
    ++numChecks;
    else{
      ++numChecks;
      return -1;
    }
    --p;
    --t;
  }
  if (timesFound == 0)
    firstOccurance = t + 1;

  return 1;
}

void initializeASCIIarray(int ASCII[], char pattern[], int m) // Updates ASCII array with correct values
{
  int var = pattern[m - 1];
  ASCII[var] = m;

  int j = m - 1;
  for (int i = 0; i < m - 1; ++i)
  {
    int var = pattern[i];
    ASCII[var] = j;
    --j;
  }
}

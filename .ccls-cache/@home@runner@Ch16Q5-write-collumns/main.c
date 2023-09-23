// Program to print select collumns from a file to stdout

#include <stdio.h>
#include <stdbool.h>

int main(void) {

  int s, t;
  char in[64];
  FILE *input;
  
  // Get file name from terminal
  printf ("Enter name of file to copy from: ");
  scanf ("%63s", in);

  // Open file
  if ( (input = fopen (in, "r")) == NULL) {
    printf ("Can't open %s for reading\n", in);
    return 1;
  }

  // Get range from terminal
  printf ("Enter start collumn: ");
  scanf ("%d", &s);
  printf ("Enter end collumn: ");
  scanf ("%d", &t);

  // Process File
  while (true) {
    char temp[64], out[64];
    fgets (temp, 63, input);
    
    int i = 0;
    for (; i <= t - s; i++) {
      out [i] = temp [s + i];
    }
    out [i] = '\0';
    
    printf ("%s\n", out);
    
    if (feof(input))
      break;
  }

  printf ("Collumns have been printed to the terminal\n");
  
  return 0;
}
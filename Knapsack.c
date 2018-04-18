#include <stdlib.h>
#include <stdio.h>

// #define MAX_SIZE 1000

int main() {
  printf("Hell World\n");
  //
  int weights[10] = {0};
  int values[10] ={0};

  // load file from command line
  char *fileName = "./data/small1.txt";
  printf("Filename is %s\n", fileName);

  // int threshold = 100; // @TODO load from command line
  
  int num;
  FILE *fptr;

  if ((fptr = fopen(fileName, "r")) == NULL) {
    printf("ERROR OPENING FILE\n");
    exit(1);
  }

  int counter = 0;
  int index = -1; // Index starts at -1 because increments before use
  while(fscanf(fptr, "%d", &num) == 1) {
    int switchNum = counter % 3;
    switch(switchNum) {
      case 0:
        // discard
        index++;
        break;
      case 1:
        // store weight
        weights[index] = num;
        break;
      case 2:
        // store values;
        values[index] = num;
        break;
    }
    counter++;
  }
  fclose(fptr);
  printf("Values array contains\n");
  for (int i = 0; i < 10; i++) {
    printf("%d\n", values[i]);
  }
  printf("Weight array contains\n");
  for (int i = 0; i < 10; i++) {
    printf("%d\n", weights[i]);
  }
  return 0;
};

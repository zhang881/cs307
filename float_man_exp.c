#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLOAT_MAX 1.79769313486231570E+308
#define FLOAT_MIN -1.79769313486231570E+308

void convertToBinary(unsigned char num[], int temp[])
{
  unsigned char *c;
  int i;
  int j;
  int tempNum;

  c = num;

  for (i = 0; i < sizeof(float); i++)
  {
    tempNum = *c;

    for (j = 0; j < 8; j++)
    {
      temp[8 * i + 7 - j] = tempNum % 2;
      tempNum /= 2;
    }

    c++;
  }
}

void writeOutput(FILE *output, unsigned char temp[])
{
  int tempNum[32];
  int i;

  if (output == NULL)
  {
    return;
  }

  if (temp[0] == 255 && temp[1] == 255 && temp[2] == 255 && temp[3] == 255)
  {
    return;
  }

  convertToBinary(temp, tempNum);

  fprintf(output, "%d ", tempNum[0]);

  for (i = 1; i <= 8; i++)
  {
    fprintf(output, "%d", tempNum[i]);
  }

  fprintf(output, " ");

  for (i = 9; i <= 31; i++)
  {
    fprintf(output, "%d", tempNum[i]);
  }

  fprintf(output, "\n");
}

void getInput(char *inputName, char *outputName)
{
  unsigned char temp;
  unsigned char num[4];
  int i;
  FILE *input = NULL;
  FILE *output = NULL;

  input = fopen(inputName, "r");
  output = fopen(outputName, "w");

  if (input == NULL)
  {
    return;
  }

  while (feof(input) != 1)
  {

    for (i = 0; i < sizeof(float); i++)
    {
      fread(&num[sizeof(float) - i - 1], 1, 1, input);
    }

    writeOutput(output, num);

    for (i = 0; i < sizeof(float); i++)
    {
      num[i] = 255;
    }
  }

  fclose(input);
  fclose(output);
}

int main(int argc, char* argv[])
{
  char *inputName;
  char *outputName;

  if (argc <= 2)
  {
    return 0;
  }

  inputName = argv[1];
  outputName = argv[2];

  getInput(inputName, outputName);

  return 0;
}

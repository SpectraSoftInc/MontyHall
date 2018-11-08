// MontyHall.cpp : Defines the entry point for the console application.
//
// Playing with the Monty Hall Prolem (also equiv. to the Three Prisoner Problem.)
// On a game show, the grand prise is hidden behind one of 3 doors.  The player
// picks a door to open.  Before they do, the host opens one of the other two
// doors (one that is NOT the correct door), then asks the player if they want to
// stay with their original pick or swich to the other remaining door.
//
// Most people assume the 2 remaining doors have an equal chance.  However, switching
// at that point will win 2 out of 3 times where the original guess has 1 out of 3
// chances of being correct.
//
////////////

#include "stdafx.h"
#include "stdlib.h"
#include "time.h"
#include "conio.h"

  // prototypes
void Pause();
void MontyHallProblem();
void BertrandsBoxProblem();

  // constants
const int nCount = 300;

int main(int argc, char* argv[])
{
  srand(time(NULL));

  MontyHallProblem();
  Pause();
  BertrandsBoxProblem();

  return 0;
}

void MontyHallProblem()
{
  int nCar,
      nGuess,
      nRight = 0,
      nSecondRight = 0,
      i;

  printf("\nMonty Hall Problem:\n");

  for (i=0; i<nCount; i++)
  {
    nCar = rand() % 3;
    nGuess = rand() % 3;
    printf("Guess %u, was %u (%s)\n", nGuess, nCar, (nGuess == nCar) ? "Right" : "Wrong");
    if (nGuess == nCar)
      nRight++;
    else
      nSecondRight++;
  }

  printf("If no switch: %u of %u guesses were right: %u%%\n", nRight, nCount, (nRight * 100 / nCount));
  printf("If switch:    %u of %u guesses were right: %u%%\n", nSecondRight, nCount, (nSecondRight * 100 / nCount));
}

void BertrandsBoxProblem()
{
  int aBoxes[3] = {2, 0, 1};    // the # of coins (out of the 2 in each box) that are gold.
  int nBox,
      nFirstWasGold = 0,        // count
      nSecondWasGold = 0,       // count
      i;

  printf("\nBertrand's Box Problem:\n");

  for (i=0; i<nCount; i++)
  {
    nBox = rand() % 3;
    if ((aBoxes[nBox] == 2) ||
        ((aBoxes[nBox] == 1) && ((rand() % 2) == 0)))
    {
        // first coin pulled was gold
      nFirstWasGold++;
      printf("GOLD   : ");
      if (aBoxes[nBox] == 2)    // if this box had both gold, then the second will be gold as well.
      {
        nSecondWasGold++;
        printf("GOLD\n");
      }
      else
        printf("SILVER\n");
    }
    else
      printf("SILVER\n");
  }

  printf("\nResult: %u out of %u times (%u%%) gold was picked first.\n",
    nFirstWasGold, nCount, (nFirstWasGold * 100 / nCount));
  printf("Of those, %u (%u%%) were followed by another gold piece.\n",
    nSecondWasGold, (nSecondWasGold * 100 / nFirstWasGold));
}

void Pause()
{
  printf("\nPress a key to continue...");
  getch();
  printf("\n\n");
}

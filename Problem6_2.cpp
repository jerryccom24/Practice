#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
  const int SIZE = 20; //this is the number of rolls we will do
  int diceRolls[SIZE]; //integer array to store our rolls

  int indexOfLongestSequence = 0; //this will be the intital index of our longest sequence
  int longestSequenceCount = 1; //this will be the count of the LONGEST sequence

  srand(time(0)); //for generating random numbers


  //Fill Array With Dice Rolls  
  for(int i = 0; i < SIZE; i++)
    {
      diceRolls[i] = rand()%6 + 1; //assign a random number between 1 and 6
    }

  
  //Use nested loop to find the first occurence of the longest sequence of identical numbers
  for(int i = 0; i <SIZE;i++)
    {
      int currCount = 1;//the lowest current count of identical numbers in the sequence will always begin at 1

      //check the next values of the current index and increment if it matches 
      for(int j=i+1;j<SIZE;j++)
	{
	  //if the next indexs value does not equal the current index value then break from this for loop
	  if(diceRolls[j] != diceRolls[i])
	    {
	      break;
	    }
	  else//otherwise increment current count
	    {
	      currCount++;
	    }


	  //check to see if the current count is the longest
	  if(currCount > longestSequenceCount)
	    {
	      longestSequenceCount = currCount;//set the longest sequence count
	      indexOfLongestSequence = i;//mark the beginning index of the longest sequence
	    }

	}

    }
  
  cout<<endl;
  
  //display the outcome
  for(int i = 0; i < SIZE;i++)
    {
      //place opening parenthesis when time...
      if(i == indexOfLongestSequence)
	cout<<"( ";

      cout<<diceRolls[i]<<" ";

      //place closing parenthesis when time...
      if(i == indexOfLongestSequence + longestSequenceCount-1)
	cout<<") ";
    }

  return 0;
}


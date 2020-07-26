#include<iostream>
#include<cstdlib>
using namespace std;

//prototype the functions
void printArray(int ar[],int s);
int deleteArrayElement(int ar[], int size, int value);
void resetArray(int ar[]);



int main()
{
  srand(time(0));//for random number generation

  int currSize = 10;//constant array size  
  int numbers[10]={1,2,3,4,5,6,7,8,9,10};//our array with numbers 1-10 in order
  int permutationArray[currSize];//this array will hold the perumutations and will be of size 10
  int numberOfRuns = 0; //start at ZERO , and generate 1 permutation each RUN

  //GENERATE AND PRINT the 10 random permutation arrays
  while(numberOfRuns != 10)
    {
      
      for(int i = 0; i < 10;i++)
	{
	  int deletedElement;
	  int randomIndex = rand()%currSize;// pick random index of the second array
	  deletedElement = deleteArrayElement(numbers,currSize,randomIndex);//get deleted element from array 
	  permutationArray[i] = deletedElement;//add to permutation index
	  currSize--;//decrease current size of the "secondArray" which holds distinct values 1-10
	}  
      
      currSize = 10;//reset current size
      cout<<endl;
      cout<<"Permutation #"<< numberOfRuns+1 <<": ";
      printArray(permutationArray,10); //print the permutation
      resetArray(numbers);//reset the "second array" 1-10
      numberOfRuns++;//increment number of runs (permutations generated)
    }

  return 0;
}

//reset 1-10 array
void resetArray(int ar[])
{
  for(int i = 0;i <10;i++)
    ar[i] = i+1;
}

//delete the element from array and shift over all subsequent elements
int deleteArrayElement(int ar[], int size, int index)
{  
  int deletedValue = ar[index];
 
  //Decrease size of array and Shift elements over
  size = size - 1; // decrement size of array
  for(int i = index; i < size; i++)
    ar[i] = ar[i+1];//shift all elements over

  return deletedValue;//returns the value removed from the array
}


//for printing the permutations
void printArray(int ar[],int s)
{

  cout<<"[ ";
  for(int i = 0; i < s; i++)
    {
      cout<<ar[i];
    }
  cout<<" ]";
  cout<<endl;
}

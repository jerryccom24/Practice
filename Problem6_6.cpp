#include<iostream>
#include<iomanip>
using namespace std;

void print(int ar[4][4]);
bool isMagicSquare(int ar[4][4]);

int main()
{
  int matrix[4][4];//our 4x4 matrix
  
  cout<<endl;
  //read in the matrix
  for(int i = 0;i<4;i++)
    {
      for(int j = 0;j<4;j++)
	{
	  cout<<"Enter Value For Row:["<<i+1<<"] Column:["<<j+1<<"]  >>";
	  cin>>matrix[i][j];
	}
    }

  cout<<endl<<endl;

  if(isMagicSquare(matrix))
    {
      cout<<"Congratulations! The Matrix below IS a Magic Square:"<<endl;
      print(matrix);
    }
  else{
    cout<<"Oops! The Matrix below is NOT a Magic Square:"<<endl;
      print(matrix);
  }


  return 0;
}



//FUNCTION WILL CHECK IF THE SQUARE IS a MAGIC SQUARE
bool isMagicSquare(int ar[4][4])
{
  int magicNumber=0;
  
  //gets the SUM of the TOP ROW. This will 
  for(int i = 0,j=3;j>=0;j--)
    {
      magicNumber+=ar[i][j];
    }

  
  //CHECK THAT ALL OF THE ROWS ARE EQUAL and RETURN FALSE if they are not
  for(int i = 1;i<4;i++)
    {
      int rowSum = 0;
      for(int j = 0;j<4;j++)
	{
	  rowSum+= ar[i][j];
	}
     
      if(rowSum != magicNumber)
	return false;

      rowSum = 0;//reset for each row
    }

  //CHECK THAT ALL THE COLUMNS ARE EQUAL and RETURN FALSE if they are not
  for(int r = 0;r<4;r++)
    {
      int columnSum = 0;
      for(int c=0;c<4;c++)
	{
	  columnSum +=ar[c][r];
	}

      if(columnSum!= magicNumber)
	return false;

      columnSum = 0;
    }

  //CHECK THAT DIAGONALS ARE EQUAL and RETURN FALSE if they are not
  int firstDiagonalSum=0;
  int secondDiagonalSum=0;

  for(int i = 0; i < 4; i++)
    { 
      for(int j = 0;j<4;j++)
	{
	  if(i==j)
	    {
	      firstDiagonalSum += ar[i][j];
	    }

	  if((i+j) == (4-1))
	    {
	      secondDiagonalSum +=ar[i][j];
	    } 
	}
    }
  //check if they are equal to the magic number and if they do, return FALSE
  if(firstDiagonalSum != magicNumber || secondDiagonalSum != magicNumber)
    return false;


  return true; //if has not returned false at some point then, all condititons have passed and it is a magic square...return true
}




//Function to print the matrix
void print(int ar[4][4])
{
  for(int i = 0;i<4;i++)
    {
      for(int j = 0;j<4;j++)
        cout<<fixed<<right<<setw(5)<<ar[i][j];

      cout<<endl;

    }
}

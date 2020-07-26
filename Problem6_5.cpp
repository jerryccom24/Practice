#include<iostream>
#include<vector>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;

//prototypes
void print(vector<int> vec);
vector<int> solve(vector<int> vec);
bool gameIsOver(vector<int> vec);

int main()
{

  int deckSize = 45;//We will always start with 45 cards
  vector<int> vec; //our vector which will hold our "piles of cards"
  srand(time(0));//for random number generation

  //while the decksize is not equal to ZERO insert random pile size
  //after this loop we will have a vector with some amount of randomly sized piles
  while(deckSize != 0)
    {
      int pileSize = rand()%deckSize+1;
      deckSize = deckSize - pileSize;
      vec.push_back(pileSize);
    }



  bool GameOver = false;//game is initially not over

  //exit loop when GameOver == false
  while(!GameOver) 
    {      
      vec = solve(vec);//solve 1 move
      print(vec);//print outcome
      GameOver = gameIsOver(vec);//check if game over
    }


  return 0;
}


//will return true if it reaches its final order of (10,9,8,7,6,5,4,3,2,1) Otherwise the game is not over yet
bool gameIsOver(vector<int> vec)
{
  for(int i = 0,k=10; i<vec.size();i++,k--)
    {
      if(vec[i] != k)
	return false;
     
    }
  return true;
}

//print vector
void print(vector<int> vec)
{
  cout<<endl;
  for(int i = 0; i < vec.size();i++)
    {
      cout<<vec[i]<<" ";
    }
  cout<<endl;
}


//returns the new vector after doing 1 solve move
vector<int> solve(vector<int> vec)
{
  int initialSize = vec.size();

  //subtract 1 from all spots
  for(int i = 0; i < vec.size(); i++)
    {
      vec[i] = vec[i] - 1;

      if(vec[i] == 0)
	vec.erase(vec.begin()+i);

    }
  
  vec.push_back(initialSize);//add the sum of taking 1 from all to the vector
  
  sort(vec.begin(),vec.end(),greater<int>());//sort the vector in descending order after each "solve" 

  return vec;//return our new vector

}

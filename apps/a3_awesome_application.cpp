#include <iostream>
#include "MGY.hpp"
// blood bank that provides our app. with information about people who donates (1) or need blood (0)
// every day as a string ,then we check each character in it, when 1 we enqueue and when 0
// we dequeue,and we count each time we enqueue or dequeue and the difference is the no. of blood 
//bages remained.
// done by rania & amr & gamila

int main( )
{
  int k = 0;
  int j = 0;
  char dailyData [100]; //we will save the user's i/p in this array.

  queue::CharQueue bloodBank; 
  std::cin >> dailyData;
  for ( int i = 0 ; i < 100 ; ++i )
  { 
    if (dailyData [i] == '+' )
    { 
      queue::enqueue (bloodBank , 'B');
      ++k;
    }
    else if (dailyData [i] == '-' )
    { 
      queue::dequeue (bloodBank);
      ++j;
    } 
  }
  std::cout<< "The Number of blood donors = " << k  << std::endl;
  std::cout<< "The Number of blood receivers = " << j << std::endl;
  std::cout<< "The Number of Blood Bags remained is = " << k - j << std::endl;
  return 0;

}

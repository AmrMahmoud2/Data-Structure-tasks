#include <iostream>
#include <string>
#include "MGY.hpp"

bool Pair(char open , char close);
bool Balanced(std::string exp);

int main( )
{
    std::string word ; 
    std::cin >> word ;
	if (Balanced(word))
    std::cout << "Balanced";
	else 
    std::cout << "Not balanced";

    return 0 ;
}

bool Pair(char open , char close)
   
	{
        if (open == '(' && close == ')') 
        return true ;
        else 
        return false ;
    }

bool Balanced(std::string exp) 
{
	stack::CharStack brackets;
	for (int i = 0; i < exp.length(); i++)
    {
		if (exp[i] == '(')
			stack::push( brackets , exp[i] );
		
        else if (exp[i] == ')')
        {
			if (stack::isEmpty( brackets )) 
            return false;
			
            else if ( Pair(stack::front( brackets ), exp[i] == false))
            return false;
			stack::pop( brackets );
		}
	}
	if (stack::isEmpty( brackets )) 
    return true;
	else 
    return false;
}    

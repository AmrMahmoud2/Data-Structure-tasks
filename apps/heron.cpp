#include "mathematics.hpp" // for mathematics::heron
#include <iostream> // for std::cout
//#include <algorithm> // for std::atof //this is not working i used <cstdlib> istead.
#include <string>
#include <cstdlib>

int main( int argc , char **argv )
{
    double a = 0, b = 0, c = 0;

    if( argc != 4 )
    {
        std::cout << "Incorrect usage!" << std::endl;
        return 1;
    }
    else
    {
        a = std::atof( argv[1] );
        b = std::atof( argv[2] );
        c = std::atof( argv[3] );
    }
    std::cout << mathematics::heron( a , b , c ) << std::endl;
    return 0;
}
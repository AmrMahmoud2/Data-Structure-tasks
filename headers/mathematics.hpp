#ifndef MATHEMATICS_HPP
#define MATHEMATICS_HPP

#include <cmath> // for std::sqrt

namespace mathematics
{

    double calculation( double a , double b , char operation )
    {
        switch(operation)
        {
            case '*' :
            {
                return a*b;
            }
            break;
            case '/' :
            {
                return a/b;
            }
            break;
            case '+' :
            {
                return a+b;
            }
            break;
            case '-' :
            {
                return a-b;
            }
            break;
            default:
            {
                return 0;
            }
        }
    }

    double heron( double a , double b , double c )
    {
        double s = ( a + b + c )/2; //s is the semiperimeter of the triangle.
        double area = sqrt ( s * (s-a) * (s-b) * (s-c) );
        return area;
    }
    double pow2( double deviation )
    {
        return deviation*deviation;
    }

}

#endif // MATHEMATICS_HPP

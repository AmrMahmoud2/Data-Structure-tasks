#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <iostream>
#include "mathematics.hpp"
namespace arrays
{
    void printAll( double *base , int arraySize )
    {
        for(int i = 0; i < arraySize; ++i)
        {
            std::cout<<base[i]<<std::endl;
        }
    }


    double maxArray( double *base, int arraySize )
    {   
        double max = 0;
        for(int i = 0; i < arraySize; ++i)
        {
            if ( max < base[i] )
            {
                max = base [i];
            }
        }
        return max;
    }

    double minArray( double *base, int arraySize )
    {
        double min = 0;
        for(int i = 0; i < arraySize; ++i)
        {
            if ( min > base[i] )
            {
                min = base [i];
            }
        }
        return min;
    }


    double meanArray( double *base , int arraySize )
    {
        double sum = 0;
        for(int i = 0; i < arraySize; ++i)
        {
            
            sum = sum + base [i];
        }
        return (sum/arraySize);
    }


    double varianceArray( double *base, int arraySize )
    {
        double var = 0, sum = 0;
        double n = meanArray( &base[0] , arraySize );
        for(int i = 0; i < arraySize; ++i)
        {
            double deviation = n - base[i];
            sum = sum + mathematics::pow2 (deviation);
            var = sum / arraySize;
        }
        return var;
    }


    struct DoubleArray
    {
        double *base;
        int size;
    };


    struct CharacterArray
    {
        double *base;
        int size;
    };


    void printAll( DoubleArray array )
    {
        for( int i = 0; i < array.size; ++i )
        {
            std::cout<<array.base[i]<<std::endl;
        }
    }


    double maxArray( DoubleArray array )
    {
        double max = 0;
        for( int i = 0; i < array.size; ++i )
        {
            if ( max < array.base[i] )
            {
                max = array.base[i];
            }
        }
        return max;
    }


    double minArray( DoubleArray array )
    {
        double min = 0;
        for( int i = 0; i < array.size; ++i )
        {
            if ( min > array.base[i] )
            {
                min = array.base [i];
            }
        }
        return min;
    }


    double meanArray( DoubleArray array )
    {
        double sum = 0;
        for(int i = 0; i < array.size; ++i)
        {
            
            sum += array.base [i];
        }
        return (sum/array.size);
        return arrays::meanArray( &array.base , array.size );
    }


    double varianceArray( DoubleArray array )
    {
        double var = 0, sum = 0;
        for(int i = 0; i < array.size; ++i)
        {
            double deviation = meanArray( array)- array.base[i];
            sum = sum + mathematics::pow2 (deviation);
            var = sum / array.size;
        }
        return var;
    }

}   

#endif // ARRAYS_HPP

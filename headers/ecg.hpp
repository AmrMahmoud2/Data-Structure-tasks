#ifndef ECG_HPP
#define ECG_HPP

#include "arrays.hpp"


namespace ecg
{
    void analyzeECG( double *base , int arraySize , double &mean, double &variance, double &max, double &min )
    {
        mean = arrays::meanArray ( &base[0] , arraySize );
        variance = arrays::varianceArray ( &base[0] , arraySize );
        max = arrays::maxArray ( &base[0] , arraySize );
        min = arrays::minArray ( &base[0] , arraySize );
    }

    
    struct Statistics
    {
        double mean = 0 ;
        double variance = 0 ;
        double min = 0;
        double max = 0;
    };


    using ECGArray = arrays::DoubleArray;

    Statistics analyzeECG( ECGArray ecg )
    {
        Statistics analysis;
        analysis.mean = arrays::meanArray ( ecg );
        analysis.variance = arrays::varianceArray ( ecg );
        analysis.max = arrays::maxArray ( ecg );
        analysis.min = arrays::minArray ( ecg );

        return analysis;
    }

}

#endif // ECG_HPP

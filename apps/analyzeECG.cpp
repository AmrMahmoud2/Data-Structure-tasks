#include "ecg.hpp" // for ecg::analyzeECG
#include "helpers.hpp" // for helpers::loadECG

int main( int argc , char **argv )
{
    if( argc != 2 )
    {
        std::cout << "Invalid usage!" << std::endl;
        return 1;
    }
    else
    {
        int size = 0;
        double *ecgArray = helpers::getECG( argv[1] , size );

        //for part 2
        ecg::ECGArray ecg {ecgArray,size};
        ecg::Statistics stats = ecg::analyzeECG(ecg);

        std::cout <<"ECG average : " << stats.mean << std::endl
                 << "ECG variance: " << stats.variance << std::endl
                 << "ECG range   : (" << stats.min << "," << stats.max << ")" << std::endl;

        //for part 1
        /*double average = 0, standardDev = 0, max = 0 , min = 0;
        ecg::analyzeECG( &ecgArray[0] , size , average , standardDev , max , min );

        std::cout <<"ECG average : " << average << std::endl
                 << "ECG variance: " << standardDev << std::endl
                 << "ECG range   : (" << min << "," << max << ")" << std::endl;*/

        delete [] ecgArray;
        return 0;
    }
}

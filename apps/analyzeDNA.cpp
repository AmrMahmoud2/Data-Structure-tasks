#include "helpers.hpp" // for helpers::loadDNA
#include "dna.hpp" // for dna::analyzeDNA


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
        char *dnaArray1 = helpers::getDNA( argv[1] , 0 , size );


        int counterA = 0, counterC = 0, counterG = 0 , counterT = 0;

        char *complementarySeq = dna::analyzeDNA( &dnaArray1[0] , size , counterA , counterC , counterG , counterT );

        // We may need to make a new character array, but with a null terminated character to be able to print on screen.
        char *complementarySeqTerminated = new char[ size + 1 ];
        std::copy( &complementarySeq[0] , &complementarySeq[size - 1] , &complementarySeqTerminated[0] );
        complementarySeqTerminated[ size ] = '\0';

        std::cout <<"Adenine (A) content:" << counterA << std::endl
                 << "Guanine (G) content:" << counterG << std::endl
                 << "Cytocine(C) content:" << counterC << std::endl
                 << "Thymine (T) content:" << counterT << std::endl << std::endl
                 << "Complementary Sequence:" << std::endl << complementarySeqTerminated << std::endl;

        // Clean up.
        delete [] complementarySeq;
        delete [] complementarySeqTerminated;
        return 0;
    }
}

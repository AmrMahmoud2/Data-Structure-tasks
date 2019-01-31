//
// Created by asem on 01/04/18.
// Modified by Amr

#include "set.hpp"
#include "helpers_trees.hpp"
#include <iostream>


int main( int argc, char **argv )
{
    if( argc == 3 )
    {
        std::vector< std::string > words = getFileWords( argv[1] );
        std::vector< std::string > txt = getFileWords( argv[2] );
        set::WordSet word_set1 = set::create();
        set::WordSet word_set2 = set::create();
        for( int i = 0 ; i < words.size() ; ++i )
        {
            std::string new_item = words[i];
            set::insert( word_set1 , new_item );
        }
        for( int i = 0 ; i < txt.size() ; ++i )
        {
            std::string new_item = txt[i];
            set::insert( word_set2 , new_item );
        }
        set::printAll( word_set1 );
        std::cout << set::size( word_set1 )<<std::endl;
        set::union_( word_set1 , word_set2 );
        set::intersect( word_set1 , word_set2 );
        set::equals( word_set1 , word_set2 );
    }
    return 0;
}

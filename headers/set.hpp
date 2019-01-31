//
// Created by asem on 01/04/18.
// Modified by Amr

#ifndef SBE201_WORDCOUNT_MAPS_SET_HPP
#define SBE201_WORDCOUNT_MAPS_SET_HPP

#include "bst.hpp"
#include <iostream>

namespace set
{

    using WordSet = bst::BSTNode*;


    WordSet create()
    {
        return nullptr;
    }

    bool isEmpty( set::WordSet &wset )
    {
        /*return wset == nullptr;*/
        bst::isEmpty( wset );
    }

    int size( set::WordSet &wset )
    {
        /*if( !isEmpty( wset ) )
        {
            return 1 + size( wset->left ) + size( wset->right );
        }
        else return 0;*/
        bst::size( wset );
    }

    bool contains( set::WordSet &wset , std::string item )
    {
        /*if( isEmpty( wset ) )
        {
            return false;
        }
        else
        {
            if( item == wset->item )
            {
                return true;
            }    
            else if( item < wset->item )
            {
                return contains( wset->left , item );
            }
            else
            {
                return contains( wset->right , item);
            }
        }*/    
        bst::find( wset , item );
        
    }   
    void remove( set::WordSet &wset , std::string to_remove )
    {
        /*if ( isEmpty( wset )) 
        {
            return ;
        }

        else if ( to_remove == wset->item )
        {
            if ( !isEmpty( wset->left ) && !isEmpty( wset->right ))
            {
                WordSet minRight = bst::minNode( wset->right );
                wset->item = minRight->item;
                remove( wset->right , minRight->item );
            } 
            else
            {
                WordSet discard = wset;

                if ( bst::isLeaf( wset ))
                {
                    wset = nullptr;
                }
                else if ( !isEmpty( wset->left ))
                {
                    wset = wset->left;
                }
                else
                {
                    wset = wset->right;
                }

                delete discard;
            }

        } 
        else if ( to_remove < wset->item )
        {
            remove( wset->left, to_remove );
        }
            
        else 
        {
            remove( wset->right, to_remove );
        }*/
        bst::remove( wset , to_remove );
    }

    void insert( set::WordSet &wset , std::string new_item )
    {
        if( ! bst::find( wset , new_item))
        {
            bst::insert( wset , new_item );
        }
            
    }

    void printAll( set::WordSet &wset )
    {
        if( wset )
        {
            printAll( wset->left );
            std::cout << wset->item << std::endl;
            printAll( wset->right );
        }
    }
    
    void populate( set::WordSet &setA , set::WordSet &setB )
    {
        populate( setA->left , setB );
        populate( setA->right , setB );
        set::insert( setB , setA->item );
    }
    set::WordSet union_( set::WordSet &set1 , set::WordSet &set2 )
    {
        WordSet set3;
        populate( set1 , set3 );
        populate( set2 , set3 );
        set::printAll( set3 );
    }

    set::WordSet intersect( set::WordSet &set1 , set::WordSet &set2 )
    {
        WordSet set3;
        for( int i = 0 ; i < set1->item.size() ; ++i )
        {
            if( set::contains( set2 , set1->item ))
            {
                set::insert( set3 , set1->item );
            }
            else 
            {
                return 0;
            }
            set::printAll( set3 );
        }
    }

    bool equals( set::WordSet &set1 , set::WordSet &set2 )
    {
       if( set::size( set1 ) == set::size( set2 ) )
       {
            int comparison = 0;
            while( comparison == 0 )
            {
                comparison = set1->item.compare( set2->item );
            }
            std::cout << "The two sets are equal" << std::endl;
       }    
       else
       {
           std::cout << "The two sets are not equal" << std::endl;
       }
    }
}
#endif //SBE201_WORDCOUNT_MAPS_SET_HPP

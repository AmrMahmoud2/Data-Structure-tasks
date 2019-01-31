//
// Created by asem on 01/04/18.
//

#ifndef SBE201_WORDCOUNT_MAPS_BST_HPP
#define SBE201_WORDCOUNT_MAPS_BST_HPP

#include <iostream>
#include <string>
#include <queue>

namespace bst
{

struct BSTNode
{
    std::string item;
    BSTNode* left;
    BSTNode* right;
};

using Tree = BSTNode * ;

Tree create()
{
    return nullptr ;
}

bool isEmpty( Tree node )
{
    return node == nullptr;
}

bool isLeaf( Tree node )
{
    return node->left == nullptr && node->right == nullptr;
}

int size( Tree node )
{
    if ( !isEmpty( node ))
        return 1 + size( node->left ) + size( node->right );
    else return 0;
}

Tree minNode( Tree tree )
{
    if ( tree->left )
        return minNode( tree->left );
    else
    {
        return tree;
    }
}

Tree maxNode( Tree tree )
{
   if ( tree->right )
        return maxNode( tree->right );
    else
    {
        return tree;
    }

}

bool find( Tree tree, std::string item )
{
    if ( isEmpty( tree ))
        return false;
    else
    {
        if ( item == tree->item )
            return true;

        else if ( item < tree->item )
            return find( tree->left , item );

        else return find( tree->right , item );
    }
}

void insert( Tree &tree, std::string item )
{
    if ( isEmpty( tree ))
        tree = new BSTNode{ item , nullptr , nullptr };

    else
    {
        if ( item < tree->item )
            insert( tree->left, item );

        else insert( tree->right, item );
    }
}



void remove( Tree &tree, std::string item )
{
        if ( isEmpty( tree )) return;

    if ( item == tree->item )
    {
        if ( !isEmpty( tree->left ) && !isEmpty( tree->right ))
        {
            Tree minRight = minNode( tree->right );
            tree->item = minRight->item;
            remove( tree->right, minRight->item );
        } else
        {
            Tree discard = tree;

            if ( isLeaf( tree ))
                tree = nullptr;
            else if ( !isEmpty( tree->left ))
                tree = tree->left;
            else
                tree = tree->right;

            delete discard;
        }

    } else if ( item < tree->item )
        remove( tree->left, item );
    else remove( tree->right, item );
}




void clear( Tree &tree )
{
       if ( !isEmpty( tree ))
    {
        clear( tree->left );
        clear( tree->right );
        delete tree;
        tree = nullptr;
    }
}

void preorder( Tree tree )
{
     if( tree )
    {
        std::cout << "[" << tree->item << "]";
        preorder( tree->left );
        preorder( tree->right );
    }
}

void inorder( Tree tree )
{
    if( tree )
    {
        inorder( tree->left );
        std::cout << "[" << tree->item << "]";
        inorder( tree->right );
    }
}

void postorder( Tree tree )
{
     if( tree )
    {
        postorder( tree->left );
        postorder( tree->right );
        std::cout << "[" << tree->item << "]";
    }
}

void breadthFirst( Tree tree )
{

}

}


#endif //SBE201_WORDCOUNT_MAPS_BST_HPP_HPP

// EECS560_Lab1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"

int getChoice();
void menuLoop( BinarySearchTree& bst );
void insertItem( BinarySearchTree& bst );
void deleteItem( BinarySearchTree& bst );
void deletemin( BinarySearchTree& bst );
void deletemax( BinarySearchTree& bst );
void printPreorder( BinarySearchTree& bst );
void printInOrder( BinarySearchTree& bst );
void printLevelOrder( BinarySearchTree& bst );

int main()
{
    int anInteger;
    std::ifstream fileReader( "data.txt" );


    if( fileReader.is_open() )
    {
        BinarySearchTree bst;

        while( fileReader >> anInteger )
        {
            bst.insert( anInteger );
        }

        menuLoop( bst );
        fileReader.close();
    }
    else
    {
        std::cout << "Error reading file\n";
    }

    return 0;
}

void menuLoop( BinarySearchTree& bst )
{
    int choice = 0;

    while( choice != 8 )
    {
        choice = getChoice();

        switch( choice )
        {
        case 1:
            insertItem( bst );
            break;
        case 2:
            deleteItem( bst );
            break;
        case 3:
            deletemin( bst );
            break;
        case 4:
            deletemax( bst );
            break;
        case 5:
            printPreorder( bst );
            break;
        case 6:
            printInOrder( bst );
            break;
        case 7:
            printLevelOrder( bst );
            break;
        default:
            if( choice != 8 )
            {
                std::cout << "Enter a valid choice (1-5)\n";
            }
            break;
        }
    }
}

int getChoice()
{
    int choice = 0;

    std::cout << "..........................................................\n";
    std::cout << "Please choose one of the folowing commands:\n";
    std::cout << "1 - insert\n"
        << "2 - remove\n"
        << "3 - deletemin\n"
        << "4 - deletemax\n"
        << "5 - preorder\n"
        << "6 - inorder\n"
        << "7 - levelorder\n"
        << "8 - exit\n"
        << "\n";

    std::cin >> choice;

    return choice;
}

void insertItem( BinarySearchTree& bst )
{
    std::cout << "Choose a number to be added to the tree\n";
    int number;
    std::cin >> number;
    if( !bst.insert( number ) )
    {
        std::cout << "Error, could not add " << number << ", value is already in the tree.\n";
    }
}

void deleteItem( BinarySearchTree& bst )
{
    std::cout << "Choose a number to be removed from the tree\n";
    int number;
    std::cin >> number;
    if( !bst.remove( number ) )
    {
        std::cout << "Error, cannot delete " << number << ", value is not in the tree.\n";
    }
}

void deletemin( BinarySearchTree& bst )
{
    if( !bst.deletemin() )
    {
        std::cout << "The tree is empty\n";
    }
}

void deletemax( BinarySearchTree& bst )
{
    if( !bst.deletemax() )
    {
        std::cout << "The tree is empty\n";
    }
}

void printPreorder( BinarySearchTree& bst )
{
    bst.preorder();
    std::cout << std::endl;
}

void printInOrder( BinarySearchTree& bst )
{
    bst.inorder();
    std::cout << std::endl;
}

void printLevelOrder( BinarySearchTree& bst )
{
    bst.levelorder();
    std::cout << std::endl;
}
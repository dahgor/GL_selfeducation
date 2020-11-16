//                 Created by Denys Horban
//
//               Task #3 for Linux knowledge
//
//  Create program which count and print file names is some folder. 
//  Name of folder should be received as command line argument.
//  Program should start two threads. The first one should only calculate element,
//  the second one should print full path of element.

#include <iostream>
#include <pthread.h>
#include <dirent.h>



int main(int argc, char** argv)
{
    //  Validating command line arguments
    if (argc != 2)
    {
        std::cout << "Entered wrong arguments:\n"
                << "BrowseDir [directory name to browse]\n";
        exit(EXIT_FAILURE);
    }
    
    //  Creating pointer to dir object
    DIR* dir_ptr;

    //  Assigning directory to dir object pointer
    //  if failed -> printing message and exiting program
    if (!(dir_ptr = opendir(argv[1])))
    {
        std::cout << "Cannot open directory\n";
        exit(EXIT_FAILURE);
    }

    return 0;
}
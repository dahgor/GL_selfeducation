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

//  If create_pthread method failed it exits program
void ExitIfFailed(int operation);

//  Counts files in given directory
void* CountFiles(void* directory);

//  Prints out filenames in given directory
void* PrintFilenames(void* directory);

int main(int argc, char** argv)
{
    //  Validating command line arguments
    if (argc != 2)
    {
        std::cout << "Entered wrong arguments:\n"
                << "BrowseDir [directory name to browse]\n";
        exit(EXIT_FAILURE);
    }

    //  Checking if it's possible to open directory with given name
    if (!(opendir(argv[1])))
    {
        std::cout << "Cannot open directory\n";
        exit(EXIT_FAILURE);
    }

    //  Threads for counting and printing names
    pthread_t counter;
    pthread_t printer;

    //  Creating threads
    ExitIfFailed(pthread_create(&counter, NULL, CountFiles, (void*) argv[1]));
    ExitIfFailed(pthread_create(&printer, NULL, PrintFilenames, (void*) argv[1]));

    //  Waiting for threads to finish execution
     pthread_join(counter, NULL);
     pthread_join(printer, NULL);

    return 0;
}

void ExitIfFailed(int operation)
{
    if (operation)
    {
        std::cout << "Error - pthread_create() return code: " << operation << std::endl;
        exit(EXIT_FAILURE);
    }
}

void* CountFiles(void* directory)
{
    // Initializes DIR with pointer to opened directory
    DIR* dir_ptr = opendir(static_cast<const char*>(directory));

    struct dirent* dirent_ptr;
    int counter = 0;

    while (dirent_ptr = readdir(dir_ptr))
    {
        //  Skips other directories
        if (dirent_ptr->d_type == DT_DIR )
        {
            continue;
        }
        
        ++counter;
    }

    //  Prints result
    std::cout << "Total number of files: " << counter << std::endl;

    pthread_exit(0);
}

void* PrintFilenames(void* directory)
{
    // Initializes DIR with pointer to opened directory
    DIR* dir_ptr = opendir(static_cast<const char*>(directory));
    struct dirent* dirent_ptr;

    //  Iteration through all items in directory
    while (dirent_ptr = readdir(dir_ptr))
    {
        //  Skips other directories
        if (dirent_ptr->d_type == DT_DIR )
        {
            continue;
        }
        
        //  Prints file names
        std::cout << dirent_ptr->d_name << std::endl;
    }
    pthread_exit(0);
}
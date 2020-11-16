//                 Created by Denys Horban
//
//               Task #3 for Linux knowledge
//
//  Create program which count and print file names is some folder. 
//  Name of folder should be received as command line argument.
//  Program should start two threads. The first one should only calculate element,
//  the second one should print full path of element.
//
//  Process devided into 2 threads. It's guaranteed that:
//  1.Output stream won't be mixed by random threads' output
//  2.Firstly, the counter thread prints result

#include <iostream>
#include <pthread.h>
#include <dirent.h>
#include <unistd.h>
#include <vector>

//  If create_pthread method failed it exits program
void ExitIfFailed(int operation);

//  Counts files in given directory
void* CountFiles(void* directory);

//  Prints out filenames in given directory
void* PrintFilenames(void* directory);

// Mutex to synchronize access to output steam
pthread_mutex_t out_stream = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char** argv)
{
    //  Validating command line arguments
    if (argc != 2)
    {
        std::cout << "Entered wrong arguments:\n"
                << "BrowseDir [directory name to browse]\n";
        exit(EXIT_FAILURE);
    }

    //  Checking if it's possible to open directory
    //  argv[1] is directory name
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
    //  Occupy output stream by this thread
    pthread_mutex_lock(&out_stream);

    // Initializes DIR with pointer to opened directory
    DIR* dir_ptr = opendir(static_cast<const char*>(directory));

    struct dirent* dirent_ptr;
    int counter = 0;

    // Iteration through all items in directory
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
    std::cout << "----------------------------\n";
    std::cout << "Total number of files: " << counter << std::endl;
    std::cout << "----------------------------\n";

    //  Free output stream
    pthread_mutex_unlock(&out_stream);

    pthread_exit(0);
}

void* PrintFilenames(void* directory)
{
    // Initializes DIR with pointer to opened directory
    DIR* dir_ptr = opendir(static_cast<const char*>(directory));
    struct dirent* dirent_ptr;

    // Getting current directory full path
    char* current_dir_path = get_current_dir_name();

    //  Storage for filenames
    //  used to minimize waiting time
    std::vector<std::string> filenames;

    //  Iteration through all items in directory
    while (dirent_ptr = readdir(dir_ptr))
    {
        //  Skips other directories
        if (dirent_ptr->d_type == DT_DIR )
        {
            continue;
        }
        
        //  Adding filenames to storage
        filenames.push_back(static_cast<std::string>(current_dir_path) + "/" + static_cast<char*>(directory) + "/" + dirent_ptr->d_name);
    }
    //  Occupy output stream by this thread
    pthread_mutex_lock(&out_stream);

    //  Prints out filenames
    for (std::string name : filenames)
        std::cout << name << std::endl;
    
    //  Free output stream
    pthread_mutex_unlock(&out_stream);

    pthread_exit(0);
}
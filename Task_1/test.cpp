#include <iostream>
#include <cstring>
#include "stack.hpp"

using std::cout;
using std::cin;
using std::endl;

//  Clears input buffer till '\n' occurs
void ClearInputBuffer();
//  Prints a line of '=' characters to show border
void ShowBorder();
//  Gets int in limits: (min_limit, max_limit)
void GetInputInt(int& number, const int& min_limit, const int& max_limit);
//  Prints menu and gets user's choice
void GetInputOperations(char& answer);

int main()
{
    cout << "Class Stack<int> test program\n";
    //  Getting int from user to create Stack
    int size;
    cout << "\nEnter the size for Stack(0, 100 000)\n";
    GetInputInt(size, 0, 100000);

    //  Creating Stack with given size
    Stack MyStack(size);
    ShowBorder();
    cout << "Stack created!\n";
    ShowBorder();

    //  Starting cycle to process user's input
    char answer;
    int item_to_add;
    do
    {
        //  Getting chosen operation
        GetInputOperations(answer);

        //  Processing chosen operation
        //  until quit is required
        switch (answer)
        {
        //  Stack.push(arg)
        case '1':
            ShowBorder();

            //  If there's free place in Stack pushes one more
            if (MyStack.capacity() < MyStack.size())
            {
                cout << "Integer to add(-100 000, 100 000)\n";
                GetInputInt(item_to_add, -100000, 100000);

                MyStack.push(item_to_add);
                cout << "Item added\n";
            }
            else
            {
                cout << "Stack is full\n";
            }
            
            ShowBorder();
            break;

        //  Stack.pop()
        case '2':
            ShowBorder();

            //  If Stack is not Empty pops one item
            if (MyStack.capacity() > 0)
            {
                cout << "Item from Stack:\n"
                    << MyStack.pop() << endl;
            }
            else
            {
                cout << "No data in Stack\n";
            }

            ShowBorder();
            break;

        //  Stack.resize(arg)
        case '3':
            ShowBorder();

            cout << "The new size for Stack(0, 100 000)\n";
            GetInputInt(size, 0, 100000);
            MyStack.resize(size);
            cout << "Stack resized\n";

            ShowBorder();
            break;

        //  Stack.capacity()
        case '4':
            ShowBorder();

            cout << "Capasity: "
                << MyStack.capacity() << endl;

            ShowBorder();
            break;

        //  Stack.size()
        case '5':
            ShowBorder();

            cout << "Size: "
                << MyStack.size() << endl;

            ShowBorder();
            break;

        //  quit
        case 'Q':
        case 'q':
            break;
        
        //  If program is unpredictable - stop it
        default:
            cout << "Unpredicted behaviour\n"
                << "Program terminated\n";
            break;
        }

    } while (!strchr("Qq", answer));
    
    cout << "Bye!\n";

    return 0;
}

void ClearInputBuffer()
{
    while (cin.get() != '\n') { continue; }
}

void ShowBorder()
{
    cout << "===========================================================\n";
}

void GetInputInt(int& number, const int& min_limit, const int& max_limit)
{
    do
    {
        cout << "Please, enter the correct argument: ";

        cin >> number;

        if (cin.fail())
        {
            cin.clear();
        }

        ClearInputBuffer();
    } while (!(number > min_limit && number < max_limit));
}

void GetInputOperations(char& answer)
{
    cout << "\nChoose operation:\n"
        << "1 : push\n"
        << "2 : pop\n"
        << "3 : resize\n"
        << "4 : capacity\n"
        << "5 : size\n"
        << "q : quit\n";
    do
    {
        cout << "Your choice: ";

        cin.get(answer);
        ClearInputBuffer();
        
    } while (!strchr("12345Qq", answer));
}
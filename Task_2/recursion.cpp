//              Created by Denys Horban
//			
//            Task #2 for language knowledge
//
//  Create recursive function which calculates sum 
//  of first n element of Fibonacci number.
//
//  It uses Combinatorial identity to calculate the sum:
//  Sum(N) = FibNum(N+2) - 1
//  where Sum(N) - sum of first N Fibonacci numbers
//        FibNum(N+2) - (N+2)th Fibonacci number
//
//  To find Nth Fibonacci number it calculates every 
//  Fibonacci number till needed N. It uses 2 previous
//  numbers(starting from {0, 1} by default) to calculate the next one, 
//  FibNum(n) = FibNum(n-1) + FibNum(n-2)

#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;

//  Calculates Nth Fibonacci number
//  Returning Nth Fibonacci number
//  Receiving (Needed Nth Fibonacci number, First number, Second number in Fibonacci sequence)
long long FibonacciNumbers(const int& N, const long long& n1, const long long& n2);

int main()
{
	cout << "Calculating the sum of first N elements of Fibonacci number\n";

	//  Defines first 2 items of Fibonacci numbers;
	//  there's also a version with {1, 1} beginning
	//  if you need it -> change it here
	const int initializers[2] = {0, 1};
	cout << "Fibonacci numbers beginning is set to " << initializers[0] << ", " << initializers[1] << ", ...\n\n";

	//  Getting input from user
	cout << "Enter number of elements to sum: ";
	int number_of_elements;
	cin >> number_of_elements;
    cout << endl;

	//  If input failed or is not valid -> repeats request
	while (cin.fail() ||
		   number_of_elements <= 0)
	{
		//  Recovers cin status and clears input buffer
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Please, enter valid argument: ";
		cin >> number_of_elements;
	}
	
	//  Calculating sum by method described at the top
	long long sum = FibonacciNumbers(number_of_elements + 2, initializers[0], initializers[1]) - 1;
	cout << "\nSum = " << sum << endl;

	return 0;
}

//  Generates Nth Fibonacci number
long long FibonacciNumbers(const int& N, const long long& n1, const long long& n2)
{	
	//  Recursion depth counter
	//  Starts from 2 because two numbers are already known {0, 1} or {1, 1}
	static int counter = 2;

	//  When all iterations done -> returns needed element;
	//  N is reduced by 1 each iteration to control recursion
	//  Value '2' is used to balance forward-shift caused by 2 already known initilial values
	if (N <= 2)
	{
		return n2;
	}
	//  If calculation of the next Fibonacci number can result in stack overflowing ->
	//  returns last generated Fibonacci number and prints message
	else if (n1 + n2 < 0)
	{
		cout << "Overflowing of stack prevented!\n"
			<< "Last sucessfully calculated element is " << counter << "-th Fibonacci number\n"
			<< "The sum will be calculated for " << counter - 2
			<< " Fibonacci numbers\n";
		return n2;
	}

	++counter;

	//  Calls itself with updated arguments
	FibonacciNumbers(N - 1, n2, n1 + n2);
}
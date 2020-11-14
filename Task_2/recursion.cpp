// 				Created by Denys Horban
//			
// 			Task #2 for language knowledge
//
//	Create recursive function which calculates sum 
//	of first n element of Fibonacci number.
//
//	Using Combinatorial identity to calculate the sum:
//	Sum(N) = Num(N+2) - 1
//	where Sum(N) - sum of first N elements
//		  Num(N+2) - (N+2)th Fibonacci number


#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;

//	Generates (N+2)th Fibonacci number
long long FibonacciNumbers(const int& N, const long long& n1, const long long& n2, int& counter)
{
	//	When all iterations done -> returns needed element;
	//	N is reduced by 1 each iteration to control recursion
	//	Using value 2 to balance forward-shift by 2 (caused by initilizers {0, 1})
	if (N == 2)
	{
		return n2;
	}
	//	If calculation of the next Fibonacci number can result in overflowing ->
	//	returns last generated Fibonacci number
	else if (n1+n2 < 0)
	{
		cout << "Overflow prevented\n"
			<< "Last calculated element #" << N << endl
			<< "The sum will be calculated for #" << N - 2
			<< "-th Fibonacci number\n";
		return n2;
	}

	//	Repeats algorithm with updated arguments
	FibonacciNumbers(N - 1, n2, (n1 + n2), ++counter);
}

int main()
{
	cout << "Calculating the sum of first N elements of Fibonacci number\n\n";
	cout << "Enter number of elements to sum: ";

	//	Getting input from user and validating it
	int number_of_elements;
	cin >> number_of_elements;

	//	If input failed or is not valid -> repeats request
	while (cin.fail() ||
		   number_of_elements <= 0)
	{
		//	Recovers cin status and clears input buffer
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Please, enter valid argument: ";
		cin >> number_of_elements;
	}
	int counter_fib = 0;
	// Calculating sum by method described at the top
	// Fibonacci numbers initialized by {0, 1} arguments
	long long sum = FibonacciNumbers(number_of_elements + 2, 0, 1, ++counter_fib) - 1;

	cout << "Sum = " << sum << endl;
	cout << "COUNTER = " << counter_fib << endl;
	return 0;
}
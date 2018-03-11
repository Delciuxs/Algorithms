#include<iostream>
#include<vector>
using namespace std;


/*
	Description:
	Dynamic programming is a method for resolving problems.
	We can identify a DP if the original problem can be break down into another subproblem and the union of those 
	return an answer for the original.
	The aforementioned can be solved recursively but, if we write down all the recursive steps, we will notice that
	sometimes we are computating the same subproblem more than once, which implicates a not efficient soluction, this can be avoid
	if we storage the solution for an already solved solution, so that, if we fall down in the same subproblem, we dont have to
	recompute it again, just return the storaged value.

	Example:
	Lets see an easy example for the fibonacci secuence.
	We know that the fibonacci(n) = fibonacci(n - 1) + fibonacci(n - 2)

	fibonacci of [0] [1] [2] [3] [4] [5]
	answer		  0	  1	  1   2   3   x

	so that the fibonacci(5) = fibonacci(4) + fibonacci(3) = 3 + 2 = 5 = x

	if we right down all the recusive steps we will see that the fibonacci(5) is

									      	 				 fibonacci(5)
						 	  fibonacci(4)	 						+			           fibonacci(3)
				fibonacci(3)        +	    fibonacci(2)			         fibonacci(2)       +	    fibonacci(1)	
		fibonacci(2) + fibonacci(1) fibonacci(1) + fibonacci(0)     fibonacci(1) + fibonacci(0) 
fibonacci(1) + fibonacci(0) 

	As we can see we are recomputing the same subproblem, for example fibonacci(2) is computed 3 times, so if we storage 
	the result, we just have to return the answer for that subproblem when necesary

	Lets see an implementaton for this problem using Dynamic Programing

*/

int fibonacci(int n, vector<int> &memory)
{
	//Base Case, is a state were we can know the answer for a certarin subproblem, with this we can obtain an answer to other subproblems
	if(n == 0)
		return 0;

	//Another case base
	else if(n <= 2)
		return 1;

	//If we havent compute the result for a certain subproblem we will look it up recursively and when already know, storage
	else if(memory[n] == 0)
		memory[n] = fibonacci(n - 1, memory) + fibonacci(n - 2, memory);
	
	//If the havent compute the answer we will find out in the previous else if and then we need to return the answer
	//if we didnt enter to the previus else if that means we have already know the answer, we just have to return it
	return memory[n];

	//With this implementation we changed de complexity from O(2^n) to O(n)
	
}

int main()
{
	int n;

	cin >> n;

	vector<int> memo(n + 10, 0);

	cout << fibonacci(n, memo) << endl;

	return 0;
}

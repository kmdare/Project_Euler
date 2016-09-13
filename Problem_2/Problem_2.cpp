// Problem 2 of Project Euler
#include <iostream>
#include <time.h>
#include <iomanip>
#include <ctime>

int f(int n)
{
	int output = 2;
	int fib_1 = 1;
	int fib_2 = 2;
	while (fib_1 + fib_2<n)
	{
		int temp = fib_1 + fib_2;
		fib_1 = fib_2;
		fib_2 = temp;
		if (fib_2 % 2 == 0)
		{
			output += fib_2;
		}
	}
	return output;
}

template<typename input_type, typename output_type>
double timer(output_type(*func) (input_type), input_type params, int N = 100000)
{
	std::clock_t c_start = std::clock();
	for (int i = 0; i < N; i++) func(params);
	std::clock_t c_end = std::clock();
	double total_time = 1.0*(c_end - c_start) / (CLOCKS_PER_SEC);
	return total_time;
}

int main(void) {
	// Solution
	int params = 4000000;
	std::cout << "The solution is " << f(params) << std::endl;

	// Timing information
	int N = 100000;
	double total_time = timer(f, 4000000, N = N);
	std::cout << std::fixed << std::setprecision(10) << "Total time used for " << N << " cycles: "
		<< total_time << "s\n";
	std::cout << std::fixed << std::setprecision(10) << "CPU time used: "
		<< total_time / N << "s\n";
	return 0;
}
// Problem 1 of Project Euler
#include <iostream>
#include <time.h>
#include <iomanip>
#include <ctime>

int f(int n)
{
	int output = 0;
	for (int i = 3; i<n; i += 1)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			output += i;
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
	std::cout << "The solution is " << f(1000) << std::endl;

	// Timing information
	int N = 100000;
	double total_time = timer(f,1000, N = N);
	std::cout << std::fixed << std::setprecision(10) << "Total time used for " << N << " cycles: "
		<< total_time << " s\n";
	std::cout << std::fixed << std::setprecision(10) << "CPU time used: "
		<< total_time / N << " s\n";
	return 0;
}
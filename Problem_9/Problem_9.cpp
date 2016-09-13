// Problem 7 of Project Euler
#include <iostream>
#include <time.h>
#include <iomanip>
#include <ctime>

int f(int n) {
	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = 1; j <= n - i - 1; j++)
		{
			if (i*i+j*j==(n-i-j)*(n - i - j)) return i*j*(n-i-j);
		}
	}
	return 0;
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
	int params = 1000;
	std::cout << "The solution is " << f(params) << std::endl;

	// Timing information
	int N = 10000;
	double total_time = timer(f, params, N = N);
	std::cout << std::fixed << std::setprecision(10) << "Total time used for " << N << " cycles: "
		<< total_time << "s\n";
	std::cout << std::fixed << std::setprecision(10) << "CPU time used: "
		<< total_time / N << "s\n";
	return 0;
}
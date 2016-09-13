// Problem 6 of Project Euler
#include <iostream>
#include <time.h>
#include <iomanip>
#include <ctime>

#include <vector>
#include <algorithm>
#include <numeric>

int f(int n)
{
	std::vector<int> x(n);
	std::iota(std::begin(x), std::end(x), 1);

	int sum = 0;
	int sum_squares = 0;
	for (std::vector<int>::iterator it = x.begin(); it != x.end(); ++it)
	{
		sum += *it;
		sum_squares += *it**it;
	}
	int square_sum = sum*sum;
	int output = square_sum - sum_squares;
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
	int params = 100;
	std::cout << "The solution is " << f(params) << std::endl;

	// Timing information
	int N = 100000;
	double total_time = timer(f, params, N = N);
	std::cout << std::fixed << std::setprecision(10) << "Total time used for " << N << " cycles: "
		<< total_time << "s\n";
	std::cout << std::fixed << std::setprecision(10) << "CPU time used: "
		<< total_time / N << "s\n";
	return 0;
}
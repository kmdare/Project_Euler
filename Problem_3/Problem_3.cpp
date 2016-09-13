// Problem 3 of Project Euler
#include <iostream>
#include <time.h>
#include <iomanip>
#include <ctime>

long long int f(long long int input)
{
	long long int output = input;
	for (int i = 2; i <= input; i += 1)
	{
		int k = 0;
		while (input%i == 0)
		{
			k += 1;
			input /= i;
		}
		if (input == 1)
		{
			output = i;
			break;
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
	int params = 600851475143;
	std::cout << "The solution is " << f(600851475143) << std::endl;

	// Timing information
	int N = 100000;
	double total_time = timer(f, 600851475143, N = N);
	std::cout << std::fixed << std::setprecision(10) << "Total time used for " << N << " cycles: "
		<< total_time << "s\n";
	std::cout << std::fixed << std::setprecision(10) << "CPU time used: "
		<< total_time/N << "s\n";
	return 0;
}
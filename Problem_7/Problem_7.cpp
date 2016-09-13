// Problem 7 of Project Euler
#include <iostream>
#include <time.h>
#include <iomanip>
#include <ctime>

#include <vector>
#include <math.h>

bool is_prime(int input, std::vector<int> lower_primes)
{
	for (std::vector<int>::iterator it = lower_primes.begin(); it != lower_primes.end(); ++it)
	{
		if (*it > std::sqrt(input)) return true;
		if (input%*it == 0)
		{
			return false;
		}
	}
	return true;
}

int f(int n)
{
	std::vector<int> primes = { 2 };
	for (int i = 1; primes.size()<n; i++)
	{
		if (is_prime(2 * i + 1, primes))
		{
			primes.push_back(2 * i + 1);
		}
	}
	return primes.back();
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
	int params = 10001;
	std::cout << "The solution is " << f(params) << std::endl;

	// Timing information
	int N = 1;
	double total_time = timer(f, params, N = N);
	std::cout << std::fixed << std::setprecision(10) << "Total time used for " << N << " cycles: "
		<< total_time << "s\n";
	std::cout << std::fixed << std::setprecision(10) << "CPU time used: "
		<< total_time / N << "s\n";
	return 0;
}
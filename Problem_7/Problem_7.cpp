// Problem 7 of Project Euler
#include <iostream>
#include <time.h>
#include <iomanip>
#include <ctime>

#include <vector>
#include <math.h>

typedef unsigned int uint;

bool is_prime(uint input, std::vector<uint> primes)
{
	for (auto const& prime : primes)
	{
		if (prime > std::sqrt(input)) return true;
		if (input%prime == 0) return false;
	}
	return true;
}

uint f(uint n)
{
	std::vector<uint> primes = { 2 };
	primes.reserve(n);
	for (uint i = 1; primes.size()<n; i++)
	{
		if (is_prime(2 * i + 1, primes))
		{
			primes.push_back(2 * i + 1);
		}
	}
	return primes.back();
}

template<typename input_type, typename output_type>
double timer(output_type(*func) (input_type), input_type params, uint N = 100000)
{
	std::clock_t c_start = std::clock();
	for (uint i = 0; i < N; i++) func(params);
	std::clock_t c_end = std::clock();
	double total_time = 1.0*(c_end - c_start) / (CLOCKS_PER_SEC);
	return total_time;
}

int main(void) {
	// Solution
	uint params = 10001;
	std::cout << "The solution is " << f(params) << std::endl;

	// Timing information
	uint N = 10;
	double total_time = timer(f, params, N = N);
	std::cout << std::fixed << std::setprecision(10) << "Total time used for " << N << " cycles: "
		<< total_time << "s\n";
	std::cout << std::fixed << std::setprecision(10) << "CPU time used: "
		<< total_time / N << "s\n";
	return 0;
}
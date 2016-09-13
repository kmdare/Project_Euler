// Problem 5 of Project Euler
#include <iostream>
#include <time.h>
#include <iomanip>
#include <ctime>

#include <vector>
#include <set>
#include <algorithm>
std::vector<int> factorization(int input)
{
	std::vector<int> output = {};
	int factor = 2;
	while (factor*factor <= input)
	{
		while (input%factor == 0)
		{
			input /= factor;
			output.push_back(factor);
		}
		factor++;
	}
	if (input != 1)
	{
		output.push_back(input);
	}
	return output;
}

std::vector<int> unique(std::vector<int> input) {
	std::set<int> s;
	std::vector<int> output;
	unsigned size = input.size();
	for (unsigned i = 0; i < size; ++i) s.insert(input[i]);
	output.assign(s.begin(), s.end());
	return output;
}

int f(int n)
{
	std::vector<int> factors = factorization(n);
	for (int i = 19; i>1; i--)
	{
		std::vector<int> factors_i = factorization(i);
		std::vector<int> primes = unique(factors_i);
		for (std::vector<int>::iterator it = primes.begin(); it != primes.end(); ++it)
		{
			int factors_count = std::count(factors.begin(), factors.end(), *it);
			int factors_i_count = std::count(factors_i.begin(), factors_i.end(), *it);
			int diff = factors_i_count - factors_count; // Count how many times we need to add a given prime
			if (diff>0)
			{
				for (int j = 1; j <= diff; j++)
				{
					factors.push_back(*it);
				}
			}
		}
	}
	int product = 1;
	for (std::vector<int>::iterator it = factors.begin(); it != factors.end(); ++it)
	{
		product *= *it;
	}
	return product;
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
	int params = 20;
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
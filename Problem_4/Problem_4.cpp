// Problem 4 of Project Euler
#include <iostream>
#include <time.h>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <string>
#include <math.h>

bool is_palindrome(int input)
{
	int magnitude = std::floor(log10(input));
	int end_index = magnitude +1 - magnitude % 2;
	int a[10];
	for (int i = 0; i <=end_index; i++)
	{
		a[i] = input % 10;
		input /= 10;
	}
	for (int i = 0; i <= magnitude / 2; i++)
	{
		if (a[i] != a[end_index - i]) return false;
	}
	return true;
}

int f(int params[2])
{
	int lower_bound = params[0];
	int upper_bound = params[1];
	int output = 1;
	for (int i = upper_bound; i>lower_bound; i -= 1)
	{
		for (int j = i; j>lower_bound; j -= 1)
		{
			int product = i*j;
			if (is_palindrome(product) && (product>output))
			{
				output = product;
			}
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
	int params[2] = { 99,999 };
	std::cout << "The solution is " << f(params) << std::endl;

	// Timing information
	int N = 100;
	double total_time = timer(f, params, N = N);
	std::cout << std::fixed << std::setprecision(10) << "Total time used for " << N << " cycles: "
		<< total_time << "s\n";
	std::cout << std::fixed << std::setprecision(10) << "CPU time used: "
		<< total_time / N << "s\n";
	return 0;
}
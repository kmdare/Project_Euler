// Problem 7 of Project Euler
#include <iostream>
#include <time.h>
#include <iomanip>
#include <ctime>

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<int> read_numbers(std::string filename)
{
	std::vector<int> numbers;
	std::string line;
	std::ifstream myfile(filename);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::transform(std::begin(line), std::end(line), std::back_inserter(numbers), [](char c) {return c - '0'; });//This transforms the string to an int array
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
	
	return numbers;
}

long long f(int n) {
	long long prod;
	long long output = 0;
	std::vector<int> numbers = read_numbers("numbers.txt");
	if (n > numbers.size()) return 0;
	for (std::size_t i = 0; i != numbers.size()+1-n; i++)
	{
		prod = 1;
		for (int j = 0; j < n; j++) prod *= numbers[i + j];
		if (prod > output) output = prod;
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
	int params = 13;
	std::cout << "The solution is " << f(params) << std::endl;

	// Timing information
	int N = 1000;
	double total_time = timer(f, params, N = N);
	std::cout << std::fixed << std::setprecision(10) << "Total time used for " << N << " cycles: "
		<< total_time << "s\n";
	std::cout << std::fixed << std::setprecision(10) << "CPU time used: "
		<< total_time / N << "s\n";
	return 0;
}
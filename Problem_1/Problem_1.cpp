// Problem 1 of Project Euler
#include <iostream>
#include <time.h>
#include <iomanip>
#include <ctime>

int f()
{
	int output = 0;
	for (int i = 3; i<1000; i += 1)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			output += i;
		}
	}
	return output;
}

int main(void) {
	std::clock_t c_start = std::clock();
	std::cout << "The solution is " << f() << std::endl;
	std::clock_t c_end = std::clock();
	std::cout << std::fixed << std::setprecision(3) << "CPU time used: "
		<< 1.0*(c_end - c_start) / CLOCKS_PER_SEC << " s\n";
	return 0;
}
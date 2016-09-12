// Problem 2 of Project Euler
#include <iostream>
#include <time.h>
#include <iomanip>
#include <ctime>

int f()
{
	int output = 2;
	int fib_1 = 1;
	int fib_2 = 2;
	while (fib_1 + fib_2<4000000)
	{
		int temp = fib_1 + fib_2;
		fib_1 = fib_2;
		fib_2 = temp;
		if (fib_2 % 2 == 0)
		{
			output += fib_2;
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
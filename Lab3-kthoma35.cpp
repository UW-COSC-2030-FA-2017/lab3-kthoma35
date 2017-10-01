//lab3-kthoma35.cpp
//1 Oct. 2017

/*
1. (line 12)

2.Overflow occurs at n=256
	I am testing whether the result is greater than the previous result 
	for a smaller n. The sum should always be greater than both operands.

3.Long sum overflows at n=65536

4.Float factorial (line 40) Overflows at n=20 
	Testing that n! / n = (n-1)!
	Also in this case overflow results in value "inf"

5.Double factorial (line 54) Overflows at n=23

6.If this computation is exact it should equal 0 (when n > 1)
	n < 1 should return -1 (0 < n < 1 works)
	1.0 is exact. Larger values of n seem to be more accurate.

7.This segment is returning what I would expect
	(on my machine)

8. Changeing to doubles has no effect 
*/

#include <iostream>
using std::cout;
using std::endl;

short sum(short n)
{
	short sum(0);
	for (short i(1); i <= n; i++)
	{
		sum += i;
	}
	return sum;
}

long sum(long n)
{
	long sum(1);
	for (long i(1); i <= n; i++)
	{
		sum += i;
	}
	return sum;
}

float factorial(long n)
{
	float product(1);
	for (long i(1); i <= n; i++)
	{
		product *= i;
	}
	return product;
}

double dfactorial(long n)
{
	double product(1);
	for (long i(1); i <= n; i++)
	{
		product *= i;
	}
	return product;
}

float strangething(float n)
{
	float result(0);
	float ratio = 1 / n;
	for (int i(1); i <= n; i++)
	{
		result = result + ratio;
	}
	result -= 1.0;
	return result;
}

double strangething(double n)
{
	double result(0);
	double ratio = (1 / n);
	for (int i(1); i <= n; i++)
	{
		result = result + ratio;
	}
	result -= 1.0;
	return result;
}


int main()
{
	bool overflowed = false;
	short shortn = 250;
	long lastresult(0);
	while (!overflowed)
	{
		shortn++;
		short result = sum(shortn);
		if (result < lastresult)
		{
			overflowed = true;
		}
		else {
			lastresult = result;
		}
	}
	cout << "Short sum overflowed at " << shortn << endl;
	cout << "Computed " << lastresult << " before overflow"<< endl;

	overflowed = false;
	long longn = 60000;
	while (!overflowed)
	{
		longn++;
		long result = sum(longn);
		if (result < lastresult)
		{
			overflowed = true;
		}
		else {
			lastresult = result;
		}
	}
	cout << endl;
	cout << "Long sum overflowed at " << longn << endl;
	cout << "Computed " << lastresult << " before overflow" << endl;

	overflowed = false;
	longn = 1;
	float previous = factorial(longn);
	while (!overflowed)
	{
		longn++;
		float result = factorial(longn);
		if (result / longn != previous)
		{
			overflowed = true;
		}
		else {
			previous = result;
		}
	}
	cout << endl << "Float factorial overflowed at " << longn << endl;
	cout << "Computed " << previous << " before overflow" << endl;

	overflowed = false;
	longn = 20;
	double prevresult = dfactorial(longn);
	while (!overflowed)
	{
		longn++;
		double result = dfactorial(longn);
		if (result / longn != prevresult)
		{
			overflowed = true;
		}
		else {
			prevresult = result;
		}
	}
	cout << endl << "Double factorial overflowed at " << longn << endl;
	cout << "Computed " << prevresult << " before overflow" << endl;

	float floatn(11);
	cout << endl << strangething(floatn) << endl;
	floatn = 1.2;
	cout << endl << strangething(floatn) << endl;
	floatn = 3.457911;
	cout << endl << strangething(floatn) << endl;
	floatn = 1.0;
	cout << endl << strangething(floatn) << endl;
	floatn = 0;
	cout << endl << strangething(floatn) << endl;
	floatn = 0.000245;
	cout << endl << strangething(floatn) << endl;

	double doublen(53);
	cout << endl << strangething(doublen) << endl;
	doublen = 122.354;
	cout << endl << strangething(doublen) << endl;
	doublen = 1.223464757;
	cout << endl << strangething(doublen) << endl;
	doublen = 1.0;
	cout << endl << strangething(doublen) << endl;
	doublen = 0;
	cout << endl << strangething(doublen) << endl;
	doublen = 0.005768;
	cout << endl << strangething(doublen) << endl;

	cout << endl;
	for (float i = 3.4; i < 4.4; i += 0.2) {
		cout << "i = " << i << endl;
	}

	cout << endl;
	for (double i = 3.4; i < 4.4; i += 0.2) {
		cout << "i = " << i << endl;
	}

	return 0;
}
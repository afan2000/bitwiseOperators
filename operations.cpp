#include <iostream>


unsigned int addition(unsigned int x, unsigned int y)
{
	unsigned int carry;
	while (x != 0)
	{
		carry = (x&y) << 1;
		y = x^y;
		x = carry;
	}
	return y;
}

int subtraction(int x, int y)
{
	int carry;
	y = ~y + 1;
	while (x != 0)
	{
		carry = (x & y) << 1;
		y = x^y;
		x = carry;
	}
	return y;
}

unsigned int multiplication(unsigned int x, unsigned int y)
{
	unsigned int answer = x;
	while (y != 1)
	{
		answer = answer << 1;
		if ((y & 1) == 1)
		{
			answer = addition(x, answer);
		}
		y = y >> 1;
	}
	return answer;
}

unsigned int division(unsigned int x, unsigned int y)
{
	while (true)
	{
		int answer = 0;
		while (x != y)
		{
			int counter = 0;
			while ((y << 1) <= x)
			{
				y <<= 1;
				counter = addition(counter, 1);
			}
			answer = addition(answer, multiplication(counter, counter));
			if (x == y)
			{
				return answer;
			}
			x = subtraction(x, y);
			y >>= counter;
		}
		return addition(answer, 1);
	}
}

int main()
{
	int choice, x, y;
	std::cout << "1. Addition" << std::endl;
	std::cout << "2. Subtraction" << std::endl;
	std::cout << "3. Multiplication" << std::endl;
	std::cout << "4. Division" << std::endl;
	std::cout << "What operation are you wanting to pull off: ";
	std::cin >> choice;
	switch (choice)
	{
	case 1: std::cout << "Enter addend 1: ";
		std::cin >> x;
		std::cout << "Enter addend 2: ";
		std::cin >> y;
		std::cout << "answer: " << addition(x, y);
		return 0;
	case 2: std::cout << "Enter subtrahend: ";
		std::cin >> x;
		std::cout << "Enter minuend: ";
		std::cin >> y;
		std::cout << "answer: " << subtraction(x, y);
		return 0;
	case 3: std::cout << "Enter multiplicand: ";
		std::cin >> x;
		std::cout << "Enter	multiplier: ";
		std::cin >> y;
		std::cout << "answer: " << multiplication(x, y);
		return 0;
	case 4: std::cout << "Enter dvidend: ";
		std::cin >> x;	
		std::cout << "Enter divisor: ";
		std::cin >> y;
		std::cout << "answer: " << division(x, y);
		return 0;
	}
}

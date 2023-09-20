#include <stdio.h>

/**
 * multiply_or_divide - Checks two integer values and performs multiplication
 *                     if the result is positive, and division if negative.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The result of the operation.
 */

int multiply_or_divide(int a, int b)
{
	int result;

	if (a >= 0 && b >= 0)
		result = a * b;
	else if (a < 0 && b < 0)
		result = a / b;
	else
		result = a + b;

	return (result);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */

int main(void)
{
	int a, b, result;

	printf("Enter two integer values (a and b): ");
	scanf("%d %d", &a, &b);

	result = multiply_or_divide(a, b);

	printf("Result: %d\n", result);

	return (0);
}

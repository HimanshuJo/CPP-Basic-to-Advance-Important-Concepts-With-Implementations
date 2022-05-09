/*
Program For Stock Buy Sell To Maximize Profit

Algorithm:

Find the local minima and store it as starting index. If not exists, return.
Find the local maxima. and store it as an ending index. If we reach the end, set the end as the ending index.
Update the solution (Increment count of buy-sell pairs)
Repeat the above steps if the end is not reached.
*/

#include <stdio.h>

struct Interval
{
	int buy;
	int sell;
};

void stockBuySell(int price[], int n)
{
	if (n == 1)
		return;
	int count = 0;
	// Solution vector
	Interval sol[n / 2 + 1];
	int i = 0;
	while (i < n - 1)
	{
		// Find Local Minima. Note that the
		// limit is (n-2) as we are comparing
		// present element to the next element.
		while ((i < n - 1) && (price[i + 1] <= price[i]))
			i++;

		// If we reached the end, break as no
		// further solution possible
		if (i == n - 1)
			break;

		// Store the index of minima
		sol[count].buy = i++;

		// Find Local Maxima. Note that the
		// limit is (n-1) as we are comparing
		// to previous element
		while ((i < n) && (price[i] >= price[i - 1]))
			i++;

		// Store the index of maxima
		sol[count].sell = i - 1;

		// Increment count of buy/sell pairs
		count++;
	}
	if (count == 0)
		printf("There is no day when buying the stock will make profitn");
	else
	{
		for (int i = 0; i < count; i++)
			printf("Buy on day: %d\t Sell on day: %d\n", sol[i].buy, sol[i].sell);
	}
	return;
}

int main()
{
	// Stock prices on consecutive days
	int price[] = {100, 180, 260, 310, 40, 535, 695};
	int n = sizeof(price) / sizeof(price[0]);
	stockBuySell(price, n);
	return 0;
}
// C/C++ program to solve fractional Knapsack Problem
#include <bits/stdc++.h>

using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
class Item {
	public:
    int value, weight;

	// Constructor
	Item(int value, int weight)
	{
	this->value=value;
	this->weight=weight;
	}
};

// Comparison function to sort Item according to val/weight
// ratio
bool cmp(class Item a, class Item b)
{
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
void fractionalKnapsack(int W, struct Item arr[], int n)
{
	// sorting Item on basis of ratio
	sort(arr, arr + n, cmp);

	// Uncomment to see new order of Items with their
	// ratio
	/*
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].value << " " << arr[i].weight << " :
	"
			<< ((double)arr[i].value / arr[i].weight) <<
	endl;
	}
	*/

	int curWeight = 0; // Current weight in knapsack
	double finalvalue = 0.0; // Result (value in Knapsack)

	// Looping through all Items
	for (int i = 0; i < n; i++) {
		// If adding Item won't overflow, add it completely
		if (curWeight + arr[i].weight <= W) {
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
            cout<<"Item having weight "<<arr[i].weight<<"  is in the knapsack"<<endl;
		}

		// If we can't add current Item, add fractional part
		// of it
		else {
			int remain = W - curWeight;
			finalvalue += arr[i].value
						* ((double)remain
							/ (double)arr[i].weight);
            cout<<"Item having weight "<<arr[i].weight<<"  is in the knapsack"<<endl;
			break;
		}
	}
    cout << "Maximum value we can obtain = "
		<<finalvalue;
	// Returning final value
//	return finalvalue;
}

// Driver code
int main()
{
	int W = 50; // Weight of knapsack
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
    fractionalKnapsack(W, arr, n);
	
	return 0;
}

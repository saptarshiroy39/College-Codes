#include <iostream>

using namespace std;

// Structure to represent an item
struct Item
{
  int profit;
  int weight;
  float avg;
};

// Function to implement fractional knapsack
float fractionalKnapsack(int n, int W, int profit[], int weight[])
{
  // Create an array of items
  Item items[n];

  // Calculate the average profit-to-weight ratio (avg) for each item
  for (int i = 0; i < n; i++)
  {
    items[i].profit = profit[i];
    items[i].weight = weight[i];
    items[i].avg = (float)profit[i] / weight[i];
  }

  // Sorting items in decreasing order of avg (profit/weight ratio)
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (items[i].avg < items[j].avg)
      {
        // Swap the items
        Item temp = items[i];
        items[i] = items[j];
        items[j] = temp;
      }
    }
  }

  // Initialize variables
  int curWeight = W;
  float totalProfit = 0.0;

  // Process the items
  for (int i = 0; i < n && curWeight > 0; i++)
  {
    // If the weight of the current item is less than or equal to the remaining weight
    if (items[i].weight <= curWeight)
    {
      curWeight -= items[i].weight;   // Deduct item weight from curWeight
      totalProfit += items[i].profit; // Add item profit to totalProfit
    }
    else
    {
      // Take the fractional part of the item
      totalProfit += items[i].profit * ((float)curWeight / items[i].weight);
      curWeight = 0; // The knapsack is full
    }
  }

  return totalProfit;
}

int main()
{
  int n, W;

  cout << "Enter number of items: ";
  cin >> n;
  cout << "Enter capacity of the knapsack: ";
  cin >> W;

  int profit[n], weight[n];

  cout << "Enter profits of the items: ";
  for (int i = 0; i < n; i++)
  {
    cin >> profit[i];
  }

  cout << "Enter weights of the items: ";
  for (int i = 0; i < n; i++)
  {
    cin >> weight[i];
  }

  float maxProfit = fractionalKnapsack(n, W, profit, weight);

  cout << "Maximum profit that can be obtained: " << maxProfit << endl;

  return 0;
}
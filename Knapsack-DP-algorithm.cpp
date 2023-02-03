#include <iostream>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
                K[i][w] = 0;
           else if (wt[i-1] <= w)
           {
                if(val[i-1] + K[i-1][w-wt[i-1]] > K[i-1][w])
                    K[i][w] = val[i-1] + K[i-1][w-wt[i-1]];
                else
                    K[i][w] = K[i-1][w];
           }
           else
                K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    int val[n], wt[n];
    cout << "Enter the values and weights of the items: ";
    for(int i = 0; i < n; i++)
        cin >> val[i] >> wt[i];
    cout << "Enter the capacity of the knapsack: ";
    int W;
    cin >> W;
    cout << knapSack(W, wt, val, n);
    return 0;
}

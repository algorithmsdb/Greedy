// A Dynamic Programming based solution for 0-1 Knapsack problem
// http://www.spoj.com/problems/PARTY/

#include<bits/stdc++.h>
using namespace std;

int main()
{
int W,n;
while(1)
    {
    cin>>W>>n;
    if(W==0 && n==0) break;
    int wt[n]; int val[n];
    for(int i=0;i<n;i++)
        {
        cin>>wt[i]>>val[i];
        }
     int i, w;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0) // first row and first column are made zero
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
int best=K[n][W];
for(w=W;w!=0; w--)
    {
    if(best>K[n][w]) break;
    }
   cout<<w+1<<" "<<K[n][W]<<"\n";
   }

}


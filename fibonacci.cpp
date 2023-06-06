#include <bits/stdc++.h>
using namespace std;

// normal recursion soln
int fibonacci(int n)
{

    // base case
    if (n <= 1)
    {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// dp with memoization - top down approach (recursion + storage)
// TC- O(n) SC- O(n) + stack space(approx O(n))
int fibWithDP(int n, vector<int> &dp)
{

    // base case
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = fibWithDP(n - 1, dp) + fibWithDP(n - 2, dp);
}

int main()
{

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    int ans;

    // // normal recursion soln
    // ans = fibonacci(n);

    // // dp soln with memoization
    // ans = fibWithDP(n, dp);

    // // dp with tabulation - bottom up approach (iteration + storage)
    // // TC- O(n) SC- O(n)
    // dp[0] = 0;
    // dp[1] = 1;

    // for (int i = 2; i < n + 1; i++)
    // {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }

    // ans = dp[n];

    // most optimized soln
    // TC- O(n) SC- O(1)
    int prev = 1, prevPrev = 0, curr;
    for (int i = 2; i < n + 1; i++)
    {
        curr = prev + prevPrev;
        prevPrev = prev;
        prev = curr;
    }

    ans = curr;

    cout << ans << endl;
    return 0;
}
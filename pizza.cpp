#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

#define N 5 // Total locations including pizza shop
#define INF 999999

// Distance (time) matrix
int dist[N][N] = {
    {0, 10, 15, 20, 10},
    {10, 0, 35, 25, 17},
    {15, 35, 0, 30, 20},
    {20, 25, 30, 0, 23},
    {10, 17, 20, 23, 0}
};

int dp[1 << N][N]; // DP table
int visited_all = (1 << N) - 1; // All nodes visited
int start = 0; // Start from pizza shop (node 0)

// Recursive function for TSP
int tsp(int mask, int pos) {
    if (mask == visited_all) {
        return dist[pos][start]; // Return to shop
    }

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < N; city++) {
        // If city not yet visited
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    // Initialize dp with -1
    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;

    cout << "\n--- Pizza Delivery Route Optimization ---\n";
    int min_time = tsp(1, start);
    cout << "Minimum time to deliver all pizzas: " << min_time << " minutes\n";

    return 0;
}

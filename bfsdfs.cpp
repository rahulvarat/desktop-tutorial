#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define N 4   // Total locations (including pizza shop)
#define INF 9999

// Distance (time) between locations (graph representation)
int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visitedAll = (1 << N) - 1;  // Bitmask for all nodes visited
int dp[1 << N][N];              // Memoization table

// Recursive TSP function
int tsp(int mask, int pos) {
    // Base condition: all locations visited
    if (mask == visitedAll)
        return graph[pos][0];  // Return to pizza shop

    // If already computed
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < N; city++) {
        // If the city is not visited yet
        if ((mask & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(mask | (1 << city), city);
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
    cout << "Locations: 0 = Shop, 1, 2, 3 = Customers\n";

    int minTime = tsp(1, 0);  // Start from shop (0th node)
    cout << "Minimum time to deliver all pizzas: " << minTime << " minutes\n";

    return 0;
}

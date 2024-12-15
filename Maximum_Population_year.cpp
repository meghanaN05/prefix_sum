#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // Create an array to track population changes for years 1950 to 2050 (inclusive)
        vector<int> population(101, 0);
        
        // Process the logs to adjust population changes
        for (const auto& log : logs) {
            // Increment for the birth year
            population[log[0] - 1950]++;
            // Decrement for the death year
            population[log[1] - 1950]--;
        }
        
        // Determine the year with the maximum population
        int maxPopulation = population[0]; // Max population observed
        int year = 0; // Corresponding year
        for (int i = 1; i <= 100; ++i) {
            // Carry forward the cumulative population
            population[i] += population[i - 1];
            // Check if the current year has more population
            if (population[i] > maxPopulation) {
                maxPopulation = population[i];
                year = i;
            }
        }
        
        // Return the actual year by offsetting the index
        return year + 1950;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> logs = {{1950, 1961}, {1960, 1971}, {1970, 1981}};
    cout << "Year with maximum population: " << solution.maximumPopulation(logs) << endl;
    return 0;
}

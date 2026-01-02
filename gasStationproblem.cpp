/*
 Gas Station Problem

 Given two equal-length arrays `gas` and `cost` where `gas[i]` is the amount
 of gas available at station i and `cost[i]` is the gas required to travel
 from station i to station (i+1) mod n, determine a starting station index
 from which you can complete a full circuit. Return -1 if it's impossible.

 Greedy approach (O(n) time, O(1) space):
 - If total gas < total cost, no solution exists.
 - Otherwise, keep a running `currentTank` (net gas) and a candidate `start`.
   When `currentTank` becomes negative at index i, it means any start up to i
   cannot complete the circuit; set start = i+1 and reset `currentTank` to 0.
 - After a single pass, if total gas >= total cost, `start` is the answer.
*/

#include <iostream>
#include <vector>

using namespace std;

int gasStationproblem(vector<int>& gas, vector<int>& cost)
{
    int totalgas = 0, totalcost = 0;
    int currentgas = 0; // net gas in tank starting from current candidate
    int start = 0;      // candidate starting station (0-based index)

    for (int i = 0; i < (int)gas.size(); ++i)
    {
        totalgas += gas[i];        // accumulate total available gas
        totalcost += cost[i];      // accumulate total required cost

        // add net gain/loss at station i to current tank
        currentgas += gas[i] - cost[i];

        // If current tank is negative, we cannot reach station i+1 from
        // the current `start`. So pick next station as candidate and reset.
        if (currentgas < 0)
        {
            start = i + 1; // try next station as start
            currentgas = 0; // reset tank for new candidate
        }
    }

    // If total gas is less than total cost, circuit is impossible.
    return (totalgas < totalcost) ? -1 : start;
}

int main()
{
    // Sample input: gas at each station and cost to reach next station.
    // Indexing is 0-based; function returns starting index or -1.
    vector<int> gas = {1, 2, 4, 5, 9};    // Gas available at stations
    vector<int> cost = {3, 4, 1, 10, 1};  // Gas required to move to next station

    cout << gasStationproblem(gas, cost) << endl;
    return 0;
}
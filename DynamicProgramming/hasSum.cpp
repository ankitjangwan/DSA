#include <bits/stdc++.h>

using namespace std;

// function which takes a targetSum and array of numbers as input and return true/false depending on whether it is
//possible  to generate targetSum using numbers in the array

pair<vector<int>, bool> hasSum(int targetSum, vector<int> numbers, unordered_map<int, pair<vector<int>, bool>> memo)
{
    if (targetSum == 0)
        return make_pair(vector<int>(), true);
    if (targetSum < 0)
        return make_pair(vector<int>(), false);
    if (memo.find(targetSum) != memo.end())
    {
        return memo[targetSum];
    }
    for (auto el : numbers)
    {
        int remainder = targetSum - el;
        pair<vector<int>, bool> result = hasSum(remainder, numbers, memo);
        if (result.second)
        {
            result.first.push_back(el);
        }
        memo[targetSum] = result;
        return memo[targetSum];
    }
    memo[targetSum] = make_pair(vector<int>(), false);
    return memo[targetSum];
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    vector<int> numbers;
    int testCases, size, element, targetSum;
    unordered_map<int, pair<vector<int>, bool>> memo;
    cin >> targetSum;
    cin >> size;
    while (size--)
    {
        cin >> element;
        numbers.push_back(element);
    }
    pair<vector<int>, bool> result = hasSum(targetSum, numbers, memo);
    if (result.second)
    {
        for (auto el : result.first)
        {
            cout << el << ",";
        }
        cout << endl;
    }
    else
    {
        cout << "null";
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

// function which takes a targetSum and array of numbers as input and return true/false depending on whether it is
//possible  to generate targetSum using numbers in the array

bool canSum(int targetSum, vector<int> numbers)
{
if (targetSum == 0)
    return true;
if (targetSum < 0)
    return false;
for (auto el : numbers)
{
    int remainder = targetSum - el;
    if(canSum(remainder, numbers)){
        return true;
    }
}
return false;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
vector<int> numbers;
int testCases, size, element, targetSum;
cin >> testCases;
while (testCases--)
{
    cin >> targetSum;
    cin >> size;
    while (size--)
    {
        cin >> element;
        numbers.push_back(element);
    }
    for(auto itr: numbers){
        cout<<itr<<",";
    }
    cout<<endl;
    cout << canSum(targetSum, numbers) << endl;
    numbers.clear();
}

return 0;
}
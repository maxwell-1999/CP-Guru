#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;
#define newl "\n"
#define deb(x) cout << (#x) << ":" << x << endl;
#define ll long long
/*
How to solve
Only one non falsy truth is enough, to break the question.


How to build logic
1. Find one pattern | Break Problem to Smaller chunks & solve
2. Build logic constructively.
3. Test the logic w different tc including all ec.
First prepare a set of tc w ip and op, then test the algo w those tc.



How to implement
An algo   contains multiple steps      which contains multiple details.
A program contains multiple Block which contains multiple lines.
1. Write all steps wo details
2. For each step, write details if any
3. Note down reoccuring details - these are reusable components
4. For each detail start implementing solution
Things to take care while implementing
- Follow proper naming
- Corner case handling

How to review
Go Blockwise | Stepwise:
1. Read the step details and be clear what this block trying to do
2. Verify syntactical correctness
3. Edge cases handling, by analyzing two extremes

All effects should be well thought of before state changing commit
*/
int max_subarr(vector<int> arr)
{
    int max_sum = 0;
    int curr_sum = 0;
    for (auto ele : arr)
    {
        curr_sum += ele;
        // deb(ele);
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}
int primeSeive[1001] = {0};
int maxPrimeTill = 0;
void generateSeive()
{
    primeSeive[0] = primeSeive[1] = 1;
    // primeSeive[2] = 2;
    int c = 0;
    for (int i = 2; i < sizeof(primeSeive) / sizeof(primeSeive[0]); i++)
    {
        if (!primeSeive[i])
        {
            c++;
            primeSeive[i] = c;
            // cout << i << " ";
            for (int j = 2 * i; j < sizeof(primeSeive) / sizeof(primeSeive[0]); j += i)
            {
                if (!primeSeive[j])
                    primeSeive[j] = c;
            }
        }
    }
    maxPrimeTill = c;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &ele : arr)
        cin >> ele;
    int maxe = 1;
    bool vis[12] = {false};
    int mapping[12] = {0};
    for (auto ele : arr)
    {
        maxe = max(maxe, primeSeive[ele]);
        vis[primeSeive[ele]] = true;
    }
    int i = 1;
    int actualCounter = 1;
    for (; i < 12; i++)
    {
        if (vis[i])
        {
            mapping[i] = actualCounter;
            actualCounter++;
        }
    }
    cout << actualCounter - 1 << newl;

    for (auto ele : arr)
    {
        cout << mapping[primeSeive[ele]] << " ";
    }
}
// 3 4 5
// 1 2 1
int main()
{
    generateSeive();
    // cout << maxPrimeTill;
    int t{1};
    cin >> t;
    while (t--)
    {
        solve();
        cout << newl;
    }
    return 0;
}
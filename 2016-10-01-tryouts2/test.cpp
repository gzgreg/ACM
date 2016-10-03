#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

vector< vector<int> > getAllSubsets(vector<int> set)
{
    vector< vector<int> > subset;
    vector<int> empty;
    subset.push_back( empty );

    for (int i = 0; i < set.size(); i++)
    {
        vector< vector<int> > subsetTemp = subset;

        for (int j = 0; j < subsetTemp.size(); j++)
            subsetTemp[j].push_back( set[i] );

        for (int j = 0; j < subsetTemp.size(); j++)
            subset.push_back( subsetTemp[j] );
    }
    return subset;
}

int main(){
    ios::sync_with_stdio(0);

    vector<vector<int>> sets = getAllSubsets({1, 2, 3, 4, 5, 6, 7, 8});
    
    vector<int> nums (9, 0);

    for(vector<int> set : sets) {
        sort(set.begin(), set.end());
        if(set.size() == 1) continue;
        for(int i = 0; i < set.size(); i++) {
            if(i == set.size() - 1 || i == set.size() - 2) {
                nums[set[i]]++;
            } else {
                nums[set[i]] += 2;
            }
        }
    }

    for(int i : nums) {
         cout << i << " ";
    }

    return 0;
}
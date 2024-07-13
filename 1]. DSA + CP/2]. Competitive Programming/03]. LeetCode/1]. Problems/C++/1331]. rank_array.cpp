/*-
1331. Rank Transform of an Array

Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
*/

//map only
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        map<int, int> mp;
        for (auto &it : arr)
            mp[it] = 0;
        int rank = 0;
        for (auto &it : mp)
            mp[it.first] = ++rank;
        for (int i = 0; i < arr.size(); i++)
            arr[i] = mp[arr[i]];

        return arr;
    }
};

//sort and map
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        map<int, int> mp;
        vector<int> temp = arr;
        int rank = 1;

        sort(temp.begin(), temp.end());
        auto it = unique(temp.begin(), temp.end());
        temp.resize(distance(temp.begin(), it));

        for (int i = 0; i < temp.size(); i++)
            mp[temp[i]] = rank, ++rank;

        for (int i = 0; i < arr.size(); i++)
            arr[i] = mp[arr[i]];

        return arr;
    }
};

//map and set

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        map<int, int> mp;
        set<int> s;
        for (int i = 0; i < arr.size(); i++)
            s.insert(arr[i]);
        int rank = 1;
        for (auto &it : s)
            mp[it] = rank, ++rank;
        for (int i = 0; i < arr.size(); i++)
            arr[i] = mp[arr[i]];

        return arr;
    }
};
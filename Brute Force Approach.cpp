// Brute Force Approach 

// Time Complexity :- O(n ^ 2)

// Input :
// n=5 
// noOfCables= 6  //For Our Example Case we take Cables vector of length 6.
// cables =[[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]


//OutPut:
// maximal network rank of the entire infrastructure = 5



// CODE

#include<bits/stdc++.h>

using namespace std;

int maxNetworkRank(int n,vector<vector<int>>&cables)
{
        vector<unordered_set<int>> g(n);
	int res= 0;
        for (auto r: cables) g[r[0]].insert(r[1]), g[r[1]].insert(r[0]);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int total = g[i].size() + g[j].size() - g[i].count(j);
                res = max(res, total);
            }
        return res;
}


int main()
{
    cout<<"Enter the no vertices n : ";
    int n;
    cin>>n;
    cout<<"Enter the no of road : ";
    int noOfCables;
    cin>>noOfCables;
    vector<vector<int>>cables;   //creating a 2D Vector for cables where Each cable[i] = [ai, bi] indicates that there is a bidirectional cable between labs ai and bi
    for(int i=0;i<noOfCables;i++)       // considering Our Input Example cables of length 6.
    {
        int x,y;
        cin>>x>>y;
        cables.push_back({x,y});
    }
    int ans= maxNetworkRank(n,cables);
    cout<<"The Maximal Network Rank is :"<<ans;
    
    return 0;
}

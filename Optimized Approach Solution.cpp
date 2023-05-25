//Best Optimized Approach 

//Time Complexity :- O(n)
 

// Input :
// n=5 
//noOfCables=6  // For Our Example Case taking Cables vector of 6 length
// cables = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]


//OutPut:
// Maximal network rank is : 5



// CODE 

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int maxNetworkRank(int n,vector<vector<int>>&cables)
{
        if (n <= 2 || cables.size() == 0) return cables.size();
        // populating the adj list as a O(1) set per node
        
        vector<unordered_set<int>> adj_list(n, unordered_set<int>{});
        for (int i = 0; i < cables.size(); i++) {
            adj_list[cables[i][0]].insert(cables[i][1]);
            adj_list[cables[i][1]].insert(cables[i][0]);
        }
        
        
        // calc first and second maxes
        
        int max1 = 0, max2 = 0, imax1 = -1, imax2 = -1;
        for (int i = 0; i < n; i++) {
            int node_degree = adj_list[i].size();
            if (max1 < node_degree) {
                imax2 = imax1; max2 = max1;
                imax1 = i; max1 = node_degree;
            } else if (max2 < node_degree) {
                imax2 = i; max2 = node_degree;
            }
        }
        
        
        // just for those maxes find the best matches and the total max
        
        int ret = 0;
        for (int i = 0; i < n; i++) {
            int node_degree = adj_list[i].size();
            if (i != imax1) ret = max(ret, max1 + node_degree - (adj_list[i].count(imax1)?1:0));
            if (i != imax2) ret = max(ret, max2 + node_degree - (adj_list[i].count(imax2)?1:0));
        }
        return ret;
}



int main()
{
    cout<<"Enter the no vertices n : ";
    int n;
    cin>>n;
    cout<<"Enter the no of Cables : ";
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
    
    cout<<"The Maximal Network Rank is : "<<ans << endl;
    
    return 0;
}

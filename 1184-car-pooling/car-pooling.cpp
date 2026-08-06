class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
    //     vector<vector<int>> v;
    //     for (auto it : trips) {
    //         v.push_back({it[1], it[2], it[0]}); // {start, end, passengers}
    //     }
    // priority_queue<
    //         pair<int,int>,
    //         vector<pair<int,int>>,
    //         greater<pair<int,int>>
    //     > pq;    //(endLocation, passengers)
    //     sort(v.begin(),v.end());
    //     int curr=0;
    //     for(auto it:v)
    //     {
    //         while(!pq.empty()&&pq.top().first<=it[0])//// Remove all passengers who have already reached
    //         {
    //            curr=curr-pq.top().second;
    //            pq.pop();
    //         }
    //         pq.push({it[1],it[2]});//// Store current trip
    //         curr+=it[2];//
            // Pick new passengers
    //         if(curr>capacity) return false;
    //     }
    //     return true;
    // }

    vector<int>diff(1001,0);
    for(auto it:trips)
    {
        int pass=it[0];
        int from=it[1];
        int to=it[2];
        diff[from]+=pass;
        diff[to]-=pass;
    }
    int currpass=0;
    for(int i=0;i<=1000;i++)
    {
         currpass+=diff[i];
         if(currpass>capacity) return false;

    }
    return true;
 }
};
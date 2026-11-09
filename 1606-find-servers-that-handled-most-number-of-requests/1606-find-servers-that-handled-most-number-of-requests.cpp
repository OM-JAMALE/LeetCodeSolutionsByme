class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k, 0);
        set<int> freeServers;
        for (int i = 0; i < k; i++) freeServers.insert(i);

        // (end_time, server_id), smallest end_time on top
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy;

        for (int i = 0; i < (int)arrival.size(); i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                freeServers.insert(busy.top().second);
                busy.pop();
            }
            if (freeServers.empty()) continue;      // drop request

            auto it = freeServers.lower_bound(i % k);
            if (it == freeServers.end()) it = freeServers.begin();   // wrap around

            int id = *it;
            freeServers.erase(it);
            cnt[id]++;
            busy.push({arrival[i] + load[i], id});
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++)
            if (cnt[i] == mx) ans.push_back(i);
        return ans;
    }
};



// time limit exceeds for this 

// class Solution {
// public:
//     vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
//         vector<int> total(k,0);
//         vector<int>server(k,0);
//         int i = 0,maxreq = 0;
//         while((i < k)&&(i<arrival.size())){
//             server[i] = arrival[i] + load[i];
//             total[i]++;
//             i++;
//         }
        
//         while(i<arrival.size()){
//             if(server[i%k] <= arrival[i]){
//                 server[i%k] = arrival[i] + load[i];
//                 total[i%k]++;
//                 i++;
//             }else{
//                 int j = (i+1)%k;
//                 while(j != (i%k)){
//                     if(server[j] <= arrival[i]){
//                        server[j] = arrival[i] + load[i];
//                        total[j]++;
//                        break;
//                     }
//                     j = (j+1)%k;
//                 }
//                 i++;
//             }
//         }
//         for(int l : total){
//             if(maxreq < l){
//                 maxreq = l;
//             }
//         }
//         vector<int> arr;
//         for(int idx = 0;idx < k;idx++){
//             if(total[idx] == maxreq){
//                 arr.push_back(idx);
//             }
//         }
//         return arr;
        
//     }
// };
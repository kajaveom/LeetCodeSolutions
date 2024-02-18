class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        
        sort(meetings.begin(), meetings.end());
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> q;
        
        set<pair<long long, long long>> available;
        int m = meetings.size();
        for (int j = 0; j < n; j++)
            available.insert({j, 0});
        for (int i = 0; i < m; i++)
        {
            while (!q.empty() && q.top()[0] <= meetings[i][0])
            {
                long long j = q.top()[1], k = q.top()[2];
                q.pop();
                available.insert({j, k});
            }
            if (!available.empty())
            {
                long long j = (*available.begin()).first, k = (*available.begin()).second;
                available.erase(available.begin());
                q.push({meetings[i][1], j, k + 1});
            }
            else
            {
                long long t = q.top()[0], j = q.top()[1], k = q.top()[2];
                q.pop();
                q.push({meetings[i][1] - meetings[i][0] + t, j, k + 1});
            }
        }
        long long ans = -1, maxv = INT_MIN;
        while (!available.empty())
        {
            long long j = (*available.begin()).first, k = (*available.begin()).second;
            available.erase(available.begin());
            if (k > maxv)
            {
                ans = j;
                maxv = k;
            }
            else if (k == maxv)
                ans = min(ans, j);
        }
        while (!q.empty())
        {
            long long j = q.top()[1], k = q.top()[2];
            if (k > maxv)
            {
                ans = j;
                maxv = k;
            }
            else if (k == maxv)
                ans = min(ans, j);
            q.pop();
        }
        return ans;
    }
};
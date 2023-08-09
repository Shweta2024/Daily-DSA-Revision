//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    bool dfs(int currentNode, vector<bool>&vist, vector<bool>&anc, vector<int>adj[], string &ans)
    {
        vist[currentNode] = true;
        anc[currentNode] = true;
        
        for(auto adjacentNode : adj[currentNode])
        {
            if(!vist[adjacentNode])
            {
                if(dfs(adjacentNode,vist,anc,adj,ans))
                    return true;
            }
            else if(anc[adjacentNode])
                return true;
        }
        anc[currentNode] = false;
        char currentChar = currentNode + 'a';
        ans += string(1,currentChar);
        return false;
    }
    
    void constructGraph(vector<int>adj[], string dict[], int n)
    {
        for(int index = 0; index < n-1; index++)
        {
            string current = dict[index];
            string next = dict[index+1];
            
            int i = 0;
            while(i < current.size() && i < next.size() && current[i] == next[i])
                i++;
            
            if(i < current.size() && i < next.size())
                adj[current[i]-'a'].push_back(next[i]-'a');
        }
    }
    
    string findOrder(string dict[], int n, int k) 
    {
        //1. construct the graph
        //2. find the topo order
        
        vector<int>adj[k];
        constructGraph(adj,dict,n);
        
        string ans;
        vector<bool>vist(k,false);
        vector<bool>anc(k,false);
        // for(int i = 0; i < k; i++)
        // {
        //     cout<<"i : "<<i<<" : ";
        //     for(auto j : adj[i])
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        
        for(int currentNode = 0; currentNode < k; currentNode++)
        {
            if(!vist[currentNode])
            {
                //cycle exists : no topo order possible
                if(dfs(currentNode,vist,anc,adj,ans))
                    return "";
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
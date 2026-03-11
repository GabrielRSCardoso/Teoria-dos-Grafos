#include <iostream>
#include <set>

using namespace std;

int main(){
    int T; 
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N; 
        cin >> N;
        int V, A;
        cin >> V >> A;
        set<pair<int,int>> edges;

        for(int j = 0; j < A; j++)
        {
            int u, v;
            cin >> u >> v;

            int a = min(u,v);
            int b = max(u,v);

            edges.insert({a,b});
        }
        cout << edges.size() * 2 << endl;
        
    }
    
    return 0;
}
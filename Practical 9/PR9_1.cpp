#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dfs(int node,const vector<vector<int>>&graph,vector<bool>&visited,vector<int>&order)
{
    visited[node]=true;
    order.push_back(node);
    for(int next:graph[node])
    {
        if(!visited[next]) dfs(next,graph,visited,order);
    }
}
vector<int> bfs(int start,const vector<vector<int>>&graph)
{
    vector<bool>visited(graph.size(),false);
    vector<int>order;
    queue<int>q;
    visited[start]=true;
    q.push(start);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        order.push_back(node);
        for(int next:graph[node])
        {
            if(!visited[next])
            {
                visited[next]=true;
                q.push(next);
            }
        }
    }
    return order;
}
int main()
{
    int n,m;
    cout<<"Enter number of vertices and edges: ";
    cin>>n>>m;
    vector<vector<int>>graph(n+1);
    cout<<"Enter edges: ";
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int start;
    cout<<"Enter starting vertex: ";
    cin>>start;
    vector<bool>visited(n+1,false);
    vector<int>dfsOrder;
    dfs(start,graph,visited,dfsOrder);
    vector<int>bfsOrder=bfs(start,graph);
    cout<<"DFS: ";
    for(int node:dfsOrder) cout<<node<<" ";
    cout<<"\nBFS: ";
    for(int node:bfsOrder) cout<<node<<" ";
    cout<<"\n";
    return 0;
}
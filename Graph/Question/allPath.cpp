//? Given a graph . Calculate all paths between two given nodes

//? Given a graph check wheather there is a path between any two given vertices ?

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int> > graph;
int v; // no. of vertices
unordered_set<int> visited;
vector<vector<int> > result;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void dfs(int curr, int end, vector<int> &path){
    if(curr==end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr); // marked visited
    path.push_back(curr);
    for(auto neighbour : graph[curr]){
        if(!visited.count(neighbour)){
            dfs(neighbour,end, path);
            
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}

void allPath(int src, int dest){
    vector<int> v;
     dfs(src,dest,v);
}

int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    visited.clear();
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s,d);
    }
    int x, y;
    cin>>x>>y;
    allPath(x,y);
    for(auto path : result){
        for(auto el : path){
            cout<<el<<" ";
        }
        cout<<endl;
    }
}



// solved using DFS technique
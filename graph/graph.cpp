#include<iostream>
#include<vector>
using namespace std;


void dfs(vector<vector<int>> &adjacency_list,int source,vector<bool> &visited,vector<int> &parents) {
    //step1
    visited[source] = true;
    cout<<source<<",";
    //source =====> adjacency_list[source]
    //step2
    for(int neibhour_index = 0 ; neibhour_index < adjacency_list[source].size() ; neibhour_index++) {
        int child = adjacency_list[source][neibhour_index];
        if(visited[child] == false) {
            parents[child] = source;
            dfs(adjacency_list,child,visited,parents);
        }
    }
}

void print(vector<vector<int>> &adjacency_list) {
    int num_vertexes = adjacency_list.size();
    for(int current_vertex = 0 ; current_vertex < num_vertexes ; current_vertex++) {
        cout<<current_vertex<<" -> ";
        for(int neibhour_index = 0 ; neibhour_index < adjacency_list[current_vertex].size() ; neibhour_index++) {
            cout<<adjacency_list[current_vertex][neibhour_index]<<",";
        }
        cout<<"\n";
    }
}

int main() {

    int num_vertex,num_edges;
    cout<<"Enter the number of vertex : ";
    cin>>num_vertex;
    cout<<"Enter the number of Edges : ";
    cin>>num_edges;
    vector<vector<int>> adjacency_list(num_vertex);
    cout<<"Enter the Edges :\n";
    for(int edge_number = 0 ; edge_number < num_edges ; edge_number++) {
        int source_vertex,destination_vertex;
        cin >> source_vertex >> destination_vertex;
        adjacency_list[source_vertex].push_back(destination_vertex);
        adjacency_list[destination_vertex].push_back(source_vertex);
    }
    // print(adjacency_list);
    vector<bool> visted(num_vertex,false);
    vector<int> parent(num_vertex,-1);
    int connected_componets = 0;
    for(int i = 0 ; i < num_vertex ; i++) {
        if(visted[i] == false) {
            connected_componets++;
            dfs(adjacency_list,i,visted,parent);
        }
    }

    for(int i = 0 ; i < num_vertex ; i++) cout<<i<<"--->"<<parent[i]<<" ";

}
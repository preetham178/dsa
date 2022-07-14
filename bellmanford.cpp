#include<bits/stdc++.h>
using namespace std;
struct edge{
	int v1,v2,wt;
};
int main(){
	int n,e;
	cout<<"enter vertices and edges"<<endl;
	cin>>n>>e;
	struct edge graph[e];
	for(int i=0;i<e;i++){
		int a,b,k;
		cin>>a>>b>>k;
		graph[i].v1=a;
		graph[i].v2=b;
		graph[i].wt=k;
	}
	vector<int> dist(n,INT_MAX);
	int source;
	cin>>source;
	dist[source]=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<e;j++){
			if(dist[graph[j].v1]+graph[j].wt<dist[graph[j].v2]){
				dist[graph[j].v2]=dist[graph[j].v1]+graph[j].wt;
			}
		}
	}
	int flag=1;
	for(int j=0;j<e;j++){
		if(dist[graph[j].v1]+graph[j].wt<dist[graph[j].v2]){
			cout<<"negative edge cycle detected"<<endl; 
			flag=0;
			break;
		}
	}
	if(flag){
		for(int i=0;i<n;i++){
			cout<<dist[i];
		}
	}
	
}

#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;
#define Get getchar()
#define INF 1000000
inline int getInt()
{
    int a=0,s=1;
    char c=Get;
    while(c<33)
        c=Get;
    if(c=='-')
    {
        s=-1;
        c=Get;
    }
    while(c>33)
    {
        a=(a<<3)+(a<<1)+c-'0';
        c=Get;
    }
    return a*s;
}
struct edge {
	int u;
	int w;
};

bool operator <( edge a, edge b ) {
	return a.w < b.w;
}

void dijkstra( vector< edge > graph[], int dist[], int N, int s ) {
	dist[ s ] = 0;
	priority_queue< edge > q;
	q.push( ( edge ) { s, 0 } );

	while ( !q.empty() ) {
		edge p = q.top();
		q.pop();
		for ( int i = 0; i < graph[ p.u ].size(); ++i ) {
			int u = p.u;
			int v = graph[ p.u ][ i ].u;
			if ( dist[ u ] + graph[ p.u ][ i ].w < dist[ v ] ) {
				dist[ v ] = dist[ u ] + graph[ p.u ][ i ].w;
				q.push( graph[ p.u ][ i ] );
			}
		}
	}
}

int main() {
    int t=getInt();
    while(t--){
	int N, E;
	int S, T;
	int u, v, w, i;
		N=getInt() , E=getInt(), S=getInt(), T=getInt();
		vector< edge > graph[ N + 1 ];
		int dist[ N + 1 ];
		for ( i = 0; i < E; ++i ) {
			scanf( "%d%d%d", &u, &v, &w );
			graph[ u ].push_back( ( edge ) { v, w } );
			graph[ v ].push_back( ( edge ) { u, w } );
		}
		for ( i = 0; i <= N; ++i ) {
			dist[ i ] = INF;
		}
		dijkstra( graph, dist, N, S );
            if(dist[T]==INF)
                printf("NONE\n");
            else
                printf("%d\n", dist[T]);
    }
	return 0;
}

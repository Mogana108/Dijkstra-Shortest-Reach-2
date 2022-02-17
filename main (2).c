#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void dijkstra(int v, int g[][v], int root) {
    int dist[v], visited[v];
    for(int i = 0; i < v; i++) {
        dist[i] = -1;
        visited[i] = 0;
    }
    dist[root] = 0;
    int min_index = root;
    int min_dist = 0;
    visited[root] = 1;
    while(min_dist != -1) {
        visited[min_index] = 1;
        for(int i = 0; i < v; i++) {
            if(g[min_index][i] > 0) {
                if(visited[i] == 0 && (dist[i] == -1 || (dist[i] > (dist[min_index] + g[min_index][i])))) {
                    dist[i] = dist[min_index] + g[min_index][i];
                } 
            }
        }
        min_dist = -1;
        for(int k = 0; k < v; k++) {
            if(visited[k] == 0) {
                if(min_dist == -1 || (dist[k] != -1 && dist[k] < min_dist)) {
                    min_dist = dist[k];
                    min_index = k;     
                }
            }
        }
    }
    for(int j = 0; j < v; j++) {
        if(j != root) {
            printf("%d ", dist[j]);
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++) {
        int v, e;
        scanf("%d %d", &v, &e);
        int g[v][v];
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                g[i][j] = 0;
            }
        }
        for(int i = 0; i < e; i++) {
            int v1, v2, w;
            scanf("%d %d %d", &v1, &v2, &w);
            if(g[v1-1][v2-1] == 0 || g[v1-1][v2-1] > w) {
                g[v1-1][v2-1] = w;
                g[v2-1][v1-1] = w;
            }
        }
        int root;
        scanf("%d", &root);
        dijkstra(v, g, (root - 1));
    }   
    return 0;
}

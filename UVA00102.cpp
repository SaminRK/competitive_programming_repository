#include<bits/stdc++.h>
using namespace std;

int main(){
    int b[4], c[4], g[4];

    while (scanf("%d %d %d %d %d %d %d %d %d", &b[1], &g[1], &c[1], &b[2], &g[2], &c[2], &b[3], &g[3], &c[3] ) != EOF){
        int change[6], i, idx, mi = 2000000000;
        //if BCG
        change[1] = b[2] + b[3] + g[1] + g[3] + c[1] + c[2];
        // if BGC
        change[0] = b[2] + b[3] + g[1] + g[2] + c[1] + c[3];
        //if CBG
        change[2] = c[2] + c[3] + b[1] + b[3] + g[1] + g[2];
        //if CGB
        change[3] = c[2] + c[3] + g[1] + g[3] + b[1] + b[2];
        // if GBC
        change[4] = g[2] + g[3] + b[1] + b[3] + c[1] + c[2];
        //if GCB
        change[5] = g[2] + g[3] + c[1] + c[3] + b[1] + b[2];

        for (i = 0 ; i < 6; i++){
            if (change[i] < mi){
                mi = change[i];
                idx = i;
            }
        }
        if (idx == 0) cout << "BCG ";
        else if (idx == 1 ) cout << "BGC ";
        else if (idx == 2) cout << "CBG ";
        else if (idx == 3) cout << "CGB ";
        else if (idx == 4) cout << "GBC ";
        else if (idx == 5) cout << "GCB ";
        cout << mi << endl;

    }
}

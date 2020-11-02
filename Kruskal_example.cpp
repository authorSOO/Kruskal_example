#include	<cstdio>
#include	<algorithm>
#include	<vector>
#include  <queue>
using namespace std;


int p[10001];
int ans=0;

struct Edge
{
    int start, end, cost;
    bool operator < (const Edge &other)const{
        return cost<other.cost;
    }
    /* data */
};
int Find(int x){
    if(x==p[x])return x;
    else{
        return p[x]=Find(p[x]);
    }
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    p[x]=y;
}

int main(int argc, const char** argv) {
    int n,m;
    scanf("%d %d",&n,&m);
    vector<Edge> a(m);
    for(int i=1;i<=n;i++)p[i]=i;
    for(int j=0;j<m;j++){
        scanf("%d %d %d",&a[j].start,&a[j].end,&a[j].cost);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++){
        int x = Find(a[i].start);
        int y = Find(a[i].end);
        if(x != y){
            Union(a[i].start,a[i].end);
            ans += a[i].cost;   
        }
    }
    printf("%d",ans);

    return 0;
}
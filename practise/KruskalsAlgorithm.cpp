#include<bits/stdc++.h>
#define ll long long int
using namespace std;


struct edge
{
    ll junc1,junc2;
    ll dis;
};


bool cmp(edge *a, edge *b)
{
    return a->dis < b->dis;
}

class myGraph
{
public:
    ll n,ed,size,*par,*height;
    edge **edg;
    myGraph(ll n, ll ed)
    {
        this->n = n;
        this->ed = ed;
        size = 0;
        par = new ll[n];
        height = new ll[n];
        edg = new edge*[ed];
    }
    ~myGraph()
    {
        for(ll i=0; i<ed; i++)
        {
            delete edg[i];
        }
        delete []edg;
        delete par;
        delete height;
    }
    void addEdge(ll x, ll y, ll z)
    {
        edg[size]  = new edge();
        edg[size]->junc1 = x;
        edg[size]->junc2 = y;
        edg[size]->dis = z;
        size++;
    }

    void make_set(ll i)
    {
        par[i] = i;
        height[i] = 0;
    }

    ll find(ll i)
    {
        while(i!=par[i])
        {
            i = par[i];
        }
        return i;
    }

    void make_union(ll x, ll y)
    {
        ll p1 = find(x);
        ll p2 = find(y);
        if(p1!=p2)
        {
            if(height[p1]==height[p2])
            {
                par[p2] = p1;
                height[p1]+=1;
            }
            else if(height[p1]>height[p2])
                par[p2] = p1;
            else
                par[p1] = p2;
        }
    }

    double kruskals()
    {
        sort(edg,edg+ed,cmp);
        for(ll i=0; i<n; i++)
            make_set(i);
        double s=0,c=0;
        for(ll i=0; i<ed; i++)
        {
            if(find(edg[i]->junc1)!=find(edg[i]->junc2))
            {
                s+=edg[i]->dis;
                c++;
                make_union(edg[i]->junc1,edg[i]->junc2);
            }
            if(c==n-1)
                break;
        }
        return s;
    }

};


int main()
{
    while(true)
    {
        ll n,m;
        cin>>n>>m;
        if(n==0&&m==0)
            break;
        myGraph g(n,m);
        double s=0;
        for(ll i=1; i<=m; i++)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            s+=z;
            g.addEdge(x,y,z);
        }
        cout<<s-g.kruskals()<<endl;
    }
}


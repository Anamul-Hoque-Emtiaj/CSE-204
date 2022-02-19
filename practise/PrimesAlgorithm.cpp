#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct node
{
    ll value,weight;
    node *next;
};

struct edge
{
    ll s,d;
    ll dis;
};

struct CompareDist
{
    bool operator()(edge const& p1, edge const& p2)
    {
        return p1.dis > p2.dis;
    }
};

class myGraph
{
public:
    ll n,*par;
    bool *explore;
    node **arr;
    myGraph(ll n)
    {
        this->n = n;
        arr = new node*[n+1];
        par = new ll[n+1];
        explore = new bool[n+1];
        for(ll i=0; i<=n; i++)
        {
            arr[i] = new node();
            arr[i] = NULL;
        }
    }
    ~myGraph()
    {
        for(ll i=0; i<=n; i++)
        {
            delete arr[i];
        }
        delete []arr;
        delete par;
        delete explore;
    }
    void addEdge(ll i1, ll i2, ll w)
    {
        if(arr[i1]==NULL)
        {
            node *n = new node();
            n->value = i2;
            n->weight = w;
            n->next = NULL;
            arr[i1] = n;
        }
        else
        {
            node *t = arr[i1];
            while(t!=NULL)
            {
                if(t->next!=NULL)
                    t = t->next;
                else
                    break;
            }
            node *n = new node();
            n->value = i2;
            n->weight = w;
            n->next = NULL;
            t->next = n;
        }
    }
    void addUndirectedEdge(ll i1, ll i2, ll w)
    {
        addEdge(i1,i2,w);
        addEdge(i2,i1,w);
    }
    edge EdgeObj(ll x, ll y, ll z)
    {
        edge e;
        e.s = x;
        e.d = y;
        e.dis = z;
        return e;
    }

    double primes(ll st)
    {
        for(ll i=0; i<=n; i++)
        {
            explore[i] = false;
            par[i] = -1;
        }
        priority_queue<edge, vector<edge>, CompareDist> Q;
        node *t = arr[st];
        while(t!=NULL)
        {
            edge ed;
            ed.s = st;
            ed.d = t->value;
            ed.dis  = t->weight;
            Q.push(ed);
            t = t->next;
        }
        explore[st] = true;
        double s=0;
        while(!Q.empty())
        {
            edge e = Q.top();
            Q.pop();
            //cout<<e.s<<" "<<e.d<<" "<<e.dis<<endl;
            if(!explore[e.d])
            {
                par[e.d] = e.s;
                s+=e.dis;
                node *t = arr[e.d];

                while(t!=NULL)
                {
                    if(!explore[t->value])
                    {
                        //cout<<t->value<<" ";
                        edge ed;
                        ed.s = e.d;
                        ed.d = t->value;
                        ed.dis  = t->weight;
                        Q.push(ed);
                    }
                    t = t->next;
                }
                explore[e.d] = true;
            }
        }
        return s;
    }
};


int main()
{
    while(true)
    {
        ll n,m,mini=2000000,r=0;
        cin>>n>>m;
        if(n==0&&m==0)
            break;
        myGraph g(n);
        double s=0;
        while(m--)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            if(z<mini)
            {
                r = x;
                mini = z;
            }
            s+=z;
            g.addUndirectedEdge(x,y,z);
        }
        cout<<s-g.primes(r)<<endl;
    }
}

#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
using namespace std;

ifstream input;
ofstream output;


class SnakesOrLadders
{
public:
    int starting,ending;
};

//check if square v is a starting point of a snake or ladder.
//Return the index of snake or ladder if it is a snake or ladder
int isIn(SnakesOrLadders *a, int s, int v)
{
    for(int i=0; i<s; i++)
    {
        if(a[i].starting==v)
            return i;
    }
    return -1;
}

//node of adjacency List
class node
{
public:
    int value,cost;
    node *next;

    node(int v, int c)
    {
        value = v;
        cost = c;
        next = NULL;
    }
};

class Graph
{
    int X,*level,*parent; //X-> number of nodes
    node **adjList;
public:
    Graph(int X)
    {
        this->X = X;
        adjList = new node*[X+1];//adjacency List
        level = new int[X+1]; //shortest distance
        parent = new int[X+1]; //parent
    }
    ~Graph()
    {
        delete []level;
        delete []parent;
        delete []adjList;
    }
    //load adjacency List and call BFS function
    void init(int n, int l, SnakesOrLadders *ladders, int s, SnakesOrLadders *snakes)
    {
        for(int i=1; i<X; i++)
        {
            int temp = isIn(snakes,s,i);
            if(temp!=-1)
            {
                node *t = new node(snakes[temp].ending,0);
                adjList[i] = t;
            }
            else
            {
                temp = isIn(ladders,l,i);
                if(temp!=-1)
                {
                    node *t = new node(ladders[temp].ending,0);
                    adjList[i] = t;
                }
                else
                {
                    node *t = new node(i+1,1);
                    adjList[i] = t;
                    for(int j=i+2; j<=i+n && j<=X; j++)
                    {
                        node *t2 = new node(j,1);
                        t->next = t2;
                        t = t2;
                    }
                }
            }
        }
        BFS();
    }
    //find out shortest path of all node. keep them at level array. Also save parent node index at parent array
    void BFS()
    {
        for(int i=0; i<=X; i++)
        {
            level[i] = 100000;
            parent[i] = -1;
        }


        queue<int> Q;
        level[1] = 0;
        Q.push(1);
        while(!Q.empty())
        {
            int t = Q.front();
            node* cur = adjList[t];
            Q.pop();
            while(cur!=NULL)
            {
                if(level[cur->value]==100000)
                {
                    level[cur->value] = level[t] + cur->cost;
                    parent[cur->value] = t;
                    Q.push(cur->value);
                }
                cur = cur->next;
            }
        }
    }

    int shortestDistance(int n)
    {
        if(level[n]==100000)
            return -1;
        else
            return level[n];
    }
    //write shortest path at output File
    void printShortestPath(int n)
    {
        if(level[n]!=100000)
        {
            stack<int> st;
            int temp = n;
            st.push(temp);
            while(temp!=1)
            {
                temp = parent[temp];
                st.push(temp);
            }
            while(st.size()>1)
            {
                output<<st.top()<<" -> ";
                st.pop();
            }
            output<<st.top()<<endl;
            st.pop();
        }
    }
    //write unexplored node at output file
    bool printUnReachableNode()
    {
        bool isAllReachable = true;
        for(int i=1; i<=X; i++)
        {
            if(level[i]==100000)
            {
                output<<i<<" ";
                isAllReachable = false;
            }

        }
        return isAllReachable;
    }
};

int main()
{
    input.open("in.txt");
    output.open("out.txt");
    int t;
    input>>t;

    while(t--)
    {
        int n,X;
        input>>n>>X;
        Graph *g = new Graph(X);

        int l;
        input>>l;
        SnakesOrLadders *ladders = new SnakesOrLadders[l];
        for(int i=0; i<l; i++)
            input>>ladders[i].starting>>ladders[i].ending;

        int s;
        input>>s;
        SnakesOrLadders *snakes = new SnakesOrLadders[s];

        for(int i=0; i<s; i++)
            input>>snakes[i].starting>>snakes[i].ending;

        g->init(n,l,ladders,s,snakes);
        int r = g->shortestDistance(X);
        if(r==-1)
        {
            output<<-1<<endl;
            output<<"No solution"<<endl;
        }
        else
        {
            output<<r<<endl;
            g->printShortestPath(X);
        }

        bool isAllReachable = g->printUnReachableNode();
        if(isAllReachable)
            output<<"All reachable"<<endl;
        else
            output<<endl;
        output<<endl;
        delete []ladders;
        delete []snakes;
        delete g;
    }
    input.close();
    output.close();
    cout<<"Done"<<endl;
}

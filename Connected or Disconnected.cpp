#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>g[100];
queue<int>Q;

int d[100],col[100],par[100];

int main()
{
    int node,edge,u,v,source,c=0;

    cout<<"Input Node and Edge numbers :";
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=0;i<node;i++)
    {
        d[i]=-1;
        col[i]=1;
        par[i]=-1;
    }
    cout<<"Enter Your Source Node : ";
    cin>>source;
    col[source]=2;
    d[source]=0;
    Q.push(source);

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();

        for(int i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(col[v]==1)
            {
                col[v]=2;
                d[v]=d[u]+1;
                par[v]=u;
                Q.push(v);
            }
            col[u]=3;
        }
    }

    cout<<"The Results are : "<<endl;
    cout<<"Node  Color  Distance  Parent"<<endl;
    for(int i=0;i<node;i++)
    {
        cout<<i<<"       "<<col[i]<<"      "<<d[i]<<"        "<<par[i]<<endl;
    }

    cout<<endl<<endl;
    for(int i=0;i<node;i++)
    {
        if(d[i]==-1)
            c++;
    }
    if(c++)
        cout<<"Disconnected";
    else
        cout<<"Connected";
}



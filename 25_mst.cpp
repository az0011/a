#include<iostream>
using namespace std;

class mst
{
    public:
    int **g,*visited,n;

    mst(int n)
    {
        this->n=n;
        visited=new int[n];
        g = new int*[n];

        for (int i = 0; i < n; i++) 
        {
            g[i] = new int[n];
            visited[i] = 0;
        }

        int max_edge=n*(n-1)*0.5;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) 
            {
                g[i][j]=0;  
            }
        }
    }

    void create()
    {
        int max_edges;
        cout<<"Enter the number of edges you want to enter: ";
        cin>>max_edges;

        int origin,destination;
        int wt;
        for(int i=1;i<=max_edges;i++)
        {
            cout<<"Enter origin and destination vertex: "<<endl;
            cin>>origin>>destination;
            cout<<"Enter the cost: "<<endl;
            cin>>wt;
            g[origin][destination]=wt;
            g[destination][origin]=wt;
        }
    }

    int min_weight(int w[])
    {
        int min = INT_MAX;
        int min_index;

        for (int v = 0; v < n; v++)
        {
            if (visited[v] == 0 && w[v] < min)
            {
                min = w[v];
                min_index = v;
            }
        }
        
        return min_index;
    }

    void prims()
    {
        int parent[n];
        int w[n];

        for (int i = 0; i < n; i++) 
        {
        w[i] = INT_MAX;
        }
        w[0]=0;
        parent[0]=-1;

        for(int count=0;count<n-1;count++)
        {
            int u=min_weight(w);
            visited[u]=1;

            for(int v=0;v<n;v++)  //for obtaining the vertices connected to u 
            {
                if(visited[v]==0 && g[u][v]!=0 && g[u][v]< w[v])
                {
                    parent[v] = u; 
                    w[v] = g[u][v];
                }
            }
        }

        cout << "Edge \tWeight\n";
        int min_cost=0;
        for (int i = 1; i < n; i++)
        {
            cout << parent[i] << " - " << i << " \t"
                << g[i][parent[i]] << " \n";

            min_cost+=g[i][parent[i]];
        }
        cout<<"Minimum cost is: "<<min_cost;
            
    }
};

int main()
{
    int x;
    cout<<"Enter number of offices: ";
    cin>>x;
    mst obj(x);
    obj.create();
    obj.prims();
}
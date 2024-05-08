#include<iostream>
using namespace std;

class Queue 
{
private:
    static const int MAX_SIZE = 100; // Maximum size of the queue
    int arr[MAX_SIZE];
    int front;
    int rear;

    public:
    Queue()
    {
        front=-1;
        rear=-1;
    }

    bool isEmpty()  
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    void push(int value) 
    {
        if (isFull()) {
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = value;
    }

    void pop() 
    {
        if (isEmpty()) {
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int getFront()
    {
        if (isEmpty()) 
        {
            return 0;
        }
        return arr[front];
    }

    friend class graph;
};


class graph
{
    public:
    int **g,*visited,n;

    graph(int n)
    {
        this->n=n;
        visited=new int[n];
        g = new int*[n];

        for (int i = 0; i < n; i++) 
        {
            g[i] = new int[n];
            visited[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) 
            {
                g[i][j]=0;  
            }
        }
    }

    void create(int n)  //vertices starting from 0
    {
        int max_edges;
        cout<<"Enter the number of edges you want to enter: ";
        cin>>max_edges;

        int outdegree[n];
        int indegree[n];
        for(int i=0;i<n;i++)
        {
            outdegree[i]=0;
            indegree[i]=0;
        }

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

            outdegree[origin]+=1;
            indegree[destination]+=1;
        }

        cout<<"Vertex\tIndegree\tOutdegree"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<i<<"\t"<<indegree[i]<<"\t\t"<<outdegree[i]<<endl;
        }
    }

    void BFS(int i,int visited[])
    {
        int u;
        Queue q;
        cout<<i<<" ";
        q.push(i);
        visited[i]=1;

        while(!q.isEmpty())
        {
            u=q.getFront();
            q.pop();

            for(int v=0;v<n;v++)
            {
                if(g[u][v]!=0  && visited[v]==0)
                {
                    cout<<v<<" ";
                    visited[v]=1;
                    q.push(v);
                }
            }
        }
    }

    void DFS(int u,int visited[])
    {
        if(visited[u]==0)
        {
            cout<<u<<" ";
            visited[u]=1;
            for(int v=0;v<n;v++)
            {
                if( g[u][v]!=0  && visited[v]==0)
                {
                    DFS(v,visited);
                }
            }
        }
    }
};

int main()
{
    int n;
    int i;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    int visited[n+1];

    graph obj(n);

    int c=1;
    int choice;
    while(c!=4)
    {

        cout<<"MENU"<<endl;
        cout<<"1.Create graph and display the degree"<<endl;
        cout<<"2.BFS traversal"<<endl;
        cout<<"3.DFS traversal"<<endl;
        cout<<"4.EXIT"<<endl;
        cout<<"Enter your choice:";
        cin>>choice; 
        switch(choice)
        {
            case 1:
            {
                cout<<"\t\tIMPORTANT: NAME VERTICES FROM 0"<<endl;
                obj.create(n);
                break;
            }

            case 2:
            {
                cout<<"Enter the vertex you want to start the traversal with: ";
                cin>>i;

                for(int j=0;j<=n;j++)
                {
                    visited[j]=0;
                }
                cout<<"BFS traversal is: "<<endl;
                obj.BFS(i,visited);
                cout<<endl;
                break;
            }

            case 3:
            {
                cout<<"Enter the vertex you want to start the traversal with: ";
                cin>>i;
                for(int j=0;j<=n;j++)
                {
                    visited[j]=0;
                }
                cout<<"DFS traversal is: "<<endl;
                obj.DFS(i,visited);
                cout<<endl;
                break;
            }

            case 4:
            {
                cout<<"Exiting..."<<endl;
                c=4;
                break;
            }
        }
    }
}
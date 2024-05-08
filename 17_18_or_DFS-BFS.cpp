#include <iostream>

#include <queue>

#include <string>

using namespace std;

class node

{
public:
    string city;

    node *next;

public:
    node(string name)

    {

        city = name;

        next = NULL;
    }

    friend class graph;
};

class graph

{

public:
    int n;

    node **head;

    int set_value()

    {

        cout << "Enter number of cities: ";

        cin >> n;

        head = new node *[n];

        return n;
    }

    void create()

    {

        for (int i = 0; i < n; i++)

        {

            string cityName;

            cout << "Enter name of city " << (i + 1) << ": ";

            cin >> cityName;

            head[i] = new node(cityName);

            node *p = head[i];

            cout << "Enter number of cities adjacent to " << cityName << ": ";

            int x;

            cin >> x;

            if (x == 0)

            {

                head[i]->next = NULL;
            }

            else

            {

                string adjacentCity;

                for (int j = 0; j < x; j++)

                {

                    cout << "Enter adjacent city " << (j + 1) << ": ";

                    cin >> adjacentCity;

                    node *temp = new node(adjacentCity);

                    p->next = temp;

                    temp->next = NULL;

                    p = temp;
                }
            }
        }
    }

    void BFS(int i)

    {

        queue<int> q;

        node *p;

        int *visited = new int[n];

        for (int j = 0; j < n; j++)

        {

            visited[j] = 0;
        }

        q.push(i);

        int x;

        while (!q.empty())

        {

            x = q.front();

            q.pop();

            if (visited[x] == 0)

            {

                cout << head[x]->city << " ";

                visited[x] = 1;
            }

            p = head[x];

            while (p != NULL)

            {

                for (int k = 0; k < n; k++)

                {

                    if (p->city == head[k]->city && visited[k] == 0)

                    {

                        q.push(k);

                        break;
                    }
                }

                p = p->next;
            }
        }
    }

    void DFS(int i, int *visited)

    {

        visited[i] = 1;

        cout << head[i]->city << " ";

        node *temp = head[i]->next;

        while (temp != NULL)

        {

            for (int k = 0; k < n; k++)

            {

                if (temp->city == head[k]->city && visited[k] == 0)

                {

                    DFS(k, visited);

                    break;
                }
            }

            temp = temp->next;
        }
    }
};

int main()

{

    graph obj;

    int n = obj.set_value();

    obj.create();

    cout << "Enter the city you want to start the traversals with: ";

    string cityName;

    cin >> cityName;

    int i = -1;

    for (int j = 0; j < n; j++)

    {

        if (obj.head[j]->city == cityName)

        {

            i = j;

            break;
        }
    }

    if (i == -1)

    {

        cout << "City not found!";

        return 0;
    }

    cout << "BFS traversal: " << endl;

    obj.BFS(i);

    cout << endl;

    cout << "DFS traversal: " << endl;

    int *visited = new int[n];

    for (int j = 0; j < n; j++)

    {

        visited[j] = 0;
    }

    obj.DFS(i, visited);

    delete[] visited;

    return 0;
}


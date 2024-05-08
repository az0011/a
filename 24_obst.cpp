#include<iostream>
#include<climits>
using namespace std;

class node 
{
  	node *lc, *rc;
  	int x;

	public:
	node()
	{
		x =0;
		lc = rc = NULL;
	}
  	node(int a) 
	{
    	x = a;
    	lc = rc = NULL;
  	}
  	friend class obst;
};


class obst
{
    public:
    node *root;
    int n;
    int **c;
    int **w;
    int **r;

        // initialize all elements to 0
    obst(int n)
    {
        this->n=n;

        c = new int*[n];
        w = new int*[n];
        r = new int*[n];
        for(int i = 0; i <n; i++)
        {
            c[i] = new int[n];
            w[i] = new int[n];
            r[i] = new int[n];
        }
        
        for(int i=0;i<n;i++)                   
        {
            for(int j=0;j<n;j++)
            {
                c[i][j]=0;
                w[i][j]=0;
                r[i][j]=0;
            }
        }
    }
        
    public:
    void OBST(int p[],int q[],int st[])
    {
        
        //for 1st row
        for(int i=0;i<n;i++)    
        {
            w[i][i]=q[i];
            c[i][i]=0;
            r[i][i]=0;
        }

        //for all the remaining values of w

        for(int i=1;i<=n;i++)                   
        {
            for(int j=0;j<=n-i;j++)
            {
                w[j][j+i]=w[j][j+i-1]+p[j+i]+q[j+i];
            }
        }

        //for 2nd row
        for(int i=0;i<n;i++)   
        {
            c[i][i+1]=w[i][i+1];
            r[i][i+1]=i+1;
        }


        //for remaining values of c and r i.e. row number 3 onwards
        for(int i = 2; i <= n; i++) 
        {
            for(int j = 0; j <= n - i; j++) 
            {
                int minval = INT_MAX;
                for(int k = j + 1; k <= j + i - 1; k++) 
                {
                    int val = c[j][k - 1] + c[k][j + i] + w[j][j + i];
                    if(val < minval) 
                    {
                        minval = val;
                        r[j][j + i] = k;
                    }
                }
                c[j][j + i] = minval;
            }
        }

        // cout<<c[0][4]<<endl;
        // cout<<w[0][4]<<endl;
        // int keys[]={20,40,60,80};
        // cout<<"The root of OBST is: ";
        // int x=r[0][4];
        // cout<<keys[x-1]<<endl;  
        this->root = this->createTree(0, n-1, r, st);  // IMP 
    }

    node *createTree(int i, int j, int **r, int *st) 
	{
	    if (i != j) 
		{
	      	int k = r[i][j];
	      	node *t = new node(st[k]);
	      	t->lc = createTree(i, k - 1, r, st);
	      	t->rc = createTree(k, j, r, st);
	      	return (t);
	    } 
		else 
		{
	      	return (NULL);
	    }
   	}

  	node *getroot() 
    { 
        return root; 
    }

  	void inorder(node *root) 
	{
	    if (root) 
		{
            inorder(root->lc);
	      	cout << root->x << " ";
	      	inorder(root->rc);
    	}
  	}


};

int main()
{
    int st[] = {0,20,40,60,80};

    int n=5;
    int p[]={0,3,3,1,1};
    int q[]={2,3,1,1,1};
    obst obj(n);
    obj.OBST(p,q,st);
    cout<<"Inorder traversal of OBST is: "<<endl;
    obj.inorder(obj.getroot());
}
#include<iostream>
using namespace std;

class heap_sort
{
    public:

    void maxInsert(int A[],int n) 
    { 
        int i=n;
        int temp; 
        temp=A[n]; //temp has the last element of the array
        while(i>1 && temp>A[i/2])    //compare temp with it's parent
        { 
            A[i]=A[i/2]; 
            i=i/2; 
        } 
        A[i]=temp; 
    } 

    void maxDelete(int A[],int n) 
    { 
        int i,j;
        int temp,val; 
        val=A[1];  //val stores the root which is being deleted
        A[1]=A[n]; //replace the last element of array inplace of root
        A[n]=val; 

        i=1;       //now again make it a max heap
        j=i*2; 
        while(j<=n-1) 
        { 
            if(A[j+1]>A[j]) 
                j=j+1; 
            if(A[i]<A[j]) 
            { 
                temp=A[i]; 
                A[i]=A[j]; 
                A[j]=temp; 
                i=j; 
                j=2*j; 
            } 
            else 
                break; 
        }  
    } 
};

int main()  //complexity O(nlog n)
{  
    int n;
    cout<<"Enter the number of element in the array you want to sort: ";
    cin>>n;
    int H[n+1];
    H[0]=0;


    cout<<"Enter the elements: "<<endl;
    for(int j=1;j<=n;j++)
    {
        cin>>H[j];
    }

    int i; 
    heap_sort obj;
    
    for(i=2;i<=n;i++) 
	{
		obj.maxInsert(H,i); 
	}
	cout<<"\nAfter inserting in max heap is : ";
	for(i=1;i<=n;i++)
	{
		cout<<H[i]<<" ";
	}
	cout<<"\n"; 
	
	int val;
	cout<<"\nSorted Max heap : ";
    for(i=n;i>=2;i--) 
    { 
		obj.maxDelete(H,i); 
    } 
    for(i=1;i<=n;i++)
	{
		cout<<H[i]<<" ";
	}
}





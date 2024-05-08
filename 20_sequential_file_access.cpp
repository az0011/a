#include<iostream>
#include<fstream>
using namespace std;

class student
{
    int roll;
    string name;
    int div;

    public:

    student()
    {
        roll=0;
        name=" ";
        div=0;
    }
    student(int roll, string name, int div)
    {
        this->roll=roll;
        this->name=name;
        this->div=div;
    }

    friend fstream &operator<<(fstream &out1 , student &s)    //to write to file
    {
        out1<<s.roll<<" ";
        out1<<s.name<<" ";
        out1<<s.div<<" ";
        out1<<endl;
        return out1;
    }

    friend ostream &operator<<(ostream &out1 , student &s)    //to print on console, ostream is to write to console, ofstream is to write to file
    {
        out1<<s.roll<<" ";
        out1<<s.name<<" ";
        out1<<s.div<<" ";
        out1<<endl;
        return out1;
    }

    friend fstream &operator>>(fstream &in1, student &s)    //to read from file
    {
        in1>>s.roll;
        in1>>s.name;
        in1>>s.div;
        return in1;
    }

    void display(fstream &file, student &s)
    {
        file.open("file1.txt",ios::in);    //in means open file to read
        while(1)
        {
            file>>s;    
            if(file.eof())
            {
                break;
            }
            cout<<s;
        }
        file.close();
    }

    void search(fstream &file,int x,student &s)
    {
        file.open("file1.txt",ios::in);
        while(1)
        {
            file>>s;
            if(s.roll==x)
            {
                cout<<s;
                break;
            }
            if(file.eof())
            {
                cout<<"Record not found"<<endl;
                break;
            }
        }
        file.close();
    }

    void delete_record(fstream &file, int x, student &s,int n)
    {
        student arr[n];
        file.open("file1.txt",ios::in);
        for(int i=0;i<n;i++)
        {
            file>>s;
            arr[i]=s;
        }
        file.close();

        file.open("file1.txt",ios::out | ios::trunc); //out means make entry in file na dtrunc means destroy old content and replace with new one.
        for(int i=0;i<n;i++)
        {
            if(arr[i].roll==x)
            {
                continue;
            }
            else
            {
                file<<arr[i];
                cout<<arr[i];
            }
        }
        file.close();
    }
};


int main()
{
    student s1;
    int c=1;
    int n;
    fstream myfile;
    while(c>0)
    {
        cout<<"MENU"<<endl;
        cout<<"1.Add record to file"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"Enter your choice:";
        cin>>c;
        if(c==1)
        {
            myfile.open("file1.txt",ios::out);     //out means open for writing
            cout<<"Enter number of entries:";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                int roll;
                string name;
                int div;
                cout<<"Enter roll_no:";
                cin>>roll;
                cout<<"Enter name:";
                cin>>name;
                cout<<"Enter division:";
                cin>>div;
                student s(roll,name,div);

                myfile<<s;                      // write that particular record into file
            }
            myfile.close();
        }
        else if(c==2)
        {
            s1.display(myfile,s1);
        }
        else if(c==3)
        {
            int x;
            cout<<"Enter the roll no to search:";
            cin>>x;
            s1.search(myfile,x,s1);
        }
        else if(c==4)
        {
            int x;
            cout<<"Enter the roll no to delete:";
            cin>>x;
            s1.delete_record(myfile,x,s1,n);
        }
    }
    return 0;
}
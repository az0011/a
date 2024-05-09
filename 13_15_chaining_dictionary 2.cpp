#include <iostream>
using namespace std;
#define size 10

class Node
{
    string word;
    string meaning;
    Node *next;

public:
    Node()
    {
        word = "";
        meaning = "";
        next = NULL;
    }

    Node(string word, string meaning)
    {
        this->word = word;
        this->meaning = meaning;
        next = NULL;
    }
    friend class HashMap;
};

class HashMap
{

    Node *dict[size];

public:
    HashMap()
    {

        for (int i = 0; i < size; i++)
        {
            dict[i] = NULL;
        }
    }

    // Functions
    int getHash(string word)
    {
        int hash = 0;
        for (char ch : word)
        {
            hash += (int)ch;
        }
        return hash % size;
    }

    // Insert to HashTable
    void insert(string word, string meaning)
    {
        Node *new_node = new Node(word, meaning);

        int hash = getHash(word);

        // check if word exists there
        if (dict[hash] == NULL)
        {
            dict[hash] = new_node;
            cout << dict[hash]->word <<" stored at index "<<hash<<endl;
        }
        else
        {
            Node *temp = dict[hash];   //point temp to the segment at index where element is present
            while (temp->next!=NULL)
            {
                temp = temp->next;
                cout << temp->word << endl;
                cout << "Hii" << endl;
            }
            cout << "out" << endl;
            temp->next = new_node;
        }
    }

    // printing the hash table:
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            Node *temp = dict[i];
            cout << i << " -> ";
            while (temp)
            {
                cout << temp->word << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Search Word
    void search(string word)
    {

        int hash = getHash(word);

        for (int i = 0; i < size; i++)
        {
            Node *temp = dict[hash];
            if (temp->word == word)
            {
                cout << "Data found: " << endl;
                cout << temp->word << " - " << temp->meaning << endl;
                return;
            }
            else
            {
                while (temp)
                {
                    if (temp->word == word)
                    {
                        cout << temp->word << " - " << temp->meaning << endl;
                        return;
                    }
                    temp = temp->next;
                }
            }

            hash = hash + 1 % size;
        }
    }

    void delete_word()
    {
        string del;
        cout<<"Enter the word to delete: ";
        cin>>del;

        int hash=getHash(del);
        Node *temp=dict[hash];

        if(temp->word==del)
        {
            dict[hash]=temp->next;
            delete temp;
        }
        else
        {
            Node *q;
            while (temp)
                {
                    if (temp->word == del)
                    {
                        q->next=temp->next;
                        delete temp;
                    }
                    q=temp;
                    temp = temp->next;
                }
        }
    }
};

int main()
{
    cout << "Seperate Hashing" << endl; // prints Hashing
    bool flag = true;

    string word, meaning = "";

    HashMap *hmp = new HashMap();
    

    while (flag)
    {
        int ch;
        cout
            << "\n1. Add Word\n2.Print Dictionary\n3.Search Word\n4.Delete Word\n5.Exit"
            << endl;
        cout << "\nEnter Your Choice: " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter Word: ";
            cin >> word;
            cout << "Enter Meaning: ";
            cin >> meaning;

            hmp->insert(word, meaning);
            break;
        case 2:
            cout << "Dictionary " << endl;
            hmp->print();
            break;
        case 3:
            cout << "Search " << endl;
            cout << "Enter a word to search: ";
            cin >> word;
            hmp->search(word);
            break;
        case 4:
            hmp->delete_word();
            cout << "Deleted" << endl;
            // yet to impliment
            break;
        case 5:
            cout << "Exit..." << endl;
            flag = false;
            break;
        }
    }

    return 0;
}
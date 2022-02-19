#include<iostream>
#include<fstream>
#include "BST.cpp"
using namespace std;

int main()
{
    ifstream inputFile;
    inputFile.open("in2.txt");
    BST<int> myBST;
    while(!inputFile.eof())
    {
        string p;
        inputFile>>p;
        if(p=="F")
        {
            int q;
            inputFile>>q;
            bool r = myBST.find(q);
            if(r)
                cout<<"True\n";
            else
                cout<<"False\n";
        }
        else if(p=="I")
        {
            int q;
            inputFile>>q;
            myBST.insert(q);
            myBST.print();
        }
        else if(p=="D")
        {
            int q;
            inputFile>>q;
            bool r = myBST.remove(q);
            if(r)
                myBST.print();
            else
                cout<<"Invalid Operation\n";
        }
        else if(p=="T")
        {
            string q;
            inputFile>>q;
            myBST.traversal(q);
        }
    }
    inputFile.close();
}

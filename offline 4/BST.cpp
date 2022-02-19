#include "BSTNode.cpp"
#include<string>
#include<iostream>
using namespace std;

template <typename T>
class BST
{
private:
    BSTNode<T>* root;
    int nodecount;
    void deleteAllNode(BSTNode<T>* root)
    {
        if (root == NULL) return;
        deleteAllNode(root->left());
        deleteAllNode(root->right());
        delete root;
    }
    bool findHelp(BSTNode<T>* root, const T& v)
    {
        if (root == NULL) return false;
        else if(root->element()==v) return true;
        else if(root->element() < v) return findHelp(root->right(), v);
        else return findHelp(root->left(), v);
    }
    BSTNode<T>* insertHelp(BSTNode<T>* root, const T& v)
    {
        if(root->element()<v)
        {
            if(root->right()==NULL) return root;
            else return insertHelp(root->right(),v);
        }
        else
        {
            if(root->left()==NULL) return root;
            else return insertHelp(root->left(), v);
        }
    }

    BSTNode<T>* getmax(BSTNode<T>* rt)
    {
        if (rt->right() == NULL)
            return rt;
        else return getmax(rt->right());
    }

    BSTNode<T>* deletemax(BSTNode<T>* rt)
    {
        if (rt->right() == NULL)
            return rt->left();
        else
        {
            rt->setRight(deletemax(rt->right()));
            return rt;
        }
    }

    BSTNode<T>* removehelp(BSTNode<T>* rt, const T& k)
    {
        if (rt == NULL) return NULL;
        else if (k < rt->element())
            rt->setLeft(removehelp(rt->left(), k));
        else if (k > rt->element())
            rt->setRight(removehelp(rt->right(), k));
        else
        {
            BSTNode<T>* temp = rt;
            if (rt->left() == NULL)
            {
                rt = rt->right();
                delete temp;
            }
            else if (rt->right() == NULL)
            {
                rt = rt->left();
                delete temp;
            }
            else
            {
                BSTNode<T>* temp = getmax(rt->left());
                rt->setElement(temp->element());
                rt->setLeft(deletemax(rt->left()));
                delete temp;
            }
        }
        return rt;
    }

    void preorder(BSTNode<T>* root)
    {
        if (root == NULL) return;
        cout<<root->element()<<" ";
        preorder(root->left());
        preorder(root->right());
    }

    void postorder(BSTNode<T>* root)
    {
        if (root == NULL) return;
        postorder(root->left());
        postorder(root->right());
        cout<<root->element()<<" ";
    }
    void inorder(BSTNode<T>* root)
    {
        if (root == NULL) return;
        inorder(root->left());
        cout<<root->element()<<" ";
        inorder(root->right());
    }

    void printhelp(BSTNode<T>* root)
    {
        if (root == NULL) return;
        if(root->isLeaf())
        {
            cout<<root->element();
        }
        else
        {
           cout<<root->element();
           cout<<"(";
           printhelp(root->left());
           cout<<")(";
           printhelp(root->right());
           cout<<")";
        }
    }

public:
    BST()
    {
        root = NULL;
        nodecount = 0;
    }

    BST(const BST<T> &r) //copy constractor
    {
        if(r.root==NULL)
        {
            root = NULL;
        }
        else
        {
            root = new BSTNode<T>(r.element(),r.left(),r.right());
        }
        nodecount = r.nodecount;
    }
    BST& operator=(BST &r) ///Assignment Operator overloading
    {
        if(r.root==NULL)
        {
            root = NULL;
        }
        else
        {
            root = new BSTNode<T>(r.element(),r.left(),r.right());
        }
        nodecount = r.nodecount;
    }
    ~BST()
    {
        deleteAllNode(root);
    }

    bool find(const T& v)
    {
        return findHelp(root,v);
    }
    void insert(const T& v)
    {
        if(root==NULL)
        {
            root = new BSTNode<T>(v);
        }
        else
        {
            BSTNode<T>* p = insertHelp(root,v);
            BSTNode<T>* c = new BSTNode<T>(v);
            if(p->element()<v)
                p->setRight(c);
            else
                p->setLeft(c);
        }
        nodecount++;
    }
    bool remove(const T& v)
    {
        bool r = findHelp(root,v);
        if(r==true)
        {
            root = removehelp(root, v);
            nodecount--;
        }
        return r;
    }

    void traversal(string s)
    {
        if(s=="In")
        {
            inorder(root);
            cout<<endl;
        }
        else if(s=="Pre")
        {
            preorder(root);
            cout<<endl;
        }
        else if(s=="Post")
        {
            postorder(root);
            cout<<endl;
        }
    }
    void print()
    {
        if (root == NULL) cout << "The BST is empty.\n";
        else
        {
            printhelp(root);
            cout<<endl;
        }

    }


    int size()
    {
        return nodecount;
    }
    void clear()
    {
        deleteAllNode(root);
        root = NULL;
        nodecount = 0;
    }

};

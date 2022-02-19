#include<cstddef>
template <typename T>
class BSTNode
{
private:
    T it;
    BSTNode* lc;
    BSTNode* rc;
public:
    BSTNode()
    {
        lc = rc = NULL;
    }
    BSTNode(const T& e, BSTNode* l =NULL, BSTNode* r =NULL)
    {
        it = e;
        lc = l;
        rc = r;
    }
    ~BSTNode() {}
    T& element()
    {
        return it;
    }
    void setElement(const T& e)
    {
        it = e;
    }
    inline BSTNode* left() const
    {
        return lc;
    }
    void setLeft(BSTNode<T>* b)
    {
        lc = b;
    }
    inline BSTNode* right() const
    {
        return rc;
    }
    void setRight(BSTNode<T>* b)
    {
        rc = b;
    }
    bool isLeaf()
    {
        return (lc == NULL) && (rc == NULL);
    }
};

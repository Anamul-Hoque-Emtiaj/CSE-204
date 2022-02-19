class Heap
{
    int cur,*arr;
    int parent(int i)
    {
        return i/2;
    }
    int leftChild(int i)
    {
        return 2*i;
    }
    int rightChild(int i)
    {
        return (2*i) + 1;
    }
    void fixUp(int i)
    {
        int p = parent(i);
        if(p>0 && arr[i]>arr[p])
        {
            int temp = arr[i];
            arr[i] = arr[p];
            arr[p] = temp;
            fixUp(p);
        }
    }
    void fixDown(int i)
    {
        int l = leftChild(i);
        int r = rightChild(i);
        int maxi = i;
        if(l<cur && arr[l]>arr[i])
            maxi = l;
        if(r<cur && arr[r]>arr[maxi])
            maxi = r;
        if(maxi!=i)
        {
            int temp = arr[i];
            arr[i] = arr[maxi];
            arr[maxi] = temp;
            fixDown(maxi);
        }
    }
public:
    Heap(int size)
    {
        cur=1;
        arr = new int[size+1];
    }
    Heap(std::vector<int>&v)
    {
        cur = v.size()+1;
        arr = new int[cur];
        copy(v.begin(),v.end(),arr+1);
        for(int i=cur/2; i>0; i--)
            fixDown(i);
    }
    ~Heap()
    {
        delete []arr;
    }

    void insert(int n)
    {
        arr[cur] = n;
        fixUp(cur++);
    }
    int size()
    {
        return cur-1;
    }
    int getMax()
    {
        return arr[1];
    }
    void deleteKey()
    {
        if(cur>1)
        {
            arr[1] = arr[--cur];
            fixDown(1);
        }
    }
};

void heapsort(std::vector<int>&v)
{
    Heap h(v);
    v.clear();
    int l = h.size();
    for(int i=1; i<=l; i++)
    {
        v.push_back(h.getMax());
        h.deleteKey();
    }
}

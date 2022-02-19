public class Arr <T> implements ListADT<T>{
    private T[] arr;
    private int length;
    private int size;
    private int chunk;
    private int currentPosition;

    ///initializing an empty list assuming the chump size 2 as it is not mentioned for this case
    public Arr() {
        this.arr = (T[]) new Object[5];
        this.length = 5;
        this.chunk = 5;
        this.size = 0;
        this.currentPosition = 0;
    }
    public Arr(T[] a, int K, int X){
        this.arr = (T[]) new Object[X];
        this.length = X;
        this.chunk = X;
        this.size = K;
        this.currentPosition = 0;
        for(int i=0; i<K; i++)
            arr[i] = a[i];
    }
    @Override
    public void clear(){
        this.size = 0;
        this.currentPosition = 0;
        this.arr = (T[]) new Object[length];
    }
    @Override
    public void insert(T item){
        if(size==length){
            T[] a = arr;
            length += chunk;
            arr = (T[]) new Object[length];
            for(int i = 0; i<size; i++){
                arr[i] = a[i];
            }
        }
        for(int i=size-1; i>=currentPosition; i--){
            arr[i+1] = arr[i];
        }
        arr[currentPosition] = item;
        size++;
    }
    @Override
    public void append(T item){
        if(size==length){
            T[] a = arr;
            length += chunk;
            arr = (T[]) new Object[length];
            for(int i = 0; i<size; i++){
                arr[i] = a[i];
            }
        }
        arr[size++] = item;
    }
    @Override
    public T remove(){
        if(currentPosition>=0 && currentPosition<size){
            T r = (T) arr[currentPosition];
            for(int i=currentPosition; i<size-1; i++){
                arr[i] = arr[i+1];
            }
            size--;
            if(size==currentPosition)
                currentPosition--;
            return r;
        }
        else
            return null;
    }
    @Override
    public void moveToStart(){
        currentPosition = 0;
    }
    @Override
    public void moveToEnd(){
        currentPosition = size-1;
    }
    @Override
    public void prev(){
        if(currentPosition!=0)
            currentPosition--;
    }
    @Override
    public void next(){
        if(currentPosition!=size-1)
            currentPosition++;
    }
    @Override
    public int length(){
        return size;
    }
    @Override
    public int currPos(){
        return currentPosition;
    }
    @Override
    public void moveToPos(int pos){
        if(pos>=0 && pos<size)
            currentPosition = pos;
    }
    @Override
    public T getValue(){
        return (T) arr[currentPosition];
    }
    @Override
    public int Search(T item){
        int f=-1;
        for(int i=0; i<size; i++){
            if(arr[i]==item){
                f = i;
                break;
            }
        }
        return f;
    }
}

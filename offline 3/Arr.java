public class Arr<T> implements QueueADT<T>{
    private static final int defaultSize = 10;
    private int maxSize;
    private int front;
    private int rear;
    private T [] listArray;

    public Arr() {
        this.maxSize = defaultSize;
        front = 1;
        rear = 0;
        listArray = (T[])new Object[maxSize];
    }
    public Arr(int Size) {
        this.maxSize = Size+1;
        front = 1;
        listArray = (T[])new Object[maxSize];
        rear = 0;
    }

    public Arr(T[] arr){
        rear = 0;
        listArray = arr;
        maxSize = arr.length;
        front = 1;
    }

    private void extendMemory(){
        T[] t = listArray;
        int l = maxSize;
        maxSize = 2*maxSize;
        listArray = (T[])new Object[maxSize];
        int c=1;
        for (int i = front; i<l; i++){
            listArray[c++] = t[i%l];
        }
        front = 1;
        rear = l - 1;
    }
    @Override
    public void clear() {
        rear = 0;
        front = 1;
    }

    @Override
    public void enqueue(T it) {
        if(((rear+2) % maxSize) == front){
            extendMemory();
        }
        rear = (rear+1) % maxSize; // Circular increment
        listArray[rear] = it;

    }

    @Override
    public T dequeue() {
        if(length()==0)
            return null;
        else{
            T it = listArray[front];
            front = (front+1) % maxSize; // Circular increment
            return it;
        }
    }

    @Override
    public T frontValue() {
        if(length()==0)
            return null;
        else{
            return listArray[front];
        }
    }

    @Override
    public T rearValue() {
        if(length()==0)
            return null;
        else{
            return listArray[rear];
        }
    }

    @Override
    public int length() {
        return ((rear+maxSize) - front + 1) % maxSize;
    }

    @Override
    public T leaveQueue() {
        if(length()==0)
            return null;
        else{
            T it = listArray[rear];
            rear-=1; // Circular increment
            return it;
        }
    }
}

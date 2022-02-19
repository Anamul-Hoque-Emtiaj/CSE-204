public class Arr <T> implements StackADT<T>{
    private static final int defaultSize = 10;
    private int maxSize; // Maximum size of stack
    private int top; // Index for top Object
    private int length;
    private int direction;
    private T [] listArray;

    public Arr() {
        this.maxSize = defaultSize;
        top = 0;
        length = 0;
        direction = 1;
        listArray = (T[])new Object[maxSize];
    }
    public Arr(int maxSize) {
        this.maxSize = maxSize;
        top = 0;
        length = 0;
        listArray = (T[])new Object[maxSize];
        direction = 1;
    }

    public Arr(T[] arr, int length){
        direction = 1;
        listArray = (T[])new Object[length];;
        maxSize = arr.length ;
        this.length = length;
        top = length;
        for(int i=0; i<length; i++)
            listArray[i] = arr[i];
    }

    public Arr(T[] arr, int length, int d){
        direction = d;
        listArray = arr;
        maxSize = length ;
        this.length = 0;
        if(d==1)
            top = 0;
        else
            top = maxSize-1;
    }

    @Override
    public void clear() {
        length = 0;
        top = 0;
        listArray = (T[])new Object[maxSize];
    }

    @Override
    public void push(T it) {
        if(length==maxSize){
            T[] a = listArray;
            maxSize *= 2;
            listArray = (T[]) new Object[maxSize];
            if(direction==1){
                for(int i = 0; i<length; i++){
                    listArray[i] = a[i];
                }
            }
            else {
                for(int i = 0; i<length; i++){
                    listArray[i+length] = a[i];
                }
                top = length-1;
            }
        }
        listArray[top] = it;
        length++;
        if(direction==1)
            top++;
        else
            top--;
    }

    @Override
    public T pop() {
        assert length != 0 : "Stack is empty";
        if(direction==1){
            length--;
            return listArray[--top];
        }
        else {
            length--;
            return listArray[++top];
        }
    }

    @Override
    public T topValue() {
        assert length != 0 : "Stack is empty";
        if(direction==1)
            return listArray[top-1];
        else
            return listArray[top+1];
    }

    @Override
    public int length() {
        return length;
    }

    @Override
    public void setDirection(int direction) {
        assert length == 0 : "Stack is not empty";
        clear();
        this.direction = direction;
        if(direction==-1){
            top = maxSize-1;
        }else{
            top = 0;
        }
    }
}

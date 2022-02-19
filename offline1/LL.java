class node<T> {
    public node() {
        this.value = null;
        this.next = null;
        this.prev = null;
    }

    T value;
    node<T> next,prev;
}
public class LL <T> implements ListADT<T>{
    node<T> head,tail;
    private int size;
    private int currentPosition;

    ///initializing an empty list
    public LL(){
        head = new node<>();
        tail = new node<>();
        this.size = 0;
        this.currentPosition = 0;
    }
    public LL(T[] a, int K, int X){
        head = new node<>();
        tail = new node<>();
        head.value = a[0];
        node<T> cur = head;
        for(int i=1; i<K; i++){
            node<T> t = new node<>();
            t.value = a[i];
            t.prev = cur;
            cur.next = t;
            cur = t;
        }
        tail = cur;
        currentPosition = 0;
        size = K;
    }

    @Override
    public void clear() {
        head = new node<>();
        tail = new node<>();
        currentPosition = 0;
        size = 0;
    }

    @Override
    public void insert(T item) {
        if(size==0){
            node<T> t = new node<>();
            t.value = item;
            head = t;
            tail = t;
            size++;
        }
        else{
            node<T> cur = head;
            for(int i=1; i<=currentPosition; i++){
                cur = cur.next;
            }
            node<T> t = new node<>();
            t.value = item;
            t.prev = cur.prev;
            t.next = cur;
            cur.prev.next = t;
            cur.prev = t;
            size++;
        }

    }

    @Override
    public void append(T item) {

        if(size==0){
            node<T> t = new node<>();
            t.value = item;
            head = t;
            tail = t;
            size++;
        }
        else{
            node<T> t = new node<>();
            t.value = item;
            t.prev = tail;
            tail.next = t;
            tail = t;
            size++;
        }
    }

    @Override
    public T remove() {
        if(currentPosition>=0 && currentPosition<size){
            node<T> cur = head;
            for(int i=1; i<=currentPosition; i++){
                cur = cur.next;
            }
            cur.prev.next = cur.next;
            cur.next.prev = cur.prev;
            size--;
            if(size==currentPosition) {
                currentPosition--;
                tail = tail.prev;
            }
            return cur.value;
        }
        else
            return null;
    }

    @Override
    public void moveToStart() {
        currentPosition = 0;
    }

    @Override
    public void moveToEnd() {
        currentPosition = size-1;
    }

    @Override
    public void prev() {
        if(currentPosition!=0)
            currentPosition--;
    }

    @Override
    public void next() {
        if(currentPosition!=size-1)
            currentPosition++;
    }

    @Override
    public int length() {
        return size;
    }

    @Override
    public int currPos() {
        return currentPosition;
    }

    @Override
    public void moveToPos(int pos) {
        if(pos>=0 && pos<size)
            currentPosition = pos;
    }

    @Override
    public T getValue() {
        node<T> cur = head;
        for(int i=1; i<=currentPosition; i++){
            cur = cur.next;
        }
        return cur.value;
    }

    @Override
    public int Search(T item) {
        int f=-1;
        node<T> cur = head;
        for(int i=0; i<size; i++){
            if(cur.value==item){
                f = i;
                break;
            }
            cur = cur.next;
        }
        return f;
    }
}

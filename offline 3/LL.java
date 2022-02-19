class node<T> {
    T value;
    node<T> next;
    public node() {
        this.value = null;
        this.next = null;
    }
}
public class LL<T> implements QueueADT<T>{
    private node<T> front; // Pointer to front queue node
    private node<T> rear; // Pointer to rear queuenode
    private int size;
    public LL(){
        front = rear = new node<T>();
        size = 0;
    }
    public LL(int size){
        front = rear = new node<T>();
        this.size = 0;
    }
    @Override
    public void clear() {
        front = rear = new node<T>();
        size = 0;
    }

    @Override
    public void enqueue(T it) {
        node<T> t = new node<>();
        t.value = it;
        rear.next = t;
        rear = t;
        size++;
        if(size==1)
            front = rear;
    }

    @Override
    public T dequeue() {
        if(size==0)
            return null;
        else{
            T t = front.value;
            front = front.next;
            size--;
            return t;
        }
    }

    @Override
    public T frontValue() {
        if(size==0)
            return null;
        else
            return front.value;
    }

    @Override
    public T rearValue() {
        if(size==0)
            return null;
        else
            return rear.value;
    }

    @Override
    public int length() {
        return size;
    }

    @Override
    public T leaveQueue() {
        if(size==0)
            return null;
        else if(size==1){
            T t = front.value;
            clear();
            size--;
            return t;
        }
        else{
            node<T> cur = front;
            while (true){
                if(cur.next==rear)
                    break;
                cur = cur.next;
            }
            T t = rear.value;
            rear = cur;
            size--;
            return t;
        }
    }
}

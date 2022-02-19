class node<T> {
    T value;
    node<T> next;
    public node() {
        this.value = null;
        this.next = null;
    }
}
public class LL<T> implements StackADT<T> {
    private int length;
    private node<T> head;

    public LL() {
        length = 0;
        head = new node<>();
    }

    public LL(T[] arr,int length){
        this.length =  length;
        head = new node<>();
        head.value = arr[length-1];
        node<T> cur = head;
        for(int i=length-2; i>=0; i--){
            node<T> t = new node<>();
            t.value = arr[i];
            cur.next = t;
            cur = t;
        }
    }

    @Override
    public void clear() {
        length = 0;
        head = new node<>();
    }

    @Override
    public void push(T it) {
        node<T> t = new node<>();
        t.value = it;
        t.next = head;
        head = t;
        length++;
    }

    @Override
    public T pop() {
        assert length != 0 : "Stack is empty";
        T r = head.value;
        head = head.next;
        length--;
        return r;
    }

    @Override
    public T topValue() {
        assert length != 0 : "Stack is empty";
        return head.value;
    }

    @Override
    public int length() {
        return length;
    }

    @Override
    public void setDirection(int direction) {

    }
}

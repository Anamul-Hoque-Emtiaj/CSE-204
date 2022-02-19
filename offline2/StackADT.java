public interface StackADT <T>{
    public void clear();
    public void push(T it);
    public T pop();
    public T topValue();
    public int length();
    public void setDirection(int direction);
}

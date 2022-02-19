public interface QueueADT<T> {
    /** Reinitialize the queue. The user is responsible for
     reclaiming the storage used by the queue elements. */
    public void clear();
    /** Place an element at the rear of the queue.
     @param it The element being enqueued. */
    public void enqueue(T it);
    /** Remove and return element at the front of the queue.
     @return The element at the front of the queue. */
    public T dequeue();
    /** @return The front element. */
    public T frontValue();
    /** @return The rear element. */
    public T rearValue();
    /** @return The number of elements in the queue. */
    public int length();
    /** Remove and return element at the rear of the queue.
     @return The element at the rear of the queue. */
    public T leaveQueue();
}

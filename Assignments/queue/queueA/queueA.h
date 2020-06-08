
class Queue
{
  private:
    int front, rear, capacity;
    int *queue;
  public:
    Queue(int capacity);
    ~Queue();
    void enqueue(int data);
    int dequeue();
    bool is_empty();
};

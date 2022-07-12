class Queue {
public:
    //data members humare
    int *arr;
    int qfront;
    int rear;
    int size;
    
    Queue() {
        //size ni mil rha jb queue call hoga so we declare large array
        size=1000000;
        arr=new int[size];
        qfront=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return qfront==rear;
    }

    void enqueue(int data) {
        arr[rear]=data;
        rear++;
    }

    int dequeue() {
        if(qfront==rear)return -1;
        else{
            int v=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return v;
        }
    }

    int front() {
        if(qfront==rear)return -1;
        else{
            return arr[qfront];
        }
    }
};

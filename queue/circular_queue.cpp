class CircularQueue{
    public:
    // Initialize your data structure.
    int *arr;
    int front;
    int rear;
    int size;
    CircularQueue(int n){
        // Write your code here.
        size=n;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((front==0 and rear==size-1) or (rear==(front-1))){
            //ya to front 0 pr ho and same time pr rear last pr ho to list full hai
            //or rear ya to front se ek phle ho ghum ke aage aagi ho  ( [_ _ _ R F _ _ _] )
            return false;
        }
        else if(front==-1){
            //phla hi element aa rha hai aane do
            front=0;
            rear=0;
        }
        else if(rear==size-1 and front!=0){
            //rear last pr ho ab push aage se hoga 0 index se
            rear=0;
        }
        else{
            //ye to normal case hai rear ko aage kro and element daal do
            rear++;
        }
        arr[rear]=value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
//         cout<<"front "<<arr[front]<<endl;
        if(front==-1)return -1;//empty ho to :)
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){//agr single element present ho 
            front=rear=-1;
        }
        else if(front==size-1){//if front in on last index
            front=0;
        }
        else{//normal case
            front++;
        }
        return ans;
    }
};

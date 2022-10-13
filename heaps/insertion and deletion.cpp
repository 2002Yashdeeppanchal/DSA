class heap{
    
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size++;
        int indx=size;
        arr[indx]=val;
        while(indx>1){
            int parentindx=indx/2;
            if(arr[parentindx]<arr[indx]){
                swap(arr[parentindx],arr[indx]);
                indx=parentindx;
            }
            else{
                return;
            }
        }
    }

    void deletefromheap(){
        if(size==0){
            cout<<"kya hi delete kroge bhaiii";
        }

        arr[1]=arr[size];//root ki jgh last right node daal di and size ko -- krdo isse     this is same as swap lastright node to root and then delete 
        size--;

        int indx=1;
        while(indx<size){
            int leftchildindx=2*indx;
            int rightchildindx=(2*indx)+1;
            if(leftchildindx<size and arr[leftchildindx]>arr[indx]){
                swap(arr[leftchildindx],arr[indx]);
                indx=leftchildindx;
            }
            else if(rightchildindx<size and arr[rightchildindx]>arr[indx]){
                swap(arr[indx],arr[rightchildindx]);
                indx=rightchildindx;
            }
            else{
                //sb shi hai to chlo bhaii
                return;
            }
        }

    }

    void printheap(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl<<endl;
    }
};

void heapify(int arr[],int n,int i){
    //arr jisko heap me convert krna hai
    //n size hai uska
    //i th element jisko uski shi jgh pr pauchana hai arr me

    int currlargest=i;//currently largest among arr[i](jisko shi jgh lgana hai vo) or usko dono child me 
    int leftchildindx=2*i;
    int rightchildindx=(2*i)+1;

    if(leftchildindx<=n and arr[i]<arr[leftchildindx]){
        currlargest=leftchildindx;
    }
    if(rightchildindx<=n and arr[rightchildindx]>arr[i]){
        currlargest=rightchildindx;
    }

    if(currlargest!=i){
        //some change is happen either leftchild is greater or rightchild is greater than the element(jisko shi jgh lagna hai)
        swap(arr[i],arr[currlargest]);
        heapify(arr,n,currlargest);//further shi jgh neeche dekh ke(neeche ke subtrees pr hi condition match krane ke liye)
    }

}

void heapsort(int arr[],int n){

    int cursize=n;

    while(cursize>1){
        //step one : swap arr[n](last node) and root(arr[1])
        swap(arr[1],arr[cursize]);

        //step two : root jo ab last node hai shi jgh
        cursize--;
        heapify(arr,cursize,1);
    }

} 

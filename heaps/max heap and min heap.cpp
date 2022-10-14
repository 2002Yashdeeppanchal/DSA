//max heap

void heapify(int arr[],int n,int i){
    //arr jisko heap me convert krna hai
    //n size hai uska
    //i th element jisko uski shi jgh pr pauchana hai arr me

    int currlargest=i;//currently largest among arr[i](jisko shi jgh lgana hai vo) or usko dono child me 
    int leftchildindx=2*i;
    int rightchildindx=(2*i)+1;

    if(leftchildindx<=n and arr[currlargest]<arr[leftchildindx]){
        currlargest=leftchildindx;
    }
    if(rightchildindx<=n and arr[rightchildindx]>arr[currlargest]){
        currlargest=rightchildindx;
    }

    if(currlargest!=i){
        //some change is happen either leftchild is greater or rightchild is greater than the element(jisko shi jgh lagna hai)
        swap(arr[i],arr[currlargest]);
        heapify(arr,n,currlargest);//further shi jgh neeche dekh ke(neeche ke subtrees pr hi condition match krane ke liye)
    }

}


//min heap

void heapify(int arr[],int n,int i){
    //arr jisko heap me convert krna hai
    //n size hai uska
    //i th element jisko uski shi jgh pr pauchana hai arr me

    int currsmallest=i;//currently largest among arr[i](jisko shi jgh lgana hai vo) or usko dono child me 
    int leftchildindx=2*i;
    int rightchildindx=(2*i)+1;

    if(leftchildindx<=n and arr[currsmallest]>arr[leftchildindx]){
        currsmallest=leftchildindx;
    }
    if(rightchildindx<=n and arr[rightchildindx]<arr[currsmallest]){
        currsmallest=rightchildindx;
    }

    if(currlargest!=i){
        //some change is happen either leftchild is smaller or rightchild is smaller than the element(jisko shi jgh lagna hai)
        swap(arr[i],arr[currsmallest]);
        heapify(arr,n,currsmallest);//further shi jgh neeche dekh ke(neeche ke subtrees pr hi condition match krane ke liye)
    }

}

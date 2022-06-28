int answer(vector<int> &v,int n,int m){
    //if students are greater than the number of books
    if(m>n){
        return -1;
    }
    int sum=0;
    for(auto e : v){
        sum+=e;
    }


//iterating over the number of pages zero to the sum of all pages of all books

    int l=0;
    int r=sum;

    int ans=INT_MAX;
    while(r>=l){
        int mid= (l+r)/2;
        if(ispossiblesol(v,n,m,mid)){
            ans=min(ans,mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}


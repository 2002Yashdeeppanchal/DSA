int lowerbound(vector<int>v,int k){
    int begin=0;
    int end=v.size()-1;
    while(begin<=end){
        int mid=begin+(end-begin)/2;
        if(v[mid]<k){
            begin=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    if(begin==v.size()){
        return -1;
    }
    return begin;
}

int upperbound(vector<int>v,int k){
    int begin=0;
    int end=v.size()-1;
    while(begin<=end){
        int mid=begin+(end-begin)/2;
        if(v[mid]<=k){
            begin=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    while(v[begin]==k){
        begin++;
    }
    if(begin==v.size()){
        return -1;
    }
    return begin;
}

first simply find the peakind and then first search in the left half if not found then search in the right half


int peakindex(MountainArray &mountainArr){
        
        int begin=1;
        int end=mountainArr.length()-2;
        
        while(begin<=end){
            int mid=begin+(end-begin)/2;
            
            int valatmid=mountainArr.get(mid);
            int valatmidmo=mountainArr.get(mid-1);
            int valatmidpo=mountainArr.get(mid+1);
            
            if(valatmid>valatmidmo and valatmid>valatmidpo){
                return mid;
            }
            if(valatmid>valatmidmo and valatmid<valatmidpo){
                begin=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
    
    int findleft(MountainArray &mountainArr,int start,int over,int target){
        int begin=start;
        int end=over;
        int ans=-1;
        while(begin<=end){
            int mid=begin+(end-begin)/2;
            int valatmid=mountainArr.get(mid);
            if(valatmid==target){
                ans=mid;
            }
            if(valatmid<target){
                begin=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
    
    int findright(MountainArray &mountainArr,int start,int over,int target){
        int begin=start;
        int end=over;
        int ans=-1;
        while(begin<=end){
            int mid=begin+(end-begin)/2;
            int valatmid=mountainArr.get(mid);
            if(valatmid==target){
                ans=mid;
            }
            if(valatmid<target){
                end=mid-1;
            }
            else{
                begin=mid+1;
            }
        }
        return ans;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int peakind=peakindex(mountainArr);
        // cout<<"peakind "<<peakind<<endl;
        
        int leftind=findleft(mountainArr,0,peakind,target);
        // cout<<"leftind "<<leftind<<endl;
        if(leftind!=-1)return leftind;
        
        int rightind=findright(mountainArr,peakind,mountainArr.length()-1,target);
        // cout<<"rightind "<<rightind<<endl;
        return rightind;
    }

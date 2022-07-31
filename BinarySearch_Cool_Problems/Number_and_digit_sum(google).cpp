long long int numberCount(long long int N, long long int K)
        {
            long long int begin=0;
            long long int end=N;
            
            while(begin<=end){
                long long mid=begin+(end-begin)/2;
                long long val=(mid/10)*9;
                if(val<K){
                    begin=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            
            // if(begin>N)return 
            
            return N-begin+1;
        }


https://practice.geeksforgeeks.org/problems/number-and-the-digit-sum4021/1

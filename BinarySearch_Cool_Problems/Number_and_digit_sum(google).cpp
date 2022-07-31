oberve that 0-9 numbers give val as 0
            10-19 gives 10/10*9=9
            20-29    18
            30-39    27
            40-49    36
            .
            .
            100-109  99

        
first find the trashhold number(first number) which give the val greater than equal to K than simply note that all number gives greater than or equal val to K 



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

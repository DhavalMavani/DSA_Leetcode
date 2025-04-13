class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){

            string strNum=to_string(i);

            if(strNum.size()%2) continue;
            else{
                int n1=0, n2=0, num=i, n=strNum.size()/2;

                for(int i=0;i<n;i++){
                    n1+= num%10;
                    num/=10;
                }

                for(int i=0;i<n;i++){
                    n2+= num%10;
                    num/=10;
                }
                if(n1==n2) ans++;
            }
        }
        return ans;
    }
};
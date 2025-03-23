class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size(), l=0,r=n-1, capA=capacityA, capB=capacityB, refil=0;

        while(l<=r){
            if(l==r){
                if(capA>=plants[l] || capB>=plants[r]) return refil;
                else return refil+1;
            }
            else{
                if(capA>=plants[l] ) capA-=plants[l], l++;
                else  capA=capacityA-plants[l], refil++,l++;

                if(capB>=plants[r] ) capB-=plants[r], r--;
                else  capB=capacityB-plants[r], refil++,r--;
            }
        }

        return refil;
    }
};
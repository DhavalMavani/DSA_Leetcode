class Solution {
public:
    string ones[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string helper(int num){
        string ans;

        if(num%100>=20){
            ans+= ones[num%10] ;
            num/=10;
            if(num%10){
                string temp= tens[num%10];
                if(!ans.empty()) ans=temp+" "+ans;
                else ans=temp;
            } 
        } 
        else{
            ans= ones[num%100];
            num/=10;
        }
        num/=10;

        if(num){
            string temp= ones[num] + " Hundred";
            if(!ans.empty()) ans=temp+" "+ans;
            else ans=temp;
        } 

        return ans;
    }

    string numberToWords(int num) {
        if(num==0) return "Zero";

        string ans;
    
        if(num%1000) ans+= helper(num%1000);
        num/=1000;
        
        if(num%1000){
            string temp= helper(num%1000)+" Thousand";
            if(!ans.empty()) ans=temp+" "+ans;
            else ans=temp;
        } 
        num/=1000;

        if(num%1000){
            string temp= helper(num%1000) + " Million";
            if(!ans.empty()) ans=temp+" "+ans;
            else ans=temp;
        } 
        num/=1000;
        
        if(num%1000){
            string temp= helper(num%1000) + " Billion";
            if(!ans.empty()) ans=temp+" "+ans;
            else ans=temp;
        } 
        
        return ans;
    }
};
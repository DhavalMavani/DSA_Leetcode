class Solution {
public:
    unordered_map<int, string> numToString = {
        {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
        {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"},
        {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"},
        {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"},
        {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"},
        {19, "Nineteen"},

        {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"},
        {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"},
        {80, "Eighty"}, {90, "Ninety"}
    };

    string helper(int num){
        string ans;

        if(num%100>20 && num%10){
            ans+= numToString[num%10] ;
            num-=num%10;
            if(num%100) ans= numToString [num%100]+" "+ans ; 
        } 
        else ans= numToString[num%100];

        num/=100;

        if(num){
            string temp= numToString[num] + " Hundred";
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
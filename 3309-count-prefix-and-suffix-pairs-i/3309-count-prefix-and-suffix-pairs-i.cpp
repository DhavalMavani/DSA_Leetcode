class trieNode{
public:
    unordered_map<int,trieNode*> child;
    int count;
    trieNode(){ count=0; }
};

class Solution {
public:
    trieNode* head;
    Solution(){ head=new trieNode(); }

    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(auto &word: words){
            int n=word.size();
            trieNode* curr=head;
            for(int i=0;i<n;i++){
                int nodeNum=word[i]*128+word[n-1-i];
                if(!curr->child.count(nodeNum)) curr->child[nodeNum]=new trieNode();
                curr=curr->child[nodeNum];
                ans+=curr->count;
            }
            curr->count++;
        }
        return ans;
    }
};
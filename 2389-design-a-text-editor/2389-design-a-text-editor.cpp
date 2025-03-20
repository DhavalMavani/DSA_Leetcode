class TextEditor {
public:
    string left, right;
    
    void addText(string text) { left+=text; }
    
    int deleteText(int k) {
        int ind=max((int)left.size()-k,0);
        int ans=left.size()-ind;
        left.erase(ind);
        return ans;
    }
    
    string cursorLeft(int k) {
        while(!left.empty() && k--){
            right+=left.back();
            left.pop_back();
        }
        int ind=max((int)left.size()- 10,0);
        return left.substr(ind);
    }
    
    string cursorRight(int k) {
        while(!right.empty() && k--){
            left+=right.back();
            right.pop_back();
        }
        int ind=max((int)left.size()- 10,0);
        return left.substr(ind);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
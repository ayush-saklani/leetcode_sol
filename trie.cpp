#include<iostream>
using  namespace std;   
class trie_node{
    trie_node * child[26];
    public:
    bool isword;
    trie_node(){
        for (int i = 0; i < 26; i++){
            child[i]=NULL;
        }
        isword=false;
    }
    void insert(string str,trie_node* root){
        int n = str.length();
        trie_node* t=root;
        for(int i =0;i<n;i++){
            if(root->child[str[i]-'a']==NULL){
                trie_node* temp = new trie_node();
                root->child[str[i]-'a']=temp;
                root=root->child[str[i]-'a'];
            }
            else{
                root=root->child[str[i]-'a'];
            }
        }
        root->isword=true;
    }
    void check(string str,trie_node* root){
        int n = str.length();
        for(int i =0;i<n;i++){
            if(!root->child[str[i]-'a']){
                cout<<root->isword<<" ";
                cout<<"word doesn't exists"<<endl;
                return;
            }
            else{
                cout<<root->isword<<" ";
                root=root->child[str[i]-'a'];
            }
        }
        if(root->isword==true){
            cout<<root->isword<<" "<<endl;
            cout<<"word exists"<<endl;
        } 
        else if(root->isword==false){
            cout<<root->isword<<" "<<endl;
            cout<<"word doesn't exists"<<endl; 
        }
    }
    void false_delete_word(string str,trie_node* root,int it){
        int n = str.length();
        if(root==NULL && it<=n){
            cout<<"word doesn't exist"<<endl;
            return;
        }
        if(it!=n){
            false_delete_word(str,root->child[str[it]-'a'],it+1);
        }
        else{
            root->isword=false;
            return ;
        }
    }
    bool checker(trie_node* root){
        if(root->isword==true) return false;
        for (int i = 0; i < 26; i++){
            if(root->child[i]){
                    return false; //child hai to delete nahi karna hai i.e false
                // if(root->child[i]->isword==true){
                // }
            }
        }
        return true;
    }
    bool true_delete_word(string str,trie_node* root,int it){ /// still pending true node delete 
        int n = str.length();
        int flag;
        if(root==NULL && it<=n){
            cout<<"word doesn't exist"<<endl;
            return false; 
        }
        if(it!=n){
            cout<<root->isword<<" ";
            flag = true_delete_word(str,root->child[str[it]-'a'],it+1);
        }
        else{
            cout<<root->isword<<" "<<endl;
            root->isword=false;
            bool checking = checker(root);
            if(checking == false)return  false;
            else {
                delete(root);
                return true;
            }
        }
        if(flag==true){
            root->child[str[it]-'a']=NULL;
            bool checking = checker(root);
            if(checking == false)return  false;
            else {
                delete(root);
                return true;
            }
        }
        else{
            return false;
        }
    }
};
int main(){
    trie_node* root = new  trie_node();
    root->isword=true;
    int choice;
    cout<<"press 1 for enter"<<endl;
    cout<<"press 2 for delete"<<endl;
    cout<<"press 3 for check"<<endl;
    cout<<"press 4 for false delete"<<endl;
    string str;
    while(1) {
        cout<<"choice ";
        cin>>choice;
        cin>>str;
        switch (choice){
        case 1:
            root->insert(str,root);
            break;
        case 2:
            root->true_delete_word(str,root,0);
            break;
        case 3:
            root->check(str,root);
            break;
        case 4:
            root->false_delete_word(str,root,0);
            break;
        default:
            cout<<"invalid choice";
            return false;
            break;
        }
    }
    return 0;
}
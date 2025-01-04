#include<bits/stdc++.h>
using namespace std;
vector<string> split(string name){
    vector<string> res;
    string temp = "";
    for(int i = 0; i < name.length(); i++){
        if(name[i] == '|'){
            res.push_back(temp);
            temp = "";
        }
        else{
            temp += name[i];
        }
    }
    res.push_back(temp);
    string temper = res[1];
    res.pop_back();
    temp  = "";
    for(int i =0;i<temper.length();i++){
        if(temper[i] == ' '){
            res.push_back(temp);
            temp = "";
        }
        else{
            temp += temper[i];
        }
    }
    res.push_back(temp);
    for(int i = 0; i < res.size(); i++){
        transform(res[i].begin(), res[i].end(), res[i].begin(), ::tolower);
    }
    return res;
}
vector<string> remove_white_space(vector<string> v){
    for(int i = 1 ; i < v.size(); i++){
        string temp = "";
        for(int j = 0; j < v[i].length(); j++){
            if(v[i][j] != ' '){
                temp += v[i][j];
            }
        }
        v[i] = temp;
    }
    return v;
}
vector<string> remove_kachra(vector<string>v){
    for(int i = 1 ; i < v.size(); i++){
        for(int j = 0; j < v[i].length(); j++){
            if(v[i][j] == ','|| v[i][j] == '%' || v[i][j] == '&'){
                v[i][j] = ' ';
            }
        }
    }
    return v;
}
vector<string> remove_prefix(vector<string> v){
    if(v[1] == "the" || v[1] == "an" || v[1] == "a"){
        v.erase(v.begin() + 1);
    }
    return v;
}
vector<string> remove_postfix(vector<string> v){
    int size = v.size()-1;
    if(v[size] == "inc" || v[size] == "llc" || v[size] == "co" || v[size] == "l.l.c." || v[size] == "ll.l.c" || v[size]=="i.n.c" || v[size] == "ltd"){
        v.pop_back();
    }
    return v;
}
string make_company_name(vector<string> v){
    string res_temp = "";
    for(int i = 1; i < v.size(); i++){
        res_temp += v[i];
        if(i != v.size()-1){
            res_temp += " ";
        }
    }
    return res_temp;
}
void display(vector<string> v){
    cout<<endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}
bool standard_operating_procedure(string s,unordered_map<string,bool> &map){
    // cout << s << " ";
    vector<string> v ;
    v = split(s);
    v = remove_kachra(v);
    v = remove_white_space(v);
    v = remove_prefix(v);
    v = remove_postfix(v);
    display(v);
    string res_temp = make_company_name(v);
    if(map[res_temp]){
        return false;
    }
    map[res_temp] = true;
    return true;
}
int main(){
    unordered_map<string,bool> map;
    /*******************pre written testcases********************/
    vector<string> test_cases = {
        "a6sd4as5das4|the& alpha beta, inc",
        "a6sd4as5daas|the& ALPHA beta inc",
        "b7sd5as6das5|an& gamma delta, llc",
        "c8sd6as7das6|a& epsilon zeta, co",
        "d9sd7as8das7|the& eta theta, l.l.c.",
        "e0sd8as9das8|an& iota kappa, ll.l.c",
        "f1sd9as0das9|a& lambda mu, i.n.c",
        "g2sd0as1das0|the& nu xi, ltd",
        "h3sd1as2das1|omicron pi, inc",
        "i4sd2as3das2|rho sigma, llc",
        "j5sd3as4das3|tau upsilon, co"
    };
    int n = test_cases.size();
    for(int i =0;i<n;i++){
        bool res = standard_operating_procedure(test_cases[i],map);
        cout<<res<<endl;
    }
    /*******************pre written testcases********************/


    /*******************debugging********************/
    // string name = "a6sd4as5das4|the& lamah asjdask,  inc";
    // standard_operating_procedure(name,map);
    // return 0;
    /*******************debugging********************/
    
    /***********user will enter testcase *************/
    // int n;
    // cout<< "enter number of input"<<endl;
    // cin>>n;
    // string s;
    // for(int i =0;i<n;i++){
        // cout<<"enter string"<<endl;
        // getline(cin,s);
        // bool res = standard_operating_procedure(s,map);
        // cout<<res<<endl;
    // }
    /*******************user will enter********************/
    return 0;
}
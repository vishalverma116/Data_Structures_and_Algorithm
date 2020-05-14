#include<bits/stdc++.h>
using namespace std;

void pass(vector<int>& nums,int i,set<vector<int> >& s,vector<int> temp){
    if(i == nums.size()){
            s.insert(temp);
            return;
        }
        pass(nums,i+1,s,temp);
        
        temp.push_back(nums[i]);
        //temp.pop_back();
        pass(nums,i+1,s,temp);
}

vector<vector<int> > subset(vector<int>& nums){
    vector<vector<int> > v;
    vector<int> temp;
    sort(nums.begin(),nums.end());
    set<vector<int> > s;
    pass(nums,0,s,temp);
    copy(s.begin(),s.end(),v.begin());
    return v;
}

int main(){
    vector<int> nums = {1,2,2};
    vector<vector<int> > res;
    res = subset(nums);
    for(auto v: res){
        if(res.size() == 0){
            cout<<"[]";
        }
        else{
            vector<int> temp;
            for(auto i:v){
                temp.push_back(i);
            }
            cout<<"[";
            for(int i=0;i<temp.size()-1;i++){
                cout<<temp[i]<<" ";
            }
            cout<<temp[temp.size()-1]<<"]";
        }
    }
    cout<<"\n";
}
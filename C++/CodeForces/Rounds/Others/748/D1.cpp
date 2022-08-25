#include<bits/stdc++.h>
using namespace std;

bool allPos(vector<int>A){
    int cnt=0;
    for(auto &nums: A){
        if(nums>=0){
            cnt++;
        }
    }
    if(cnt==A.size()) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>A(n);
        set<int>in;
        for(int i=0; i<n; ++i){
            cin>>A[i];
            in.insert(A[i]);
        }
        if(allPos(A)){
            auto it1=in.begin();
            auto it2=*next(in.begin(), 1);
            cout<<(abs(*it1-it2))<<"\n";
        } else{
            bool isZ=false;
            int minPosNm=INT_MIN;
            set<int>::iterator currPos;
            set<int>::iterator currPosPrev;
            for(auto itr=in.begin(); itr!=in.end(); ++itr){
                if(*itr==0) isZ=true;
                else if(*itr>0){
                    minPosNm=*itr;
                    currPosPrev=itr;
                    itr++;
                    if(itr!=in.end())
                        currPos=itr;
                    else{
                        itr--;
                        currPos=itr;
                    }
                    break;
                }
            }
            int toChk=minPosNm;
            if(currPos!=in.end()){
                for(int i=minPosNm; i>=0; --i){
                    bool flag=true;
                    for(auto itr_=currPos; itr_!=in.end(); ++itr_){
                        int currNm=*itr_;
                        while(true){
                            if(currNm-minPosNm==0){
                                break;
                            } else{
                                if(currNm-minPosNm<0){
                                    flag=false;
                                    break;
                                } else{
                                    currNm-=minPosNm;
                                }
                            }
                        }
                        if(!flag){
                            break;
                        }
                    }
                    if(flag){
                        toChk=i;
                        break;
                    }       
                }
            }
            int fn=INT_MIN;
            for(int i=toChk; i>=0; --i){
                bool flag=true;
                for(auto itr=in.begin(); itr!=currPosPrev; ++itr){
                    int currNm=*itr;
                    int nwI=abs(currNm-i);
                    while(true){
                        if(currNm+nwI==i){
                            break;
                        } else{
                            if(currNm-i<currNm){
                                flag=false;
                                break;
                            } else{
                                currNm-=(nwI);
                            }
                        }
                    }
                    if(!flag){
                        break;
                    }
                }
                if(flag){
                    auto itt=in.begin();
                    fn=abs(*itt-i);
                    break;
                }
            }
            cout<<(fn==INT_MIN?-1:isZ==true?fn-minPosNm:fn)<<"\n";
        }
    }
}
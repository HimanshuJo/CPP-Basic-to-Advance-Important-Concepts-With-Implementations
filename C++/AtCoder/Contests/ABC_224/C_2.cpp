#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

int det(int x1, int y1, int x2, int y2, int x3, int y3){
    return x1*(y2-y3)-y1*(x2-x3)+1*(x2*y3-y2*x3);
}

int countPoints(Point arr[], int N){
    int res=0;
    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            for(int k=j+1; k<N; ++k){
                if(det(arr[i].x, arr[i].y, arr[j].x, arr[j].y, arr[k].x, arr[k].y)){
                    res++;
                }
            }
        }
    }
    return res;
}

int main(){
    int N;
    cin>>N;
    Point arr[N];
    for(int i=0; i<N; ++i){
        int x_, y_;
        cin>>x_>>y_;
        arr[i]={x_, y_};
    }
    int res=countPoints(arr, N);
    cout<<res;
}
#include<iostream>
#include<utility>
using namespace std;

class A{
    private:
        int val;
    public:
        A(int value=0):val(value){}
        ~A(){}
        A(const A& Aobj){
            val=Aobj.val;
        }
        A& operator=(const A& Aobj){
            val=Aobj.val;
            return *this;
        }
        friend bool operator<(const A& Aobj1, const A& Aobj2){
            if(Aobj1.val<Aobj2.val){
                return true;
            }
            return false;
        }
        friend bool operator==(const A& Aobj1, const A& Aobj2){
            if(Aobj1.val==Aobj2.val){
                return true;
            }
            return false;
        }
        int get_val() const{
            return val;
        }
        void set_val(int value){
            val=value;
        }
};

class B{
    private:
        long lval;
        float fval;
    public:
        B(long val1=0, float val2=0.0f):lval(val1), fval(val2){}
        ~B(){}
        B(const B& Bobj){
            lval=Bobj.lval;
            fval=Bobj.fval;
        }
        B& operator=(const B& Bobj){
            lval=Bobj.lval;
            fval=Bobj.fval;
            return *this;
        }
        friend bool operator<(const B& Bobj1, const B& Bobj2){
            if ((Bobj1.lval<Bobj2.lval)&&(Bobj1.fval<Bobj2.fval)){
                return true;
            }
            return false;
        }
        friend bool operator==(const B& Bobj1, const B& Bobj2){
            if ((Bobj1.lval==Bobj2.lval)&&(Bobj1.fval==Bobj2.fval)){
                return true;
            }
            return false;
        }
        long get_lval() const{
            return lval;
        }
        float get_fval() const{
            return fval;
        }  
};

inline pair<const char*, double>
ret2val(int val){
    if (val<=0){
        return pair<const char*, double>("Error", 0.0f);
    }
    return pair<const char*, double>("OK", 1.0f);
}

int main(){
    // either 'point to const char' or 'const point to const char'
    pair<const char*, long>pL("long pair", 1234);
    pair<const char*, float>pF("float pair", 111.111);
    A aObj(100);
    pair<const char*, A>pA("A Class", aObj);
    pair<B, const char*>pB(B(200, 111.111), "B Class");
    pair<A, B>classAB(123, B(1234, 123.456));
    pair<A, B>copyClassAB=classAB;
    pair<A*, B*>dynClassAB(new A(111), new B(123, 123.456));
    pair<const char*, double>retD=ret2val(1);
    cout<<retD.first<<" "<<retD.second<<"\n";
    if(copyClassAB==classAB){
        cout<<"Both pairs same\n";
    } else{
        cout<<"Pairs differ\n";
    }
    classAB.first.set_val(11);
    if(copyClassAB==classAB){
        cout<<"Changes made but still same\n";
    } else{
        cout<<"Changes encountered. Differ\n";
    }
    cout<<"-------\n";
    cout<<pL.first<<" "<<pL.second<<"\n";
    cout<<pF.first<<" "<<pF.second<<"\n";
    cout<<pA.first<<" "<<pA.second.get_val()<<"\n";
    cout<<pB.first.get_lval()<<" "<<pB.first.get_fval()<<" "<<pB.second<<"\n";
    cout<<dynClassAB.first->get_val()<<" "<<dynClassAB.second->get_lval()
        <<" "<<dynClassAB.second->get_fval()<<"\n";
    return 0;
}
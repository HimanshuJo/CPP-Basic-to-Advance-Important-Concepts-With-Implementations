#include<iostream>
#ifndef _LISTE_H_
#define _LISTE_H_
using namespace std;

template<class T>
class Kno{
    public:
        Kno(){}
        virtual ~Kno(){}
        virtual Kno* pst(T* d)=0;
        virtual void disp()=0;
};

template<class T>
class Gen:public Kno<T>{
    private:
        T* data;
        Kno<T>* next;
    public:
        Gen(T* d, Kno<T>* n): data(d), next(n){
            cout<<"obj for Gen Kno created \n";
        }
        ~Gen(){
            delete data;
            delete next;
        }
        Kno<T>* pst(T* d);
        void disp();
};

template<class T>
Kno<T>* Gen<T>::pst(T* d){
    int ret=data->comp(*d);
    switch(ret){
        case 0: 
        case 1:{
            Gen<T>* dKno=new Gen<T>(d, this);
            return dKno;
        }
        case -1:{
            next=next->pst(d);
            return this;
        }
    }
    return this;
}

template<class T>
void Gen<T>::disp(){
    data->disp();
    next->disp();
}

template<class T>
class EndKno:public Kno<T>{
    public:
        EndKno(){
            cout<<"Object for end kno created \n";
        }
        ~EndKno(){}
        Kno<T>* pst(T* d);
        void disp(){};
};

template<class T>
Kno<T>* EndKno<T>::pst(T* d){
    Gen<T>* data=new Gen<T>(d, this);
    return data;
}

template<class T>
class BegnKno: public Kno<T>{
    private:
        Kno<T>* next;
    public:
        BegnKno<T>(){
            next=new EndKno<T>();
            cout<<"Begin Kno created \n";
        }
        ~BegnKno(){}
        Kno<T>* pst(T* d);
        void disp();
};

template<class T>
Kno<T>* BegnKno<T>::pst(T* d){
    next=next->pst(d);
    return this;
}

template<class T>
void BegnKno<T>::disp(){
    next->disp();
}

template<class T>
class Liste{
    private:
        BegnKno<T> *begn;
    public:
        Liste(){
            begn=new BegnKno<T>();
        }
        ~Liste(){
            delete begn;
        }
        void pst(T* d){
            begn->pst(d);
        }
        void allDisp(){
            begn->disp();
        }
};

#endif
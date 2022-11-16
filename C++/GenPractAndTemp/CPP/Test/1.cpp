#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<fstream>
#define endl "\n"
using namespace std;

double customRound(double num) {
    return ceil(num*20)/20;
}

int main(){
    int numberOfEntriesInFirstInput=3, numberOfEntriesInSecondInput=2, numberOfEntriesInThirdInput=4;
    double totalSalesTaxApplicable=0;
    double totalAmountToBePaid=0;
    double priceOfCurrentItem=0;
    vector<pair<string, double>>arrayOfAllInputs;
    cout<<"Input 1:"<<endl;
    ifstream file1, file2, file3;
    file1.open("Input1.txt");
    if(!file1.is_open()){
        cout<<"Unable to open the Input1.txt"<<endl;
        return 0;
    }
    string line1, line2, line3;
    while(getline(file1, line1)){
        double currentSalesTaxApplicable=0;
        string in=line1;
        numberOfEntriesInFirstInput--;
        if(numberOfEntriesInFirstInput<0) break;
        string whetherCurrentItemIsImported="imported";
        auto it=in.find(whetherCurrentItemIsImported);
        if(it!=string::npos){
            string nmtoretrieve="";
            int begin=in.size()-1;
            while(true){
                if(in[begin]==' ') break;
                nmtoretrieve+=in[begin];
                begin--;
            }
            reverse(nmtoretrieve.begin(), nmtoretrieve.end());
            double num1=::atof(nmtoretrieve.c_str());
            priceOfCurrentItem=num1;
            string whetherCurrentItemIsBook="book", whetherCurrentItemIsFood="chocolate", whetherCurrentItemIsMedPoduct="headache", whetherCurrentItemsAreFoodProducts="chocolates";
            auto it2=in.find(whetherCurrentItemIsBook);
            auto it3=in.find(whetherCurrentItemIsFood);
            auto it4=in.find(whetherCurrentItemIsMedPoduct);
            auto it5=in.find(whetherCurrentItemsAreFoodProducts);
            if(it2==string::npos&&it3==string::npos&&it4==string::npos&&it5==string::npos){
                currentSalesTaxApplicable+=customRound((double)(priceOfCurrentItem*10)/100);
            }
            currentSalesTaxApplicable+=customRound((double)(priceOfCurrentItem*5)/100);
            totalAmountToBePaid+=num1;
        } else{
            string whetherCurrentItemIsBook="book", whetherCurrentItemIsFood="chocolate", whetherCurrentItemIsMedPoduct="headache", whetherCurrentItemsAreFoodProducts="chocolates";
            auto it2=in.find(whetherCurrentItemIsBook);
            auto it3=in.find(whetherCurrentItemIsFood);
            auto it4=in.find(whetherCurrentItemIsMedPoduct);
            auto it5=in.find(whetherCurrentItemsAreFoodProducts);
            if(it2!=string::npos||it3!=string::npos||it4!=string::npos||it5!=string::npos){
                string nmtoretrieve="";
                int begin=in.size()-1;
                while(true){
                    if(in[begin]==' ') break;
                    nmtoretrieve+=in[begin];
                    begin--;
                }
                reverse(nmtoretrieve.begin(), nmtoretrieve.end());
                double num1=::atof(nmtoretrieve.c_str());
                priceOfCurrentItem=num1;
                totalAmountToBePaid+=num1;
            } else{
                string nmtoretrieve="";
                int begin=in.size()-1;
                while(true){
                    if(in[begin]==' ') break;
                    nmtoretrieve+=in[begin];
                    begin--;
                }
                reverse(nmtoretrieve.begin(), nmtoretrieve.end());
                double num1=::atof(nmtoretrieve.c_str());
                priceOfCurrentItem=num1;
                currentSalesTaxApplicable=customRound((double)(priceOfCurrentItem*10)/100);
                totalAmountToBePaid+=num1;
            }
        }
        int frst=0;
        string toincl="";
        while(frst<=in.size()-1){
            if(isspace(in[frst])&&in[frst+1]=='a'&&in[frst+2]=='t'&&isspace(in[frst+3])) break;
            toincl+=in[frst];
            frst++;
        }
        toincl+=":";
        arrayOfAllInputs.push_back({toincl, priceOfCurrentItem+currentSalesTaxApplicable});
        totalSalesTaxApplicable+=currentSalesTaxApplicable;
        cout<<in<<endl;
    }
    cout<<endl;
    totalAmountToBePaid+=totalSalesTaxApplicable;
    cout<<"Output 1:"<<endl;
    for(auto &vals: arrayOfAllInputs){
        cout<<vals.first<<" "<<vals.second<<endl;
    }
    cout<<"Sales Taxes: "<<totalSalesTaxApplicable<<endl;
    cout<<"Total: "<<totalAmountToBePaid<<endl;
    arrayOfAllInputs.clear();
    totalSalesTaxApplicable=0;
    totalAmountToBePaid=0;
    priceOfCurrentItem=0;
    cout<<endl;
    cout<<"Input 2:"<<endl;
    file2.open("Input2.txt");
    while(getline(file2, line2)){
        double currentSalesTaxApplicable=0;
        string in=line2;
        numberOfEntriesInSecondInput--;
        if(numberOfEntriesInSecondInput<0) break;
        string whetherCurrentItemIsImported="imported";
        auto it=in.find(whetherCurrentItemIsImported);
        if(it!=string::npos){
            string nmtoretrieve="";
            int begin=in.size()-1;
            while(true){
                if(in[begin]==' ') break;
                nmtoretrieve+=in[begin];
                begin--;
            }
            reverse(nmtoretrieve.begin(), nmtoretrieve.end());
            double num1=::atof(nmtoretrieve.c_str());
            priceOfCurrentItem=num1;
            string whetherCurrentItemIsBook="book", whetherCurrentItemIsFood="chocolate", whetherCurrentItemIsMedPoduct="headache", whetherCurrentItemsAreFoodProducts="chocolates";
            auto it2=in.find(whetherCurrentItemIsBook);
            auto it3=in.find(whetherCurrentItemIsFood);
            auto it4=in.find(whetherCurrentItemIsMedPoduct);
            auto it5=in.find(whetherCurrentItemsAreFoodProducts);
            if(it2==string::npos&&it3==string::npos&&it4==string::npos&&it5==string::npos){
                currentSalesTaxApplicable+=customRound((double)(priceOfCurrentItem*10)/100);
            }
            currentSalesTaxApplicable+=customRound((double)(priceOfCurrentItem*5)/100);
            totalAmountToBePaid+=num1;
        } else{
            string whetherCurrentItemIsBook="book", whetherCurrentItemIsFood="chocolate", whetherCurrentItemIsMedPoduct="headache", whetherCurrentItemsAreFoodProducts="chocolates";
            auto it2=in.find(whetherCurrentItemIsBook);
            auto it3=in.find(whetherCurrentItemIsFood);
            auto it4=in.find(whetherCurrentItemIsMedPoduct);
            auto it5=in.find(whetherCurrentItemsAreFoodProducts);
            if(it2!=string::npos||it3!=string::npos||it4!=string::npos||it5!=string::npos){
                string nmtoretrieve="";
                int begin=in.size()-1;
                while(true){
                    if(in[begin]==' ') break;
                    nmtoretrieve+=in[begin];
                    begin--;
                }
                reverse(nmtoretrieve.begin(), nmtoretrieve.end());
                double num1=::atof(nmtoretrieve.c_str());
                priceOfCurrentItem=num1;
                totalAmountToBePaid+=num1;
            } else{
                string nmtoretrieve="";
                int begin=in.size()-1;
                while(true){
                    if(in[begin]==' ') break;
                    nmtoretrieve+=in[begin];
                    begin--;
                }
                reverse(nmtoretrieve.begin(), nmtoretrieve.end());
                double num1 = ::atof(nmtoretrieve.c_str());
                priceOfCurrentItem=num1;
                currentSalesTaxApplicable=customRound((double)(priceOfCurrentItem*10)/100);
                totalAmountToBePaid+=num1;
            }
        }
        int frst=0;
        string toincl="";
        while(frst<=in.size()-1){
            if(isspace(in[frst])&&in[frst+1]=='a'&&in[frst+2]=='t'&&isspace(in[frst+3])) break;
            toincl+=in[frst];
            frst++;
        }
        toincl+=":";
        arrayOfAllInputs.push_back({toincl, priceOfCurrentItem+currentSalesTaxApplicable});
        totalSalesTaxApplicable+=currentSalesTaxApplicable;
        cout<<in<<endl;
    }
    cout<<endl;
    totalAmountToBePaid+=totalSalesTaxApplicable;
    cout<<"Output 2:"<<endl;
    for(auto &vals: arrayOfAllInputs){
        cout<<vals.first<<" "<<vals.second<<endl;
    }
    cout<<"Sales Taxes: "<<totalSalesTaxApplicable<<endl;
    cout<<"Total: "<<totalAmountToBePaid<<endl;
    arrayOfAllInputs.clear();
    totalSalesTaxApplicable=0;
    totalAmountToBePaid=0;
    priceOfCurrentItem=0;
    cout<<endl;
    cout<<"Input 3:"<<endl;
    file3.open("Input3.txt");
    while(getline(file3, line3)){
        double currentSalesTaxApplicable=0;
        string in=line3;
        numberOfEntriesInThirdInput--;
        if(numberOfEntriesInThirdInput<0) break;
        string whetherCurrentItemIsImported="imported";
        auto it=in.find(whetherCurrentItemIsImported);
        if(it!=string::npos){
            string nmtoretrieve="";
            int begin=in.size()-1;
            while(true){
                if(in[begin]==' ') break;
                nmtoretrieve+=in[begin];
                begin--;
            }
            reverse(nmtoretrieve.begin(), nmtoretrieve.end());
            double num1=::atof(nmtoretrieve.c_str());
            priceOfCurrentItem=num1;
            string whetherCurrentItemIsBook="book", whetherCurrentItemIsFood="chocolate", whetherCurrentItemIsMedPoduct="headache", whetherCurrentItemsAreFoodProducts="chocolates";
            auto it2=in.find(whetherCurrentItemIsBook);
            auto it3=in.find(whetherCurrentItemIsFood);
            auto it4=in.find(whetherCurrentItemIsMedPoduct);
            auto it5=in.find(whetherCurrentItemsAreFoodProducts);
            if(it2==string::npos&&it3==string::npos&&it4==string::npos&&it5==string::npos){
                currentSalesTaxApplicable+=customRound((double)(priceOfCurrentItem*10)/100);
            }
            currentSalesTaxApplicable+=customRound((double)(priceOfCurrentItem*5)/100);
            totalAmountToBePaid+=num1;
        } else{
            string whetherCurrentItemIsBook="book", whetherCurrentItemIsFood="chocolate", whetherCurrentItemIsMedPoduct="headache", whetherCurrentItemsAreFoodProducts="chocolates";
            auto it2=in.find(whetherCurrentItemIsBook);
            auto it3=in.find(whetherCurrentItemIsFood);
            auto it4=in.find(whetherCurrentItemIsMedPoduct);
            auto it5=in.find(whetherCurrentItemsAreFoodProducts);
            if(it2!=string::npos||it3!=string::npos||it4!=string::npos||it5!=string::npos){
                string nmtoretrieve="";
                int begin=in.size()-1;
                while(true){
                    if(in[begin]==' ') break;
                    nmtoretrieve+=in[begin];
                    begin--;
                }
                reverse(nmtoretrieve.begin(), nmtoretrieve.end());
                double num1=::atof(nmtoretrieve.c_str());
                priceOfCurrentItem=num1;
                totalAmountToBePaid+=num1;
            } else{
                string nmtoretrieve="";
                int begin=in.size()-1;
                while(true){
                    if(in[begin]==' ') break;
                    nmtoretrieve+=in[begin];
                    begin--;
                }
                reverse(nmtoretrieve.begin(), nmtoretrieve.end());
                double num1=::atof(nmtoretrieve.c_str());
                priceOfCurrentItem=num1;
                currentSalesTaxApplicable=customRound((double)(priceOfCurrentItem*10)/100);
                totalAmountToBePaid+=num1;
            }
        }
        int frst=0;
        string toincl="";
        while(frst<=in.size()-1){
            if(isspace(in[frst])&&in[frst+1]=='a'&&in[frst+2]=='t'&&isspace(in[frst+3])) break;
            toincl+=in[frst];
            frst++;
        }
        toincl+=":";
        arrayOfAllInputs.push_back({toincl, priceOfCurrentItem+currentSalesTaxApplicable});
        totalSalesTaxApplicable+=currentSalesTaxApplicable;
        cout<<in<<endl;
    }
    cout<<endl;
    totalAmountToBePaid+=totalSalesTaxApplicable;
    cout<<"Output 3:"<<endl;
    for(auto &vals: arrayOfAllInputs){
        cout<<vals.first<<" "<<vals.second<<endl;
    }
    cout<<"Sales Taxes: "<<totalSalesTaxApplicable<<endl;
    cout<<"Total: "<<totalAmountToBePaid<<endl;
}
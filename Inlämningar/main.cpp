#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Skapar Item
class Item{
 private:
    float ItemWeight;
    string ItemName;

 public:

    //Ett item ska vara omuterbart
    Item(const float weight, const string name){

        //om vikten är negative kasta execption
        if(weight < 0){
            throw "Item weight is below 0\n";
        }else{
            ItemWeight = weight;
            ItemName = name;}
    }
};

//sätta in föremål och ta ut föremål
class Inventory{
 private:
    float WeightCapacity;
    int MaxItems;
    vector<Item> Items;
    
    //total vikt
    double TotalWeight;

 public:

    //Skapar egen vikt och max items
    Inventory(const float XmxWeight,const int XmxItems){

        //Kasta exception.
        if(XmxWeight < 0){
            throw "weight capacity is invalid\n";
        }else if(XmxItems % 8 != 0){
            throw "The maximum capacity is not divisible by 8\n";
        }else{ 
            WeightCapacity = XmxWeight;
            MaxItems = XmxItems;
        }

    }

    
    //Pushback items & vikt
    vector<Item> GetItems(){
        return Items;
    }
    

    // string WithdrawItem(string){}
    // string DepositItem(Item&){}
    // string GetItems(){}
    
};







int main(){
    Item test(12,"test");

    try{
        Inventory test(7,4);
    }
    catch(const char* msg){
        cerr << msg << endl;
    }



    return 0;
}
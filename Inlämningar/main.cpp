#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//Skapar Item
class Item{
 private:
    float ItemWeight;
    string ItemName;

 public:

    //Ett item ska vara omuterbart
    Item(const string name, const float weight){

        //om vikten är negative kasta execption
        if(weight < 0){
            throw "Item weight is below 0\n";
        }else{
            ItemWeight = weight;
            ItemName = name;
        }
    }

    //Getters
    float GetItemWeight(){
        return ItemWeight;
    }
    string GetItemName(){
        return ItemName;
    }

    //Setters
    float SetItemWeight(){

        return 0;
    }
    string SetItemName(){

        return 0;
    }

};



//sätta in föremål och ta ut föremål
class Inventory{
 private:
    float WeightCapacity;
    int MaxItems;
    vector<Item> items;
    
    float TotalWeight;
    int TotalItems;
 public:

    //Skapar egen vikt och max items
    Inventory(const int XmxItems,const float XmxWeight){

        //Kasta exception.
        if(XmxWeight < 0){
            throw "weight capacity is invalid\n";
        }else if(XmxItems % 8 != 0){
            throw "The maximum item capacity is not divisible by 8\n";
        }else{ 
            WeightCapacity = XmxWeight;
            MaxItems = XmxItems;
        }

    }


    string WithdrawItem(string Name){

        for(int i = 0; i < items.size(); i++){ 
           if(items[i].GetItemName() == Name){
                items.erase(items.begin()+ i);
                cout <<"Withdrew: " << Name <<endl;
                return Name;
           }
        }
     
        
        return "Item" + Name + "Item dose not exist.";
    }


    void DepositItem(Item& item){
        //TODO: fix check if can add item
        //TODO: enum
            if(GetWeightCap() >= GetSumWeight() + item.GetItemWeight() || GetMaxItemCap ){
                items.push_back(item);
                TotalWeight += item.GetItemWeight();
            }else{cout<<item.GetItemName()<<" too heavy to store"<<endl;
            }        
    }

    float GetItems(){

        cout<<"Inventory"<<endl;
        for(int i = 0; i < items.size(); i++){
            cout<<items[i].GetItemName()<<" "<<items[i].GetItemWeight()<<"Kg"<<endl;
            TotalItems = items[i].GetItemName();
        }
        
        return items.size();
    }

    float SumWeight(){
        float sum = 0;
        TotalWeight = sum;
        for(float i = 0; i < items.size(); i++){
         sum += items[i].GetItemWeight();
        }

        cout<<"Total Weight: ";
        return sum;
    }

    int SumItems(){
        int Itot = 0;
        TotalItems = Itot;
        for(float i = 0; i < items.size(); i++){
         Itot += items[i].GetItems();
        }

        return Itot;
    }

    //Getters
    float GetWeightCap(){
        return WeightCapacity;
    }

    float GetSumWeight(){
        return TotalWeight;
    }
    int GetMaxItemCap(){
        return MaxItems;
    }
};








int main(){
   

    try{
        int MaxItems = 8;
        float MaxWeight = 1000;
        Inventory test1(MaxItems,MaxWeight);
        cout<<"Weight cap "<<test1.GetWeightCap()<<endl;
        Item test("sword", 100);
        Item test2("staff", 100);
        Item test3("Bow", 100.2);
        Item test4("Helmet", 80.10);
        Item test5("Boots",10);
        Item test6("Gun",10);
        Item test7("Fist",10);
        Item test8("Shield",10);
        Item test9("Book",10);
        Item test10("BackPack",10);
        test1.DepositItem(test);
        test1.DepositItem(test2);
        test1.DepositItem(test3);
        test1.DepositItem(test4);
        test1.DepositItem(test5);
        test1.DepositItem(test6);
        test1.DepositItem(test7);
        test1.DepositItem(test8);
        test1.DepositItem(test9);
        test1.DepositItem(test10);

        cout<<test1.GetItems()<<endl;
        cout<<test1.SumWeight()<<endl<<endl;

        //Withdraw
        test1.WithdrawItem("staff");
        cout<<test1.GetItems()<<endl;
        cout<<test1.SumWeight()<<endl;
    }
    catch(const char* msg){
        cerr << msg << endl;
    }

 
    
    return 0;
}
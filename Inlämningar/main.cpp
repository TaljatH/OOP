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
            ItemName = name;}
    }

    string ItemDetails(){
        return "Item: " + ItemName + " " + to_string(ItemWeight) + "kg";
    }

    float GetItemWeight(){
        return ItemWeight;
    }

};



//sätta in föremål och ta ut föremål
class Inventory{
 private:
    float WeightCapacity;
    int MaxItems;
    vector<Item> items;

    float TotalWeight;

 public:

    //Skapar egen vikt och max items
    Inventory(const int XmxItems,const float XmxWeight){

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


    string WithdrawItem(string){
        
        return 0;
    }


    string DepositItem(Item& item){
        //TODO: fix check if can add item
        
        items.push_back(item);
        return "";
        
    }

    string GetItems(){
        string Total = "";
        cout << "Inventory\n";

        for(int i = 0; i < items.size(); i++){
            Total +=items[i].ItemDetails() + "\n";
        }

        return Total;
    }

    float SumWeight(){
        float sum;
        TotalWeight = sum;
        for(int i = 0; i < items.size(); i++){
          sum += items[i].GetItemWeight();
        }

        return sum;
    }
};








int main(){
    string name;
    int weight;

    try{
        Inventory test1(80,20);
        Item test("sword", 10);
        Item test2("staff", 10);
        Item test3("Bow", 30);
        Item test4("Helmet", 80);
        test1.DepositItem(test);
        test1.DepositItem(test2);
        test1.DepositItem(test3);
        test1.DepositItem(test4);
        cout<<test1.GetItems()<<endl;
        cout<<"Total Weight: " << test1.SumWeight();

    }
    catch(const char* msg){
        cerr << msg << endl;
    }
    
    return 0;
}
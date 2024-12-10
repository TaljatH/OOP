#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
#include <windows.h>

using namespace std;

//Max items = Inventory capacity <=Items
//Overweight = Inventorys weight <= Sum of Items weight
//Item_Too_Heavy = Item cant be heavier than X weight
enum Checker{NICE,MAXITEMS, OVERWEIGHT, ITEMTOOHEAVYTOOMANY};

//Skapar Item
class Item{
 private:
    float ItemWeight;
    string ItemName;

 public:

    //Ett item ska vara omuterbart
    Item(const string name, const float weight){

        if(weight < 0){
            //execption
            throw "Item weight is below 0\n";
        }else{
            ItemWeight = weight;
            ItemName = name;
        }
    }

    //Getters
    float GetItemWeight(){return ItemWeight;}
    string GetItemName(){return ItemName;}

};

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

    //Ska return item.
    Item WithdrawItem(string Name){

        for(int i = 0; i < items.size(); i++){ 
           if(items[i].GetItemName() == Name){
                
                Item WithdrawItem = items[i];
                
                items.erase(items.begin()+ i);
                
                return WithdrawItem;
            }
     
            throw "Item not found in inventory\n";
        }
    }


    Checker DepositItem(Item& item){

        if(GetSumWeight() > GetWeightCap() && items.size() < GetMaxItemCap()){

         return ITEMTOOHEAVYTOOMANY;
         
        }

        if(GetSumWeight() + item.GetItemWeight() > GetWeightCap()){

         return OVERWEIGHT;
         
        }

        if(items.size() >= GetMaxItemCap()){

         return MAXITEMS;

        }

        
        items.push_back(item);
        TotalWeight +=item.GetItemWeight();
        
        return NICE;   
    }

    //Ska inte va float och ska inte skriva ut något.
    vector<Item> GetItems(){
        vector<Item> a = items;
        return a;
    }

    float SumWeight(){
        float sum = 0;
        for(int i = 0; i < items.size(); i++){
            sum +=items[i].GetItemWeight();
            TotalWeight = sum;
        }
        return TotalWeight;
    }


    //Getters
    float GetWeightCap(){return WeightCapacity;}
    int GetMaxItemCap(){return MaxItems;}
    float GetSumWeight(){return TotalWeight;}
};





//Function 
void AddItemToInventory(Inventory& inv, Item& item){
    
    //capture result
    Checker a = inv.DepositItem(item);

    if(a == ITEMTOOHEAVYTOOMANY){
        cout << "Inventroy reached max items and inventory is too heavy"<<endl;
    }
    if(a == OVERWEIGHT){
        cout << "Could not add " << item.GetItemName() << endl;
        cout <<"Inventory is too heavy"<<endl;
    }
    if(a == MAXITEMS){
        cout << "Could not add " << item.GetItemName() << endl;
        cout << "Inventory reached max items "<<endl;
    }
}




#endif


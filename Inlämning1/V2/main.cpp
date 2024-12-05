#include "inventory.h"


void UI(){
    cout<<"\n\tInventory Menu\n"
        <<"1- Deposit Items"<<endl
        <<"2- Withdraw Items"<<endl
        <<"3- View Items"<<endl
        <<"4- Exit"<<endl;
}

int main(){
   try{

    int weight;
    string name;
    string withdraw;

   

    //Inventory
    int MaxItems,MaxCap;
    MaxItems = 8;
    MaxCap = 100;
    Inventory inv(MaxItems,MaxCap);

    cout<<"\n\tInventory"<<endl;
    cout<<"Slots: "<<MaxItems<<endl<<"Max Inventory weight: "<<MaxCap<<"Kg"<<endl;
    
    bool game = true;
    while(game){
        int MenuChoice;
        UI();
        Item a("", 0);
        if(cin>>MenuChoice){ 
            switch(MenuChoice){
                case 1: 
                    system("cls");
                    cout<<"Item Name: ";
                    cin>>name;
                    //ToUpper
                     for (char& c : name){
                     c = toupper(c);}
                    
                    cout<<"Item weight: ";
                    cin>>(weight);
                    
                    a = Item(name,weight);
                    AddItemToInventory(inv,a);
            break;

                case 2:
                
                    cout<<"Item name: ";
                    cin>>withdraw;
                    //ToUpper
                    for(char& c : withdraw){
                        c = toupper(c);
                    }
                    inv.WithdrawItem(withdraw);
            break;
                
                case 3:
                    cout<<inv.GetItems()<<endl
                        <<"Total Weight: "<<inv.GetSumWeight()<<endl;
            break;
                case 4:
                cout<<"Bye";
                game = false;
            break;

                default:
                cout<<"Invalid input"<<endl;
            break;
            }  
            }else{
                cout<<"\tINVALID INPUT"<<endl;
                cin.clear();
                cin.ignore();
            }
        }

    }
    catch(const char* msg){
        cerr << msg << endl;
    }

 
    
    return 0;
}

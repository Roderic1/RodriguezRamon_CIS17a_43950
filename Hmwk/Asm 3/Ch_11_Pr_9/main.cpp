/* 
 * File:   main.cpp
 * Author: RR
 *
 * Created on May 19, 2015, 9:46 AM
 */

#include <cstdlib>
#include <iostream>
#include <cst ring>


using namespace std;

struct Bureau{
    string name;
    float phNum;
    string topic;
    float fee;
};

void getData(Bureau * ,int);
void chngData(Bureau * ,int);
void chngInfo(Bureau * ,int);
void displyIn(Bureau * , int);
int main(int argc, char** argv) {
    Bureau day[10];
    bool done = true;
    int option;
    int post = 0;
    
    do{
        cout<<endl<<endl<<"Welcome to the Speaker's engagment conferance"<<endl;
        cout<<"Please select an option from the menu"<<endl;
        cout<<"1) If you would like to enter informtion for a new speaker"<<endl;
        cout<<"2) If you would like to change the information of a speaker"<<endl;
        cout<<"0) To exit the menu"<<endl<<endl;
        cin>>option;
        switch(option){
            case 1:
                getData(day,post);
                post++;
                break;
            case 2:
                chngData(day,post);
                break;
            case 0:
                done = false;
                break;
        }
        
    }while(done == true);
    
    

    return 0;
}

void getData(Bureau *a,int i){
    cout<<"Please enter the name of the speaker : ";
    cin.ignore();
    getline(cin,a[i].name);
    cout<<endl<<"Please enter in a contact phone # : ";
    cin>>a[i].phNum;
    cout<<"Please enter in the Topic you would like to address :"<<endl;
    cin.ignore();
    getline(cin,a[i].topic);
    cout<<"Enter in the fee charged per person to attend : ";
    cin>>a[i].fee;
    while(a[i].fee<0){
        cout<<endl<<"Sorry but the fee cannot be a negitive number : ";
        cin>>a[i].fee;
    }
    
}

void chngData(Bureau *a,int i){
    bool check = true;
    int choice;
    int speak;
    if(i>=1){
        do{
            cout<<endl<<"Select the information you would like to change"<<endl;
            for(int j = 0;j<i;j++){
                cout<<j+1<<") : "<<a[j].name<<endl;
            }
            cout<<"0) Exit to previous menu"<<endl;
            cin>>choice;
            if(choice == 0){
                check = false;
            }
            else if(choice < i){
                choice = choice-1;
                chngInfo(a,choice);
            }
            else
                cout<<"That is an invalid input";
                    
            
        }while(check == true);
    }
    else{
        cout<<"Sorry but no Speaker presentation information has been entered";
        cout<<endl<<"Select option 1 to begin";       
    }
    
}

void chngInfo(Bureau *a,int i){
    bool end = true;
    int enter;
    do{
        cout<<endl<<"What information would you like to change?"<<endl;
        cout<<"1) Speakers name"<<endl;
        cout<<"2) Contact Phone number"<<endl;
        cout<<"3) Speaker topic"<<endl;
        cout<<"4) Fee"<<endl;
        cout<<"0) Back to previous menu";
        cin>>enter;
        switch(enter){
            case 1:
                cout<<"Enter the name of the speaker : ";
                cin.ignore();
                getline(cin,a[i].name);
                break;
            case 2:
                cout<<"Enter in the Phone number";
                cin>>a[i].phNum;
                break;
            case 3:
                cout<<"Enter in the new topic";
                cin.ignore();
                getline(cin,a[i].topic);
                break;
            case 4:
                cout<<"Enter in the new fee";
                cin>>a[i].fee;
                while(a[i].fee<0){
                cout<<endl<<"Sorry but the fee cannot be a negitive number : ";
                cin>>a[i].fee;
                }
                break;
            case 0:
                end = false;
                break;
        }
    }while(end == true);          
}  
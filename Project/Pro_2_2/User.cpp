
#include <bitset>

#include "User.h"

User::User(){
    
}
void User::setN(string a){
    setName(a);
}

int User::getWord(bool &fin){
    guess = new char[10];
    const int SIZE = 10;
    ifstream inputFile;
    string fileName;
    string *canidate = new string[SIZE];
    bool num = true;
    int wordSiz;
    int i = 0;
    int selWord;
    do{
        cout<<"Would you like a 3 or 5 letter word?"<<endl;
        cin>>wordSiz;
        switch(wordSiz){
            case 3: fileName = "3word.txt";
                    num = true;
                    break;
            case 5: fileName = "5word.txt";
                    num = true;
                    break;
            case 0: fin = false;
                    num = true;
                    break;
            default: cout<<"That is an invalid entry, please try again";
                     num = false;
        }
    }while(num != true);
    word = new char[wordSiz];
    corrc = new char[wordSiz];
    //Open the file to get the word
    inputFile.open(fileName.c_str());
    while(inputFile >> canidate[i]){
        i++;
    }
//    prntAryS(canidate,i);                                                     
    selWord = rand()%90+10;selWord = selWord%10;                                           
    std::strcpy(word,canidate[selWord].c_str());
    //Close the file of the word list
    inputFile.close();
//    prntStruc(a,wordSiz);
    for(int j = 0;j < wordSiz;j++){
        corrc[j] = ' ';
    }
    for(int k = 0;k < 10;k++){
        guess[k] = ' ';
    }
    
    delete [] canidate;
    return wordSiz;
}

void User::PlayOn(bool &fin){ 
    int postion;
    int correct = 0;
    int miss = 0;
    bool tr = true;
    char input;
    int trys = 0;
    do{
    cout<<"Please enter the the letter you would like to try."<<endl;
        cout<<"Remember, you can enter the number 0 any time to quit."<<endl;
        cin>>input;
        if(isalpha(input)){
            if(islower(input))
                input = toupper(input);
            if(trys == 0){
                postion = linSearch(word,sizWord,input);
                if(postion == -1){
                    cout<<"Sorry that letter is incorrect"<<endl;
                    guess[miss] = input;
                    miss++;
                    tr = false;
                }
                else{
                    corrc[postion] = word[postion];
                    cout<<"Yes, that is one of the letters of the word"<<endl;
                    correct++;
                    tr = false;
                }
            }
            else{
                postion = linSearch(guess,miss,input);
                if(postion == -1){
                    postion = linSearch(corrc,sizWord,input);
                    if(postion == -1){
                        postion = linSearch(word,sizWord,input);
                        if(postion == -1){
                            cout<<"Sorry that letter is incorrect"<<endl;
                            guess[miss] = input;
                            miss++;
                            tr = false;
                        }
                        else{
                            corrc[postion] = word[postion];
                            cout<<"Yes, that is one of the letters of the word"<<endl;
                            correct++;
                            tr = false;
                        }
                    }
                    else{
                        cout<<"I'm sorry, but you already guessed that letter";
                        cout<<" correctly.";
                    }  
                }
                else{
                    cout<<"Sorry but you've already used that letter.";
                }
            }    
        }
        else if(input == '0'){
            cout<<"You have entered 0, we will now exit the game."<<endl;
            fin = false;
            tr = false;
            cout<<"This should display"<<fin<<"and "<<tr<<endl;
        }
        else
            cout<<"That is an invaild input, please try again.";
    }while(tr = true);
}

int User::linSearch(char b){
    int index = 0;
    int postion = -1;
    bool found = false;
    
    while(index < sizWord && !found){
        if(word[index] == b){
            found = true;
            postion = index;
        }
        index++;
    }
    return postion;
}
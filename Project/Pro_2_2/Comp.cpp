#include "Comp.h"


Comp::Comp(){
    //Initalize all the datatypes
    ALPHA = 26;
    name = "AI";
    guess = new char[10];
    list = new char[ALPHA];
    
    //Fill the array 
    for(int i = 0;i<ALPHA;i++){
        list[i] = (char)(i+65);
    }
}

Comp::Comp(int ba){
    wordSize = ba;
    word = new char[wordSize];
    correc = new char[wordSize];
    const int SIZE = 10;
    ifstream inputFile;
    string fileName;
    string *canidate = new string[SIZE];
    bool num = true;
//    int wordSiz;
    int selWord;
    int i = 0;
    //Select a word for the comp to test
        switch(ba){
            case 3: fileName = "3word.txt";
                    break;
            case 5: fileName = "5word.txt";
                    break;
            default: cout<<"There is an error in the Comps word choice";
        }

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
    for(int j = 0;j < wordSize;j++){
        correc[j] = ' ';
    }
    for(int k = 0;k < 10;k++){
        guess[k] = ' ';
    }
    delete canidate;
    
}

void Comp::getSize(int i){
    
}

int Comp::linSearch(char b){
    int index = 0;
    int postion = -1;
    bool found = false;
    
    while(index < wordSize && !found){
        if(word[index] == b){
            found = true;
            postion = index;
        }
        index++;
    }
    return postion;
}

void Comp::playOn(bool &fin){
    srand(static_cast<unsigned int>(time(0)));
        int postion;
    int correct = 0;
    int miss = 0;
    bool tr = true;
    char input;
    int trys = 0;
    int ran;
    do{
        ran = rand()%16+10;
        input = (char)(ran + 26);
        cout<< input;
        if(isalpha(input)){
            if(islower(input))
                input = toupper(input);
            if(trys == 0){
                postion = linSearch(word,wordSize,input);
                if(postion == -1){
                    cout<<"Comp guessed an incorrect letter"<<endl;
                    guess[miss] = input;
                    miss++;
                    tr = false;
                }
                else{
                    correc[postion] = word[postion];
                    cout<<"Comp guessed the correct letter"<<endl;
                    correct++;
                    tr = false;
                }
            }
            else{
                postion = linSearch(guess,miss,input);
                if(postion == -1){
                    postion = linSearch(correc,wordSize,input);
                    if(postion == -1){
                        postion = linSearch(word,wordSize,input);
                        if(postion == -1){
                            cout<<"Sorry that letter is incorrect"<<endl;
                            guess[miss] = input;
                            miss++;
                            tr = false;
                        }
                        else{
                            correc[postion] = word[postion];
                            cout<<"Comp guessed the correct letter"<<endl;
                            correct++;
                            tr = false;
                        }
                    }
                    
                }
                
            }    
        }
        
    }while(tr = true);
}
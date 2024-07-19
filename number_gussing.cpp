#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    srand(time(nullptr));

    int secretNumber=rand()%100 +1;
    int guess;
    int attempts=0;
    cout<<"Welcome to the nummber  Guessing Game!"<<endl;
    cout<<"Guess the number between 1 and 100. "<<endl;
     do{
        cout <<"Enter your guessed number"<<endl;
        cin>> guess;
        attempts;

        if(guess< secretNumber){
            cout<<"Too low!Try again"<<endl;
        }
        else if(guess>secretNumber){
            cout<<"Too high!Try again"<<endl;
        }
        else{
            cout<<"Congratulation!You guesses the number "<<endl;
            cout<<"Number of the attempts:"<<attempts<<endl;
        }
}while (guess !=secretNumber);
return 0;
}

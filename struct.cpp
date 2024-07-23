#include <iostream>
#include <string>
#include <iomanip> //for setw
using namespace std;

struct CardType { //create CardType struct with variables
    string suit;
    int value;
    int points;
};

//Function Prototypes
void FormCards(CardType deck[]);
void DisplayCards(const CardType deck[]);

int main(){
    CardType deck[52];//init deck
    //call functions
    FormCards(deck);
    DisplayCards(deck);

    return 0;
}
//function to form cards and aprropriate points;
void FormCards(CardType deck[]){
    string suits[] = {"Diamond", "Club", "Heart", "Spade"}; // init suits array with names

    int index = 0; // init index for count
    for (int s = 0; s < 4; s++){ // count suit thru 4 for cards
        for(int v = 1; v <= 13; v++){ // and count value through 13 for cards
            deck[index].suit = suits[s];
            deck[index].value = v;

            //Calculate point values
            if(suits[s] == "Heart"){
                if (v < 10){
                    deck[index].points = 5; //if value less than 10 - 5 points
                } else{
                    deck[index].points = 10; // 10 everything else
                }
            } else if (suits[s] == "Spade"){
                if (v == 12){
                    deck[index].points = 100; //spade value is 12, points = 100
                } else{
                    deck[index].points = 0; // 0 everything else
                }
            } else {
                deck[index].points = 0;
                if(suits[s] == "Diamond" && v == 11){ // diamond and value is 11, -100 points
                    deck[index].points = -100;
                }
            }
            index++;//increment index to continue count

        }
    }
}
//function to diplay cards
void DisplayCards(const CardType deck[]){//display head
    cout << "Here is the deck of cards: " << endl << endl;
    cout << "  SUIT        VALUE        POINTS" << endl;
    //count through cards
    for (int i = 0; i < 52; i++){
        cout << "  ";
        cout << setw(8) << left << deck[i].suit;//display suit

        //Display values as "A", "J", "Q", "K" for 1, 11, 12, 13
        if (deck[i].value == 1){
            cout <<setw(9) << right << "A";
        } else if (deck[i].value == 11){
            cout << setw(9) << right << "J";
        } else if (deck[i].value == 12){
            cout << setw(9) << right << "Q";
        } else if (deck[i].value == 13){
            cout << setw(9) << right << "K";
        } else{
            cout << setw(9) << right << deck[i].value;//display regular values for non face cards
        }


        cout << setw(14) << right << deck[i].points << endl;//display points

    }
}
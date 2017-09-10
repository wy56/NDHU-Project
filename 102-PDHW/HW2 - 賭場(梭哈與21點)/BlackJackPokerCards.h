#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "PokerCard.h"
#include "EricShuffler.h"
#include "Hacker.h"
#define Deck_number 52 //define a deck has 52 card
#define showcarddeck 1
#define hacknum 10000
using namespace std;

class BlackJackPokerCards :public PokerCards
{
public:

    BlackJackPokerCards(int deck)
    {

        construc_forPoker(deck);
        //cout<<"bulid deck finish"<<endl;
        //test.shuffleCard();
        shuffle_withdefineprob();
        //cout<<"shuffle finish"<<endl;

//        displayCards();
//        cout<<"display finish"<<endl;
    }


private:
    //EricShuffler test;





};

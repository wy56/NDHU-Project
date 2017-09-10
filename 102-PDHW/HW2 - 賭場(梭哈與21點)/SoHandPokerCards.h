#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define Deck_number 52 //define a deck has 52 card
#define showcarddeck 1
#define hacknum 10000
using namespace std;


class SoHandPokerCards:public PokerCards
{

public:
    SoHandPokerCards(int deck)
    {
        construc_forPoker(deck);
        shuffle_withdefineprob();

    }


private:




};

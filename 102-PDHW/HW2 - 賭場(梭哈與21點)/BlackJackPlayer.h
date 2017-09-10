#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define Deck_number 52 //define a deck has 52 card
#define showcarddeck 1
#define hacknum 10000
using namespace std;

class BlackJackPlayer:public Player
{
public:
    BlackJackPlayer()
    {
        initial();

    }

    int getcardminsum()  //return the minimum sum of card
    {
        int sum=0,temp = 0;
        for(int i=0; i<getnumCards(); i++)
        {
            temp = getcardface(i);
            if(temp>10)sum+=10;
            else sum+=temp;
        }
        return sum;
    }

private:




};

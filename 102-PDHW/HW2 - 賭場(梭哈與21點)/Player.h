#ifndef _Player_
#define _Player_


#include <iostream>
#include <vector>
#include "Card.h"
#include <algorithm>
#include <iomanip>
#define Deck_number 52 //define a deck has 52 card
#define showcarddeck 1
#define hacknum 10000
using namespace std;
class Player
{
private:
    Card *ptrCards;    // 玩家手上的牌
    int numCards;  // 玩家手上的牌數
    int coins;  //玩家手上的錢錢
    int bet; //玩家下的錢錢
    int nowcard;
    int totalbet;//總賭注
     //use for sort card
public:
    //void showCards(); // 秀出玩家手上所有的牌
    Player()
    {
        numCards = 0;
        totalbet = 0;
        //ptrCards = new Card[100];
    }
//        Player(int n)
//        {
//
//        }
    void initial()
    {
        numCards = 0;
        totalbet = 0;
    }
    int getnumCards()
    {
        return numCards;
    }
    int getcardface(int i)
    {
        return ptrCards[i].getface();
    }
    int getcardsuit(int i)
    {
        return ptrCards[i].getsuit();
    }
    void sethandcard(int deck)   //dynmatic set every player max card number
    {
        ptrCards = new Card[deck*Deck_number];
    }
    void settotalbet(int n)
    {
        totalbet =n;
    }
    int gettotalbet()
    {
        return totalbet;
    }
    void giveCard(int s,int f)
    {
        ptrCards[numCards].setCard(s,f);

        numCards++;
    }
    void deletetopCard()  //just for delete tempcard
    {
        numCards--;
    }
    void setcoin() //set coin
    {
        //int temp;
        do
        {
            cin>>coins;
            if(cin.fail())
            {
                //cout<<"Please input correct number : ";
                cin.clear();
                cin.ignore();
                coins = -1;
            }

            if(coins<=0)cout<<"(error input)input coins again : ";
        }
        while(coins<=0);
    }

    void setbet() //set every loop bet
    {

        do
        {
            cin>>bet;
            if(cin.fail())
            {
                //cout<<"Please input correct number : ";
                cin.clear();
                cin.ignore();
                bet = -1;
            }

            //if(coins<=0)cout<<"(error input)input coins again : ";
            if(bet<=0 ||bet>coins)cout<<"(error input)input bet again :";
        }
        while(bet<=0||bet>coins);
    }
    void setcoin(int in)
    {
        coins = in;
    }
    void setbet(int in) //set bet use input
    {
        bet = in;
    }
    int getcardsum() //return player's card face sum
    {
        int sum = 0,temp,ace=0;
        for(int i=0; i<numCards; i++)
        {
            temp = ptrCards[i].getface();
            if(temp>10)temp = 10;
            else if(temp==1)
            {
                temp = 11;
                ace++;
            }
            sum+=temp;
        }
        while(sum>21)
        {
            if(ace>0)
            {
                sum-=10;
                ace--;
            }
            else break;
        }
        return sum;
    }
    void setnumCards(int n)
    {
        numCards = n;
    }

    void showCards()
    {
        for(int i =0; i<numCards; i++)
        {
            ptrCards[i].showoneline();

            if(i!=numCards-1)cout<<" ";
            else cout<<endl;
        }
    }
    int getbet() //return bet
    {
        return bet;
    }
    int getcoins()  //return coins
    {
        return coins;
    }
    int status()
    {
        if(getcardsum()>21)
        {
            cout<<"busting!!"<<endl;
            return 0;
        }
        return 1;
    }
    int topface()
    {
        return ptrCards[numCards-1].getface(); //return top face
    }

    void playerShowcard(bool show)
    {
        for(int i=0; i<numCards; i++)
        {
            //cout<<setw(3)<<i+1<<".";

            if(i==0&&show)
            {
                cout<<"[";
                ptrCards[i].showoneline();
                cout<<"]";
            }
            else if(i!=0)
            {
                cout<<"[";
                ptrCards[i].showoneline();
                cout<<"]";
            }
            else cout<<"[ ? ]";
        }
    }

};
#endif // _Player_

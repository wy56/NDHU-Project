#ifndef _PokerCard_
#define _PokerCard_


#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Player.h"
#define Deck_number 52 //define a deck has 52 card
#define showcarddeck 1
#define hacknum 10000
using namespace std;
class PokerCards
{
private:
    Card *ptrCards;     // 賭桌上的撲克牌塔（指標指到第一張牌）
    int numCards;    // 這副撲克牌塔目前還剩下多少牌
    int start; //從第幾張牌開始
    vector<Card> setofCards;
public:

    PokerCards()      // 預設建構子
    {

    }
    PokerCards(PokerCards &p)      //拷貝建構子
    {
        start = p.start;
        numCards = p.numCards;
        ptrCards = (Card*)malloc(sizeof(Card)*p.numCards);
        for(int i = 0; i<numCards; i++)
        {
            ptrCards[i] = p.ptrCards[i];
        }

    }
    //PokerCard(int n); // 建構一個由 n 副牌構成的牌塔
    PokerCards(int n)
    {
        construc_forPoker(n);
    }

    void construc_forPoker(int n)
    {
        start = 0;
        //int start = 0;
        ptrCards = new Card[n*Deck_number];  //用 new 初始化一個array 大小取決於 牌的數量
        //pointerCards = vector<Card>
        numCards = n*Deck_number;

        //循序建立牌組
//            for(int i=0;i<n;i++)
//            {
//                for(int j=1;j<5;j++)
//                {
//                    for(int k=1;k<14;k++)
//                    {
//                        ptrCards[start].setCard(j,k);
//                        start++;
//                        //cout<<j<<" "<<k<<endl;
//                    }
//                }
//            }
        //依牌組數量插牌  為了方便取牌
        for(int k=1; k<14; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=1; j<5; j++)
                {
                    ptrCards[start].setCard(j,k);
                    start++;
                }
            }

        }


        start = 0;
    }
    ~PokerCards()   //這是解構子(上課練習)
    {
        cout<<"Delete PokerCards..."<<endl;

        cout<<"Delete Finish..."<<endl;
    }
    //Card dealCard(Player& p, int n);	// 發牌(發出前n張牌給玩家p)


    void dealCard(Player& p, int n)
    {
        //int pnow = p.getnumCards();
        for(int i=0; i<n; i++)
        {
            p.giveCard(ptrCards[start].getsuit(),ptrCards[start].getface());
            start++;
        }
    }
    void reset()
    {
        start = 0;
        for(int k=1; k<14; k++)
        {
            for(int i=0; i<numCards/Deck_number; i++)
            {
                for(int j=1; j<5; j++)
                {
                    ptrCards[start].setCard(j,k);
                    start++;
                }
            }

        }
        start = 0;
    }

    //void shuffle();  // 現在所剩下的牌重新洗牌
    void shuffle()
    {
        //cout<<"@@";
        srand(time(0));
        int change,s,f;
        for(int i = start; i<numCards; i++)
        {

            change = rand()%numCards;
            s = ptrCards[i].getsuit();
            f = ptrCards[i].getface();

            ptrCards[i].setCard(ptrCards[change].getsuit(),ptrCards[change].getface());
            ptrCards[change].setCard(s,f);
            //cout<<ptrCards[i].getsuit()<<" "<<ptrCards[i].getface()<<endl;
        }

    }
    void shuffle_withdefineprob() //使用預設機率洗牌
    {
        double pp[] = {0.06,0.08,0.05,0.09,0.1,0.05,0.08,0.02,0.05,0.1,0.15,0.05,0.12};
        for(int i=1; i<13; i++)
        {
            pp[i] = pp[i]+pp[i-1];
        }
        srand(time(0));
        int *numarray,tt,count_p;
        numarray = new int[13];
        for(int i=0; i<13; i++)
        {
            numarray[i] = numCards/13;
        }
        Card *temp;
        double change;
        temp = new Card[numCards];

        for(int i = 0; i<numCards; i++)
        {
            //cout<<i;
            count_p = 0;
            do
            {
                change = (rand()%100)/100.0;

                //cout<<change<<" ";

                for(int j=0; j<13; j++)
                {
                    if(change<pp[j])
                    {
                        tt = j;
                        break;
                    }
                }
                //cout<<tt<<" ";
                //cout<<numarray[tt]<<" "<<numCards/Deck_number<<" "<<"@";
                //cout<<change<<" "<<tt<<"("<<(tt)*(numCards/Deck_number)*4+numarray[tt]-1<<")"<<endl;
                if(numarray[tt]!=0)
                {
                    //cout<<(tt)*(numCards/Deck_number)+numarray[tt]-1<<" ";
                    temp[i].setCard(ptrCards[(tt)*(numCards/Deck_number)*4+numarray[tt]-1].getsuit(),ptrCards[(tt)*(numCards/Deck_number)*4+numarray[tt]-1].getface());
                    //cout<<ptrCards[(tt)*(numCards/Deck_number)*4+numarray[tt]-1].getsuit()<<":"<<ptrCards[(tt)*(numCards/Deck_number)*4+numarray[tt]-1].getface()<<"@";
                    numarray[tt]--;
                    break;
                }
                else
                {
                    count_p++;
                    if(count_p>3)
                    {
                        for(int k=tt+1;; k++)
                        {
                            //cout<<"@";
                            k%=13;
                            if(numarray[k]!=0)
                            {
                                temp[i].setCard(ptrCards[(k)*4*(numCards/Deck_number)+numarray[k]-1].getsuit(),ptrCards[(k)*4*(numCards/Deck_number)+numarray[k]-1].getface());
                                numarray[k]--;
                                break;
                            }
                        }
                        break;
                    }
                }

            }
            while(1);
        }

        delete ptrCards;
        ptrCards = temp;
    }


    void shuffle(double pp[])
    {
        srand(time(0));
        int *numarray,tt,count_p;
        numarray = new int[13];
        for(int i=0; i<13; i++)
        {
            numarray[i] = numCards/13;
        }
        Card *temp;
        double change;
        temp = new Card[numCards];
        for(int i = 0; i<numCards; i++)
        {
            //cout<<i;
            count_p = 0;
            do
            {
                change = (rand()%100)/100.0;

                //cout<<change<<" ";

                for(int j=0; j<13; j++)
                {
                    if(change<pp[j])
                    {
                        tt = j;
                        break;
                    }
                }
                //cout<<tt<<" ";
                //cout<<numarray[tt]<<" "<<numCards/Deck_number<<" "<<"@";
                //cout<<change<<" "<<tt<<"("<<(tt)*(numCards/Deck_number)*4+numarray[tt]-1<<")"<<endl;
                if(numarray[tt]!=0)
                {

                    //cout<<(tt)*(numCards/Deck_number)+numarray[tt]-1<<" ";
                    temp[i].setCard(ptrCards[(tt)*(numCards/Deck_number)*4+numarray[tt]-1].getsuit(),ptrCards[(tt)*(numCards/Deck_number)*4+numarray[tt]-1].getface());
                    //cout<<ptrCards[(tt)*(numCards/Deck_number)*4+numarray[tt]-1].getsuit()<<":"<<ptrCards[(tt)*(numCards/Deck_number)*4+numarray[tt]-1].getface()<<"@";
                    numarray[tt]--;
                    break;
                }
                else
                {
                    count_p++;
                    if(count_p>3)
                    {
                        for(int k=tt+1;; k++)
                        {
                            //cout<<"@";
                            k%=13;
                            if(numarray[k]!=0)
                            {
                                temp[i].setCard(ptrCards[(k)*4*(numCards/Deck_number)+numarray[k]-1].getsuit(),ptrCards[(k)*4*(numCards/Deck_number)+numarray[k]-1].getface());
                                numarray[k]--;
                                break;
                            }
                        }
                        break;
                    }
                }

            }
            while(1);
        }

        delete ptrCards;
        ptrCards = temp;
    }
    //void displayCards(); //秀出牌塔中所有牌

    int getnumface(int n)
    {
        return ptrCards[n].getface();
    }
    void displayCards()
    {
        for(int i = start; i<numCards; i++)
        {
            cout<<i+1<<":";
            ptrCards[i].show();
        }
    }
};
#endif // _PokerCard_

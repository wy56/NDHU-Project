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
    Card *ptrCards;     // ���W�����J�P��]���Ы���Ĥ@�i�P�^
    int numCards;    // �o�Ƽ��J�P��ثe�ٳѤU�h�ֵP
    int start; //�q�ĴX�i�P�}�l
    vector<Card> setofCards;
public:

    PokerCards()      // �w�]�غc�l
    {

    }
    PokerCards(PokerCards &p)      //�����غc�l
    {
        start = p.start;
        numCards = p.numCards;
        ptrCards = (Card*)malloc(sizeof(Card)*p.numCards);
        for(int i = 0; i<numCards; i++)
        {
            ptrCards[i] = p.ptrCards[i];
        }

    }
    //PokerCard(int n); // �غc�@�ӥ� n �ƵP�c�����P��
    PokerCards(int n)
    {
        construc_forPoker(n);
    }

    void construc_forPoker(int n)
    {
        start = 0;
        //int start = 0;
        ptrCards = new Card[n*Deck_number];  //�� new ��l�Ƥ@��array �j�p���M�� �P���ƶq
        //pointerCards = vector<Card>
        numCards = n*Deck_number;

        //�`�ǫإߵP��
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
        //�̵P�ռƶq���P  ���F��K���P
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
    ~PokerCards()   //�o�O�Ѻc�l(�W�ҽm��)
    {
        cout<<"Delete PokerCards..."<<endl;

        cout<<"Delete Finish..."<<endl;
    }
    //Card dealCard(Player& p, int n);	// �o�P(�o�X�en�i�P�����ap)


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

    //void shuffle();  // �{�b�ҳѤU���P���s�~�P
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
    void shuffle_withdefineprob() //�ϥιw�]���v�~�P
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
    //void displayCards(); //�q�X�P�𤤩Ҧ��P

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

#ifndef _Eric_
#define _Eric_

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "PokerCard.h"
#include "Player.h"
#include <cmath> //for abs()
#define Deck_number 52 //define a deck has 52 card
#define showcarddeck 1
#define hacknum 10000
using namespace std;
class EricShuffler
{
public:
    EricShuffler()  //將定義 導入class 中
    {
        double cc=0; //check probsum is 1;
        double P[]= {0.06,0.08,0.05,0.09,0.1,0.05,0.08,0.02,0.05,0.1,0.15,0.05,0.12}; //定義機率
        for(int i=0; i<13; i++)
        {
            Prob[i]=P[i];
            cc+=P[i];
        }
        if(abs(cc-1)>0.001)cout<<"Warring error probility set! Please check!"<<cc<<endl;
        ProbSum[0] = Prob[0];
        for(int i=1; i<13; i++)
        {
            ProbSum[i]=ProbSum[i-1]+P[i];
        }
    }
    void shuffleCard(PokerCards& pc)  // 用雷以勒洗牌器對牌塔洗牌cout<<tt<<" ";
    {
        pc.reset();
        //cout<<"@@";
        pc.shuffle(ProbSum);
        //pc.displayCards();

    }
    void shuffleCard()
    {

    }

    void PrintProbs()// 印出 Prob[13]的值
    {
        cout<<"Print every card probability"<<endl;
        for(int i=0; i<13; i++)cout<<i+1<<":"<<Prob[i]<<" ";
        cout<<endl;
    }

    void PrintProbSum()// 印出 Prob[13] sum的值
    {
        cout<<"Print ProbSum"<<endl;
        for(int i=0; i<13; i++)cout<<i+1<<":"<<ProbSum[i]<<" ";
        cout<<endl;
    }

private:
    int getNextCard(int face, int *next_face) {} // 現在牌點數為face，回傳下一張牌點數(*next_face)
    double Prob[13]; //機率陣列
    double ProbSum[13]; //累進機率

};

#endif // _Eric_

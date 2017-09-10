#ifndef _Hack_
#define _Hack_


#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define Deck_number 52 //define a deck has 52 card
#define showcarddeck 1
#define hacknum 10000
#define delaytime 1
using namespace std;
class Hacker
{
public:
    Hacker(int M) //建構子, M為牌塔內有幾副牌
    {
        //PokerCards hackpoker(M);
        //hackuse = new PokerCards(M);
        //Count[14][14] = new double[M*4+1]  ;
        Count = new double **[14];
        for(int i=0; i<14; i++)
        {
            Count[i] = new double *[14];
            for(int j=0; j<14; j++)
            {
                Count[i][j] = new double[M*4+1];
                for(int k=0; k<M*4+1; k++)Count[i][j][k]=0;
            }

        }
        //cout<<"@@";
        //for(int i=0;i<4;i++)
    }
    void Estimate(int n, EricShuffler &sh,int deckn) //使用發牌器sh洗牌塔N(如n=100000)次，以便從中統計出Count[X][Y][M]和計算Prob[13][13]
    {
        PokerCards pp(deckn);
        int temprecord[14];
        int lastface;
        for(int i =1; i<=n; i++)
        {
            //cout<<"@";
            sh.shuffleCard(pp);
            for(int j=0; j<14; j++)temprecord[j]=0;
            //pp.displayCards();
            lastface = pp.getnumface(0);
            temprecord[lastface]++;
            //cout<<deckn*Deck_number;
            for(int j=1; j<deckn*Deck_number; j++)
            {
                if(pp.getnumface(j)<1||pp.getnumface(j)>13||lastface>13)
                {
                    //cout<<"@@@";
                    cout<<pp.getnumface(j)<<" "<<j;
                    cin>>lastface;
                }
                //cout<<lastface<<" "<<pp.getnumface(j)<<" "<<temprecord[pp.getnumface(j)+1]<<endl;
                Count[lastface][pp.getnumface(j)][temprecord[pp.getnumface(j)]]++;
                temprecord[pp.getnumface(j)]++;
                lastface = pp.getnumface(j);

            }
            //cout<<endl;
            for(int j=1; j<delaytime; j++); //delay

            //Sleep(1);
            //if(i%500==0) cout<<"Already finish "<<i<<" times hack"<<endl;
            cout << "\rNow hacking: " << i * 100 / n << "%" << flush;
            //_sleep(1);
            //cout<<endl;
        }
        cout<<endl;

        for(int X = 1; X<=13; X++)
        {
            for(int Y=1; Y<=13; Y++)
            {
                int total_count=0;

                int M=0;
                for(int k=1; k<=deckn*4; k++)M+=Count[X][Y][k];

                for(int y=1; y<=13; y++)
                {
                    for(int k=1; k<=deckn*4; k++)total_count+=Count[X][y][k];
                }
                if(total_count==0)Prob[X][Y]=0;
                else
                {
                    Prob[X][Y] = (double)M/total_count;
                }
            }
        }


    }
    double getNextCardProb(int topface,int face) //若上一張牌點數為face，回傳下張牌Prob[face][Y](Y=1,..,13)的機率值（放在prob[13]陣列中）
    {
        return Prob[topface][face];
    }
    void showNextCardProb(int face)
    {
        cout<<"Prob Matrix:"<<endl;
        char cardface[][3] = {{'A'},{'2'},{'3'},{'4'},{'5'},{'6'},{'7'},{'8'},{'9'},{"10"},{'J'},{'Q'},{'K'}};
        for(int i = 0; i<14; i++)
        {
            if(i==0)
            {
                //for(int j=1; j<14; j++)cout<<setw(5)<<j<<" ";
                for(int j=1; j<14; j++)cout<<setw(5)<<cardface[j-1]<<" ";
                cout<<endl;
            }
            else
            {
                //for(int j=1;j<14;j++)
                cout<<setw(5)<<fixed<<setprecision(3)<<Prob[face][i]<<" ";
            }

        }
        cout.unsetf( ios::fixed);
        cout<<endl;
    }
    void PrintProbs() //印出Prob[13][13]矩陣
    {
        cout<<"Prob Matrix:"<<endl<<" ";
        char cardface[][3] = {{'A'},{'2'},{'3'},{'4'},{'5'},{'6'},{'7'},{'8'},{'9'},{"10"},{'J'},{'Q'},{'K'}};
        for(int i = 0; i<14; i++)
        {
            if(i==0)
            {
                for(int j=1; j<14; j++)
                {
                    cout<<setw(5)<<cardface[j-1];
                }
            }
            for(int j=1; j<14&&i>0; j++)
            {
                if(j==1)
                {
                    cout<<setw(2)<<cardface[i];
                }

                cout<<setw(5)<<fixed<<  setprecision(2)<<Prob[i][j];
            }
            cout<<endl;
        }
        cout.unsetf( ios::fixed);
    }
    void  getBustingProb(int facesum,int face)
    {
        double pp=0;

        for(int i=1; i<14; i++)
        {
            if(facesum+i>21)pp+=Prob[face][i];
        }
        cout<<"Probability of Busting (爆牌機率) ="<<setw(6)<<pp;
        cout<<endl;
    }

private:
    //PokerCards *hackuse;
    double*** Count; //請根據M值，動態配置Count[13][13][M]陣列
    double Prob[14][14]; //估出來的Prob[M][X][Y]

};

#endif // _Hack_


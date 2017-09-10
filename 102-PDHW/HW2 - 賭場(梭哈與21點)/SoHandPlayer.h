#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Player.h"
#define Deck_number 52 //define a deck has 52 card
#define showcarddeck 1
#define hacknum 10000
using namespace std;

class SoHandPlayer :public Player
{
public:
    SoHandPlayer()
    {
        initial();
    }
    int check_handcard(bool theend)
    {

        int maxt = 0,temp = 0;
        if(getnumCards()==2)
        {
            return one(theend);
        }
        else
        {

            sortcard.clear();
            for(int p=0; p<getnumCards(); p++)
            {
                sortcard.push_back(getcardface(p));
            }
            sort (sortcard.begin(),sortcard.end());
            //reverse(sortcard.begin(),sortcard.end());
            //for(int p=0;p<numCards;p++)cout<<sortcard[p]<<" ";

            temp = Royal_Flush(theend);
            if(temp>maxt)
            {
                maxt = temp;
            }
            temp = Four_Of_A_Kind(theend);
            if(temp>maxt)
            {
                maxt = temp;
            }
            temp = Flush(theend);
            if(temp>maxt)
            {
                maxt = temp;
            }
            temp = Straight(theend);
            if(temp>maxt)
            {
                maxt = temp;
            }
            temp = Three_Of_A_Kind(theend);
            if(temp>maxt)
            {
                maxt = temp;
            }
            temp = Full_House(theend);
            if(temp>maxt)
            {
                maxt = temp;
            }
            temp = Two_Pair(theend);
            if(temp>maxt)
            {
                maxt = temp;
            }
            temp = One_Pair(theend);
            if(temp>maxt)
            {
                maxt = temp;
            }
            temp = one(theend);
            if(temp>maxt)
            {
                maxt = temp;
            }


            return maxt;
        }

    }
    int  Flush (bool t) //500
    {
        int temp;
        if(t)
        {
            temp = getcardsuit(0);
            for(int i=1; i<getnumCards(); i++)
            {
                if(temp!=getcardsuit(i))return 0;
            }
            return sortcard[getnumCards()-1]+500;
        }
        else return 0;

    }
    int Royal_Flush(bool t) //800
    {
        int temp;
        if(t)
        {
            temp = Flush(t);
            if(temp<700)return 0;
            temp = sortcard[0];
            for(int i=1; i<getnumCards(); i++)
            {
                if((temp+1)!=sortcard[i])return 0;
                temp = sortcard[i];
            }
            return temp+800;
        }
        else return 0;

    }
    int Four_Of_A_Kind(bool t) //700
    {
        if(t)
        {
            int no = 0;
            int temp = getcardface(0);

            for(int i=1; i<getnumCards()-1; i++)
            {
                if(temp ==getcardface(i))no++;
            }
            if(no==4)return temp+700;
            no = 0;
            temp = getcardface(1);
            for(int i=2; i<getnumCards(); i++)
            {
                if(temp ==getcardface(i))no++;
            }
            if(no==4)return temp+700;

            return 0;
        }
        else return 0;

    }
    int Straight(bool t) //400
    {
        int temp;
        if(t)
        {
            temp = getcardface(0);
            for(int i=1; i<getnumCards(); i++)
            {
                if((temp+1)!=sortcard[i])return 0;
                temp = sortcard[i];
            }
            return temp+400;
        }
        else return 0;

    }
    int Three_Of_A_Kind(bool t) //300
    {
//        if(getnumCards()<3)return 0;
//        int temp;
//        for(int p=0; p<getnumCards()-2; p++)
//        {
//            temp = ptrCards[p].getface();
//            if(temp==ptrCards[p+1].getface()&&temp==ptrCards[p+2].getface())return 300+temp;
//        }
//        return 0;
//
        int temp ;//=
        int count_n;
        int maxcard=0;
        for(int p=0; p<getnumCards(); p++)
        {
            count_n = 0;
            temp = getcardface(p);
            for(int qq= 0;qq<getnumCards();qq++)
            {
                if(temp==getcardface(qq))count_n++;
            }
            if(count_n>2&&temp>maxcard)maxcard=temp;


        }

        if(maxcard>0)return maxcard+300;
        else return 0;


    }
    int Full_House(bool t) //600
    {
        if(t)
        {
            if(getcardface(0)==getcardface(1)&&getcardface(0)==getcardface(2)&&getcardface(3)==getcardface(4))return getcardface(0)+600;
            if(getcardface(0)==getcardface(1)&&getcardface(2)==getcardface(3)&&getcardface(2)==getcardface(4))return getcardface(4)+600;
        }
        else return 0;
        return 0;
    }
    int Two_Pair(bool t) //200
    {
        int m,temp,shift;
        m=0;
        temp = 0;
        if(t==false)shift = 1;
        else shift=0;
        for(int p=0+shift; p<getnumCards(); p++)
        {
            for(int t =p+1; t<getnumCards(); t++)
            {
                if(getcardface(p)==getcardface(t))
                {
                    temp++;
                    if(getcardface(p)>m)m = getcardface(p);
                }
            }
        }
        if(temp>1)return 200+m;
        return 0;
    }
    int One_Pair(bool t) //100
    {
        int m,temp,shift;
        if(t==false)shift = 1;
        else shift=0;

        m=0;
        temp = 0;
        for(int p=0+shift; p<getnumCards(); p++)
        {
            for(int t =p+1; t<getnumCards(); t++)
            {
                if(getcardface(p)==getcardface(t))
                {
                    temp++;
                    if(getcardface(p)>m)m = getcardface(p);
                }
            }
        }
        if(temp>0)return 100+m;
        return 0;
    }

    int one(bool t) //0
    {
        int mm=0;

        if(t)
        {
            for(int i=0; i<getnumCards(); i++)
            {
                if(getcardface(i)>mm)mm = getcardface(i);
            }
        }
        else
        {
            for(int i=1; i<getnumCards(); i++)
            {
                if(getcardface(i)>mm)mm = getcardface(i);
            }
        }
        return mm;
    }

private:
vector<int> sortcard;



};

#ifndef __card__
#define __card__


#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define Deck_number 52 //define a deck has 52 card
#define showcarddeck 1
#define hacknum 10000
using namespace std;

class Card
{
private:
    int suit;   // 花色
    int face;   // 點數
    int cardnum; //card reference
public:
    //Card(); // initial card data
    Card() //初始化 suit and face
    {
        setsuit(0);
        setface(0);
    }
    //void show();       // 用以在螢幕顯示出此牌之花色及點數
    void show()  //print a card suit and face use ascii code to print picture
    {
        if(suit==1)cout<<(char)6<<"\t"<<face<<endl;
        else if(suit==2)cout<<(char)3<<"\t"<<face<<endl;
        else if(suit==3)cout<<(char)4<<"\t"<<face<<endl;
        else if(suit==4)cout<<(char)5<<"\t"<<face<<endl;
        else cout<<"Error card"<<endl;

    }
    void showoneline()  //print a card suit and face use ascii code to print picture and never us next line
    {
        char cardface[][3] = {{'A'},{'2'},{'3'},{'4'},{'5'},{'6'},{'7'},{'8'},{'9'},{"10"},{'J'},{'Q'},{'K'}};
        if(suit==1)cout<<(char)6<<" "<<cardface[face-1]; //這裡作一些修改 使可以印 J Q K
        else if(suit==2)cout<<(char)3<<" "<<cardface[face-1];
        else if(suit==3)cout<<(char)4<<" "<<cardface[face-1];
        else if(suit==4)cout<<(char)5<<" "<<cardface[face-1];
        else cout<<"Error card";
    }
    int getsuit()  //get card suit
    {
        return suit;
    }

    int getface()  //get face number
    {
        return face;
    }

    void setface(int n) //set card face number
    {
        face = n;
    }

    void setsuit(int n)  //set card suit
    {
        suit = n;
    }
    //void setCard(int suit, int face);	// 用以設定此牌之花色與點數
    void setCard(int suit, int face)
    {
        setface(face); //設定點數
        setsuit(suit); //設定花色
        //cout <<suit<<" "<<face;
    }

};
#endif // __card__

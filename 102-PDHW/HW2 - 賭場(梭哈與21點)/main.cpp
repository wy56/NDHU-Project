/* 410221002 資工一 陳韋佑 */

#include <iostream>
#include <ctime>  //for time()
#include <stdlib.h>  //for rand()
//#include "Player.h"
#include "Card.h"
//#include "PokerCard.h"
#include "EricShuffler.h"
#include "Hacker.h"
#include "SoHandPokerCards.h"
#include "SoHandPlayer.h"
#include "BlackJackPlayer.h"
#include "BlackJackPokerCards.h"
#include <vector>
#include <cmath> //for abs()
#include <algorithm>
#include <iomanip>
#include<conio.h>
//#include  <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "showmenu.h"
#define Deck_number 52 //define a deck has 52 card
#define showcarddeck 1
#define hacknum 10000
#define setdeck 1 //給soha預測1副牌組

using namespace std;


struct myclass
{
    bool operator() (int i,int j)
    {
        return (i>j);
    }
} myobject;

int checkinputnum()
{
    int input;

    do
    {
        cin>>input;
        if(cin.fail())
        {
            //cout<<"Please input correct number : ";
            cin.clear();
            cin.ignore();
            input = -1;
        }
        if(input<=0)cout<<"(error input)input again : ";
    }
    while(input<=0);
    return input;
}


int main()
{
    //for(int i=0;i<200;i++)
    //cout<<(char)1<<" ";

    /*
    0.先判斷要怎麼玩

    1.一開始先確認有多少玩家

    2.確認玩家後確認每位玩家有多少賭資(大於0)

    3.第一回合每位玩家獲得一張暗牌(蓋著不被別人看到)及一張明牌(打開會讓人看到)，其餘回合每位玩家僅獲得一張明牌

    4.根據玩家明牌的點數大小，點數最大者喊出要賭多少錢，若不喊則尋找下一位點數最大者
      (如果是21點 則每人拿點數 直到換下一個人)
    5.詢問剩下的玩家是否也要下相同賭注，否則放棄。
       (如果是21點 則直到結算)
    6.重複3~5直到每位玩家共有5張牌後
        (如果是21點 重復到每個人完成)
    7.每位玩家將暗牌亮出比大小，贏者獲得賭注
       (如果是21點 比較每個人牌面大小)

    */
    int numPlayers;  // 玩家數量
    //int setdeck=1; //
    int deckcard,needend;// 牌數 //needend 判斷結束
    int gametimes,remainpp; //gametimes 遊戲回合 //remainpp 剩餘玩家
    int chose,cardtop,nowmax,nowbet; //chose 為玩家選項 cardtop為目前最大
    int *playersort,order,*score,*status;//status 玩家繼續 score 賭注版 order 順序
    bool Show_Hand,toend;
    string cardsuits[9] = {"雜牌","一對","二對","三條","順子","同花","葫蘆","鐵支","同花順"};
    char cardface[][3] = {{'A'},{'2'},{'3'},{'4'},{'5'},{'6'},{'7'},{'8'},{'9'},{"10"},{'J'},{'Q'},{'K'}};
    double tempprobabilityofcard[9];
    int tempofcardmax[9];

    int numDecks;//黑傑克用 輸入牌組數

    while(1) //除非玩家不想玩
    {

        /*動畫區 */
        srand(time(NULL));
//        cout<<"請選擇要玩哪個? 1:21點 2:梭哈 ->";
//        cin>>chose;
        chose = getmenu();
                {
        if(chose==2)exit(0);
        else if(chose ==1)cout<<"玩家選擇玩 21點! "<<endl;
        else if(chose ==0)cout<<"玩家選擇玩 梭哈! "<<endl;

        for(int j=0;j<70;j++)
        {
            if(j<30)_sleep(rand()%20+10);
            else if(j>60)_sleep(rand()%150+250);
            else _sleep(rand()%80+40);
            cout<<(j*100.0/70)<<"%"<<"讀取進度";
            //for(int i=0;i<j;i++)
            //{
            cout<<"\r"<<setfill((char)2)<<setw(j)<<flush;//cout<<(char)2;
            //}
            cout.clear();
        }
        system("cls");
        //cout<<"\r"<<setfill((char)2)<<setw(70)<<endl;
        cout<<setfill((char)2)<<setw(80)<<"100%讀取完成!!"<<endl;
        /*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
        cout.clear();
        //cout.unsetf( ios::setfill);
        cout<<setfill(' ');
        //cout << "\rNow hacking: " << i * 100 / n << "%" << flush;
        }

        {

            //cout<<"請輸入1玩21點，或是2玩梭哈，或是其他結束 :";
            //cin>>chose;

            if(chose==1)//21點
            {
                /* 第一階段模擬: 牌塔 */
                cout<<"預設破解發牌規律次數 10萬次 建議用一組牌組"<<endl;
                cout<<"越多組時間呈線性可由#define hacknum 100 修改"<<endl;
                cout<<"預設發牌張數為 2 因為是21點嘛"<<endl<<endl;
                cout << "<This is a BlackJack game(21點)>"<<endl;
                /*1前置作業*/
                cout << "How many decks of cards do you want? "; //set decks
                cin >> numDecks;
                EricShuffler test;

                /**繼承**************************/
                BlackJackPokerCards Bpoker(numDecks);


                /**算機率**************/
                Hacker Ta(numDecks);
                Ta.Estimate(hacknum,test,numDecks);

                Ta.PrintProbs();

                cout << "幾個玩家 (>= 2)? ";  //set players
            do//至少牌組的牌是玩家的5倍 詳情參考說明文件
            {
                cin >> numPlayers;
                if(cin.fail())
                {
                    cout<<"Please input number!"<<endl;
                    numPlayers = -1;
                    cin.clear();
                    cin.ignore();
                }
                else if(numPlayers*5+5>numDecks*52)
                {
                    cout<<"Your Decks maybe not enough to supply too many players!"<<endl;
                    cout<<"Please input again! How many players? ";
                }
                else if(numPlayers<2)cout<<"please input more player numbers!"<<endl;
            }
            while(numPlayers*5+5>numDecks*52||numPlayers<2);

            numPlayers+=1; ////因為多了莊家

            BlackJackPlayer *BJPlayer = new BlackJackPlayer[numPlayers+1];


            /* 第二階段模擬：發牌動作 */
            for (int c=0; c<2; c++) // 每人輪流得一張牌，共得numCards張牌 這裡預設2
                for (int p=0; p<numPlayers; p++)
                {
                    if(c==0)BJPlayer[p].sethandcard(numDecks);
                    Bpoker.dealCard(BJPlayer[p], 1);
                }
                /* 第三階段模擬：設定賭金 */
            cout<<"玩家資本＝＝＝＝＝"<<endl;
            //cout << "How many coins do each player have? "<<endl; //set evey player's coins
            //for(int i=0; i<numPlayers; i++)
            for(int i=0; i<numPlayers-1; i++)  //這裡多了莊家 所以要-1
            {
                cout<<"玩家 "<<i+1<<" 有: ";
                //cout<<"Player "<<i<<" have: ";
                BJPlayer[i].setcoin();
            }

            /* 第四階段模擬：設定賭注 */
            cout<<"下注＝＝＝＝＝"<<endl;
            //cout << "How much do each player want to bet? "<<endl;
            //for(int i=0; i<numPlayers; i++)
            for(int i=0; i<numPlayers-1; i++)  //這裡莊家不用下注喔 所以要-1
            {
                cout<<"玩家 "<<i+1<<" 下注: ";
                //cout<<"Player "<<i<<" have: ";
                BJPlayer[i].setbet();
            }

            cout<<"******* 首輪發牌 *******"<<endl;
            for(int i=0; i<numPlayers; i++)
            {
                if(i==numPlayers-1)cout<<"莊家手牌 :";
                else cout<<"玩家 "<<i+1<<" 手牌 :";
                BJPlayer[i].showCards();
            }

            cout<<"============Game start============"<<endl;
            cout<<"============ 遊戲開始 ============"<<endl;
            /*第五階段模擬：玩家輪迴*/

            char *type;
            char player[10] = "玩家 ";
            char chief[10] = "莊家 ";
            for(int i=0; i<numPlayers; i++)
            {
                if(i!=numPlayers-1)type = player;
                else type = chief;
                //cout <<"Player "<<i<<"'s round. "<<"[Total point: "<<players[i].getcardsum()<<" Points]"<<endl;
                //cout <<"Player "<<i<<"'s card ->";
                if(i!=numPlayers-1)cout<<type<<i+1<<" 手牌 -->";
                else cout<<type<<" 手牌 -->";
                BJPlayer[i].showCards();
                if(i!=numPlayers-1)cout<<type<<i+1<<" Total point: "<<BJPlayer[i].getcardsum()<<" Points]"<<endl;
                else cout<<type<<" Total point: "<<BJPlayer[i].getcardsum()<<" Points]"<<endl;


                Ta.showNextCardProb(BJPlayer[i].topface());
                Ta.getBustingProb(BJPlayer[i].getcardminsum(),BJPlayer[i].topface()); //print bsting prob


                cout <<"What do you want to do? "<<endl;
                //players[i].action(poker);
                {
                    int in;
                    while(1)
                    {
                        cout<<"1. Hit. 2. Stand. 3. Double.(選擇一個)"<<endl;
                        do
                        {
                            cin>>in;
                            if(cin.fail())
                            {
                                cout<<"Please input correct number(1 or 2 or 3) : ";
                                cin.clear();
                                cin.ignore();
                                in = -1;
                            }
                            else if(!(in>0&&in<4))cout<<"Error input,please input again : ";
                        }
                        while(!(in>0&&in<4));

                        if(in==1)
                        {
                            Bpoker.dealCard(BJPlayer[i],1);
                            //
                        }
                        else if(in==2)
                        {
                            break;
                        }
                        else if(in==3)
                        {
                            if((BJPlayer[i].getcoins()-BJPlayer[i].getbet()*2)>=0)BJPlayer[i].setbet((BJPlayer[i].getbet())*2);
                            Bpoker.dealCard(BJPlayer[i],1);
                            //if(BJPlayer[i].status()==0)break;
                            cout<<"換下一個玩家 ===================================================="<<endl;
                            break;
                        }
                        if(i!=numPlayers-1)cout<<"玩家"<<i+1<<" Total point: "<<BJPlayer[i].getcardsum()<<" Points]"<<endl;
                        else cout<<"莊家"<<"Total point: "<<BJPlayer[i].getcardsum()<<" Points]"<<endl;

                        BJPlayer[i].showCards();
                        if(BJPlayer[i].status()==0)break;
                        else
                        {
                            Ta.showNextCardProb(BJPlayer[i].topface());
                            Ta.getBustingProb(BJPlayer[i].getcardminsum(),BJPlayer[i].topface()); //print bsting prob
                        }
                        cout <<"What do you want to do? "<<endl;

                    }

                }

                cout<<endl;
            }

            cout<<"--------------------------------------------"<<endl;
            /*第六階段模擬：結算*/
            int minnum=21;  //temp for calculate winnwer
            int win=0,nowin=1;
            for(int i=0; i<numPlayers; i++)
            {
                //PokerCards
                if(i!=numPlayers-1)cout <<"玩家 "<<i+1;
                else cout<< "莊家";

                cout<<" have: "<<"[Total point: "<<BJPlayer[i].getcardsum()<<" Points]"<<endl;
                cout <<"show card :";

                BJPlayer[i].showCards();
                if(BJPlayer[i].getcardsum()<=21&&abs(BJPlayer[i].getcardsum()-21)<minnum)
                {
                    win = BJPlayer[i].getcardsum();
                    minnum=abs(BJPlayer[i].getcardsum()-21);
                    nowin = 0;
                }
                else if(BJPlayer[i].getcardsum()>21)
                {
                    cout<<"Oh !Busting!!"<<endl;
                }

                BJPlayer[i].setcoin(BJPlayer[i].getcoins()-BJPlayer[i].getbet());
            }
            cout<<"--------------------------------------------"<<endl;
            if(nowin==1)win = -1;
            for(int i=0; i<numPlayers-1; i++)  //不用計算莊家
            {
                if(BJPlayer[i].getcardsum()==win)
                {
                    BJPlayer[i].setcoin(BJPlayer[i].getcoins()+BJPlayer[i].getbet()*2);
                    cout<<"Player "<<i+1<<" has "<<BJPlayer[i].getcoins()<<" coins."<<endl;
                }
                else
                {
                    cout<<"Player "<<i+1<<" has "<<BJPlayer[i].getcoins()<<" coins."<<endl;
                }

            }

            /*第七階段模擬：結束*/

            cout<<"--------------------------------------------"<<endl;
            cout<<"Thanks you use this program play BlackJack"<<endl;
            /******21點結束***************/
            cout<<"是否回到首頁(y) 結束(any key) "<<endl;;
            //cout<<"即使按Y也是會結束遊戲^_^"<<endl;
            cin.clear();
            cin.ignore();
            char pp;
            pp = getch();
            //cin>>pp;
            if(toupper(pp)!='Y')return 0;
            //break;
            system("cls");


            }
            else if (chose ==0)
            {
            /*****************************************************
            *
            *分隔線
            *接下來是梭哈
            *
            *
            *
            *
            *
            *
            *
            *
            *******************************************************/
                {

                SoHandPokerCards Sopoker(setdeck);
                deckcard = setdeck*Deck_number;

                //破解區
                cout<<"前置破解中~~~~"<<endl;
                srand(time(NULL));
                EricShuffler test;
                test.shuffleCard(Sopoker);
                Hacker Ta(setdeck);
                Ta.Estimate(hacknum,test,setdeck);
                Ta.PrintProbs();
                cout<<"破解完成"<<endl;

                cout<<"====================================================================="<<endl;
                cout<<"歡迎來到小小梭哈!"<<endl<<"請輸入有幾個玩家?(大於1人小於11人)"<<endl;
                /*前置作業*/
                //cout << "How many players? ";  //set players
                do
                {
                    numPlayers = checkinputnum();
                    if(numPlayers>11||numPlayers<2)cout<<"輸入人數異常請重新輸入 :";
                }
                while(numPlayers>11||numPlayers<2);
                char cardface[][3] = {{'A'},{'2'},{'3'},{'4'},{'5'},{'6'},{'7'},{'8'},{'9'},{"10"},{'J'},{'Q'},{'K'}};

                //cin>>numPlayers;
                remainpp = numPlayers; //設定初始值為玩家數 若為0代表遊戲不需要維持

                playersort = new int[numPlayers];
                score = new int[numPlayers];
                status = new int[numPlayers];

                SoHandPlayer *Soplayers = new SoHandPlayer[numPlayers];
                //setdeck = (numPlayers*5)%52+1;

                gametimes = 0;

                /*設定賭金 */

                //cout << "How many coins do each player have? "<<endl; //set evey player's coins
                for(int i=0; i<numPlayers; i++)
                {
                    //cout<<"Player "<<i<<" have: ";
                    cout<<"請輸入玩家"<<i+1<<"有多少籌碼(大於0)? ";
                    Soplayers[i].setcoin();

                    score[i]=0;
                    status[i] = 1;
                }
                //2-1的洗牌就先不用了
                //poker.shuffle();


                /* 發牌動作 */
                for (int c=0; c<2; c++) // 每人輪流得一張牌，共得numCards張牌
                    for (int p=0; p<numPlayers; p++)
                    {
                        if(c==0)Soplayers[p].sethandcard(6);
                        Sopoker.dealCard(Soplayers[p], 1);
                    }

                needend = 0;
                Show_Hand = false;
                toend = false;
                while(1) //game loop forever
                {


                    if(gametimes==0)
                    {
                        cout<<"遊戲開始囉!"<<endl;

                    }
                    else
                    {
                        for (int p=0; p<numPlayers; p++)
                        {
                            if(status[p])Sopoker.dealCard(Soplayers[p], 1);
                        }
                    }
                    cout<<"----------------------我是分隔線------------------------"<<endl;
                    cout<<"第"<<gametimes+1<<"回合"<<endl;

                    //nowmax =0;
                    vector<int> ptest;
                    for(int p=0,t=0; p<numPlayers; p++)
                    {
                        if(status[p])
                        {
                            cout<<"玩家"<<p+1<<"的牌面為: ";
                            Soplayers[p].playerShowcard(false);

                            cout<<endl;
                            cardtop = Soplayers[p].check_handcard(false);
                            cout<<" "<<cardsuits[cardtop/100]<<"最大點為 :"<<cardtop%100<<endl<<endl;


                            ptest.push_back(cardtop);
                            playersort[t++] = cardtop;
                            //if(cardtop>t){t=cardtop; nowmax = t;}
                        }
                        else
                        {
                            cout<<"玩家"<<p+1<<" 目前棄權!"<<endl<<endl;
                        }

                    }
                    //vector<int> myvector (playersort, playersort+5);
                    sort (playersort, playersort+numPlayers);
                    reverse(playersort,playersort+numPlayers);
                    //for(int p=0;p<numPlayers;p++)cout<<playersort[p];

                    order = 0;
                    chose=0;
                    if(!Show_Hand&&!toend)
                    {
                        do
                        {
                            for(int p=0; p<numPlayers; p++)
                            {
                                if(Soplayers[p].check_handcard(false)==playersort[order])nowmax = p;
                                //cout<<players[p].check_handcard(false);
                            }
                            //cout<<playersort[0];
                            if(Soplayers[nowmax].getcoins()==0)
                            {
                                cout<<"你沒錢了 無法喊點數 輪下一人!!"<<endl;
                                order++;
                                chose = 2;
                            }
                            else
                            {
                                //system("cls");
                                cout<<"玩家"<<nowmax+1<<"最大"<<endl;
                                //第一次喊話 這裡要印出機率//2014/04/08

                                cout<<"Show player "<<nowmax+1<<"'s next card face probability!!"<<endl;
                                Ta.showNextCardProb(Soplayers[nowmax].topface());
                                for(int pp=0; pp<9; pp++)tempprobabilityofcard[pp]=tempofcardmax[pp]=0;
                                /*接下來這段想實現 可以告訴使用者下一次牌型的機率*/

                                for(int pp=0; pp<13; pp++)
                                {
                                    double temppp = Ta.getNextCardProb(Soplayers[nowmax].topface(),pp+1);
                                    Soplayers[nowmax].giveCard(1,pp+1);
                                    cardtop = Soplayers[nowmax].check_handcard(false);
                                    tempprobabilityofcard[cardtop/100]+=temppp;
                                    if((cardtop%100)>tempofcardmax[cardtop/100])tempofcardmax[cardtop/100]=(cardtop%100);
                                    Soplayers[nowmax].deletetopCard();
                                }
                                for(int pp=0; pp<9; pp++)
                                {
                                    if(tempprobabilityofcard[pp]>0)
                                    {
                                        cout<<"牌型:"<<cardsuits[pp]<<" 機率:"<<setprecision(3)<<tempprobabilityofcard[pp]<<" 最大牌面可能為: "<<tempofcardmax[pp]<<endl;
                                    }
                                }
                                cout<<"以上預測僅供參考"<<endl;
                                /*到這裡結束 */
                                cout<<"請說話:1.我要賭 2.放棄不賭 :"<<endl;
                                do
                                {
                                    chose = checkinputnum();
                                    if(chose!=2&&chose!=1)cout<<"請輸入 1 or 2 :";
                                }
                                while(chose!=2&&chose!=1);
                                if(chose==2)
                                {
                                    order++;
                                    status[nowmax]=0;
                                    remainpp--;
                                }
                            }

                            //cin>>chose;



                            //cout<<"@"<<nowmax;
                            if(order>=numPlayers-1)break;
                        }
                        while(chose!=1);
                    }

                    if(remainpp==1)
                    {
                        if(toend==false)cout<<"贏家產生"<<endl;
                        toend = true;
                    }
                    else if(!Show_Hand)
                    {
                        cout<<"請輸入你想賭多少錢(不得超過自己賭資或小於等於0)    目前賭資剩餘:"<<Soplayers[nowmax].getcoins()<<endl;
                        Soplayers[nowmax].setbet();
                        int temp  = Soplayers[nowmax].getbet()+Soplayers[nowmax].gettotalbet();
                        Soplayers[nowmax].settotalbet(temp);
                        Soplayers[nowmax].setcoin(Soplayers[nowmax].getcoins()-Soplayers[nowmax].getbet());
                        cout<<"玩家 "<<nowmax+1<<" 賭了 "<<Soplayers[nowmax].getbet()<<"元!"<<endl;
                        if(Soplayers[nowmax].getcoins()==0)
                        {
                            Show_Hand=true;
                            cout<<"Show Hand!!!!!"<<endl;
                        }
                    }
                    //
                    for(int p = 0; (p<numPlayers)&&!toend; p++)
                    {
                        if(status[p])
                        {
                            do
                            {
                                if(p!=nowmax)
                                {

                                    cout<<"----------------------我是分隔線------------------------"<<endl;

                                    //這裡印出跟牌的使用者機率
                                    cout<<"Show player "<<p+1<<"'s next card face probability!!"<<endl;
                                    cout<<"以下印出下輪發牌後最大牌組的機率"<<endl;
                                    Ta.showNextCardProb(Soplayers[p].topface());
                                    for(int pp=0; pp<9; pp++)tempprobabilityofcard[pp]=tempofcardmax[pp]=0;
                                    /*接下來這段想實現 可以告訴使用者下一次牌型的機率*/

                                    for(int pp=0; pp<13; pp++)
                                    {
                                        double temppp = Ta.getNextCardProb(Soplayers[nowmax].topface(),pp+1);
                                        Soplayers[p].giveCard(1,pp+1);
                                        cardtop = Soplayers[p].check_handcard(false);
                                        tempprobabilityofcard[cardtop/100]+=temppp;
                                        if((cardtop%100)>tempofcardmax[cardtop/100])tempofcardmax[cardtop/100]=(cardtop%100);
                                        Soplayers[p].deletetopCard();
                                    }
                                    for(int pp=0; pp<9; pp++)
                                    {
                                        if(tempprobabilityofcard[pp]>0)
                                        {
                                            cout<<"牌型:"<<cardsuits[pp]<<" 機率:"<<setprecision(3)<<tempprobabilityofcard[pp]<<" 最大牌面可能為: "<<tempofcardmax[pp]<<endl;
                                        }
                                    }
                                    cout<<"以上預測僅供參考"<<endl;
                                    /*到這裡結束 */


                                    if(Soplayers[nowmax].getbet()>=Soplayers[p].getcoins()||Show_Hand)
                                    {
                                        if(Soplayers[nowmax].getbet()>=Soplayers[p].getcoins())cout<<"錢不夠了 ";
                                        cout<<"請問玩家"<<p+1<<"是否要梭哈?(1是梭了2是放棄)"<<endl;
                                    }
                                    else
                                    {
                                        cout<<"請問玩家"<<p+1<<"是否要跟著玩家"<<nowmax+1<<"賭"<<Soplayers[nowmax].getbet()<<"元?(1是跟2是放棄)"<<endl;
                                        cout<<"(目前剩餘:"<<Soplayers[p].getcoins()<<"元)"<<endl;
                                    }
                                    do
                                    {
                                        chose = checkinputnum();
                                        if(chose!=2&&chose!=1)cout<<"請正確輸入 1 or 2 :";
                                    }
                                    while(chose!=2&&chose!=1);

                                    //cin>>chose;
                                    if(chose==2)
                                    {
                                        cout<<"玩家"<<p+1<<"選擇放棄不跟"<<endl;
                                        status[p]=0;
                                        remainpp--;
                                    }
                                    else if(chose == 1&&Soplayers[nowmax].getbet()>=Soplayers[p].getcoins())
                                    {
                                        Show_Hand = true;
                                        cout<<"玩家"<<p+1<<"錢不夠只好梭了!!"<<endl;
                                        Soplayers[p].setbet(Soplayers[p].getcoins());
                                        int temp = Soplayers[p].getbet()+Soplayers[p].gettotalbet();
                                        Soplayers[p].settotalbet(temp);
                                        Soplayers[p].setcoin(0);
                                    }
                                    else if(chose ==1&&Show_Hand)
                                    {
                                        cout<<"玩家"<<p+1<<"選擇跟著梭了!!"<<endl;
                                        Soplayers[p].setbet(Soplayers[p].getcoins());
                                        int temp = Soplayers[p].getbet()+Soplayers[p].gettotalbet();
                                        Soplayers[p].settotalbet(temp);
                                        Soplayers[p].setcoin(0);
                                    }
                                    else if(chose ==1)
                                    {
                                        cout<<"玩家"<<p+1<<"選擇跟上賭注!!"<<endl;
                                        Soplayers[p].setbet(Soplayers[nowmax].getbet());
                                        int temp = Soplayers[p].getbet()+Soplayers[p].gettotalbet();
                                        Soplayers[p].settotalbet(temp);
                                        Soplayers[p].setcoin(Soplayers[p].getcoins()-Soplayers[p].getbet());
                                        cout<<"(目前剩餘:"<<Soplayers[p].getcoins()<<"元)"<<endl;
                                    }
                                }
                                else break;

                            }
                            while(chose<1||chose>2);

                        }

                    }

                    gametimes++;
                    if(Show_Hand)
                    {
                        toend = true;
                    }


                    if(gametimes>=4||remainpp==1)
                    {
                        //cout<<"game over";
                        int t=0;
                        cout<<"----------------------我是分隔線------------------------"<<endl;
                        cout<<"開牌!"<<endl;
                        for(int p=0; p<numPlayers; p++)
                        {
                            if(status[p])
                            {
                                cout<<"玩家"<<p+1<<"的牌面為: ";
                                Soplayers[p].playerShowcard(true);

                                cout<<endl;
                                cardtop = Soplayers[p].check_handcard(true);
                                cout<<"牌型為"<<cardsuits[cardtop/100]<<"最大點為 :"<<cardface[cardtop%100-1]<<endl<<endl;


                                ptest.push_back(cardtop);
                                playersort[t++] = cardtop;
                                //if(cardtop>t){t=cardtop; nowmax = t;}
                            }
                            else
                            {
                                cout<<"玩家"<<p+1<<" 目前棄權!"<<endl<<endl;
                            }
                        }

                        sort (playersort, playersort+t);
                        reverse(playersort, playersort+t);
                        //統計所有賭金  //統計勝者人數
                        int mm = 0,vv=0;
                        for(int p = 0; p<numPlayers; p++)
                        {
                            mm+=Soplayers[p].gettotalbet();
                            if(Soplayers[p].check_handcard(true)==playersort[0])vv++;
                        }
                        mm/=vv;
                        cout<<"本局結束!"<<endl;
                        cout<<"----------------------我是分隔線------------------------"<<endl;
                        cout<<"以下印出各玩家剩餘賭資"<<endl;
                        //以下統計賭資
                        for(int p=0; p<numPlayers; p++)
                        {
                            if(Soplayers[p].check_handcard(true)==playersort[0])
                            {
                                Soplayers[p].setcoin(Soplayers[p].getcoins()+mm);
                                cout <<"本局獲勝者"<<(char)2;
                            }
                            else
                            {
                                //Soplayers[p].setcoin(Soplayers[p].getcoins()-Soplayers[p].getbet();
                            }
                            if(Soplayers[p].getcoins()==0)cout<<"玩家 "<<p+1<<"破產了"<<endl;
                            else cout<<"玩家 "<<p+1<<" 賭資為: "<<Soplayers[p].getcoins()<<endl;
                        }

                        break;
                    }

                }

            }
            cout<<"是否回到首頁(Y or 任意鍵代表結束)?? "<<endl;;
            //cout<<"即使按Y也是會結束遊戲^_^"<<endl;
            cin.clear();
            cin.ignore();
            char pp;
            //cin>>pp;
            pp = getch();
            if(toupper(pp)!='Y')return 0;
            //break;
            system("cls");
        }
        else
        {
            return 0;
        }




    }

    }
    return 0;
}

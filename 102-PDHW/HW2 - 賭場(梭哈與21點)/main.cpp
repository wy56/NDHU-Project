/* 410221002 ��u�@ ������ */

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
#define setdeck 1 //��soha�w��1�ƵP��

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
    0.���P�_�n���

    1.�@�}�l���T�{���h�֪��a

    2.�T�{���a��T�{�C�쪱�a���h�ֽ��(�j��0)

    3.�Ĥ@�^�X�C�쪱�a��o�@�i�t�P(�\�ۤ��Q�O�H�ݨ�)�Τ@�i���P(���}�|���H�ݨ�)�A��l�^�X�C�쪱�a����o�@�i���P

    4.�ھڪ��a���P���I�Ƥj�p�A�I�Ƴ̤j�̳ۥX�n��h�ֿ��A�Y���۫h�M��U�@���I�Ƴ̤j��
      (�p�G�O21�I �h�C�H���I�� ���촫�U�@�ӤH)
    5.�߰ݳѤU�����a�O�_�]�n�U�ۦP��`�A�_�h���C
       (�p�G�O21�I �h���쵲��)
    6.����3~5����C�쪱�a�@��5�i�P��
        (�p�G�O21�I ���_��C�ӤH����)
    7.�C�쪱�a�N�t�P�G�X��j�p�AĹ����o��`
       (�p�G�O21�I ����C�ӤH�P���j�p)

    */
    int numPlayers;  // ���a�ƶq
    //int setdeck=1; //
    int deckcard,needend;// �P�� //needend �P�_����
    int gametimes,remainpp; //gametimes �C���^�X //remainpp �Ѿl���a
    int chose,cardtop,nowmax,nowbet; //chose �����a�ﶵ cardtop���ثe�̤j
    int *playersort,order,*score,*status;//status ���a�~�� score ��`�� order ����
    bool Show_Hand,toend;
    string cardsuits[9] = {"���P","�@��","�G��","�T��","���l","�P��","��Ī","�K��","�P�ᶶ"};
    char cardface[][3] = {{'A'},{'2'},{'3'},{'4'},{'5'},{'6'},{'7'},{'8'},{'9'},{"10"},{'J'},{'Q'},{'K'}};
    double tempprobabilityofcard[9];
    int tempofcardmax[9];

    int numDecks;//�³ǧJ�� ��J�P�ռ�

    while(1) //���D���a���Q��
    {

        /*�ʵe�� */
        srand(time(NULL));
//        cout<<"�п�ܭn������? 1:21�I 2:���� ->";
//        cin>>chose;
        chose = getmenu();
                {
        if(chose==2)exit(0);
        else if(chose ==1)cout<<"���a��ܪ� 21�I! "<<endl;
        else if(chose ==0)cout<<"���a��ܪ� ����! "<<endl;

        for(int j=0;j<70;j++)
        {
            if(j<30)_sleep(rand()%20+10);
            else if(j>60)_sleep(rand()%150+250);
            else _sleep(rand()%80+40);
            cout<<(j*100.0/70)<<"%"<<"Ū���i��";
            //for(int i=0;i<j;i++)
            //{
            cout<<"\r"<<setfill((char)2)<<setw(j)<<flush;//cout<<(char)2;
            //}
            cout.clear();
        }
        system("cls");
        //cout<<"\r"<<setfill((char)2)<<setw(70)<<endl;
        cout<<setfill((char)2)<<setw(80)<<"100%Ū������!!"<<endl;
        /*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
        cout.clear();
        //cout.unsetf( ios::setfill);
        cout<<setfill(' ');
        //cout << "\rNow hacking: " << i * 100 / n << "%" << flush;
        }

        {

            //cout<<"�п�J1��21�I�A�άO2�������A�άO��L���� :";
            //cin>>chose;

            if(chose==1)//21�I
            {
                /* �Ĥ@���q����: �P�� */
                cout<<"�w�]�}�ѵo�P�W�ߦ��� 10�U�� ��ĳ�Τ@�յP��"<<endl;
                cout<<"�V�h�ծɶ��e�u�ʥi��#define hacknum 100 �ק�"<<endl;
                cout<<"�w�]�o�P�i�Ƭ� 2 �]���O21�I��"<<endl<<endl;
                cout << "<This is a BlackJack game(21�I)>"<<endl;
                /*1�e�m�@�~*/
                cout << "How many decks of cards do you want? "; //set decks
                cin >> numDecks;
                EricShuffler test;

                /**�~��**************************/
                BlackJackPokerCards Bpoker(numDecks);


                /**����v**************/
                Hacker Ta(numDecks);
                Ta.Estimate(hacknum,test,numDecks);

                Ta.PrintProbs();

                cout << "�X�Ӫ��a (>= 2)? ";  //set players
            do//�ܤֵP�ժ��P�O���a��5�� �Ա��Ѧһ������
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

            numPlayers+=1; ////�]���h�F���a

            BlackJackPlayer *BJPlayer = new BlackJackPlayer[numPlayers+1];


            /* �ĤG���q�����G�o�P�ʧ@ */
            for (int c=0; c<2; c++) // �C�H���y�o�@�i�P�A�@�onumCards�i�P �o�̹w�]2
                for (int p=0; p<numPlayers; p++)
                {
                    if(c==0)BJPlayer[p].sethandcard(numDecks);
                    Bpoker.dealCard(BJPlayer[p], 1);
                }
                /* �ĤT���q�����G�]�w��� */
            cout<<"���a�ꥻ�סססס�"<<endl;
            //cout << "How many coins do each player have? "<<endl; //set evey player's coins
            //for(int i=0; i<numPlayers; i++)
            for(int i=0; i<numPlayers-1; i++)  //�o�̦h�F���a �ҥH�n-1
            {
                cout<<"���a "<<i+1<<" ��: ";
                //cout<<"Player "<<i<<" have: ";
                BJPlayer[i].setcoin();
            }

            /* �ĥ|���q�����G�]�w��` */
            cout<<"�U�`�סססס�"<<endl;
            //cout << "How much do each player want to bet? "<<endl;
            //for(int i=0; i<numPlayers; i++)
            for(int i=0; i<numPlayers-1; i++)  //�o�̲��a���ΤU�`�� �ҥH�n-1
            {
                cout<<"���a "<<i+1<<" �U�`: ";
                //cout<<"Player "<<i<<" have: ";
                BJPlayer[i].setbet();
            }

            cout<<"******* �����o�P *******"<<endl;
            for(int i=0; i<numPlayers; i++)
            {
                if(i==numPlayers-1)cout<<"���a��P :";
                else cout<<"���a "<<i+1<<" ��P :";
                BJPlayer[i].showCards();
            }

            cout<<"============Game start============"<<endl;
            cout<<"============ �C���}�l ============"<<endl;
            /*�Ĥ����q�����G���a���j*/

            char *type;
            char player[10] = "���a ";
            char chief[10] = "���a ";
            for(int i=0; i<numPlayers; i++)
            {
                if(i!=numPlayers-1)type = player;
                else type = chief;
                //cout <<"Player "<<i<<"'s round. "<<"[Total point: "<<players[i].getcardsum()<<" Points]"<<endl;
                //cout <<"Player "<<i<<"'s card ->";
                if(i!=numPlayers-1)cout<<type<<i+1<<" ��P -->";
                else cout<<type<<" ��P -->";
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
                        cout<<"1. Hit. 2. Stand. 3. Double.(��ܤ@��)"<<endl;
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
                            cout<<"���U�@�Ӫ��a ===================================================="<<endl;
                            break;
                        }
                        if(i!=numPlayers-1)cout<<"���a"<<i+1<<" Total point: "<<BJPlayer[i].getcardsum()<<" Points]"<<endl;
                        else cout<<"���a"<<"Total point: "<<BJPlayer[i].getcardsum()<<" Points]"<<endl;

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
            /*�Ĥ����q�����G����*/
            int minnum=21;  //temp for calculate winnwer
            int win=0,nowin=1;
            for(int i=0; i<numPlayers; i++)
            {
                //PokerCards
                if(i!=numPlayers-1)cout <<"���a "<<i+1;
                else cout<< "���a";

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
            for(int i=0; i<numPlayers-1; i++)  //���έp����a
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

            /*�ĤC���q�����G����*/

            cout<<"--------------------------------------------"<<endl;
            cout<<"Thanks you use this program play BlackJack"<<endl;
            /******21�I����***************/
            cout<<"�O�_�^�쭺��(y) ����(any key) "<<endl;;
            //cout<<"�Y�ϫ�Y�]�O�|�����C��^_^"<<endl;
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
            *���j�u
            *���U�ӬO����
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

                //�}�Ѱ�
                cout<<"�e�m�}�Ѥ�~~~~"<<endl;
                srand(time(NULL));
                EricShuffler test;
                test.shuffleCard(Sopoker);
                Hacker Ta(setdeck);
                Ta.Estimate(hacknum,test,setdeck);
                Ta.PrintProbs();
                cout<<"�}�ѧ���"<<endl;

                cout<<"====================================================================="<<endl;
                cout<<"�w��Ө�p�p����!"<<endl<<"�п�J���X�Ӫ��a?(�j��1�H�p��11�H)"<<endl;
                /*�e�m�@�~*/
                //cout << "How many players? ";  //set players
                do
                {
                    numPlayers = checkinputnum();
                    if(numPlayers>11||numPlayers<2)cout<<"��J�H�Ʋ��`�Э��s��J :";
                }
                while(numPlayers>11||numPlayers<2);
                char cardface[][3] = {{'A'},{'2'},{'3'},{'4'},{'5'},{'6'},{'7'},{'8'},{'9'},{"10"},{'J'},{'Q'},{'K'}};

                //cin>>numPlayers;
                remainpp = numPlayers; //�]�w��l�Ȭ����a�� �Y��0�N��C�����ݭn����

                playersort = new int[numPlayers];
                score = new int[numPlayers];
                status = new int[numPlayers];

                SoHandPlayer *Soplayers = new SoHandPlayer[numPlayers];
                //setdeck = (numPlayers*5)%52+1;

                gametimes = 0;

                /*�]�w��� */

                //cout << "How many coins do each player have? "<<endl; //set evey player's coins
                for(int i=0; i<numPlayers; i++)
                {
                    //cout<<"Player "<<i<<" have: ";
                    cout<<"�п�J���a"<<i+1<<"���h���w�X(�j��0)? ";
                    Soplayers[i].setcoin();

                    score[i]=0;
                    status[i] = 1;
                }
                //2-1���~�P�N�����ΤF
                //poker.shuffle();


                /* �o�P�ʧ@ */
                for (int c=0; c<2; c++) // �C�H���y�o�@�i�P�A�@�onumCards�i�P
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
                        cout<<"�C���}�l�o!"<<endl;

                    }
                    else
                    {
                        for (int p=0; p<numPlayers; p++)
                        {
                            if(status[p])Sopoker.dealCard(Soplayers[p], 1);
                        }
                    }
                    cout<<"----------------------�ڬO���j�u------------------------"<<endl;
                    cout<<"��"<<gametimes+1<<"�^�X"<<endl;

                    //nowmax =0;
                    vector<int> ptest;
                    for(int p=0,t=0; p<numPlayers; p++)
                    {
                        if(status[p])
                        {
                            cout<<"���a"<<p+1<<"���P����: ";
                            Soplayers[p].playerShowcard(false);

                            cout<<endl;
                            cardtop = Soplayers[p].check_handcard(false);
                            cout<<" "<<cardsuits[cardtop/100]<<"�̤j�I�� :"<<cardtop%100<<endl<<endl;


                            ptest.push_back(cardtop);
                            playersort[t++] = cardtop;
                            //if(cardtop>t){t=cardtop; nowmax = t;}
                        }
                        else
                        {
                            cout<<"���a"<<p+1<<" �ثe���v!"<<endl<<endl;
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
                                cout<<"�A�S���F �L�k���I�� ���U�@�H!!"<<endl;
                                order++;
                                chose = 2;
                            }
                            else
                            {
                                //system("cls");
                                cout<<"���a"<<nowmax+1<<"�̤j"<<endl;
                                //�Ĥ@���۸� �o�̭n�L�X���v//2014/04/08

                                cout<<"Show player "<<nowmax+1<<"'s next card face probability!!"<<endl;
                                Ta.showNextCardProb(Soplayers[nowmax].topface());
                                for(int pp=0; pp<9; pp++)tempprobabilityofcard[pp]=tempofcardmax[pp]=0;
                                /*���U�ӳo�q�Q��{ �i�H�i�D�ϥΪ̤U�@���P�������v*/

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
                                        cout<<"�P��:"<<cardsuits[pp]<<" ���v:"<<setprecision(3)<<tempprobabilityofcard[pp]<<" �̤j�P���i�ର: "<<tempofcardmax[pp]<<endl;
                                    }
                                }
                                cout<<"�H�W�w���ȨѰѦ�"<<endl;
                                /*��o�̵��� */
                                cout<<"�л���:1.�ڭn�� 2.��󤣽� :"<<endl;
                                do
                                {
                                    chose = checkinputnum();
                                    if(chose!=2&&chose!=1)cout<<"�п�J 1 or 2 :";
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
                        if(toend==false)cout<<"Ĺ�a����"<<endl;
                        toend = true;
                    }
                    else if(!Show_Hand)
                    {
                        cout<<"�п�J�A�Q��h�ֿ�(���o�W�L�ۤv���Τp�󵥩�0)    �ثe���Ѿl:"<<Soplayers[nowmax].getcoins()<<endl;
                        Soplayers[nowmax].setbet();
                        int temp  = Soplayers[nowmax].getbet()+Soplayers[nowmax].gettotalbet();
                        Soplayers[nowmax].settotalbet(temp);
                        Soplayers[nowmax].setcoin(Soplayers[nowmax].getcoins()-Soplayers[nowmax].getbet());
                        cout<<"���a "<<nowmax+1<<" ��F "<<Soplayers[nowmax].getbet()<<"��!"<<endl;
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

                                    cout<<"----------------------�ڬO���j�u------------------------"<<endl;

                                    //�o�̦L�X��P���ϥΪ̾��v
                                    cout<<"Show player "<<p+1<<"'s next card face probability!!"<<endl;
                                    cout<<"�H�U�L�X�U���o�P��̤j�P�ժ����v"<<endl;
                                    Ta.showNextCardProb(Soplayers[p].topface());
                                    for(int pp=0; pp<9; pp++)tempprobabilityofcard[pp]=tempofcardmax[pp]=0;
                                    /*���U�ӳo�q�Q��{ �i�H�i�D�ϥΪ̤U�@���P�������v*/

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
                                            cout<<"�P��:"<<cardsuits[pp]<<" ���v:"<<setprecision(3)<<tempprobabilityofcard[pp]<<" �̤j�P���i�ର: "<<tempofcardmax[pp]<<endl;
                                        }
                                    }
                                    cout<<"�H�W�w���ȨѰѦ�"<<endl;
                                    /*��o�̵��� */


                                    if(Soplayers[nowmax].getbet()>=Soplayers[p].getcoins()||Show_Hand)
                                    {
                                        if(Soplayers[nowmax].getbet()>=Soplayers[p].getcoins())cout<<"�������F ";
                                        cout<<"�аݪ��a"<<p+1<<"�O�_�n����?(1�O���F2�O���)"<<endl;
                                    }
                                    else
                                    {
                                        cout<<"�аݪ��a"<<p+1<<"�O�_�n��۪��a"<<nowmax+1<<"��"<<Soplayers[nowmax].getbet()<<"��?(1�O��2�O���)"<<endl;
                                        cout<<"(�ثe�Ѿl:"<<Soplayers[p].getcoins()<<"��)"<<endl;
                                    }
                                    do
                                    {
                                        chose = checkinputnum();
                                        if(chose!=2&&chose!=1)cout<<"�Х��T��J 1 or 2 :";
                                    }
                                    while(chose!=2&&chose!=1);

                                    //cin>>chose;
                                    if(chose==2)
                                    {
                                        cout<<"���a"<<p+1<<"��ܩ�󤣸�"<<endl;
                                        status[p]=0;
                                        remainpp--;
                                    }
                                    else if(chose == 1&&Soplayers[nowmax].getbet()>=Soplayers[p].getcoins())
                                    {
                                        Show_Hand = true;
                                        cout<<"���a"<<p+1<<"�������u�n���F!!"<<endl;
                                        Soplayers[p].setbet(Soplayers[p].getcoins());
                                        int temp = Soplayers[p].getbet()+Soplayers[p].gettotalbet();
                                        Soplayers[p].settotalbet(temp);
                                        Soplayers[p].setcoin(0);
                                    }
                                    else if(chose ==1&&Show_Hand)
                                    {
                                        cout<<"���a"<<p+1<<"��ܸ�۱��F!!"<<endl;
                                        Soplayers[p].setbet(Soplayers[p].getcoins());
                                        int temp = Soplayers[p].getbet()+Soplayers[p].gettotalbet();
                                        Soplayers[p].settotalbet(temp);
                                        Soplayers[p].setcoin(0);
                                    }
                                    else if(chose ==1)
                                    {
                                        cout<<"���a"<<p+1<<"��ܸ�W��`!!"<<endl;
                                        Soplayers[p].setbet(Soplayers[nowmax].getbet());
                                        int temp = Soplayers[p].getbet()+Soplayers[p].gettotalbet();
                                        Soplayers[p].settotalbet(temp);
                                        Soplayers[p].setcoin(Soplayers[p].getcoins()-Soplayers[p].getbet());
                                        cout<<"(�ثe�Ѿl:"<<Soplayers[p].getcoins()<<"��)"<<endl;
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
                        cout<<"----------------------�ڬO���j�u------------------------"<<endl;
                        cout<<"�}�P!"<<endl;
                        for(int p=0; p<numPlayers; p++)
                        {
                            if(status[p])
                            {
                                cout<<"���a"<<p+1<<"���P����: ";
                                Soplayers[p].playerShowcard(true);

                                cout<<endl;
                                cardtop = Soplayers[p].check_handcard(true);
                                cout<<"�P����"<<cardsuits[cardtop/100]<<"�̤j�I�� :"<<cardface[cardtop%100-1]<<endl<<endl;


                                ptest.push_back(cardtop);
                                playersort[t++] = cardtop;
                                //if(cardtop>t){t=cardtop; nowmax = t;}
                            }
                            else
                            {
                                cout<<"���a"<<p+1<<" �ثe���v!"<<endl<<endl;
                            }
                        }

                        sort (playersort, playersort+t);
                        reverse(playersort, playersort+t);
                        //�έp�Ҧ����  //�έp�Ӫ̤H��
                        int mm = 0,vv=0;
                        for(int p = 0; p<numPlayers; p++)
                        {
                            mm+=Soplayers[p].gettotalbet();
                            if(Soplayers[p].check_handcard(true)==playersort[0])vv++;
                        }
                        mm/=vv;
                        cout<<"��������!"<<endl;
                        cout<<"----------------------�ڬO���j�u------------------------"<<endl;
                        cout<<"�H�U�L�X�U���a�Ѿl���"<<endl;
                        //�H�U�έp���
                        for(int p=0; p<numPlayers; p++)
                        {
                            if(Soplayers[p].check_handcard(true)==playersort[0])
                            {
                                Soplayers[p].setcoin(Soplayers[p].getcoins()+mm);
                                cout <<"������Ӫ�"<<(char)2;
                            }
                            else
                            {
                                //Soplayers[p].setcoin(Soplayers[p].getcoins()-Soplayers[p].getbet();
                            }
                            if(Soplayers[p].getcoins()==0)cout<<"���a "<<p+1<<"�}���F"<<endl;
                            else cout<<"���a "<<p+1<<" ��ꬰ: "<<Soplayers[p].getcoins()<<endl;
                        }

                        break;
                    }

                }

            }
            cout<<"�O�_�^�쭺��(Y or ���N��N����)?? "<<endl;;
            //cout<<"�Y�ϫ�Y�]�O�|�����C��^_^"<<endl;
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

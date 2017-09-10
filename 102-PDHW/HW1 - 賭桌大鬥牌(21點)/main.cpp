/* 410221002 資工一 陳韋佑 */

#include <iostream>
#include <ctime>  //for time()
#include <stdlib.h>  //for rand()
#include <vector>
#include <cmath> //for abs()
#include <iomanip>

#define Deck_number 52 //define a deck has 52 card

#define showcarddeck 0
#define hacknum 100000
//#define _debug
//#define

using namespace std;

//class Card;
//class Player;
//class PokerCards;



class Card
{
private:
    int suit;
    int face;
    int cardnum; //card reference
public:
    //Card(); // initial card data
    Card()
    {
        setsuit(0);
        setface(0);
    }
    //void show();
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
        if(suit==1)cout<<(char)6<<" "<<face;
        else if(suit==2)cout<<(char)3<<" "<<face;
        else if(suit==3)cout<<(char)4<<" "<<face;
        else if(suit==4)cout<<(char)5<<" "<<face;
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

    void setCard(int suit, int face)
    {
        setface(face);
        setsuit(suit);
    }
};

class Player
{
private:
    Card *ptrCards;
    int numCards;
    int coins;
    int bet;

public:
    Player()
    {
        numCards = 0;
    }
    Player(int n)
    {

    }
    void sethandcard(int deck)   //dynmatic set every player max card number
    {
        ptrCards = new Card[deck*Deck_number];
    }
    void giveCard(int s,int f)
    {
        ptrCards[numCards].setCard(s,f);
        numCards++;
    }
    void setcoin() //set coin
    {
        //int temp;
        do
        {
            cin>>coins;
            if(cin.fail())
            {
                cout<<"Please input correct coin number : ";
                cin.clear();
                cin.ignore();
                coins = -1;
            }
            else if(coins<=0)cout<<"(error input)input coins again : ";
        }
        while(coins<=0);
    }

    void setbet() //set every loop bet
    {
        //int temp;
        do
        {
            cin>>bet;
            if(cin.fail())
            {
                cout<<"Please input correct bet number : ";
                cin.clear();
                cin.ignore();
                bet = -1;
            }
            else if(bet<=0 ||bet>coins)cout<<"(error input)input bet again :";
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
    int getcardminsum()  //return the minimum sum of card
    {
        int sum=0,temp = 0;
        for(int i=0; i<numCards; i++)
        {
            temp = ptrCards[i].getface();
            if(temp>10)sum+=10;
            else sum+=temp;
        }
        return sum;
    }
    void setnumCards(int n)
    {
        numCards = n;
    }
    int getnumCards()
    {
        return numCards;
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
//    int  Bustingnum()  return  will Busting number
//    {
//
//    }


};

class PokerCards
{
private:
    Card *ptrCards;
    int numCards;
    int start;
    vector<Card> setofCards;
public:
    PokerCards()
    {

    }
    PokerCards(PokerCards &p)
    {
        start = p.start;
        numCards = p.numCards;
        ptrCards = (Card*)malloc(sizeof(Card)*p.numCards);
        for(int i = 0; i<numCards; i++)
        {
            ptrCards[i] = p.ptrCards[i];
        }

    }
    PokerCards(int n)
    {
        start = 0;
        //int start = 0;
        ptrCards = new Card[n*Deck_number];
        //pointerCards = vector<Card>
        numCards = n*Deck_number;

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
    ~PokerCards()
    {
        cout<<"Delete PokerCards..."<<endl;

        cout<<"Delete Finish..."<<endl;
    }


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

    //void shuffle();
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


    void shuffle(double pp[])
    {
        //srand(time(0));
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
    int getnumface(int n)
    {
        return ptrCards[n].getface();
    }
    //void displayCards();
    void displayCards()
    {
        for(int i = start; i<numCards; i++)
        {
            cout<<i+1<<":";
            ptrCards[i].show();
        }
    }
};


class EricShuffler
{
public:
    EricShuffler()
    {
        double cc=0; //check probsum is 1;
        double P[]= {0.1,0.1,0,0.1,0.1,0.05,0.05,0.05,0.05,0.1,0.2,0,0.1}; //©w¸q¾÷²v
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
    void shuffleCard(PokerCards& pc)
    {
        pc.reset();
        //cout<<"@@";
        pc.shuffle(ProbSum);
        //pc.displayCards();

    }
    void PrintProbs()
    {
        cout<<"Print every card probability"<<endl;
        for(int i=0; i<13; i++)cout<<i+1<<":"<<Prob[i]<<" ";
        cout<<endl;
    }

    void PrintProbSum()
    {
        cout<<"Print ProbSum"<<endl;
        for(int i=0; i<13; i++)cout<<i+1<<":"<<ProbSum[i]<<" ";
        cout<<endl;
    }

private:
    int getNextCard(int face, int *next_face) {}
    double Prob[13];
    double ProbSum[13];

};

class Hacker
{
public:
    Hacker(int M)
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
    void Estimate(int n, EricShuffler &sh,int deckn)
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
            for(int j=1; j<1000; j++); //delay

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
    void getNextCardProb(int face, double *prob)
    {

    }
    void showNextCardProb(int face)
    {
        cout<<"Prob Matrix:"<<endl;

        for(int i = 0; i<14; i++)
        {
            if(i==0)
            {
                for(int j=1; j<14; j++)cout<<setw(5)<<j<<" ";
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
    void PrintProbs()
    {
        cout<<"Prob Matrix:"<<endl<<" ";

        for(int i = 0; i<14; i++)
        {
            if(i==0)
            {
                for(int j=1; j<14; j++)cout<<setw(5)<<j;
            }
            for(int j=1; j<14&&i>0; j++)
            {
                if(j==1)
                {
                    cout<<setw(2)<<i;
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
        cout<<"Probability of Busting (ÃzµP¾÷²v) ="<<setw(6)<<pp;
        cout<<endl;
    }

private:
    //PokerCards *hackuse;
    double*** Count;
    double Prob[14][14];

};

int main()
{
//    PokerCards pppp(1);
//    PokerCards pp = pppp;
//    PokerCards tt(pp);
//    pppp.shuffle();
//    pppp.displayCards();
//    cout<<"============"<<endl;
//    pp.displayCards();
//
//    delete pp;
    srand(time(NULL));
    EricShuffler test;
    //test.PrintProbSum();
    //test.PrintProbs();

    //define
    cout<<"¹w³]¯}¸ÑµoµP³W«ß¦¸¼Æ 10¸U¦¸ «ØÄ³¥Î¤@²ÕµP²Õ"<<endl;
    cout<<"¶V¦h²Õ®É¶¡§e½u©Ê¥i¥Ñ#define hacknum 100 ­×§ï"<<endl;
    cout<<"¹w³]µoµP±i¼Æ¬° 2 ¦]¬°¬O21ÂI¹À"<<endl<<endl;

    //

    bool con_game = true;
    while(con_game)
    {

        {


            int numPlayers;
            int numCards=2;
            int numDecks;
            cout << "<This is a BlackJack game(21ÂI)>"<<endl;

            cout << "How many decks of cards do you want? "; //set decks
            cin >> numDecks;
            PokerCards poker(numDecks);
            //if(showcarddeck)poker.displayCards();
            test.shuffleCard(poker);

            if(showcarddeck)poker.displayCards();

            cout<<"(Step 1) Hacker estimation"<<endl;
            cout<<"Estimating from "<<hacknum<<" rounds of card shuffling."<<endl;
            Hacker Ta(numDecks);
            Ta.Estimate(hacknum,test,numDecks);
            Ta.PrintProbs();
            /*step 1 finish*/

            cout<<"(Step 2) Play game"<<endl;


            poker.shuffle(); // ¬~µP
            //poker.displayCards();

            cout << "´X­Óª±®a (>= 2)? ";  //set players
            do
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

            numPlayers+=1;

            Player* players = new Player[numPlayers+1];

            //cout << "How many cards can a player get? "; //set card (recommend 2)
            //cin >> numCards;

            /* ²Ä¤G¶¥¬q¼ÒÀÀ¡GµoµP°Ê§@ */
            for (int c=0; c<numCards; c++)
                for (int p=0; p<numPlayers; p++)
                {
                    if(c==0)players[p].sethandcard(numDecks);
                    poker.dealCard(players[p], 1);
                }

            /* ²Ä¤T¶¥¬q¼ÒÀÀ¡G³]©w½äª÷ */
            cout<<"ª±®a¸ê¥»¡×¡×¡×¡×¡×"<<endl;
            //cout << "How many coins do each player have? "<<endl; //set evey player's coins
            //for(int i=0; i<numPlayers; i++)
            for(int i=0; i<numPlayers-1; i++)
            {
                cout<<"ª±®a "<<i+1<<" ¦³: ";
                //cout<<"Player "<<i<<" have: ";
                players[i].setcoin();
            }

            cout<<"¤Uª`¡×¡×¡×¡×¡×"<<endl;
            //cout << "How much do each player want to bet? "<<endl;
            //for(int i=0; i<numPlayers; i++)
            for(int i=0; i<numPlayers-1; i++)
            {
                cout<<"ª±®a "<<i+1<<" ¤Uª`: ";
                //cout<<"Player "<<i<<" have: ";
                players[i].setbet();
            }
            cout<<"******* ­º½üµoµP *******"<<endl;
            for(int i=0; i<numPlayers; i++)
            {
                if(i==numPlayers-1)cout<<"²ø®a¤âµP :";
                else cout<<"ª±®a "<<i+1<<" ¤âµP :";
                players[i].showCards();
            }


            cout<<"============Game start============"<<endl;
            cout<<"============ ¹CÀ¸¶}©l ============"<<endl;
            /*²Ä¤­¶¥¬q¼ÒÀÀ¡Gª±®a½ü°j*/

            char *type;
            char player[10] = "ª±®a ";
            char chief[10] = "²ø®a ";
            for(int i=0; i<numPlayers; i++)
            {
                if(i!=numPlayers-1)type = player;
                else type = chief;
                //cout <<"Player "<<i<<"'s round. "<<"[Total point: "<<players[i].getcardsum()<<" Points]"<<endl;
                //cout <<"Player "<<i<<"'s card ->";
                if(i!=numPlayers-1)cout<<type<<i+1<<" ¤âµP -->";
                else cout<<type<<" ¤âµP -->";
                players[i].showCards();
                if(i!=numPlayers-1)cout<<type<<i+1<<" Total point: "<<players[i].getcardsum()<<" Points]"<<endl;
                else cout<<type<<" Total point: "<<players[i].getcardsum()<<" Points]"<<endl;


                Ta.showNextCardProb(players[i].topface());
                Ta.getBustingProb(players[i].getcardminsum(),players[i].topface()); //print bsting prob


                cout <<"What do you want to do? "<<endl;
                //players[i].action(poker);
                {
                    int in;
                    while(1)
                    {
                        cout<<"1. Hit. 2. Stand. 3. Double.(¿ï¾Ü¤@­Ó)"<<endl;
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
                            poker.dealCard(players[i],1);
                            //
                        }
                        else if(in==2)
                        {
                            break;
                        }
                        else if(in==3)
                        {
                            if((players[i].getcoins()-players[i].getbet()*2)>=0)players[i].setbet((players[i].getbet())*2);
                            poker.dealCard(players[i],1);
                            //if(players[i].status()==0)break;
                            cout<<"´«¤U¤@­Óª±®a ===================================================="<<endl;
                            break;
                        }
                        if(i!=numPlayers-1)cout<<"ª±®a"<<i+1<<" Total point: "<<players[i].getcardsum()<<" Points]"<<endl;
                        else cout<<"²ø®a"<<"Total point: "<<players[i].getcardsum()<<" Points]"<<endl;

                        players[i].showCards();
                        if(players[i].status()==0)break;
                        else
                        {
                            Ta.showNextCardProb(players[i].topface());
                            Ta.getBustingProb(players[i].getcardminsum(),players[i].topface()); //print bsting prob
                        }
                        cout <<"What do you want to do? "<<endl;

                    }

                }

                cout<<endl;
            }

            cout<<"--------------------------------------------"<<endl;
            /*²Ä¤»¶¥¬q¼ÒÀÀ¡Gµ²ºâ*/
            int minnum=21;  //temp for calculate winnwer
            int win=0,nowin=1;
            for(int i=0; i<numPlayers; i++)
            {
                //PokerCards
                if(i!=numPlayers-1)cout <<"ª±®a "<<i+1;
                else cout<< "²ø®a";

                cout<<" have: "<<"[Total point: "<<players[i].getcardsum()<<" Points]"<<endl;
                cout <<"show card :";

                players[i].showCards();
                if(players[i].getcardsum()<=21&&abs(players[i].getcardsum()-21)<minnum)
                {
                    win = players[i].getcardsum();
                    minnum=abs(players[i].getcardsum()-21);
                    nowin = 0;
                }
                else if(players[i].getcardsum()>21)
                {
                    cout<<"Oh !Busting!!"<<endl;
                }

                players[i].setcoin(players[i].getcoins()-players[i].getbet());
            }
            cout<<"--------------------------------------------"<<endl;
            if(nowin==1)win = -1;
            for(int i=0; i<numPlayers-1; i++)  //¤£¥Î­pºâ²ø®a
            {
                if(players[i].getcardsum()==win)
                {
                    players[i].setcoin(players[i].getcoins()+players[i].getbet()*2);
                    cout<<"Player "<<i+1<<" has "<<players[i].getcoins()<<" coins."<<endl;
                }
                else
                {
                    cout<<"Player "<<i+1<<" has "<<players[i].getcoins()<<" coins."<<endl;
                }

            }

            /*²Ä¤C¶¥¬q¼ÒÀÀ¡Gµ²§ô*/

            cout<<"--------------------------------------------"<<endl;
            cout<<"Thanks you use this program play BlackJack"<<endl;


        }
        char flag;
        //clrscr();
        cout<<"¬O§_¥t±Ò·s§½(Y)/µ²§ô¹CÀ¸(any key) ? ";
        cin.clear();
        cin.ignore();
        cin>>flag;
        if(toupper(flag)!='Y')con_game = false;

    }

    cout<<"Bye Bye! Press any key to exit!"<<endl;

    cin.clear();
    cin.ignore();
    string s;
    getline(cin,s);

//
//    /* ²Ä¤T¶¥¬q¼ÒÀÀ: ª±®a¨qµP */
//    for (int p=0;p<numPlayers;p++) {
//        cout << "Player " << p << " have: " << endl;
//        players[p].showCards(); // ¨C­Óª±®a½ü¬y¨qµP
//    }

    // ª±®a¨qªºµP¥i©MµP¶ð¨qªºµP¹ï·Ó¡A¥H«KÀËÅçµoµPµ{§Ç¦³§_¥X¿ù


    return 0;
}

/* 410221002 ��u�@ ������ */

#include <iostream>
#include<fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

#include "Bitmap.h"
#include "ImageProc.h"
#include "Matcher.h"
#include <cstdlib>
#include <windows.h>
#include <dirent.h>
#include <conio.h>


#define filein "1.pgm"
#define fileout "outfile.pgm"

#define typenames ".pgm"
using namespace std;

void getdir(string , vector<string>&,vector<string>&,string);
void gotoxy(int, int);

int main()
{
    ///get the folderfile .pgm
    string dir = string(".");//��Ƨ����|(�����}or�۹��}) use '.' relative path
    vector<string> files = vector<string>();
    vector<string> tfiles = vector<string>();
    map<double,string > tt;//,greater<double>
    Bitmap *ppp;
    getdir(dir, files,tfiles,typenames);

    if(files.size()==0)cout<<"�P�����ɦP�ؿ��U�L�ݿ��Ѫ��ɮ�."<<endl;
    //for(int i=0;i<tfiles.size();++i)cout<<tfiles[i]<<endl;
    //for(int i=0;i<files.size();++i)cout<<files[i]<<endl;

    //////////////////////////////

    // buile every pic
    //Bitmap *bmp_pp = new Bitmap[files.size()];
    //Bitmap *bmp_tt = new Bitmap[tfiles.size()];
    vector<Bitmap*> ccc;//(files.size());
    vector<Bitmap*> templatefile;//(tfiles.size());
    //vector<Bitmap> q; //copy is not good
    // deal process
    ImageProc Imp;

    //deal Match
    Matcher Mc;


    //goto a;
    /*
    read template file ,t*.pgm

    */
    for(unsigned int i =0;i<tfiles.size();++i) //template read
    {
        ifstream in_file(tfiles[i].c_str());
        cout<<"Ū�J�ɦW: "<<tfiles[i]<<endl; //print file name
        ppp = new Bitmap();
       //cout<<ppp;
        //Bitmap bmp_pp;
        //in_file>>bmp_pp;
        in_file>>(*ppp);

        *ppp = Imp.binarize(*ppp);
        *ppp = Imp.cutpicture(*ppp);

        *ppp = Imp.normalize(*ppp,512,512);

        templatefile.push_back(ppp);

        //ppp->Tprint();
        in_file.close();
    }

    system("cls");

    //cout<<files.size();

    /*
    read test data *.pgm
    */
    int zoom_x = 60;
    int zoom_y = 32;
    for(unsigned int i =0;i<files.size();++i) //testfile read
    {
        int tempy = 0;//for x position
        ifstream in_file(files[i].c_str());
        cout<<"Ū�J�ɦW: "<<files[i]<<" �ثe�� "<<i+1<<"���� �@"<<files.size()<<"��."<<endl;
        ppp = new Bitmap();
        in_file>>(*ppp);
        *ppp = Imp.binarize(*ppp);
        *ppp = Imp.cutpicture(*ppp);
        Imp.printZoom(*ppp,zoom_y,zoom_x);



        //cout<<"@";
        *ppp = Imp.normalize(*ppp,512,512);
        tt.clear();
        for(unsigned int j=0;j<tfiles.size();++j)
        {
            double df = Mc.calcDiff(*ppp,*(templatefile[j]));
            tt[df] = tfiles[j];
        }

        map<double, string>::iterator iter;
        gotoxy(zoom_x+4,tempy++);
        cout<<"�P�˪O�����ѵ��G";
        for(iter = tt.begin();iter!=tt.end();++iter)
        {
            gotoxy(zoom_x+4,tempy++);
            cout<<(*iter).second<<'\t'<<"�ۦ��׬� "<<setprecision(4)<<(1-((*iter).first)/262144)*100<<"%"<<endl;

        }

        gotoxy(0,zoom_y+4);
        cout<<"�Ы���V�� -> �i��U�@���ɮפ��"<<endl;
        ccc.push_back(ppp);
        //ppp->print();
        in_file.close();
        //getchar();
        char ch;
        int hc;
        do
        {
            ch = getch();
            //hc = ch;
            if(ch==77)break;
            //cout<<hc;
        }while(1);

        system("cls");
    }

    //vector<Bitmap*>::iterator it;
    //cout<<templatefile.size();
//    for(it =templatefile.begin();it!=templatefile.end();++it)//cout<<(*it)->getWidth(); //templatefile.pop_back();//
//    {
//        (*it)->print();
//        system("cls");
//
//    }

// 1�����D �b���L�X
//    *(templatefile[1]) = Imp.normalize(*(templatefile[1]),20,20);
//    (templatefile[1])->Tprint();
//
//    *(ccc[1]) = Imp.normalize(*(ccc[1]),20,20);
//    (ccc[1])->Tprint();


//first check file corect
//  for single file
//    ifstream in_file(filein);
//    while(!in_file.is_open())
//    {
//        cout<< "open file:"<<filein<<" fail!"<<endl<<"Input file name (.pgm): ";
//        char filet[20];
//        cin>>filet;
//        in_file.clear();
//        in_file.open(filet);
//        //in_file();
//        //return false;
//    }
//    cout<<"Read file success!"<<endl;



    goto a; //just for fun.....
    //in_file>>bmp_pp;
    //in_file.close();
    //bmp_pp.print();



//    cout<<"�ɮ�Ū�J����"<<endl;
//    cout<<"�ϧιw��->"<<endl;


   // bmp_pp =Imp.binarize(bmp_pp); //

//    cout<<"�G�ȤƧ���"<<endl;
////    cout<<bmp_pp<<endl;
   // bmp_pp = Imp.normalize(bmp_pp,80,80);  //���令80*80�ո� ��V�j�i�V���
////    cout<<"�Y�񧹦�"<<endl;
//
//
   // bmp_pp = Imp.cutpicture(bmp_pp);
    //cout<<bmp_pp.getHeight()<<" " <<bmp_pp.getWidth()<<endl;

   // bmp_pp.print();
//    ofstream out_file(fileout);
//    while(!out_file.is_open())
//    {
//        cout<< "create file:"<<filein<<" fail!"<<endl<<"Input file name (.pgm): ";
//        char filet[20];
//        cin>>filet;
//        out_file.clear();
//        out_file.open(filet);
//        //in_file();
//        //return false;
//    }
//    cout<<"Create file success!"<<endl;
//    out_file<<bmp_pp;
//
//    cout<<"�ɮ׿�X����"<<endl;

    //bmp_pp.print();

    //Bitmap BB;

    //cout << "Hello world!" << endl;
    a:
    return 0;
}



void getdir(string dir, vector<string> &files,vector<string> &tfiles,string type)
{
    DIR *dp;//�Х߸�Ƨ�����
    struct dirent *dirp;
    string tempname;
    dp = opendir(dir.c_str());
//    if((dp = opendir(dir.c_str())) == NULL){
//        cout << "Error(" << errno << ") opening " << dir << endl;
//        return errno;
//    }
    while((dirp = readdir(dp)) != NULL){//�p�Gdirent���ЫD��
        tempname = string(dirp->d_name);
        if(tempname.size()>4&&!tempname.compare(tempname.size()-4,4,type))//get .pgm
        {
            if(tempname[0]=='t')tfiles.push_back(tempname);//�N��Ƨ��M�ɮצW��Jvector
            else files.push_back(tempname);//�N��Ƨ��M�ɮצW��Jvector
        }
    }
    closedir(dp);//������Ƨ�����
    //return 0;
}


void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}


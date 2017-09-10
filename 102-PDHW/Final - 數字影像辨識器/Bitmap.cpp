#include <iostream>

#include "Bitmap.h"
#include <string>
#include <sstream>

using namespace std;

Bitmap::Bitmap () //�w�]�غc�l
{
    setWidth(0);
    setHeight(0);
}

Bitmap::Bitmap(int width ,int height ) //�غc�@�Ӽe�סA���ת��I�}��width  height
{
    setWidth(width);
    setHeight(height);
    createpixmatrix();
}

Bitmap::Bitmap(const Bitmap &bmp) //�����غc�l
{

}

void Bitmap::createpixmatrix()
{
    pix = new int*[height];
    for(int i=0;i<height;i++)
    {
        pix[i] = new int[width];
    }
}
void Bitmap::createpixmatrix(int y,int x) //�o�̧ڭ̥��gTpix
{
    Tpix = new int*[y];
    for(int i=0;i<y;i++)
    {
        Tpix[i] = new int[x];
    }
}

int Bitmap::getWidth () const //���o�v���e��
{
    return width;
}
void Bitmap::setWidth (int w)  //�]�w�v���e��
{
    width = w;
}

int Bitmap::getHeight () const //���o�v������
{
    return height;
}
void Bitmap::setHeight (int h)  //�]�w�v������
{
    height = h;
}

int Bitmap::getTw () const //���ot�v���e��
{
    return Tw;
}
void Bitmap::setTw (int w)  //�]�wt�v���e��
{
    Tw = w;
}

int Bitmap::getTh () const //���ot�v������
{
    return Th;
}
void Bitmap::setTh (int h)  //�]�wt�v������
{
    Th = h;
}


int Bitmap::getLight() const//���o�̤j�G��
{
    return Light;
}
void Bitmap::setLight(int L)//�]�w�̤j�G��
{
    Light = L;
}


int Bitmap::getplight () const //���o�v���e��
{
    return point_light;
}
void Bitmap::setplight (int pl)  //�]�w�v���e��
{
    point_light = pl;
}


int Bitmap::getMLight() const//���o�}�C���̤j�G��
{
    return MLight;
}
void Bitmap::setMLight(int L)//�s��}�C���̤j�G��
{
    MLight = L;
}


int& Bitmap::pixel (int y ,int x)  //���o����(y;x)��Reference
{
    return (pix[y][x]);
    //return NULL;
}
int Bitmap::getpixelvalue(int y,int x)const
{
    return pix[y][x];
}
int Bitmap::getTpixelvalue(int y,int x)const
{
    return Tpix[y][x];
}
void Bitmap::setPixel(int y,int x,int value) //�]�w����(y,x)����
{
    pix[y][x] = value;
}

void Bitmap::setTPixel(int y,int x,int value) //�]�wT����(y,x)����
{
    Tpix[y][x] = value;
}


void Bitmap::print()//�L�X�ݬ�
{
    cout<<endl;
    for(int i=0;i<getHeight();++i)
    {
        for(int j=0;j<getWidth();++j)
        {
            if(pixel(i,j)!=0)cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}

void Bitmap::Tprint()//�L�X�ݬ�
{
    cout<<endl;
    for(int i=0;i<Th;++i)
    {
        for(int j=0;j<Tw;++j)
        {
            if(getTpixelvalue(i,j)!=0)cout<<"@";
            else cout<<" ";
        }
        cout<<endl;
    }
}
/********
The output operator must be overloaded with the global function
because the first operand must be an ostream object, rather than the current class object.
The function must return an ostream object or ostream reference
********/

ostream& operator<<( ostream& out , const Bitmap& fileoutput)
{//change for teacher's file


    cout<<"�ɮ׼g�J��~~"<<endl;
    out<<"P2"<<endl;
    //out<<"#"<<endl;
//    out<<fileoutput.getWidth()<<" "<<fileoutput.getHeight()<<endl;
//    out<<fileoutput.getLight()<<endl;
    out<<fileoutput.getTw()<<" "<<fileoutput.getTw()<<endl;
    out<<fileoutput.getLight()<<endl;

    //out<<"#"<<endl;
    //for(int i=0;i<fileoutput.getHeight();++i)
    for(int i=0;i<fileoutput.getTh();++i)
    {
        //for(int j=0;j<fileoutput.getWidth();++j)
        for(int j=0;j<fileoutput.getTw();++j)
        {
            //out<<fileoutput.getpixelvalue(i,j);
            out<<fileoutput.getTpixelvalue(i,j);
            //if(j!=fileoutput.getWidth()-1)out<<" ";
            if(j!=fileoutput.getTw()-1)out<<" ";
            //if(pixel(i,j)!=0)cout<<"*";
            //else cout<<" ";
        }
        out<<endl;
    }

    //out<<"@@@";
    return out;
}

istream& operator>>( istream& in ,Bitmap& fileinput)
{

    string temp;
    //stringstream ss;

    int w = 0,h=0,L=0,line = 0,v=0,M=0,t,average;
    //cout<<"Ū����~~~~~~"<<endl;
    in>>temp;
    if(temp!="P2")
    {
        cout<<"�ɮ׿��~"<<endl;
        return in;
    }
    else
    {
// not for teacher file
//        //cout<<"^^";
//        //while(getline(in,temp))
//        while(in>>temp)
//        {
//            if(temp[0]!='#')
//            {
//                if(w == 0&&h ==0)
//                {
//                    stringstream iss(temp);
//                    iss>>w>>h;
//                    fileinput.setWidth(w);
//                    fileinput.setHeight(h);
//                    fileinput.createpixmatrix();
//                    //cout<<w<<" "<<h<<endl;
//                }
//                else if(L==0)
//                {
//                    stringstream iss(temp);
//                    iss>>L;
//                    fileinput.setLight(L);
//                }
//                else
//                {
//                    stringstream iss(temp);
//                    for(int i=0;i<w;i++)
//                    {
//                        iss>>v;
//                        //cout<<v;
//                        if(v>M)M=v;
//                        fileinput.setPixel(line,i,v);
//                    }
//                    line++;
//                    fileinput.setMLight(M);
//
//                }
//                //cout<<temp;
//                //cout<<endl;
//            }
//            else
//            {
//                getline(in,temp);
//            }
            //cout<<"@@";

            //for teacher file
            in>>w>>h;
            fileinput.setWidth(w);
            fileinput.setHeight(h);
            fileinput.createpixmatrix();

            in>>L;
            fileinput.setLight(L);
            average = 0;
            for(int i=0;i<h;++i)
            {
                for(int j=0;j<w;++j)
                {
                    in>>t;
                    fileinput.setPixel(i,j,t);
                    average+=t;
                    if(t>M)M=t;
                    //cout<<t<<" ";
                }
                //cout<<endl;
            }
            fileinput.setMLight(M);

            average = average/w*h;
            if(average>M/2)fileinput.setplight(0);
            else fileinput.setplight(L);

        }

    //cout<<"Ū������"<<endl;
    //in>>cc;
    //cout<<cc;
    return in;
}


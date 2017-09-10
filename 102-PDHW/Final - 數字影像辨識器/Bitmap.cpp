#include <iostream>

#include "Bitmap.h"
#include <string>
#include <sstream>

using namespace std;

Bitmap::Bitmap () //預設建構子
{
    setWidth(0);
    setHeight(0);
}

Bitmap::Bitmap(int width ,int height ) //建構一個寬度，高度的點陣圖width  height
{
    setWidth(width);
    setHeight(height);
    createpixmatrix();
}

Bitmap::Bitmap(const Bitmap &bmp) //拷貝建構子
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
void Bitmap::createpixmatrix(int y,int x) //這裡我們先寫Tpix
{
    Tpix = new int*[y];
    for(int i=0;i<y;i++)
    {
        Tpix[i] = new int[x];
    }
}

int Bitmap::getWidth () const //取得影像寬度
{
    return width;
}
void Bitmap::setWidth (int w)  //設定影像寬度
{
    width = w;
}

int Bitmap::getHeight () const //取得影像高度
{
    return height;
}
void Bitmap::setHeight (int h)  //設定影像高度
{
    height = h;
}

int Bitmap::getTw () const //取得t影像寬度
{
    return Tw;
}
void Bitmap::setTw (int w)  //設定t影像寬度
{
    Tw = w;
}

int Bitmap::getTh () const //取得t影像高度
{
    return Th;
}
void Bitmap::setTh (int h)  //設定t影像高度
{
    Th = h;
}


int Bitmap::getLight() const//取得最大亮度
{
    return Light;
}
void Bitmap::setLight(int L)//設定最大亮度
{
    Light = L;
}


int Bitmap::getplight () const //取得影像寬度
{
    return point_light;
}
void Bitmap::setplight (int pl)  //設定影像寬度
{
    point_light = pl;
}


int Bitmap::getMLight() const//取得陣列中最大亮度
{
    return MLight;
}
void Bitmap::setMLight(int L)//存放陣列中最大亮度
{
    MLight = L;
}


int& Bitmap::pixel (int y ,int x)  //取得像素(y;x)的Reference
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
void Bitmap::setPixel(int y,int x,int value) //設定像素(y,x)的值
{
    pix[y][x] = value;
}

void Bitmap::setTPixel(int y,int x,int value) //設定T像素(y,x)的值
{
    Tpix[y][x] = value;
}


void Bitmap::print()//印出看看
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

void Bitmap::Tprint()//印出看看
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


    cout<<"檔案寫入中~~"<<endl;
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
    //cout<<"讀取中~~~~~~"<<endl;
    in>>temp;
    if(temp!="P2")
    {
        cout<<"檔案錯誤"<<endl;
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

    //cout<<"讀取完成"<<endl;
    //in>>cc;
    //cout<<cc;
    return in;
}


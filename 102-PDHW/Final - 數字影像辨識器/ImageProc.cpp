#include <iostream>
#include "ImageProc.h"

using namespace std;

Bitmap& ImageProc::binarize(Bitmap &bmp)//將bmp黑白化後傳回黑白點陣圖的結果
{
    // Gmax/2  為門檻，其中 Gmax 是點陣圖中最大的像素值
    // 為啥要用getlight 因為在抓取的圖形 有可能點是 0 或是 Max light,判斷的依據是在讀取圖形時 計算所有點的平均
    // 如果平均大於 MAX/2 則背景是 MAX LIGHT，此時點就是0 反之 點就是Max light.
    for(int i=0;i<bmp.getHeight();++i)
    {
        for(int j=0;j<bmp.getWidth();++j)
        {
            //cout<<"@_@|||";
            if(bmp.getplight()>0)//代表 point 是 max light
            {
                if(bmp.getpixelvalue(i,j)>(bmp.getMLight()/2))bmp.setPixel(i,j,bmp.getLight());
                else bmp.setPixel(i,j,0);
            }
            else //point light represent 0
            {
                if(bmp.getpixelvalue(i,j)<(bmp.getMLight()/2))bmp.setPixel(i,j,bmp.getLight());
                else bmp.setPixel(i,j,0);
            }

        }
    }

    return bmp;
}
Bitmap& ImageProc::normalize(Bitmap &bmp,int new_w,int new_h)//將bmp縮放為寬度為new_w，高度為new_h的點陣圖
{
    int **tempMatrix;
    tempMatrix = new int*[new_h];
    float t_x = float(bmp.getWidth())/new_w,t_y = float(bmp.getHeight())/new_h; //這裡要注意倍數 的形態 若用int為0

    // hide information
    //cout<<"寬縮放 "<<1.0/t_x<<" 倍,高縮放 "<<1.0/t_y<<" 倍"<<endl;
    for(int i=0;i<new_h;++i)tempMatrix[i] =new int[new_w];
    bmp.setTh(new_h);
    bmp.setTw(new_w);
    //將值縮放後
    //bmp.print();
    for(int y=0;y<new_h;++y)
    {
        for(int x=0;x<new_w;++x)
        {
            if(bmp.pixel(y*t_y,x*t_x)!=0){tempMatrix[y][x] = bmp.getLight();}
            else tempMatrix[y][x] = 0;
            //cout<<tempMatrix[y][x];
            //cout<<bmp.getpixelvalue(y*t_y,x*t_x);
        }
        //cout<<endl;
    }
    //把縮放後的的放回T陣列 方便起見 額外開一個matrix

    bmp.createpixmatrix(new_h,new_w);

    for(int y=0;y<new_h;++y)
    {
        for(int x=0;x<new_w;++x)
        {
            bmp.setTPixel(y,x,tempMatrix[y][x]);
        }
    }
    //for(int i=0)
    //cout<<"@@";
    for(int y=0;y<new_h;++y)delete tempMatrix[y];
    delete tempMatrix;
    return bmp;
}
Bitmap& ImageProc::cutpicture(Bitmap &bmp) //cut and resize
{
    int Lw,Rw,Uh,Dh; //from left,right,top ,bottom

    Lw = bmp.getWidth();
    Rw = 0;
    Uh = bmp.getHeight();
    Dh = 0;
    for(int i=0;i<bmp.getHeight();++i)
    {
        for(int j=0;j<bmp.getWidth();++j)
        {
            if(bmp.getpixelvalue(i,j)!=0)
            {
                if(j<Lw)Lw = j;
                if(j>Rw)Rw = j;
                if(i<Uh)Uh = i;
                if(i>Dh)Dh = i;
            }
        }
    }
    int t = 0;
    int *temp = new int[(Rw-Lw+1)*(Dh-Uh+1)];
    for(int i=Uh;i<Dh;++i)
    {
        for(int j=Lw;j<Rw;++j)
        {
            temp[t++] = bmp.getpixelvalue(i,j);
//            if(temp[t-1]==bmp.getplight())cout<<"*";
//                else cout<<" ";
//            if(bmp.getpixelvalue(i,j)!=0)cout<<"*";
//            else cout<<" ";

        }
        //cout<<endl;
    }
    t = 0;
    for(int i=0;i<Dh-Uh;++i)
    {
        for(int j=0;j<Rw-Lw;++j)
        {

//            if(temp[t++]!=0)cout<<"*";
//            else cout<<" ";
            if(temp[t++]!=0)bmp.setPixel(i,j,bmp.getLight());
            else bmp.setPixel(i,j,0);
        }
        //cout<<endl;
    }
    bmp.setWidth(Rw-Lw);
    bmp.setHeight(Dh-Uh);
    //print
//    cout<<Lw<<" "<<Rw<<" "<<Uh<<" "<<Dh<<endl;
//    cout<<endl;
//    for(int i=Uh;i<Dh;++i)
//    {
//        for(int j=Lw;j<Rw;++j)
//        {
//            if(bmp.getpixelvalue(i,j)!=0)cout<<"*";
//            else cout<<" ";
//        }
//        cout<<endl;
//    }
    //cout<<"@@@";

    return bmp;

}

void ImageProc::printZoom(Bitmap &bmp,int new_h,int new_w)
{

     for(int i=-1;i<=new_h;++i)
     {
        for(int j=-1;j<new_w;++j)
        {
            if(i<0||i==new_h)cout<<"=";
            else
            {
                if(j<0)cout<<"=";
                else
                {
                    if(bmp.pixel(i*float(bmp.getHeight())/new_h,j*float(bmp.getWidth())/new_w)!=0)cout<<"*";
                    else cout<<" ";
                }
            }
        }
        cout<<"="<<endl;
     }




}


double* ImageProc::extract(Bitmap &bmp)//從bmp上抽取出一維特徵陣列
{



}

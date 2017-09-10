#include <iostream>
#include "ImageProc.h"

using namespace std;

Bitmap& ImageProc::binarize(Bitmap &bmp)//�Nbmp�¥դƫ�Ǧ^�¥��I�}�Ϫ����G
{
    // Gmax/2  �����e�A�䤤 Gmax �O�I�}�Ϥ��̤j��������
    // ��ԣ�n��getlight �]���b������ϧ� ���i���I�O 0 �άO Max light,�P�_���̾ڬO�bŪ���ϧή� �p��Ҧ��I������
    // �p�G�����j�� MAX/2 �h�I���O MAX LIGHT�A�����I�N�O0 �Ϥ� �I�N�OMax light.
    for(int i=0;i<bmp.getHeight();++i)
    {
        for(int j=0;j<bmp.getWidth();++j)
        {
            //cout<<"@_@|||";
            if(bmp.getplight()>0)//�N�� point �O max light
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
Bitmap& ImageProc::normalize(Bitmap &bmp,int new_w,int new_h)//�Nbmp�Y�񬰼e�׬�new_w�A���׬�new_h���I�}��
{
    int **tempMatrix;
    tempMatrix = new int*[new_h];
    float t_x = float(bmp.getWidth())/new_w,t_y = float(bmp.getHeight())/new_h; //�o�̭n�`�N���� ���κA �Y��int��0

    // hide information
    //cout<<"�e�Y�� "<<1.0/t_x<<" ��,���Y�� "<<1.0/t_y<<" ��"<<endl;
    for(int i=0;i<new_h;++i)tempMatrix[i] =new int[new_w];
    bmp.setTh(new_h);
    bmp.setTw(new_w);
    //�N���Y���
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
    //���Y��᪺����^T�}�C ��K�_�� �B�~�}�@��matrix

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


double* ImageProc::extract(Bitmap &bmp)//�qbmp�W����X�@���S�x�}�C
{



}

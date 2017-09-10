#include <iostream>
#include "Matcher.h"


using namespace std;
double Matcher::calcDiff( double *f1 , double *f2 )
{

}

double Matcher::calcDiff( Bitmap &b1 , Bitmap &b2 )
{
    int ans = 0;
    for(int i = 0;i<b1.getTh();++i)
        for(int j = 0;j<b2.getTw();++j)
            if(b1.getTpixelvalue(i,j)!=b2.getTpixelvalue(i,j))ans++;
    return ans;
}

int Matcher::recognize(Bitmap &b, int method)
{

}

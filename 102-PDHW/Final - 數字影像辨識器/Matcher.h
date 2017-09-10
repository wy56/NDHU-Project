#ifndef _Matcher_h
#define _Matcher_h

#include "Bitmap.h"

using namespace std;
class Matcher
{
    public :
    double calcDiff( double *f1 , double *f2 ) ; //計算特徵向量f1和特徵向量f2間的差異度
    double calcDiff( Bitmap &, Bitmap &) ; //計算點陣圖b1和點陣圖b2間的差異度
    int recognize(Bitmap &, int method);


    //針對輸入之點陣圖b，依據指定之方法(method)進行//比對，傳回辨識結果之數字代號（0-9）//method=1: 點陣圖樣版比對法，method=2:特徵向量比對法
};


#endif // _Matcher_h

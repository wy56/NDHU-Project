#ifndef _ImagPP_
#define _ImagPP_

#include "Bitmap.h"
class ImageProc
{
    public :
        Bitmap& binarize(Bitmap &bmp);//將bmp黑白化後傳回黑白點陣圖的結果
        Bitmap& normalize(Bitmap &bmp,int new_w,int new_h);//將bmp縮放為寬度為new_w，高度為new_h的點陣圖
        void printZoom(Bitmap &,int ,int );//print zoom out
        //將bmp做切割 從左 從右 從上 從下 使邊界維持在字型附近
        Bitmap& cutpicture(Bitmap &bmp);
        double *extract(Bitmap &bmp);//從bmp上抽取出一維特徵陣列
    private:

};


#endif // _Bitmap_

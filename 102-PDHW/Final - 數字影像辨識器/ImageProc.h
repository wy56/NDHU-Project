#ifndef _ImagPP_
#define _ImagPP_

#include "Bitmap.h"
class ImageProc
{
    public :
        Bitmap& binarize(Bitmap &bmp);//�Nbmp�¥դƫ�Ǧ^�¥��I�}�Ϫ����G
        Bitmap& normalize(Bitmap &bmp,int new_w,int new_h);//�Nbmp�Y�񬰼e�׬�new_w�A���׬�new_h���I�}��
        void printZoom(Bitmap &,int ,int );//print zoom out
        //�Nbmp������ �q�� �q�k �q�W �q�U ����ɺ����b�r������
        Bitmap& cutpicture(Bitmap &bmp);
        double *extract(Bitmap &bmp);//�qbmp�W����X�@���S�x�}�C
    private:

};


#endif // _Bitmap_

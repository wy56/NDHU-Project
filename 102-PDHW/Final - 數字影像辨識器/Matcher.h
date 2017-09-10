#ifndef _Matcher_h
#define _Matcher_h

#include "Bitmap.h"

using namespace std;
class Matcher
{
    public :
    double calcDiff( double *f1 , double *f2 ) ; //�p��S�x�V�qf1�M�S�x�V�qf2�����t����
    double calcDiff( Bitmap &, Bitmap &) ; //�p���I�}��b1�M�I�}��b2�����t����
    int recognize(Bitmap &, int method);


    //�w���J���I�}��b�A�̾ګ��w����k(method)�i��//���A�Ǧ^���ѵ��G���Ʀr�N���]0-9�^//method=1: �I�}�ϼ˪����k�Amethod=2:�S�x�V�q���k
};


#endif // _Matcher_h

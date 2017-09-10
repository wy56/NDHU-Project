#ifndef _Bitmap_
#define _Bitmap_

#define MAX_HEIGHT 512  //�I�}�Ϯe�\���̤j����

#define MAX_WIDTH 512 //�I�}�Ϯe�\���̤j�e�O

class Bitmap
{
public:

int getWidth () const; //���o�v���e��
void setWidth (int); //�]�w�v���e��
int getTw() const;
void setTw(int=0);

int getHeight () const; //���o�v������
void setHeight (int); //�]�w�v������
int getTh() const;
void setTh(int=0);

int getLight() const;//���o�̤j�G��
void setLight(int);//�]�w�̤j�G��

int getMLight()const;//���o�}�C���̤j�G��
void setMLight(int);//�s��}�C���̤j�G��

int getplight()const;//���o�I���G��
void setplight(int);//�]�w�I���G�� �i��O�̤p �]�i��O�̤j

Bitmap (); //�w�]�غc�l

Bitmap(int width ,int height ); //�غc�@�Ӽe�סA���ת��I�}��width  height

Bitmap(const Bitmap &bmp); //�����غc�l

void setTPixel(int,int,int);
void setPixel(int y,int x,int value); //�]�w����(y,x)����
int& pixel (int y ,int x); //���o����(y;x)��Reference
int getpixelvalue(int y,int x)const;//���o������value
int getTpixelvalue(int y,int x)const;//���otemp matrix������value

void print();
void Tprint();

friend std::ostream &operator<<(std::ostream& out , const Bitmap& fileoutput);// overload cout operator

friend std::istream& operator>>(std::istream& out , Bitmap& fileinput ); //overload cin operator
void createpixmatrix();//�ʺA
void createpixmatrix(int,int);//�ʺA
private:

int width;//�v���e��
int Tw;

int height;//�v������
int Th;

int Light;//�̤j�G�� ����

int MLight;//�s��Ū���� �J�쪺�̤j�G��


int point_light;
int **pix;//[MAX_HEIGHT][MAX_WIDTH];//�G�������Ȱ}�C  ���ӬOchar �o�̧令 int
int **Tpix;
//std::string filename;
};






#endif // _Bitmap_

#ifndef _Bitmap_
#define _Bitmap_

#define MAX_HEIGHT 512  //點陣圖容許之最大高度

#define MAX_WIDTH 512 //點陣圖容許之最大寬是

class Bitmap
{
public:

int getWidth () const; //取得影像寬度
void setWidth (int); //設定影像寬度
int getTw() const;
void setTw(int=0);

int getHeight () const; //取得影像高度
void setHeight (int); //設定影像高度
int getTh() const;
void setTh(int=0);

int getLight() const;//取得最大亮度
void setLight(int);//設定最大亮度

int getMLight()const;//取得陣列中最大亮度
void setMLight(int);//存放陣列中最大亮度

int getplight()const;//取得點的亮度
void setplight(int);//設定點的亮度 可能是最小 也可能是最大

Bitmap (); //預設建構子

Bitmap(int width ,int height ); //建構一個寬度，高度的點陣圖width  height

Bitmap(const Bitmap &bmp); //拷貝建構子

void setTPixel(int,int,int);
void setPixel(int y,int x,int value); //設定像素(y,x)的值
int& pixel (int y ,int x); //取得像素(y;x)的Reference
int getpixelvalue(int y,int x)const;//取得像素的value
int getTpixelvalue(int y,int x)const;//取得temp matrix像素的value

void print();
void Tprint();

friend std::ostream &operator<<(std::ostream& out , const Bitmap& fileoutput);// overload cout operator

friend std::istream& operator>>(std::istream& out , Bitmap& fileinput ); //overload cin operator
void createpixmatrix();//動態
void createpixmatrix(int,int);//動態
private:

int width;//影像寬度
int Tw;

int height;//影像高度
int Th;

int Light;//最大亮度 為白

int MLight;//存放讀取時 遇到的最大亮度


int point_light;
int **pix;//[MAX_HEIGHT][MAX_WIDTH];//二維像素值陣列  本來是char 這裡改成 int
int **Tpix;
//std::string filename;
};






#endif // _Bitmap_

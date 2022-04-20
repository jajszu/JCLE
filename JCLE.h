#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <cmath>
#include <conio.h>
using namespace std;

class Sprite
{
   int x,y;
   char texture;
  public:
   int getPosX()
   {
      return this->x;
   }
      int getPosY()
   {
      return this->y;
   }
   char getTexture()
   {
      return this->texture;
   }
   void setTexture(char txt)
   {
      this->texture = txt;
   }
   void setPosition(int x,int y)
   {
      this->x = x;
      this->y = y;
   }
};


class Keyboard
{
   public:

      bool isKeyPressed()
      {
         return kbhit();
      }

      char Key()
      {
         return getch();
      }
};


class Square
{

   char texture;
   int x,y,w,h;
   public:
      Square(int x,int y,int w,int h)
      {
         this->x = x;
         this->y = y;
         this->h = h;
         this->w = w;
      }

      void setTexture(char txt)
      {
         this->texture = txt;
      }
       int getPosX()
   {
      return this->x;
   }
      int getPosY()
   {
      return this->y;
   }
    int getWidth()
   {
      return this->w;
   }
      int getHeight()
   {
      return this->h;
   }
    char getTexture()
   {
      return this->texture;
   }
    void setPosition(int x,int y)
   {
      this->x = x;
      this->y = y;
   }
};

class engine
{
   int **map;
   int height,width;
   char background;
  public:
engine(int width,int height)
{
   this->map = new int*[width];
   for(int i = 0;i<width;i++)
   {
      this->map[i] = new int[height];
   }
   this->height = height;
   this->width = width;
}

void setBackground(char back)
{
   this->background = back;
   for(int i=0;i<this->width;i++)
   {
      for(int j=0;j<this->height;j++)
      {

         map[i][j] = (int)back;
      }
   }
}

void draw(Sprite sprite)
{
   map[sprite.getPosY()][sprite.getPosX()] = (int)sprite.getTexture();
}
void draw(Square square)
{
  for(int i=square.getPosX();i<square.getPosX()+square.getWidth();i++)
  {
     for(int j=square.getPosY();j<square.getPosY()+square.getHeight();j++)
     {
        map[j][i] = (int)square.getTexture();
     }
  }
}

void clear()
{
      HANDLE hCon;
   COORD dwPos;
   dwPos.X=0;
   dwPos.Y=0;
   hCon=GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(hCon,dwPos);
   setBackground(background);

}

void display()
{
   for(int i=0;i<this->width;i++)
   {
      for(int j=0;j<this->height;j++)
      {

         cout<<" "<<(char)map[i][j];
      }
      cout<<endl;
   }
}

};




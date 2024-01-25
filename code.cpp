#include "iGraphics.h"
#include<time.h>
bool musicOn = true;
int screen = 0;

struct puzzle{
	int x;
	int y;
};

struct puzzle pic[9];

char puzzlePices[9][20]={"image1x1.bmp","image1x2.bmp","image1x3.bmp","image2x1.bmp","image2x2.bmp","image2x3.bmp",
 "image3x1.bmp","image3x2.bmp","image3x3.bmp"};

 int cordinatesX[3]={0,167,167*2},cordinatesY[3]={0,167,167*2};
 int indexX=167;
 int indexY=167;
 int x;
 int y;


void iDraw()
{
	iClear();
	// place your drawing codes here
	if (screen == 0)
	{   

		iShowBMP(0, 0, "Home page.bmp");
		iShowBMP2(30, 300, "button 1.bmp", 0);
		iShowBMP2(30, 200, "button 2.bmp", 0);
		iShowBMP2(30, 100, "button 3.bmp", 0);
		iShowBMP2(580,20,"info button.bmp",0);
	}
	if (screen == 1)
	{
		iShowBMP(0, 0, "screen2.bmp");
		iShowBMP(550,300,"preview.bmp");
		int count = 0;
		for (int i = 0; i<=500; i+=167)
		{
			for (int j = 0; j<=500; j+=167)
			{
				// if (i == 0 && j == 0)    continue;
				// else
				// 
				srand(time(NULL));
					iShowBMP(i,j, puzzlePices[rand()%9+1]);
					count++;
				//}
			}
		}
		iShowBMP2(550, 30, "button6.bmp", 0);
	}

		//iShowBMP(0,0,"pokemon.bmp");
		

	if (screen == 2)
	{

		iShowBMP(0, 0, "pikachuNew.bmp");
		iShowBMP2(50, 400, "button4.bmp", 0);
		iShowBMP2(550, 400, "button5.bmp", 0);
		iShowBMP2(550, 30, "button6.bmp", 0);
	}
	if (screen == 3)
	{
		iShowBMP(0, 0, "screen3.bmp");
		iShowBMP2(550, 30, "button6.bmp", 0);
	}
	if(screen == 4){
         iShowBMP(0,0,"screen4.bmp");
		 iText(30, 120, "Use Left click to move a picture .The picture you click will be swapped", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(30, 100, "with the blank pic.", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(30, 20, "You have \"30 SECONDS \" time to match it.", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 0, 0);
		iText(30, 50, "Press o to mute sound and m to unmute.", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(550, 400, "button6.bmp", 0);
	}

	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	// place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (screen == 0)
		{
			if (mx >= 30 && mx <= 230 && my >= 300 && my <= 368)
			{
				screen = 1;
			}
			if (mx >= 30 && mx <= 230 && my >= 200 && my <= 268)
			{
				screen = 2;
			}
			if (mx >= 30 && mx <= 230 && my >= 100 && my <= 168)
			{
				screen = 3;
			}
			if(mx>=580 && mx <= 780 && my >= 20 && my <= 88)
			{
				screen = 4;
			}
		}
		
		if(screen==1)
		{
			if(mx >= 550 && mx <= 750 && my >= 30 && my <= 98)
			{
				screen=0;
			}
		}
		if(screen==2)
		{
			if(mx >= 550 && mx <= 750 && my >= 30 && my <= 98)
			{
				screen=0;
			}
		}
		if (screen ==2)
		{
			if(mx >= 50 && mx <= 250 && my >= 400 && my <= 468)
			{
                PlaySound("bg music.wav", NULL, SND_LOOP | SND_ASYNC);

			}
			if(mx >= 550 && mx <= 750 && my >= 400 && my <= 468)
			{
				PlaySound(0,0,0);
				   
			}
	
		}
		if(screen==3)
		{
           if(mx >= 550 && mx <= 750 && my >= 30 && my <= 98)
			{
				screen=0;
			}
		}

		if(screen == 4)
		{
			if(mx >= 550 && mx <= 750 && my >= 400 && my <= 468)
			{
				screen=0;
			}
		}
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'x')
	{
		// do something with 'x'
		exit(0);
	}
    if(screen!=1){

	if(key == 'm'){
	PlaySound("bg music.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if(key == 'o'){
	  PlaySound(0,0,0);
	}
	}
	

	// place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	
	

	// place your codes for other keys here
}
int main()
{
	// place your own initialization codes here.
	// t=iSetTimer(50,iChangePic);
	
	PlaySound("bg music.wav", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(800, 500, "Pokemon Puzzle Game");
	return 0;
}
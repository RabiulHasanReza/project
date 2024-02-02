#include "iGraphics.h"
#include <stdlib.h>
#include<time.h>

void location_change();
void coordinates();
void check_match();

void location_change2();
void coordinates2();
void check_match2();

bool musicOn=true;
bool easy=true;
int screen = 0;
clock_t start,start2;

struct puzzle{
	int x;
	int y;
};

struct puzzle pic[9];

struct correctPuzzle{
	int x;
	int y;
};

struct correctPuzzle correct_pic[9];

struct puzzle2{
	int x2;
	int y2;
};

struct puzzle2 pic2[16];

struct correctPuzzle2{
	int x2;
	int y2;
};

struct correctPuzzle2 correct_pic2[16];

bool match=true;
bool match2=true;
char puzzlePices[9][20]={"image1x1.bmp","image2x1.bmp","image3x1.bmp","image1x2.bmp","image2x2.bmp","image3x2.bmp","image1x3.bmp",
"image2x3.bmp", "image3x3.bmp"};

char puzzlePices2[16][25]={"image@1x1.bmp","image@2x1.bmp","image@3x1.bmp","image@4x1.bmp","image@1x2.bmp","image@2x2.bmp","image@3x2.bmp",
"image@4x2.bmp","image@1x3.bmp","image@2x3.bmp", "image@3x3.bmp","image@4x3.bmp","image@1x4.bmp","image@2x4.bmp","image@3x4.bmp",
"image@4x4.bmp"};

int wall_x=0,wall_y=334;
int wall_x2=0,wall_y2=375;
char score[10];

void iDraw()
{
	iClear();
	// place your drawing codes here
	if (screen == 0)                    //Home page
	{   

		iShowBMP(0, 0, "Home page.bmp");
		iShowBMP2(30, 300, "button 1.bmp", 0);
		iShowBMP2(30, 200, "button 2.bmp", 0);
		iShowBMP2(30, 100, "button 3.bmp", 0);
		iShowBMP2(580,20,"info button.bmp",0);
	}
	
	if (screen == 1)                  //Puzzle1
	{
		//iShowBMP(0, 0, "screen2.bmp");
		iShowBMP(0,0,"wall.bmp");
		iShowBMP(550,300,"preview.bmp");
		iText(600, 275, "Match this", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(550, 30, "button6.bmp", 0);
       
	   iSetColor(255,255,255);
		clock_t end = clock();
		double time_diff = ( start - end) / CLOCKS_PER_SEC;
		char str[10];
		sprintf(str, "%.2lf", time_diff);
		if (time_diff < 1){
			screen = 5;
			PlaySound("game over.wav", NULL,SND_ASYNC);
			 //PlaySound("bg music.wav", NULL, SND_LOOP | SND_ASYNC);
		}
		iText(580, 150, "TIME :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(660, 150, str, GLUT_BITMAP_TIMES_ROMAN_24);

		int count = 1;
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				if (i == 0 && j == 0)    continue;
				else
				{
					iShowBMP(pic[count].x,pic[count].y, puzzlePices[count]);
					count++;
				 }
			}
		}
		check_match();
		if(match == true){
			screen = 6;
            if(easy)
			sprintf(score, "%g",30-time_diff);
			else
			sprintf(score, "%g",20-time_diff);
			
			PlaySound("win.wav",NULL,SND_ASYNC);
		}
		
	}
	if (screen == 8)                 //Puzzle2
	{
		//iShowBMP(0, 0, "screen2.bmp");
		iShowBMP(0,0,"wall.bmp");
		iShowBMP(550,300,"preview2.bmp");
		iText(600, 275, "Match this", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(550, 30, "button6.bmp", 0);
       
	   iSetColor(255,255,255);
		clock_t end = clock();
		double time_diff = ( start2 - end) / CLOCKS_PER_SEC;
		char str[10];
		sprintf(str, "%.2lf", time_diff);
		if (time_diff < 1){
			screen = 5;
			PlaySound("game over.wav", NULL,SND_ASYNC);
			 //PlaySound("bg music.wav", NULL, SND_LOOP | SND_ASYNC);
		}
		iText(580, 150, "TIME :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(660, 150, str, GLUT_BITMAP_TIMES_ROMAN_24);

		int index = 1;
		for (int i = 0; i<4; i++)
		{
			for (int j = 0; j<4; j++)
			{
				if (i == 0 && j == 0)    continue;
				else
				{
					iShowBMP(pic2[index].x2,pic2[index].y2, puzzlePices2[index]);
					index++;
				 }
			}
		}
		check_match2();
		if(match2 == true){
			screen = 6;
			if(easy)
			sprintf(score, "%g",45-time_diff);
			else
			sprintf(score, "%g",30-time_diff);
			PlaySound("win.wav",NULL,SND_ASYNC);
		}
		
	}

		//iShowBMP(0,0,"pokemon.bmp");
		

	if (screen == 2)                       //music
	{

		iShowBMP(0, 0, "pikachuNew.bmp");
		iShowBMP2(50, 400, "button4.bmp", 0);
		iShowBMP2(550, 400, "button5.bmp", 0);
		iShowBMP2(550, 30, "button6.bmp", 0);
	}
	if (screen == 3)                     //mode
	{
		iShowBMP(0, 0, "screen3.bmp");
		iShowBMP2(550, 30, "button6.bmp", 0);
		iShowBMP2(50, 350, "button9.bmp", 0);
		iShowBMP2(550,350, "button10.bmp", 0);
	}
	if(screen == 4)                    //Info
	{                  
        iShowBMP(0,0,"bg8.bmp");
	    iText(30, 120, "Use Left click to move a picture .The picture you click will be swapped", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(30, 100, "with the blank pic.", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(30, 20, "You have \"30 or 45 SECONDS \" time to match it.", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 0, 0);
		iText(30, 50, "Press o to mute sound and m to unmute.", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(550, 400, "button6.bmp", 0);
		iText(30,150,"In easy mode you will get more time than hard mode",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(screen == 5)                //lose
	{                         
		iShowBMP(0,0,"lose.bmp");
		iShowBMP2(550, 30, "button6.bmp", 0);
		iSetColor(0,0,0);
		iText(350, 350, "YOU LOSE", GLUT_BITMAP_TIMES_ROMAN_24);
		//iShowBMP2(0,0,"R.bmp",0);
	}

	if(screen==6)                //win
	{
		iShowBMP(20,20,"win.bmp");
		iShowBMP2(550, 30, "button6.bmp", 0);
        iSetColor(255,255,255);
		iText(520,400,"YOU WON",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550,300,"YOUR TIME :",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700,300,score,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(730,300,"sec",GLUT_BITMAP_TIMES_ROMAN_24);

	}
	if(screen == 7)            //enter
	{
		iShowBMP(0,0,"bg4.bmp");
		iShowBMP2(0,375,"button11.bmp",0);
		iShowBMP2(375,375,"button12.bmp",0);
		iShowBMP2(300, 30, "button6.bmp", 0);
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
				
				screen = 7;
				
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
				screen=7;
			}
			int tempx = (mx/167)*167 ;
			int tempy = (my/167)*167 ;
			for (int i = 1; i<=9; i++)
			{
				if (pic[i].x == tempx && pic[i].y == tempy)
				{
					pic[i].x = wall_x;
					pic[i].y = wall_y;
					wall_x = tempx;
					wall_y = tempy;
					break;
				}

			}
		}
		if(screen==8)
		{
			if(mx >= 550 && mx <= 750 && my >= 30 && my <= 98)
			{
				screen=7;
			}
			int tempx2 = (mx/125)*125 ;
			int tempy2 = (my/125)*125 ;
			for (int i = 1; i<=16; i++)
			{
				if (pic2[i].x2 == tempx2 && pic2[i].y2 == tempy2)
				{
					pic2[i].x2 = wall_x2;
					pic2[i].y2 = wall_y2;
					wall_x2 = tempx2;
					wall_y2 = tempy2;
					break;
				}

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
                PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
				musicOn = true;

			}
			if(mx >= 550 && mx <= 750 && my >= 400 && my <= 468)
			{
				PlaySound(0,0,0);
				musicOn = false;
				   
			}
	
		}
		if(screen==3)
		{
           if(mx >= 50 && mx <= 250 && my >= 350 && my <= 350+68)
			{
				easy=false;
			}
			if(mx >= 550 && mx <= 750 && my >= 350 && my <= 350+68)
			{
				easy=true;
			}
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
		if(screen == 5)
		{   
			
			if(mx >= 550 && mx <= 750 && my >= 30 && my <= 98)
			{
				screen=0;
				if(musicOn == true){
				 PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
		}
		if(screen == 6)
		{
			if(mx >= 550 && mx <= 750 && my >= 30 && my <= 98)
			{
				screen=0;
				if(musicOn == true){
				 PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
		}
		if(screen == 7){
			if(mx>=0 && mx<=200 && my>=375 && my<=375+68){
				coordinates();
				location_change();
				screen = 1;
				if(easy==true)
				{
					start=clock()+31000;
				}
				else
				{
					start=clock()+21000;
				}
			}
			if(mx>=375 && mx<=575 && my>=375 && my<=375+68){
				coordinates2();
				location_change2();
				screen = 8;
				if(easy==true)
				{
					start2=clock()+46000;
				}
				else
				{
					start2=clock()+31000;
				}	
			}
			if(mx >= 300 && mx <= 500 && my >= 30 && my <= 98)
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
	PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if(key == 'o'){
	  PlaySound(0,0,0);
	}
	}
	

	// place your codes for other keys here
}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	


	// place your codes for other keys here
}

void location_change()
{
	int low = 2, high = 9;
	int box[6];
	srand(time(NULL));

	for (int i = 0; i<6; i++)
	{
		box[i] = rand() % (high - low) + low;
	redo:
		for (int j = 0; j<i; j++)
		{
			if (box[i] == box[j])
			{
				box[i] = rand() % (high - low) + low;
				goto redo;
			}
		}
		
	}
	for (int i = 0; i<6; i = i + 2)
	{
		pic[box[i]].x = correct_pic[box[i + 1]].x;
		pic[box[i]].y = correct_pic[box[i + 1]].y;
		//printf("%d got %d's coordinates\n",box[i],box[i+1]);
		pic[box[i + 1]].x = correct_pic[box[i]].x;
		pic[box[i + 1]].y = correct_pic[box[i]].y;

	}

}
void coordinates()
{
	int n = 0;
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			pic[n].x = 0 + j * 167;		//storing real addresses
			pic[n].y = 334 - i * 167;
			correct_pic[n].x = pic[n].x;	//storing real addresses
			correct_pic[n].y = pic[n].y;
			n++;

		}
	}
}

void check_match(){
	 match = true;
    int n=1;
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (i == 0 && j == 0)    continue;
			else
			{
				if (pic[n].x != correct_pic[n].x)
				{
					match = false;
					break;
				}
				if (pic[n].y != correct_pic[n].y)
				{
					match = false;
					break;
				}
				n++;
			}

		}
	}
}

void location_change2()
{
	int low = 2, high = 16;
	int box[8];
	srand(time(NULL));

	for (int i = 0; i<8; i++)
	{
		box[i] = rand() % (high - low) + low;
	redo:
		for (int j = 0; j<i; j++)
		{
			if (box[i] == box[j])
			{
				box[i] = rand() % (high - low) + low;
				goto redo;
			}
		}
		
	}
	for (int i = 0; i<8; i = i + 2)
	{
		pic2[box[i]].x2 = correct_pic2[box[i + 1]].x2;
		pic2[box[i]].y2 = correct_pic2[box[i + 1]].y2;
		//printf("%d got %d's coordinates\n",box[i],box[i+1]);
		pic2[box[i + 1]].x2 = correct_pic2[box[i]].x2;
		pic2[box[i + 1]].y2 = correct_pic2[box[i]].y2;

	}

}
void coordinates2()
{
	int n = 0;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			pic2[n].x2 = 0 + j * 125;		//storing real addresses
			pic2[n].y2 = 375 - i * 125;
			correct_pic2[n].x2 = pic2[n].x2;	//storing real addresses
			correct_pic2[n].y2= pic2[n].y2;
			n++;

		}
	}
}

void check_match2(){
	 match2 = true;
    int n=1;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			if (i == 0 && j == 0)    continue;
			else
			{
				if (pic2[n].x2 != correct_pic2[n].x2)
				{
					match2 = false;
					break;
				}
				if (pic2[n].y2 != correct_pic2[n].y2)
				{
					match2 = false;
					break;
				}
				n++;
			}

		}
	}
}
int main()
{
	// place your own initialization codes here.
	// t=iSetTimer(50,iChangePic);
	
	PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(800, 500, "Pokemon Puzzle Game");
	return 0;
}
#include "iGraphics.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void location_change();
void coordinates();
void check_match();

void location_change2();
void coordinates2();
void check_match2();

bool musicOn = true;
bool easy = true, enter = false;
int screen = 0, puzzleCount;
clock_t start, start2;
int puzNo = 1, run = 1, puzNo2 = 1;
double moveCount = 0;

struct puzzle
{
	int x;
	int y;
};

struct puzzle pic[9];

struct correctPuzzle
{
	int x;
	int y;
};

struct correctPuzzle correct_pic[9];

struct puzzle2
{
	int x2;
	int y2;
};

struct puzzle2 pic2[16];

struct correctPuzzle2
{
	int x2;
	int y2;
};

struct correctPuzzle2 correct_pic2[16];

bool match = true;
bool match2 = true;
char puzzlePices[9][20] = {"image1x1.bmp", "image2x1.bmp", "image3x1.bmp", "image1x2.bmp", "image2x2.bmp", "image3x2.bmp", "image1x3.bmp",
						   "image2x3.bmp", "image3x3.bmp"};
char puzzlePices1[9][20] = {"image#1x1.bmp", "image#2x1.bmp", "image#3x1.bmp", "image#1x2.bmp", "image#2x2.bmp", "image#3x2.bmp", "image#1x3.bmp",
							"image#2x3.bmp", "image#3x3.bmp"};
char puzzlePices3[9][20] = {"image$1x1.bmp", "image$2x1.bmp", "image$3x1.bmp", "image$1x2.bmp", "image$2x2.bmp", "image$3x2.bmp", "image$1x3.bmp",
							"image$2x3.bmp", "image$3x3.bmp"};
char puzzlePices4[9][20] = {"image&1x1.bmp", "image&2x1.bmp", "image&3x1.bmp", "image&1x2.bmp", "image&2x2.bmp", "image&3x2.bmp", "image&1x3.bmp",
							"image&2x3.bmp", "image&3x3.bmp"};

char puzzlePices2[16][25] = {"image@1x1.bmp", "image@2x1.bmp", "image@3x1.bmp", "image@4x1.bmp", "image@1x2.bmp", "image@2x2.bmp", "image@3x2.bmp",
							 "image@4x2.bmp", "image@1x3.bmp", "image@2x3.bmp", "image@3x3.bmp", "image@4x3.bmp", "image@1x4.bmp", "image@2x4.bmp", "image@3x4.bmp",
							 "image@4x4.bmp"};

char puzzlePices5[16][25] = {"image^1x1.bmp", "image^2x1.bmp", "image^3x1.bmp", "image^4x1.bmp", "image^1x2.bmp", "image^2x2.bmp", "image^3x2.bmp",
							 "image^4x2.bmp", "image^1x3.bmp", "image^2x3.bmp", "image^3x3.bmp", "image^4x3.bmp", "image^1x4.bmp", "image^2x4.bmp", "image^3x4.bmp",
							 "image^4x4.bmp"};

char puzzlePices6[16][25] = {"image!1x1.bmp", "image!2x1.bmp", "image!3x1.bmp", "image!4x1.bmp", "image!1x2.bmp", "image!2x2.bmp", "image!3x2.bmp",
							 "image!4x2.bmp", "image!1x3.bmp", "image!2x3.bmp", "image!3x3.bmp", "image!4x3.bmp", "image!1x4.bmp", "image!2x4.bmp", "image!3x4.bmp",
							 "image!4x4.bmp"};

int wall_x = 0, wall_y = 334;
int wall_x2 = 0, wall_y2 = 375;
char score[10];
char move[10];
char name[100];
int nameIndex = 0;
int coX=270,coY=200;

void iDraw()
{
	iClear();
	// place your drawing codes here
	if (screen == 0) // Home page
	{
        
		iShowBMP(0, 0, "OIG4.bmp");
		iShowBMP2(30, 300, "button 1.bmp", 0);
		iShowBMP2(30, 200, "button 2.bmp", 0);
		iShowBMP2(30, 100, "button 3.bmp", 0);
		iShowBMP2(580, 20, "info button.bmp", 0);
		iShowBMP2(580, 120, "button14.bmp", 0);
		iShowBMP(coX,coY,"try.bmp");
		iSetColor(0,0,0);
		iLine(270,0,270,300);
		iLine(570,0,570,300);
		iLine(270,300,570,300);
		iLine(271,0,271,300);
		iLine(571,0,571,300);
		iLine(270,301,570,301);
		iLine(272,0,272,300);
		iLine(572,0,572,300);
		iLine(270,302,570,302);
	}

	if (screen == 1) // Puzzle1
	{

		
		iShowBMP(0, 0, "wall.bmp");
		iShowBMP2(550, 30, "button6.bmp", 0);
		if (puzNo == 1)
		{
			iShowBMP(550, 300, "preview.bmp");
		}
		if (puzNo == 2)
		{
			iShowBMP(550, 300, "preview1.bmp");
		}
		if (puzNo == 3)
		{
			iShowBMP(550, 300, "preview3.bmp");
		}
		if (puzNo == 4)
		{
			iShowBMP(550, 300, "preview4.bmp");
		}
		iText(600, 275, "Match this", GLUT_BITMAP_TIMES_ROMAN_24);
		// iShowBMP2(550, 30, "button6.bmp", 0);

		iSetColor(255, 255, 255);
		clock_t end = clock();
		double time_diff = (start - end) / CLOCKS_PER_SEC;
		char str[10];
		char str2[10];
		sprintf(str, "%g", time_diff);
		sprintf(str2, "%g", moveCount);
		if (time_diff < 1)
		{
			screen = 5;
			PlaySound(TEXT("game over.wav"), NULL, SND_ASYNC);
			if (puzNo < 4)
			{
				puzNo++;
			}
			else
			{
				puzNo = 1;
			}

			wall_x = 0;
			wall_y = 334;
		}
		iText(580, 150, "TIME :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(660, 150, str, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(580, 180, "MOVE :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(680, 180, str2, GLUT_BITMAP_TIMES_ROMAN_24);

		int count = 1, count1 = 1, count3 = 1, count4 = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 0 && j == 0)
					continue;
				else
				{
					if (puzNo == 1)
					{
						iShowBMP(pic[count].x, pic[count].y, puzzlePices[count]);
						count++;
					}
					if (puzNo == 2)
					{
						iShowBMP(pic[count1].x, pic[count1].y, puzzlePices1[count1]);
						count1++;
					}
					if (puzNo == 3)
					{
						iShowBMP(pic[count3].x, pic[count3].y, puzzlePices3[count3]);
						count3++;
					}
					if (puzNo == 4)
					{
						iShowBMP(pic[count4].x, pic[count4].y, puzzlePices4[count4]);
						count4++;
					}
				}
			}
		}
		check_match();
		if (match == true)
		{
			screen = 6;
			run == 1;
			if (easy)
				sprintf(score, "%g", 30 - time_diff);
			else
				sprintf(score, "%g", 20 - time_diff);

			sprintf(move, "%g", moveCount);

			PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
			if (puzNo < 4)
			{
				puzNo++;
			}
			else
			{
				puzNo = 1;
			}
		}
	}
	if (screen == 8) // Puzzle2
	{
		// iShowBMP(0, 0, "screen2.bmp");
		iShowBMP(0, 0, "wall.bmp");
		if (puzNo2 == 1)
			iShowBMP(550, 300, "preview2.bmp");
		if (puzNo2 == 2)
			iShowBMP(550, 300, "raichu.bmp");
		if (puzNo2 == 3)
			iShowBMP(550, 300, "Rrttt.bmp");
		iShowBMP2(550, 30, "button6.bmp", 0);
		iText(600, 275, "Match this", GLUT_BITMAP_TIMES_ROMAN_24);
		// iShowBMP2(550, 30, "button6.bmp", 0);

		iSetColor(255, 255, 255);
		clock_t end = clock();
		double time_diff = (start2 - end) / CLOCKS_PER_SEC;
		char str[10];
		char str2[10];
		sprintf(str, "%g", time_diff);
		sprintf(str2, "%g", moveCount);
		if (time_diff < 1)
		{
			screen = 5;
			PlaySound(TEXT("game over.wav"), NULL, SND_ASYNC);
			// PlaySound("bg music.wav", NULL, SND_LOOP | SND_ASYNC);
			wall_x2 = 0;
			wall_y2 = 375;
		}
		iText(580, 150, "TIME :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(660, 150, str, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(580, 180, "MOVE :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(680, 180, str2, GLUT_BITMAP_TIMES_ROMAN_24);

		int index = 1, index2 = 1, index3 = 1;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i == 0 && j == 0)
					continue;
				else
				{
					if (puzNo2 == 1)
					{
						iShowBMP(pic2[index].x2, pic2[index].y2, puzzlePices2[index]);
						index++;
					}
					if (puzNo2 == 2)
					{
						iShowBMP(pic2[index2].x2, pic2[index2].y2, puzzlePices5[index2]);
						index2++;
					}
					if (puzNo2 == 3)
					{
						iShowBMP(pic2[index3].x2, pic2[index3].y2, puzzlePices6[index3]);
						index3++;
					}
				}
			}
		}
		check_match2();
		if (match2 == true)
		{
			screen = 6;
			run == 1;
			if (easy)
				sprintf(score, "%g", 45 - time_diff);
			else
				sprintf(score, "%g", 30 - time_diff);

			sprintf(move, "%g", moveCount);

			PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
			if (puzNo2 < 3)
			{
				puzNo2++;
			}
			else
			{
				puzNo2 = 1;
			}
		}
	}

	// iShowBMP(0,0,"pokemon.bmp");

	if (screen == 2) // music
	{

		iShowBMP(0, 0, "pikachuNew.bmp");
		iShowBMP2(50, 400, "button4.bmp", 0);
		iShowBMP2(550, 400, "button5.bmp", 0);
		iShowBMP2(550, 30, "button6.bmp", 0);
	}
	if (screen == 3) // mode
	{
		iShowBMP(0, 0, "screen3.bmp");
		iShowBMP2(550, 30, "button6.bmp", 0);
		iShowBMP2(50, 350, "button9.bmp", 0);
		iShowBMP2(550, 350, "button10.bmp", 0);
		iSetColor(255, 255, 255);
		if (easy)
		{
			iText(30, 450, "MODE : Easy", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else
		{
			iText(30, 450, "MODE : Hard", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
	if (screen == 4) // Info
	{
		iShowBMP(0, 0, "bg8.bmp");
		iText(30, 120, "Use Left click to move a picture .The picture you click will be swapped", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(30, 100, "with the blank pic.", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(30, 20, "You have \"30 or 45 SECONDS \" time to match it.", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 0, 0);
		iText(30, 50, "Press o to mute sound and m to unmute.", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(550, 400, "button6.bmp", 0);
		iText(30, 150, "In easy mode you will get more time than hard mode", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400,250,"High score will be shown if you win .",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400,220,"To save your score put your name.",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400,190,"Don't forget to press enter",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (screen == 5) // lose
	{
		iShowBMP(0, 0, "lose.bmp");
		iShowBMP2(550, 280, "button6.bmp", 0);
		iShowBMP2(20, 280, "buttonPlay.bmp", 0);
		iSetColor(0, 0, 0);
		
	}

	if (screen == 6) // win
	{
		iShowBMP(20, 20, "win.bmp");
		iShowBMP2(550, 30, "button6.bmp", 0);
		iSetColor(255, 255, 255);
		iText(520, 400, "YOU WON", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550, 300, "YOUR TIME :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 300, score, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550, 250, "YOUR MOVE :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(720, 250, move, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(730, 300, "sec", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 255, 255);
		iFilledRectangle(0, 420, 800, 50);
		iSetColor(0, 0, 0);
		iText(20, 435, "ENTER YOUR NAME :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(280, 435, name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 435, "press enter");

		if (puzzleCount == 1)
		{
			if (enter)
			{
				if (run == 1)
				{
					FILE *ifp1 = fopen("score.txt", "r");
					FILE *ofp2 = fopen("out.txt", "w");
					int mind = 0;
					// comparing
					char id[150];
					while (fgets(id, 100, ifp1))
					{

						char point[10];
						fgets(point, 8, ifp1);
						int v = atoi(point);

						if (moveCount < v && mind == 0)
						{
							fputs(name, ofp2);
							fprintf(ofp2, "\n");
							fputs(move, ofp2);
							fprintf(ofp2, "\n");
							fputs(id, ofp2);
							fputs(point, ofp2);

							mind++;
						}
						else
						{
							fputs(id, ofp2);
							fputs(point, ofp2);
						}
					}
					fclose(ifp1);
					fclose(ofp2);
					FILE *ofp1 = fopen("score.txt", "w");
					FILE *ifp2 = fopen("out.txt", "r");

					char temp[200];
					while (fgets(temp, 150, ifp2))
					{
						fputs(temp, ofp1);
					}
					fclose(ifp2);
					fclose(ofp1);
					run++;
				}
			}
			// show file
			FILE *ifp = fopen("score.txt", "r");
			if (ifp == NULL)
				printf("Cant open ifp");
			else
			{

				char newName[200];
				char point[10];
				fgets(newName, 200, ifp);
				fgets(point, 8, ifp);
				iSetColor(255, 255, 255);
				iText(480, 150, "NAME :", GLUT_BITMAP_TIMES_ROMAN_24);
				iText(580, 150, newName, GLUT_BITMAP_TIMES_ROMAN_24);
				iText(670, 150, "MOVE :", GLUT_BITMAP_TIMES_ROMAN_24);
				iText(760, 150, point, GLUT_BITMAP_TIMES_ROMAN_24);
			}
			fclose(ifp);
			iSetColor(255, 0, 0);
			iLine(520, 195, 800, 195);
			iText(550, 200, "TOP SCORE :", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (puzzleCount == 2)
		{
			if (enter)
			{
				if (run == 1)
				{
					FILE *ifp1 = fopen("score2.txt", "r");
					FILE *ofp2 = fopen("out2.txt", "w");
					int mind = 0;
					// comparing
					char id[150];
					while (fgets(id, 100, ifp1))
					{

						char point[10];
						fgets(point, 8, ifp1);
						int v = atoi(point);

						if (moveCount < v && mind == 0)
						{
							fputs(name, ofp2);
							fprintf(ofp2, "\n");
							fputs(move, ofp2);
							fprintf(ofp2, "\n");
							fputs(id, ofp2);
							fputs(point, ofp2);
							mind++;
						}
						else
						{
							fputs(id, ofp2);
							fputs(point, ofp2);
						}
					}
					fclose(ifp1);
					fclose(ofp2);
					FILE *ofp1 = fopen("score2.txt", "w");
					FILE *ifp2 = fopen("out2.txt", "r");

					char temp[200];
					while (fgets(temp, 150, ifp2))
					{
						fputs(temp, ofp1);
					}
					fclose(ifp2);
					fclose(ofp1);
					run++;
				}
			}

			// show file
			FILE *ifp = fopen("score2.txt", "r");
			if (ifp == NULL)
				printf("Cant open ifp");
			else
			{

				char newName[200];
				char point[10];
				fgets(newName, 200, ifp);
				fgets(point, 8, ifp);
				iSetColor(255, 255, 255);
				iText(480, 150, "NAME :", GLUT_BITMAP_TIMES_ROMAN_24);
				iText(580, 150, newName, GLUT_BITMAP_TIMES_ROMAN_24);
				iText(670, 150, "MOVE :", GLUT_BITMAP_TIMES_ROMAN_24);
				iText(760, 150, point, GLUT_BITMAP_TIMES_ROMAN_24);
			}
			fclose(ifp);
			iSetColor(255, 0, 0);
			iLine(520, 195, 800, 195);
			iText(550, 200, "TOP SCORE :", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
	if (screen == 7) // enter
	{
		iShowBMP(0, 0, "bg4.bmp");
		iShowBMP2(0, 375, "button11.bmp", 0);
		iShowBMP2(375, 375, "button12.bmp", 0);
		iShowBMP2(300, 30, "button6.bmp", 0);
		iSetColor(0, 0, 0);
		if (easy)
		{
			iText(30, 450, "MODE : Easy", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else
		{
			iText(30, 450, "MODE : Hard", GLUT_BITMAP_TIMES_ROMAN_24);
		}

		// iSetColor(255, 255, 255);
		// iFilledRectangle(0, 150, 800, 50);
		// iSetColor(0, 0, 0);
		// iText(20, 165, "ENTER YOUR NAME :", GLUT_BITMAP_TIMES_ROMAN_24);
		// iText(280, 165, name, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (screen == 9)
	{
		iShowBMP(0, 0, "leaderboard.bmp");
		iShowBMP2(550, 30, "button6.bmp", 0);
		iSetColor(0, 0, 0);
		iText(20, 450, "Puzle 3x3", GLUT_BITMAP_TIMES_ROMAN_24);
		iLine(0, 440, 150, 440);
		FILE *ifp = fopen("score.txt", "r");
		if (ifp == NULL)
			printf("Cant open ifp");
		else
		{
			for (int i = 0; i < 3; i++)
			{
				char newName[150];
				char point[10];
				fgets(newName, 200, ifp);
				fgets(point, 8, ifp);
				iText(30, 400 - i * 50, newName, GLUT_BITMAP_TIMES_ROMAN_24);
				iText(120, 400 - i * 50, point, GLUT_BITMAP_TIMES_ROMAN_24);
			}
			fclose(ifp);
		}
		iSetColor(0, 0, 0);
		iText(520, 450, "Puzle 4x4", GLUT_BITMAP_TIMES_ROMAN_24);
		iLine(520, 440, 670, 440);
		FILE *ifp2 = fopen("score2.txt", "r");
		if (ifp2 == NULL)
			printf("Cant open ifp");
		else
		{
			for (int i = 0; i < 3; i++)
			{
				char newName[150];
				char point[10];
				fgets(newName, 200, ifp);
				fgets(point, 8, ifp);
				iText(530, 400 - i * 50, newName, GLUT_BITMAP_TIMES_ROMAN_24);
				iText(620, 400 - i * 50, point, GLUT_BITMAP_TIMES_ROMAN_24);
			}
			fclose(ifp2);
		}
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
		if (screen == 0)               //Home
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
			if (mx >= 580 && mx <= 780 && my >= 20 && my <= 88)
			{
				screen = 4;
			}
			if (mx >= 580 && mx <= 780 && my >= 120 && my <= 188)
			{
				screen = 9;
			}
		}

		if (screen == 1)                   //puzzle 1;
		{
			if (mx >= 0 && mx <= 500 && my >= 0 && my < 500)
			{
				moveCount++;
				PlaySound(TEXT("click.wav"),NULL,SND_ASYNC);
			}
			if (mx >= 550 && mx <= 750 && my >= 30 && my <= 98)
			{
				screen = 7;
				if (musicOn == true)
				{
					PlaySound(TEXT("music.wav"), NULL, SND_LOOP | SND_ASYNC);
				}
				if (puzNo < 4)
				{
					puzNo++;
				}
				else
				{
					puzNo = 1;
				}
				wall_x = 0;
				wall_y = 334;
			}

			int tempx = (mx / 167) * 167;
			int tempy = (my / 167) * 167;
			for (int i = 1; i <= 9; i++)
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
		if (screen == 8)              //puzzle 2
		{
			if (mx >= 550 && mx <= 750 && my >= 30 && my <= 98)
			{
				screen = 7;
				wall_x2 = 0;
				wall_y2 = 375;
				if (musicOn == true)
				{
					PlaySound(TEXT("music.wav"), NULL, SND_LOOP | SND_ASYNC);
				}
				if (puzNo2 < 3)
				{
					puzNo2++;
				}
				else
				{
					puzNo2 = 1;
				}
			}
			if (mx >= 0 && mx <= 500 && my >= 0 && my < 500)
			{
				moveCount++;
			}
			int tempx2 = (mx / 125) * 125;
			int tempy2 = (my / 125) * 125;
			for (int i = 1; i <= 16; i++)
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
		if (screen == 2)       //music
		{
			if (mx >= 550 && mx <= 750 && my >= 30 && my <= 98)
			{
				screen = 0;
			}
			if (mx >= 50 && mx <= 250 && my >= 400 && my <= 468)
			{
				PlaySound(TEXT("music.wav"), NULL, SND_LOOP | SND_ASYNC);
				musicOn = true;
			}
			if (mx >= 550 && mx <= 750 && my >= 400 && my <= 468)
			{
				PlaySound(0, 0, 0);
				musicOn = false;
			}
		}
		if (screen == 3)       //mode
		{
			if (mx >= 50 && mx <= 250 && my >= 350 && my <= 350 + 68)
			{
				easy = false;
			}
			if (mx >= 550 && mx <= 750 && my >= 350 && my <= 350 + 68)
			{
				easy = true;
			}
			if (mx >= 550 && mx <= 750 && my >= 30 && my <= 98)
			{
				screen = 0;
			}
		}

		if (screen == 4)         //info
		{
			if (mx >= 550 && mx <= 750 && my >= 400 && my <= 468)
			{
				screen = 0;
			}
		}
		if (screen == 5)        //lose
		{

			if (mx >= 550 && mx <= 750 && my >= 280 && my <= 348)
			{
				screen = 0;
				if (musicOn == true)
				{
					PlaySound(TEXT("music.wav"), NULL, SND_LOOP | SND_ASYNC);
				}
			}
			if (mx >= 20 && mx <= 200 && my >= 280 && my <= 348)
			{
				screen = 7;
				if (musicOn == true)
				{
					PlaySound(TEXT("music.wav"), NULL, SND_LOOP | SND_ASYNC);
				}
			}
		}
		if (screen == 6)                //win
		{
			if (mx >= 550 && mx <= 750 && my >= 30 && my <= 98)
			{
				screen = 0;
				enter = false;
				if (musicOn == true)
				{
					PlaySound(TEXT("music.wav"), NULL, SND_LOOP | SND_ASYNC);
				}
			}
		}
		if (screen == 7)           //enter
		{
			if (mx >= 0 && mx <= 200 && my >= 375 && my <= 375 + 68)
			{
				run = 1;
				moveCount = 0;
				coordinates();
				location_change();
				screen = 1;
				puzzleCount = 1;
				if (easy == true)
				{
					start = clock() + 31000;
				}
				else
				{
					start = clock() + 21000;
				}
				PlaySound(0, 0, 0);
			}
			if (mx >= 375 && mx <= 575 && my >= 375 && my <= 375 + 68)
			{
				run = 1;
				moveCount = 0;
				coordinates2();
				location_change2();
				screen = 8;
				puzzleCount = 2;
				if (easy == true)
				{
					start2 = clock() + 46000;
				}
				else
				{
					start2 = clock() + 31000;
				}
				PlaySound(0, 0, 0);
			}
			if (mx >= 300 && mx <= 500 && my >= 30 && my <= 98)
			{
				screen = 0;
			}
		}

		if (screen == 9)                //leaderboard.
		{
			if (mx >= 550 && mx <= 750 && my >= 30 && my <= 98)
			{
				screen = 0;
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
	if (screen != 1 && screen != 8 && screen != 7)          //for entering the mane.
	{

		if (key == 'm')
		{
			PlaySound(TEXT("music.wav"), NULL, SND_LOOP | SND_ASYNC);
		}
		if (key == 'o')
		{
			PlaySound(0, 0, 0);
		}
	}
	if (screen == 6)
	{
		if (key != '\b')
		{
			name[nameIndex] = key;
			nameIndex++;
			name[nameIndex] = '\0';
		}
		else
		{
			if (nameIndex > 0)
			{
				nameIndex--;
				name[nameIndex] = '\0';
			}
			else
			{
				nameIndex = 0;
			}
		}
		if (key == '\r')
		{
			enter = true;
		}
	}
}

// place your codes for other keys here

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	// place your codes for other keys here
}

void location_change()          // this function generates random position for puzzle. 
{
	int low = 2, high = 9;
	int box[6];
	srand(time(NULL));

	for (int i = 0; i < 6; i++)
	{
		box[i] = rand() % (high - low) + low;
	redo:
		for (int j = 0; j < i; j++)
		{
			if (box[i] == box[j])
			{
				box[i] = rand() % (high - low) + low;
				goto redo;
			}
		}
	}
	for (int i = 0; i < 6; i = i + 2)
	{
		pic[box[i]].x = correct_pic[box[i + 1]].x;
		pic[box[i]].y = correct_pic[box[i + 1]].y;
		pic[box[i + 1]].x = correct_pic[box[i]].x;
		pic[box[i + 1]].y = correct_pic[box[i]].y;
	}
}
void coordinates()                 //this fuction generates real position for matched puzzled.
{
	int n = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pic[n].x = 0 + j * 167; // storing real addresses
			pic[n].y = 334 - i * 167;
			correct_pic[n].x = pic[n].x; // storing real addresses
			correct_pic[n].y = pic[n].y;
			n++;
		}
	}
}

void check_match()           // tihs function check if its a match or not to declair win .
{
	match = true;
	int n = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0 && j == 0)
				continue;
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

	for (int i = 0; i < 8; i++)
	{
		box[i] = rand() % (high - low) + low;
	redo:
		for (int j = 0; j < i; j++)
		{
			if (box[i] == box[j])
			{
				box[i] = rand() % (high - low) + low;
				goto redo;
			}
		}
	}
	for (int i = 0; i < 8; i = i + 2)
	{
		pic2[box[i]].x2 = correct_pic2[box[i + 1]].x2;
		pic2[box[i]].y2 = correct_pic2[box[i + 1]].y2;
		// printf("%d got %d's coordinates\n",box[i],box[i+1]);
		pic2[box[i + 1]].x2 = correct_pic2[box[i]].x2;
		pic2[box[i + 1]].y2 = correct_pic2[box[i]].y2;
	}
}
void coordinates2()
{
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			pic2[n].x2 = 0 + j * 125; // storing real addresses
			pic2[n].y2 = 375 - i * 125;
			correct_pic2[n].x2 = pic2[n].x2; // storing real addresses
			correct_pic2[n].y2 = pic2[n].y2;
			n++;
		}
	}
}

void check_match2()
{
	match2 = true;
	int n = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0 && j == 0)
				continue;
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

void animation(){
	coX+=100;
	if(coX==570 && coY==200){
		coY=100;
		coX=270;
	}
	if(coX==570 && coY==100){
		coY=0;
		coX=270;
	}
	if(coX==570 && coY==0){
		coX=270;
		coY=200;
	
	}
	
	
}
int main()
{
	// place your own initialization codes here.
	

	
	iSetTimer(500,animation);
	PlaySound(TEXT("music.wav"), NULL, SND_LOOP | SND_ASYNC);
	iInitialize(800, 500, "Pokemon Puzzle Game");
	return 0;
}
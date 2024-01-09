
# include "iGraphics.h"

int x = 50, y = 50;
int flag1=0;
int dx=10,dy=10;
int r=255,g=255,b=255;
bool jump=false;
int t,t1;
bool back=false;
int imagex=0;
int imagey=0;
int imageIndex=0;
int height=50, width=50;

char smurf[2][40]={"smurf.bmp","smurf.bmp"};



/*
	function iDraw() is called again and again by the system.

	*/

void iDraw() {
	//place your drawing codes here
	iClear();
	iSetColor(r,g,b);
	iFilledCircle(x,y,20);
	iSetColor(255,255,255);
	iText(100, 100, "Rabiul Hasan Reza",GLUT_BITMAP_TIMES_ROMAN_24);
	

	

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	x=mx-100;
	y=my-20;
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		x += 50;
		jump=true;
        iResumeTimer(t);
		//y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		x -= 50;
		//y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	if(key == 'd'){
		x+=50;
	}
	if(key == 'a'){
		x-=50;
	}
	if(key == 'w'){
		y+=50;
	}
	if(key == 's'){
		y-=50;
	}
	if(key=='r'){
		r=255;
		g=0;
		b=0;
	}
	if(key=='g'){
		r=0;
		g=255;
		b=0;
	}
	if(key=='b'){
		r=0;
		g=0;
		b=255;
	}
	if(key=='z'){
		iResumeTimer(t);
	}
	//place your codes for other keys here
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
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}
void change(){
	x+=dx;
	y+=dy;
	if(x>=800 || x<=0){
		dx*=-1;
	}
	if(y>=500 || y<=0){
		dy*=-1;
	}
	if(x>=800){
		r=255;
		g=0;
		b=0;
	}
	if(x<=0){
		r=0;
		g=255;
		b=0;
	}
	if(y>=500){
		r=0;
		g=0;
		b=255;
	}
	if(y<=0){
		iPauseTimer(t);

	}
}

void jump_set(){
	if(jump){
		if(y<=400){
		y+=10;
		}
	else if(y>=400){
	   jump=false;
	}
	}
}

int main(){
	//place your own initialization codes here.
	
	t=iSetTimer(25,change);
	iInitialize(800, 500, "project");
	return 0;
}

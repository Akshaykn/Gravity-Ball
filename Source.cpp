#include<stdlib.h>
#include<glut.h>
#include<time.h>
#include<stdio.h>
#include<mmsystem.h>
#include<math.h>
#include<windows.h>
//#include<sdafx.h>
float bspd=.025; 
char name[25];
float b1x=70,b1y=0;
float hm=0.0;
int w1,i=0,wflag=1,gameover=0;
int score=0,flag2=0,level=0;
char lscore[50],nlevel[50];
static int maxscore=0; 
float blockcolors[5][3]={ {0.3f, 0.8f, 0.26},{0.5f, 0.5f, 0.5f},{0.1f, 0.0f, 0.0f},{0.1f, 0.1f, 0.0f},{0.5f, 1.0f, 1.0f}};
void init(void)
{
               srand(time(0));
               b1y=(rand()% 10)-10;//b/ w 10 to 44
               glClearColor(0.0f,0.07f,0.14f,1.0f);//Lilac);
			   //glColor4f(0.0f, 1.0f, 1.0f, 1.0f);//light blue
               glShadeModel(GL_SMOOTH);
               glLoadIdentity();
               glOrtho(-100.0,100.0,-100.0,100.0, -1.0 , 1.0);
}


void drawcircle()
{        
	     
         glColor4f(0.9,0.3,.2,.7);
		 float r=6;
		 glLineWidth(6);
       glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < 100; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
		glVertex2f(x,y);
    }
	glEnd();
	  glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
      glBegin(GL_POLYGON);
    for(int ii = 0; ii < 1000; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(1000);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
		glVertex2f(x,y);
    }
	glEnd();
}



void showtext(float x,float y,float z,void *font,char*string)
{
              char *c;
              glRasterPos3f(x,y,z);
                 for(c=string;*c !='\0'; c++)
                {
                       glutBitmapCharacter(font, *c);
                }
}

void display1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f,0.07f,0.14f,1.0f);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glColor3f(1,1,1);
	 showtext(-25,0,0,GLUT_BITMAP_TIMES_ROMAN_24,"GAME OVER");
	  showtext(-30,-40,0,GLUT_BITMAP_HELVETICA_18,"YOUR SCORE IS:");
	  showtext(10,-40,0,GLUT_BITMAP_HELVETICA_18,lscore);
	  showtext(50,-78,0,GLUT_BITMAP_HELVETICA_18,"Press");
	 glRectf(63,-80,70,-71);
	 glColor3f(0,0,0);
	 showtext(64,-78,0,GLUT_BITMAP_TIMES_ROMAN_24,"Q");
	 glColor3f(1,1,1);
	  showtext(71,-78,0,GLUT_BITMAP_HELVETICA_18,"to exit");
	glFlush();
	glutSwapBuffers();
}

void mykey(unsigned char key,int x,int y)

{
	if(key=='Q') exit(0);
}


void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(1,1,1,1);
glColor4f(0.0f, 1.0f, 1.0f, 1.0f);//light blue

      
if(
(i==1465||i==-1465)

||
  (
        ( ((int)b1x==3)  || ((int)b1x==1)  || ((int)b1x==0
		)  ) && (int)b1y+80 >= (int)hm  &&   (int)b1y <= (int)hm )
		||
	   (( ((int)b1x+9==0) ) &&   (int)b1y+80 >= (int)hm  &&   (int)b1y <= (int)hm )
	   //||
         
			//  ( ( (int)b1y==(int)hm) ||  ( (int) b1y+80== (int)hm) && (int)b1x+5==0 ) 
  )
{ 
	  glutDestroyWindow(w1);
	  glutCreateWindow("game over");
	  init();
      glutDisplayFunc(display1);
	  glutKeyboardFunc(mykey);

}
else if(wflag==1)
{
      wflag=0;
	  int iflag=1;
	  // glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
      glColor3f(1,1,1);
	   showtext(-68,85,0,GLUT_BITMAP_HELVETICA_18,"JAWAHARLAL NEHRU NATIONAL COLLEGE OF ENGINEERING");
       showtext(-45,65,0,GLUT_BITMAP_HELVETICA_18,"DEPARTMENT OF COMPUTER SCIENCE");
	   showtext(-68,50,0,GLUT_BITMAP_HELVETICA_18,"a mini project for Computer Graphics & Visualization Laboratery");

	   glRectf(-30,0,30,20);
	   glColor3f(0.0f, 0.1f, 0.1f);//Dark blue
	   showtext(-22,8.5,0,GLUT_BITMAP_TIMES_ROMAN_24,"GRAVITY-BALL");
	   glColor3f(1,1,1);
	    showtext(-20,-28,0,GLUT_BITMAP_HELVETICA_18,"[CLICK TO START]");
	   showtext(-85,-40,0,GLUT_BITMAP_HELVETICA_18,"PRESENTED BY:");
	   showtext(-80,-55,0,GLUT_BITMAP_HELVETICA_18,"AKSHAY KRISHNA NAIK");
	   showtext(-20,-55,0,GLUT_BITMAP_HELVETICA_18,"4JN14CS006");
	   showtext(-80,-65,0,GLUT_BITMAP_HELVETICA_18,"SACHIN");
	   showtext(-40,-65,0,GLUT_BITMAP_HELVETICA_18,"PRESENTED BY:");

    glutSwapBuffers();
    glFlush();
}

else

{        if(score%5==0&&flag2==1)
         {
			 level+=1;
			 bspd+=0.005;
			 flag2=0;
         }
         else if(score%5!=0&&flag2!=1)
		 {
			 flag2=1;
         }
	       
           
          glPushMatrix();
          glColor3f(0.0,0.5,0.7);
         glRectf(-100,80,100,100); //ceil 
          glRectf(-100,-100,100,-80); //floor
		  glColor4f(0,0.25,0.89,0.6);
         glRectf(-97,-95,-71,-85);
		 glColor4f(0,0.25,0.89,0.6);
         glRectf(75,-95,97,-85);

		 glColor3f(1,1,1);
		 showtext(-95,-92.5,0,GLUT_BITMAP_HELVETICA_18,"SCORE:");
		 sprintf(lscore,"%d",score);
		  showtext(-77,-92.5,0,GLUT_BITMAP_HELVETICA_18,lscore);
		 glColor3f(1,1,1);
		 showtext(77,-92.5,0,GLUT_BITMAP_HELVETICA_18,"LEVEL:");
		  sprintf(nlevel,"%d",level);
		  showtext(92,-92.5,0,GLUT_BITMAP_HELVETICA_18,nlevel);
        glTranslatef(0.0,hm,0.0);
		
        drawcircle();
     
          if(b1x<-50)
        {
             score+=1;  
             b1x=50; 
             b1y=(rand()% 40)-60;
        }
        else
           b1x-=bspd;

        
         glTranslatef(b1x,-hm,0.0);
       glColor3fv(blockcolors[level]);//Blue-Green
      
      //glColor3f(1.0,0.0,0.0);
      
	  glBegin(GL_POLYGON);
	      glVertex2f(b1x,b1y);
		  glVertex2f(b1x,b1y+80);
		  glVertex2f(b1x+10,b1y+80);
		  glVertex2f(b1x+10,b1y);
      glEnd();
      glPopMatrix();
      glutSwapBuffers();
     glFlush();
    }
}


void moveHeliU(void)
{
hm+=0.05;
i++;
glutPostRedisplay();
}


void moveHeliD()
{
hm-=0.05;
i--;
glutPostRedisplay();
}


void mouse(int button, int state, int x, int y)
{
switch (button)
{
case GLUT_LEFT_BUTTON:
if (state == GLUT_DOWN){
	PlaySound("click_x.wav",NULL,SND_FILENAME|SND_ASYNC);
//PlaySound(NULL,0,0);
glutIdleFunc(moveHeliU);
}
else if (state == GLUT_UP)
glutIdleFunc(moveHeliD);
break;
default: break;
}
}




int main(int argc, char** argv)
{

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (800,600);
glutInitWindowPosition (100,100);
w1=glutCreateWindow ("Gravity Ball");
init();
glutDisplayFunc(display);
glutMouseFunc(mouse); 
glEnable(GL_LINE_SMOOTH);
//glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}


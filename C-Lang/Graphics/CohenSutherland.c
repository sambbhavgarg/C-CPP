#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<time.h>
#include<stdio.h>
#include<math.h>
#define outcode int

double xmin = 50, ymin = 50, xmax = 100, ymax = 100;// Windows boundaries
double xvmin = 200, yvmin = 200, xvmax = 300, yvmax = 300; // Viewport

const int RIGHT = 8; // bit codes for the right
const int LEFT = 2; //bit codes for the left
const int TOP = 4;// bit codes for the top
const int BOTTOM = 1; //bit codes for the bottom

outcode ComputeOutCode(double x, double y);
void CohenSutherlandLineClipAnddraw(double x0, double y0, double x1,double y1){
  outcode outcode0, outcode1, outcodeOut;
  int accept = 0, done = 0;
  outcode0 = ComputeOutCode(x0, y0);
  outcode1 = ComputeOutCode(x1, y1);
  do{
    if (!(outcode0 | outcode1)){
      accept = 1;
      done = 1;
    }
    else
      if (outcode0 & outcode1)
        done = 1;

      else{
        double x, y;
        outcodeOut = outcode0 ? outcode0 : outcode1;
        if (outcodeOut & TOP) {
          x = x0 + (x1 - x0)*(ymax - y0) / (y1 - y0);
          y = ymax;
        }

        else{
          if (outcodeOut & BOTTOM) {
            x = x0 + (x1 - x0)*(ymin - y0) / (y1 - y0);
            y = ymin;
          }

          else{
            if (outcodeOut & RIGHT){
              y = y0 + (y1 - y0)*(xmax - x0) / (x1 - x0);x = xmax;
            }
            else{
                y = y0 + (y1 - y0)*(xmin - x0) / (x1 - x0);
                x = xmin;
            }
          }

          if (outcodeOut == outcode0){
              x0 = x;
              y0 = y;
              outcode0 = ComputeOutCode(x0, y0);
          }

          else{
            x1 = x;
            y1 = y;
            outcode1 = ComputeOutCode(x1, y1);
          }
        }
      }
  }
  while (!done);

  if (accept){
    double sx = (xvmax - xvmin) / (xmax - xmin);
    double sy = (yvmax - yvmin) / (ymax - ymin);
    double vx0 = xvmin + (x0 - xmin)*sx;
    double vy0 = yvmin + (y0 - xmin)*sy;
    double vx1 = xvmin + (x1 - xmin)*sx;
    double vy1 = yvmin + (y1 - ymin)*sy;

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xvmin, yvmin);
    glVertex2f(xvmax, yvmin);
    glVertex2f(xvmax, yvmax);
    glVertex2f(xvmin, yvmax);
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2d(vx0, vy0);
    glVertex2d(vx1, vy1);
    glEnd();
  }
}

  outcode ComputeOutCode(double x, double y){
  outcode code = 0;
  if (y>ymax)//above the clip window
    code |= TOP;
  if (y<ymin)//below the clip window
    code |= BOTTOM;
  if (x>xmax)//to the right of the clip window
    code |= RIGHT;
  if (x<xmin) //to the left of the clip window
    code |= LEFT;
  return code;
}

void display(){
  double x0 = 120, y0 = 10, x1 = 40, y1 = 130;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0); // draw red color lines
  glBegin(GL_LINES);
  glVertex2d(x0, y0);
  glVertex2d(x1, y1);
  glVertex2d(60, 20);
  glVertex2d(80, 120);
  glEnd();
  glColor3f(0.0, 0.0, 1.0); // draw a blue colored window
  glBegin(GL_LINE_LOOP);
  glVertex2f(xmin, ymin);
  glVertex2f(xmax, ymin);
  glVertex2f(xmax, ymax);
  glVertex2f(xmin, ymax);
  glEnd();
  CohenSutherlandLineClipAnddraw(x0, y0, x1, y1);
  CohenSutherlandLineClipAnddraw(60, 20, 80, 120);
  glFlush();
}

void myinit(){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("cohen Sutherland line clipping algorithm");
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
  return 0;
}

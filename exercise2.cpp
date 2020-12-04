#include <glut.h>
#include <stdio.h>

GLfloat ax= 100.0 , ay = 100.0 , bx = 100 , by = 400.0 , cx = 400 , cy = 400
,dx = 400 , dy = 100 , ax1 , ay1, bx1, by1, cx1, cy1, dx1, dy1 ,a, b, c, d, n;

GLint m = 10, i;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    n = 0 ;
    for (i=1 ; i<=m ; ++i)
    {
        a = b = c = d = n/10;
        ax1 = ax + a* (bx - ax);
        ay1 = ay + a* (by - ay);

        bx1 = bx + b* (cx-bx);
        by1 = by + b* (cy - by);

        cx1 = cx + c* (dx - cx);
        cy1 = cy + c* (dy - cy);

        dx1 = dx + d* (ax - dx);
        dy1 = dy + d*(ay - dy);


        printf(" ax1 , ay1 : %f     ,      %f \n", ax1, ay1);
        printf(" bx1, by1 : %f, %f \n", bx1, by1);
        printf(" cx1 , cy1 : %f, %f \n", cx1, cy1);
        printf(" dx1 , dy1 : %f, %f \n", dx1, dy1);
        printf("**\n");

        glBegin (GL_LINE_LOOP);
            glVertex2f( ax1 , ay1);
            glVertex2f ( bx1, by1);
            glVertex2f(cx1, cy1);
            glVertex2f(dx1,dy1);
        glEnd();

        n = n + 1;
    }
    glFlush();
}

void init()
{
    glClearColor(0,0,0,0);
    glColor3f(0,1,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode (GL_MODELVIEW);

}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Sierpinski Gasket");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}
/* 
This code has been taken from rosettacode.org with a few modifications (on lines 77 through 191)
c program:
--------------------------------
1. draws Mandelbrot set for Fc(z)=z*z +c
using Mandelbrot algorithm ( boolean escape time )
-------------------------------         
2. technique of creating ppm file is  based on the code of Claudio Rocchini
http://en.wikipedia.org/wiki/Image:Color_complex_plot.jpg
create 24 bit color graphic file ,  portable pixmap file = PPM 
see http://en.wikipedia.org/wiki/Portable_pixmap
to see the file use external application ( graphic viewer)
*/

#include <stdio.h>
#include <math.h>

int main() {
    /* screen ( integer) coordinate */
    int iX, iY;
    const int iXmax = 800; 
    const int iYmax = 800;
    /* world ( double) coordinate = parameter plane*/
    double Cx, Cy;
    const double CxMin = -2.5;
    const double CxMax = 1.5;
    const double CyMin = -2.0;
    const double CyMax = 2.0;
    /* */
    double PixelWidth = (CxMax - CxMin)/iXmax;
    double PixelHeight = (CyMax - CyMin)/iYmax;
    /* color component ( R or G or B) is coded from 0 to 255 */
    /* it is 24 bit color RGB file */
    const int MaxColorComponentValue = 255; 
    FILE * fp;
    char *filename = "Mandelbrot.ppm";
    char *comment = "# ";/* comment should start with # */
    static unsigned char color[3];
    /* Z=Zx+Zy*i  ;   Z0 = 0 */
    double Zx, Zy;
    double Zx2, Zy2; /* Zx2=Zx*Zx;  Zy2=Zy*Zy  */
    /*  */
    int Iteration;
    const int IterationMax = 200;
    /* bail-out value , radius of circle ;  */
    const double EscapeRadius = 2;
    double ER2 = EscapeRadius*EscapeRadius;
    /*create new file,give it a name and open it in binary mode  */
    fp = fopen(filename,"wb"); /* b -  binary mode */
    /*write ASCII header to the file*/
    fprintf(fp, "P6\n %s\n %d\n %d\n %d\n", comment, iXmax, iYmax, MaxColorComponentValue);
    /* compute and write image data bytes to the file*/
    for(iY = 0; iY < iYmax; iY++) {
        Cy=CyMin + iY*PixelHeight;
        if (fabs(Cy)< PixelHeight/2) Cy=0.0; /* Main antenna */
        for(iX=0;iX<iXmax;iX++) {         
            Cx = CxMin + iX*PixelWidth;
            /* initial value of orbit = critical point Z= 0 */
            Zx = 0.0;
            Zy = 0.0;
            Zx2 = Zx*Zx;
            Zy2 = Zy*Zy;
            /* */
            for (Iteration = 0; Iteration < IterationMax && ((Zx2 + Zy2) < ER2); Iteration++) {
                Zy = 2*Zx*Zy + Cy;
                Zx = Zx2 - Zy2 +Cx;
                Zx2 = Zx*Zx;
                Zy2 = Zy*Zy;
            };
            /* compute  pixel color (24 bit = 3 bytes) */
            if (Iteration==IterationMax) { /*  interior of Mandelbrot set = black */
                color[0] = 0;
                color[1] = 0;
                color[2] = 0;                           
            }
            else { /* exterior of Mandelbrot set */
                if (Iteration < IterationMax/50) {
                    color[0] = 30; /* Red*/
                    color[1] = 0;  /* Green */ 
                    color[2] = 0;/* Blue */
                }
                if (Iteration < IterationMax/40) {
                    color[0] = 40; /* Red*/
                    color[1] = 0;  /* Green */ 
                    color[2] = 0;/* Blue */
                }
                else if (Iteration < IterationMax/30) {
                    color[0] = 50; /* Red*/
                    color[1] = 10;  /* Green */ 
                    color[2] = 0;/* Blue */
                }
                else if (Iteration < IterationMax/20) {
                    color[0] = 60; /* Red*/
                    color[1] = 20;  /* Green */ 
                    color[2] = 0;/* Blue */
                }
                else if (Iteration < 2*IterationMax/20) {
                    color[0] = 102; /* Red*/
                    color[1] = 51;  /* Green */ 
                    color[2] = 0;/* Blue */
                }
                else if (Iteration < 3*IterationMax/20) {
                    color[0] = 102; /* Red*/
                    color[1] = 0;  /* Green */ 
                    color[2] = 0;/* Blue */
                }
                else if (Iteration < 4*IterationMax/20) {
                    color[0] = 153; /* Red*/
                    color[1] = 0;  /* Green */ 
                    color[2] = 0;/* Blue */
                }
                else if (Iteration < 5*IterationMax/20) {
                    color[0] = 204; /* Red*/
                    color[1] = 102;  /* Green */ 
                    color[2] = 0;/* Blue */
                }
                else if (Iteration < 6*IterationMax/20) {
                    color[0] = 204; /* Red*/
                    color[1] = 0;  /* Green */ 
                    color[2] = 0;/* Blue */
                }
                else if (Iteration < 7*IterationMax/20) {
                    color[0] = 204; /* Red*/
                    color[1] = 102;  /* Green */ 
                    color[2] = 51;/* Blue */
                }
                else if (Iteration < 8*IterationMax/20) {
                    color[0] = 255; /* Red*/
                    color[1] = 0;  /* Green */ 
                    color[2] = 0;/* Blue */
                }
                else if (Iteration < 9*IterationMax/20) {
                    color[0] = 255; /* Red*/
                    color[1] = 128;  /* Green */ 
                    color[2] = 0;/* Blue */
                }
                else if (Iteration < 10*IterationMax/20) {
                    color[0] = 255; /* Red*/
                    color[1] = 51;  /* Green */ 
                    color[2] = 51;/* Blue */
                }
                else if (Iteration < 11*IterationMax/20) {
                    color[0] = 255; /* Red*/
                    color[1] = 153;  /* Green */ 
                    color[2] = 51;/* Blue */
                }
                else if (Iteration < 12*IterationMax/20) {
                    color[0] = 255; /* Red*/
                    color[1] = 178;  /* Green */ 
                    color[2] = 102;/* Blue */
                }
                else if (Iteration < 13*IterationMax/20) {
                    color[0] = 255; /* Red*/
                    color[1] = 255;  /* Green */ 
                    color[2] = 102;/* Blue */
                }
                else if (Iteration < 14*IterationMax/20) {
                    color[0] = 255; /* Red*/
                    color[1] = 204;  /* Green */ 
                    color[2] = 153;/* Blue */
                }
                else if (Iteration < 15*IterationMax/20) {
                    color[0] = 255; /* Red*/
                    color[1] = 255;  /* Green */ 
                    color[2] = 153;/* Blue */
                }
                else if (Iteration < 16*IterationMax/20) {
                    color[0] = 255; /* Red*/
                    color[1] = 255;  /* Green */ 
                    color[2] = 204;/* Blue */
                }
                else if (Iteration < 17*IterationMax/20) {
                    color[0] = 255; /* Red*/
                    color[1] = 255;  /* Green */ 
                    color[2] = 255;/* Blue */
                }
                else if (Iteration < 18*IterationMax/20) {
                    color[0] = 255; /* Red*/
                    color[1] = 255;  /* Green */ 
                    color[2] = 255;/* Blue */
                }
                else if (Iteration < 19*IterationMax/20) {
                    color[0] = 255; /* Red*/
                    color[1] = 255;  /* Green */ 
                    color[2] = 255;/* Blue */
                }
                else {
                    color[0] = 255; /* Red*/
                    color[1] = 255;  /* Green */ 
                    color[2] = 255;/* Blue */
                }
                // color[0] = 255; /* Red*/
                // color[1] = 255;  /* Green */ 
                // color[2] = 255;/* Blue */
            };
            /*write color to the file*/
            fwrite(color,1,3,fp);
        }
    }
    fclose(fp);
    return 0;
}
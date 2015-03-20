#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>

double rotary=0;
double rotarx=0;
double rotarz=0;
double zoom=1;
void init(void)
{
 /* selecciona el color de borrado */
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glShadeModel (GL_FLAT);
}

void observar(unsigned char key, int x, int y)
{
        switch (key) {
            case 'X': rotarx += 5;// ROTAMOS 5 GRADOS AL EJE Y POSITIVO, CON LA FECLA DERECHA// AL TECLEAR X MAYUSCULA NOS PODREMOS MOVER EN EL EJE POSITIVO X
                    break;
            case 'x': rotarx += 5;// ROTAMOS 5 GRADOS AL EJE Y POSITIVO, CON LA FECLA DERECHA -= 0.1;// AL TECLEAR X MINUSCULA NOS PODREMOS MOVER EN EL EJE NEGATIVO X
                    break;
            case 'Y': rotary += 5;// ROTAMOS 5 GRADOS AL EJE Y POSITIVO, CON LA FECLA DERECHA+= 0.1;// AL TECLEAR Y MAYUSCULA NOS PODREMOS MOVER EN EL EJE POSITIVO Y
                    break;
            case 'y': rotary += 5;// ROTAMOS 5 GRADOS AL EJE Y POSITIVO, CON LA FECLA DERECHA -= 0.1;// AL TECLEAR y MINUSCULA NOS PODREMOS MOVER EN EL EJE NEGATIVO y
                    break;
            case 'Z': rotarz += 5;// ROTAMOS 5 GRADOS AL EJE Y POSITIVO, CON LA FECLA DERECHA += 0.1;// AL TECLEAR Z MAYUSCULA NOS PODREMOS MOVER EN EL EJE POSITIVO Z
                    break;
            case 'z': rotarz += 5;// ROTAMOS 5 GRADOS AL EJE Y POSITIVO, CON LA FECLA DERECHA -= 0.1;// AL TECLEAR Z MINUSCULA NOS PODREMOS MOVER EN EL EJE NEGATIVO z
                    break;

            case 43: zoom+=0.1;
             break;
             case 45: zoom-=0.1;
             break;
    }
    glutPostRedisplay();//ACTUALIZANDO VENTANA
}
void display(void)
{
 /* borra la pantalla */
 glClear (GL_COLOR_BUFFER_BIT);
 /* seleccionamos la matriz modelo/vista */
 glMatrixMode(GL_MODELVIEW);
 /* color */
 glColor3f(1.0, 1.0, 1.0);
glLoadIdentity();
glTranslatef(0.0, 0.0, 0.0);
glRotatef( rotarx, 1.0, 0.0, 0.0 );// NOS SERVORA PARA ROTAR EN EJE X
  glRotatef( rotary, 0.0, 1.0, 0.0 ); // NOS SERVIRA PARA ROTAR EN EJE Y
glRotatef( rotarz, 0.0, 0.0, 1.0 ); // NOS SERVIRA PARA ROTAR EN EJE Z

glScalef( zoom, zoom,zoom );// DONDE USAREMOS PARAPODER CAMBIAR DE TAMANO SOBRE EL EJE Y

 /* transformación modelo/vista */
 gluLookAt(0.0,0.0,0.2, //punto de vista en el eje X,Y,Z
 0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
 0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
 /* Dibujamos una tetera */
 glutWireTeapot(0.5);
 /* Vacia el buffer de dibujo */
 glFlush ();
}
/*void reshape(int w, int h)
{
 /* definemos el marco */
 /*glViewport(0, 0, w, h);
 /* cambiamos a la matriz de proyección */
 /*glMatrixMode(GL_PROJECTION);
 /* definimos una proyección perspectiva con
 un fovy de 60 grados y el near a 1.0 y el
 far a 20.0 */
 /*glLoadIdentity();
 gluPerspective(60.0, GLfloat(w) / GLfloat(h), 1.0, 20.0);
}*/
int main(int argc, char** argv)
{
// Inicializa la librería auxiliar GLUT
 glutInit(&argc, argv);
// Inicializa el modo de visualización
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// Indica el tamaño de la ventana (ancho,alto)
 glutInitWindowSize(500, 500);
// Indica la posición inicial (xmin,ymin)
 glutInitWindowPosition(100, 100);// Abre la ventana con el título indicado
 glutCreateWindow("Dibujando una tetera 3d");
// Inicializar valores
 init();
// Indica cual es la función de dibujo
 glutDisplayFunc(display);
// Indica cual es la función para el cambio de tamaño de la ventana
 //glutReshapeFunc(reshape);
// Comienza el bucle de dibujo y proceso de eventos.
 glutKeyboardFunc(observar);
 glutMainLoop();
}

#include <stdio.h>
#include <GL/freeglut.h>

float tx = 0;
float ty = 0;

int init(void);
void display(void);
int main(int argc, char** argv);
void tecladoSetas(int ky, int x, int y);

int main(int argc, char** argv) {
    glutInit(&argc,argv);                                     //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);               //configura o modo de display
    glutInitWindowPosition(200,0);
    glutInitWindowSize(500,500);                              //configura a largura e altura da janela de exibição
    glutCreateWindow("Escala com Ponto Fixo");           //cria a janela de exibição

    init();                          //executa função de inicialização
    glutDisplayFunc(display);        //estabelece a função "display" como a função callback de exibição.
    glutMainLoop();                  //mostre tudo e espere
    return 0;
}

int init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);     //define a cor de fundo

    glMatrixMode(GL_PROJECTION);          //carrega a matriz de projeção
    gluOrtho2D(0,100,0,100);      //define projeção ortogonal 2D que mapeia  objetos da coordenada do mundo para coordenadas da tela
}


void desenhaQuadrado(void){
     glBegin(GL_POLYGON);                    //desenha uma casa
         glVertex2f(0,0);
         glVertex2f(0,10);
         glVertex2f(10,10);
         glVertex2f(10,0);
    glEnd();
}

void tecladoSetas(int key, int x, int y){
    if (key == GLUT_KEY_RIGHT){
        tx = tx+1;
        // glMatrixMode(GL_PROJECTION);
        // glLoadIdentity();
        glTranslatef(tx, ty, 0.0);
    }
    else if(key == GLUT_KEY_LEFT){
        tx = tx-1;
        // glMatrixMode(GL_PROJECTION);
        // glLoadIdentity();
        glTranslatef(tx, ty, 0.0);
    }
    else if (key == GLUT_KEY_UP){
        ty = ty+1;
        // glMatrixMode(GL_PROJECTION);
        // glLoadIdentity();    
        glTranslatef(tx, ty, 0.0);
    }
    else if (key == GLUT_KEY_DOWN){
        ty = ty-1;
        // glMatrixMode(GL_PROJECTION);
        // glLoadIdentity();
        glTranslatef(tx, ty, 0.0);
    }
    glutPostRedisplay();
}


void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);              // Desenha objetos com a cor vermelha
    desenhaQuadrado();
    glMatrixMode(GL_MODELVIEW);           //carrega a matriz de modelo
    glLoadIdentity();                     // carrega a matriz identidade

    glutSpecialFunc(tecladoSetas);

    glFlush();                            //desenha os comandos não executados

}
#include <GL/freeglut_std.h>
#include <zeno/zeno.h>
#include <zeno/types/FunctionObject.h>
#include <zeno/types/NumericObject.h>
#include <zeno/utils/zlog.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <zeno/types/DictObject.h>
#include <zeno/PrimitiveObject.h>
static float lastx = 0, lasty = 0;
static float fx=0,fy=0,ax=0,ay=0;
static bool clicked = false;

// mouse controls
int mouseOldX, mouseOldY;
int mouseButtons = 0;

inline static int interval;
inline static int nx, ny;


float camera_trans[] = {0, 0, -3};
float camera_rot[]   = {0, 0, 0};
float camera_trans_lag[] = {0, 0, -3};
float camera_rot_lag[] = {0, 0, 0};

float rotateX = 20.0f, rotateY = 0.0f;
float translateX = 0.0f, translateY = 0.0f, translateZ = -10.0f;
static std::shared_ptr<zeno::Scene> scene;

static void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double) w / (double) h, 0.1, 1000.0);

    nx = w;
    ny = h;
}

static void click(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        mouseButtons |= 1<<button;
    }
    else if (state == GLUT_UP)
    {
        mouseButtons = 0;
        fx = 0;
        fy = 0;
    }

    mouseOldX = x;
    mouseOldY = y;
    glutPostRedisplay();
}

static void motion(int x, int y)
{
    

    float dx, dy;
    dx = (float)(x - mouseOldX);
    dy = (float)(y - mouseOldY);

    if (mouseButtons == 1)
    {
        rotateX += dy * 0.2f;
        rotateY += dx * 0.2f;
    }
    else if (mouseButtons == 2)
    {
        translateX += dx * 0.01f;
        translateY -= dy * 0.01f;
    }
    else if (mouseButtons == 4)
    {
        fx = dx;
        fy = -dx;
    }

    mouseOldX = x;
    mouseOldY = y;

    glutPostRedisplay();
}
static void displayFunc() {
    glViewport(0, 0, nx, ny);
    glClearColor(0.23f, 0.23f, 0.23f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(translateX, translateY, translateZ);
    glRotatef(rotateX, 1.0, 0.0, 0.0);
    glRotatef(rotateY, 0.0, 1.0, 0.0);
    zeno::vec3f vec(fx, fy, 0);
    auto obj = std::make_shared<zeno::NumericObject>(vec);
    scene->getGraph().setGraphInput("mouse", std::move(obj));
    scene->getGraph().applyGraph();
    auto obj2 = scene->getGraph().getGraphOutput<zeno::PrimitiveObject>("oParticles");
    printf("%d\n", obj2->size());
    //glutWireTeapot(1.0);


    glutSwapBuffers();
    glutPostRedisplay();
}

static void timerFunc(int interval) {
    glutPostRedisplay();
    glutTimerFunc(interval, timerFunc, interval);
}

static void keyboardFunc(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
}

int main(int argc, char* argv[])
{
    scene = zeno::createScene();
    scene->loadScene(
    #include "my_zeno_scene.h"
    );
    scene->switchGraph("main");

    nx = 512;
    ny = 512;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(nx, ny);
    glutCreateWindow("GLUT Window");
    glutDisplayFunc(displayFunc);
    glutKeyboardFunc(keyboardFunc);
    glutMouseFunc(click);
    glutReshapeFunc(reshape);
    glutMotionFunc(motion);
    glutMainLoop();
}

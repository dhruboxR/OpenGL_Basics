#include <GL/glut.h>
#include <vector>
using namespace std;

struct Point {
    float x, y; // coordinates (x,y)
    float r, g, b;
};

vector<Point> shape = {

    // LEFT SLOPE -- Climbing from Bottom-left to the top Peak
    {-0.6f, -0.5f,   1.0f, 0.0f, 0.0f},     // Bottom left corner RED
    {-0.4f, -0.13f,  1.0f, 0.5f, 0.0f},     // Moving up-right (Orange)
    {-0.2f, 0.23f,   1.0f, 1.0f, 0.0f},     // Moving up-right (Yellow)'
    {0.0f, 0.6f,     0.0f, 1.0f, 0.0f},     // Top Peak (Green)

    // RIGHT SLOPE -- Descending down from top peak to bottom right
    {0.2f, 0.23f,    0.0f, 1.0f, 1.0f},     // Moving Down-right (Cyan)
    {0.4f, -0.13f,   0.0f, 0.5f, 1.0f},     // Moving Down-right (Light Blue)
    {0.6f, -0.5f,    0.0f, 0.0f, 1.0f},      // Bottom-right Corner (Solid Blue)

    // BOTTOM-EDGE -- Closing the loop leftward
    {0.2f, -0.5f,   0.5f, 0.0f, 1.0f},      // Moving left (Purple)
    {-0.2f, -0.5f,  1.0f, 0.0f, 1.0f}       // Moving left (Magenta)

};

// Handles all the drawing logic
void display() {
    // Clear the screen color buffer
    glClear(GL_COLOR_BUFFER_BIT);
    // -----------------------------------------------------------------------------------

    glPointSize(10.0f);
    glEnable(GL_POINT_SMOOTH);

    glBegin(GL_POINTS);
        for(const auto& p : shape) {
            glColor3f(p.r, p.g, p.b);
            glVertex2f(p.x, p.y);
        }
    glEnd();
    //------------------------------------------------------------------------------------
    // Force execution of OpenGL commands in buffer
    glFlush();
}

// Handles window resizing and maintains proper aspect ratio
void reshape(int width, int height) {
    // Set the viewport to cover the new window size
    glViewport(0, 0, width, height);

    // Set up the coordinate system (Projection matrix)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set a 2D orthographic viewing region (Left, Right, Bottom, Top)
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    // Switch back to modelview matrix for object transformations
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    // Initialize the GLUT library
    glutInit(&argc, argv);

    // Set the display mode (Single buffer and RGB color mode)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Define WINDOW SIZE
    int windowWidth = 1000;
    int windowHeight = 850;
    glutInitWindowSize(windowWidth, windowHeight);

    // Calculate the center position of the screen dynamically & set the position
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    int positionX = (screenWidth - windowWidth) / 2;
    int positionY = (screenHeight - windowHeight) / 2;
    glutInitWindowPosition(positionX, positionY);

    // Create the window with a specific title
    glutCreateWindow("Centered GLUT Window");

    // Set the background clearing color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Register the display callback function
    glutDisplayFunc(display);

    // Register the reshape callback function
    glutReshapeFunc(reshape);

    // Enter the infinite GLUT event processing loop
    glutMainLoop();

    return 0;
}
/*
             (0.0, 0.6) [Green]
                    /\
                   /  \
     (-0.2, 0.23) .    . (0.2, 0.23)
                 /      \
  (-0.4, -0.13) .        . (0.4, -0.13)
               /          \
              /____________\
(-0.6, -0.5) .   .     .    . (0.6, -0.5) [Blue]
    [Red]     (-0.2, -0.5) (0.2, -0.5)
*/

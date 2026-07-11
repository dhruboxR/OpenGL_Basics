#include <GL/glut.h>

// Handles all the drawing logic
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        // vertex 1 : bottom-left (red)
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);

        // vertex 2 : top Peak (green)
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.0f, 0.5f);

        // vertex 3 : bottom-right (blue)
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.5f, -0.5f);
    glEnd();

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

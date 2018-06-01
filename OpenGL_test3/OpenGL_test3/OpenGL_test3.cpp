// OpenGL_test3.cpp : 定义控制台应用程序的入口点。
//
/*
#include "stdafx.h"
#define GLUT_DISABLE_ATEXIT_HACK
#include "GL/glut.h"
int main(int argc, char **argv)
{
	glutInit(&argc, argv); // Initialize GLUT function callings
}
// Lesson.cpp : 定义控制台应用程序的入口点。
//
*/
/*
#include "stdafx.h"
#define GLUT_DISABLE_ATEXIT_HACK
#include "GL/glut.h"
int main(int argc, char **argv)
{
glutInit(&argc, argv); // Initialize GLUT function callings
}

*/
#include "stdafx.h"
#include <windows.h> // Header File For Windows
#include <stdio.h> // Header File For Standard Input/Output
#include <gl/gl.h> // Header File For The OpenGL32 Library
#include <gl/glu.h> // Header File For The GLu32 Library
#include "gl/glaux.h" // Header File For The Glaux Library
#define GLUT_DISABLE_ATEXIT_HACK
#include "GL/glut.h"
#define MAX_STARTS 50 // Number Of Stars To Draw
#define MAX_PARTICLES 1000 // Number Of Particles To Create
typedef struct // Create A Structure For Star
{
	int r, g, b; // Stars Color
	GLfloat dist, // Stars Distance From Center
		angle; // Stars Current Angle
}
stars;
stars star[MAX_STARTS]; // Need To Keep Track Of 'MAX_STARTS' Stars
typedef struct // Create A Structure For Particle
{
	bool active; // Active (Yes/No)
	float life; // Particle Life
	float fade; // Fade Speed
	float r; // Red Value
	float g; // Green Value
	float b; // Blue Value
	float x; // X Position
	float y; // Y Position
	float z; // Z Position
	float xi; // X Direction
	float yi; // Y Direction
	float zi; // Z Direction
	float xg; // X Gravity
	float yg; // Y Gravity
	float zg; // Z Gravity
}
particles; // Particles Structure
particles particle[MAX_PARTICLES]; // Particle Array (Room For Particle Info)
static GLfloat colors[12][3] = // Rainbow Of Colors
{
	{ 1.0f,0.5f,0.5f },{ 1.0f,0.75f,0.5f },{ 1.0f,1.0f,0.5f },{ 0.75f,1.0f,0.5f },
	{ 0.5f,1.0f,0.5f },{ 0.5f,1.0f,0.75f },{ 0.5f,1.0f,1.0f },{ 0.5f,0.75f,1.0f },
	{ 0.5f,0.5f,1.0f },{ 0.75f,0.5f,1.0f },{ 1.0f,0.5f,1.0f },{ 1.0f,0.5f,0.75f }
};
float slowdown = 2.0f; // Slow Down Particles
GLuint col; // Current Color Selection
GLfloat star_spin; // Spin Stars
GLuint texture[2]; // Storage For One textures
int InitGL(int width, int height);
void DrawGLScene(void);
void myReshape(int w, int h);
void myKeyboard(int key, int x, int y);
void myMovedMouse(int x, int y);
AUX_RGBImageRec *LoadBMP(char *Filename);
int LoadGLTextures();
int main(int argc, char **argv) {
	glutInit(&argc, argv); // Initialize GLUT function callings
	glutInitWindowSize(800, 600); // Set window size (width, height) in number of pixels
								  // Set window position, from the left and top of the screen,
	glutInitWindowPosition(200, 100); // in numbers of pixels
									  // Specify a window creation event
	glutCreateWindow("3D Graph");
	// Specify the drawing function that is called when the window
	glutDisplayFunc(DrawGLScene); // is created or re-drew
	glutReshapeFunc(myReshape);
	glutSpecialFunc(myKeyboard);
	glutMotionFunc(myMovedMouse);
	InitGL(800, 600); // Invoke this function for initialization
	glutMainLoop(); // Enter the event processing loop
	return 0; // Indicate normal termination
}
int InitGL(int width, int height) {
	myReshape(width, height);
	if (!LoadGLTextures()) // Jump To Texture Loading Routine
	{
		return FALSE; // If Texture Didn't Load Return FALSE
	}
	glEnable(GL_TEXTURE_2D); // Enable Texture Mapping
	glShadeModel(GL_SMOOTH); // Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // Black Background
	glClearDepth(1.0f); // Depth Buffer Setup
	glDisable(GL_DEPTH_TEST); // Disable Depth Testing
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST); // Really Nice Point Smoothing
	glBlendFunc(GL_SRC_ALPHA, GL_ONE); // Set The Blending Function For Translucency
	glEnable(GL_BLEND);
	int loop;
	for (loop = 0; loop<MAX_STARTS; loop++)
	{
		star[loop].angle = 0.0f;
		star[loop].dist = (float(loop) / MAX_STARTS)*5.0f;
		star[loop].r = rand() % 256;
		star[loop].g = rand() % 256;
		star[loop].b = rand() % 256;
	}
	for (loop = 0; loop<MAX_PARTICLES; loop++) // Initials All The Textures
	{
		particle[loop].active = true; // Make All The Particles Active
		particle[loop].life = 1.0f; // Give All The Particles Full Life
		particle[loop].fade = float(rand() % 100) / 1000.0f + 0.003f; // Random Fade Speed
		particle[loop].r = colors[loop*(12 / MAX_PARTICLES)][0]; // Select Red Rainbow Color
		particle[loop].g = colors[loop*(12 / MAX_PARTICLES)][1]; // Select Red Rainbow Color
		particle[loop].b = colors[loop*(12 / MAX_PARTICLES)][2]; // Select Red Rainbow Color

		particle[loop].xi = float((rand() % 50) - 26.0f)*10.0f; //Random Speed On X Axis
		particle[loop].yi = float((rand() % 50) - 25.0f)*10.0f; // Random Speed On Y Axis
		particle[loop].zi = float((rand() % 50) - 25.0f)*10.0f; // Random Speed On Z Axis
		particle[loop].xg = 0.0f; // Set Horizontal Pull To Zero
		particle[loop].yg = -0.8f; // Set Vertical Pull Downward
		particle[loop].zg = 0.0f; // Set Pull On Z Axis To Zero
	}
	return TRUE;
}
void myReshape(int width, int height) {
	if (height == 0) // Prevent A Divide By Zero By
	{
		height = 1; // Making Height Equal One
	}
	glViewport(0, 0, width, height); // Reset The Current Viewport
	glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
	glLoadIdentity(); // Reset The Projection Matrix
					  // Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
	glLoadIdentity(); // Reset The Modelview Matrix
}
GLvoid DrawGLScene(GLvoid) // Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
	glBindTexture(GL_TEXTURE_2D, texture[0]); // Select Our Texture
	int loop;
	for (loop = 0; loop<MAX_STARTS; loop++) // Loop Through All The Stars
	{
		GLfloat tilt = 90.0f; // Tilt The View
		glLoadIdentity(); // Reset The View Before We Draw Each Star
		glTranslatef(0.0f, 0.0f, -15.0f); // Zoom Into The Screen (Using The Value In 'zoom')
		glRotatef(tilt, 1.0f, 0.0f, 0.0f); // Tilt The View (Using The Value In 'tilt')
		glRotatef(star[loop].angle, 0.0f, 1.0f, 0.0f); // Rotate To The Current Stars Angle
		glTranslatef(star[loop].dist, 0.0f, 0.0f); // Move Forward On	The X Plane
		glRotatef(-star[loop].angle, 0.0f, 1.0f, 0.0f); // Cancel The Current Stars Angle
		glRotatef(-tilt, 1.0f, 0.0f, 0.0f); // Cancel The Screen Tilt
		glRotatef(star_spin, 0.0f, 0.0f, 1.0f);
		glColor4ub(star[loop].r, star[loop].g, star[loop].b, 255);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);

		glEnd();
		star_spin += 0.01f;
		star[loop].angle += float(loop) / MAX_STARTS;
		star[loop].dist -= 0.01f;
		if (star[loop].dist<0.0f)
		{
			star[loop].dist += 5.0f;
			star[loop].r = rand() % 256;
			star[loop].g = rand() % 256;
			star[loop].b = rand() % 256;
		}
	}
	glBindTexture(GL_TEXTURE_2D, texture[1]); // Select Our Texture
	for (loop = 0; loop<MAX_PARTICLES; loop++) // Loop Through All The Particles
	{
		if (particle[loop].active) // If The Particle Is Active
		{
			glLoadIdentity();// Reset The View Before We Draw Each Star
			glTranslatef(20.0f, 0.0f, -60.0f); // Zoom Into The Screen (Using The Value In 'zoom')
			float x = particle[loop].x; // Grab Our Particle X Position
			float y = particle[loop].y; // Grab Our Particle Y Position
			float z = particle[loop].z; // Particle Z Pos + Zoom
										// Draw The Particle Using Our RGB Values, Fade The Particle Based On It's Life
			glColor4f(particle[loop].r, particle[loop].g, particle[loop].b, particle[loop].life);
			glBegin(GL_TRIANGLE_STRIP); // Build Quad From A Triangle Strip
			glTexCoord2d(1, 1); glVertex3f(x + 0.5f, y + 0.5f, z); // TopRight
			glTexCoord2d(0, 1); glVertex3f(x - 0.5f, y + 0.5f, z); // Top Left
			glTexCoord2d(1, 0); glVertex3f(x + 0.5f, y - 0.5f, z); // Bottom Right
			glTexCoord2d(0, 0); glVertex3f(x - 0.5f, y - 0.5f, z); // Bottom Left
			glEnd(); // Done Building Triangle Strip
			particle[loop].x += particle[loop].xi / (slowdown * 1000);// Move On The X Axis By X Speed
			particle[loop].y += particle[loop].yi / (slowdown * 1000);// Move On The Y Axis By Y Speed
			particle[loop].z += particle[loop].zi / (slowdown * 1000);// Move On The Z Axis By Z Speed
			particle[loop].xi += particle[loop].xg; // Take Pull On X Axis Into Account
			particle[loop].yi += particle[loop].yg; // Take Pull On Y Axis Into Account
			particle[loop].zi += particle[loop].zg; // Take Pull On Z Axis Into Account
			particle[loop].life -= particle[loop].fade; // Reduce Particles Life By 'Fade'
			if (particle[loop].life < 0.0f) // If Particle Is Burned Out
			{
				particle[loop].life = 1.0f; // Give It New Life
				particle[loop].fade = float(rand() % 100) / 1000.0f + 0.003f; // Random Fade Value
				particle[loop].x = 0.0f; // Center On X Axis
				particle[loop].y = 0.0f; // Center On Y Axis
				particle[loop].z = 0.0f; // Center On Z Axis
				particle[loop].xi = float((rand() % 60) - 32.0f); // X Axis Speed And Direction
				particle[loop].yi = float((rand() % 60) - 30.0f); // Y Axis Speed And Direction
				particle[loop].zi = float((rand() % 60) - 30.0f); // Z Axis Speed And Direction
				particle[loop].r = colors[col][0]; // Select Red From Color Table
				particle[loop].g = colors[col][1]; // Select Green From Color Table
				particle[loop].b = colors[col][2]; // Select Blue From Color Table
			}
		}
	}
	glFlush(); // Force to display the new drawings immediately
	glutSwapBuffers();
	glutPostRedisplay(); // Trigger an automatic redraw for animation
}
void myKeyboard(int key, //按键的ASCII码
	int x, //事件发生时鼠标的位置
	int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
	case GLUT_KEY_UP:
	case GLUT_KEY_RIGHT:
	case GLUT_KEY_DOWN:
		col++; // Change The Particle Color
		if (col>11) col = 0; // If Color Is To High Reset It
		break;
	}
}
void myMovedMouse(int x, int y)
{
}
AUX_RGBImageRec *LoadBMP(char *Filename) // Loads A Bitmap Image
{
	FILE *File = NULL; // File Handle
	if (!Filename) // Make Sure A Filename Was Given
	{
		return NULL; // If Not Return NULL
	}
	File = fopen(Filename, "r"); // Check To See If The File Exists
	if (File) // Does The File Exist?
	{
		fclose(File); // Close The Handle
		return auxDIBImageLoadA(Filename); // Load The Bitmap And Return A Pointer
	}
	return NULL; // If Load Failed Return NULL
}
int LoadGLTextures() // Load Bitmaps And Convert To Textures
{
	int Status = FALSE; // Status Indicator
	AUX_RGBImageRec *TextureImage[2]; // Create Storage Space For The Texture
	memset(TextureImage, 0, sizeof(void *) * 2); // Set The Pointer To NULL
												 // Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
	if (TextureImage[0] = LoadBMP("picture/Star.bmp"))
	{
		Status = TRUE; // Set The Status To TRUE
		glGenTextures(1, &texture[0]); // Create One Texture
									   // Create Linear Filtered Texture
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX,
			TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
	}
	if (TextureImage[0]) // If Texture Exists
	{
		if (TextureImage[0]->data) // If Texture Image Exists
		{
			free(TextureImage[0]->data); // Free The Texture Image Memory
		}
		free(TextureImage[0]); // Free The Image Structure
	}
	Status = FALSE;
	if (TextureImage[1] = LoadBMP("picture/Particle.bmp")) // Load Particle Texture
	{
		Status = TRUE; // Set The Status To TRUE
		glGenTextures(1, &texture[1]); // Create One Texture
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[1]->sizeX, TextureImage[1]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[1]->data);
	}
	if (TextureImage[1]) // If Texture Exists
	{
		if (TextureImage[1]->data) // If Texture Image Exists
		{
			free(TextureImage[1]->data); // Free The Texture Image Memory
		}
		free(TextureImage[1]); // Free The Image Structure
	}
	return Status; // Return The Status
}


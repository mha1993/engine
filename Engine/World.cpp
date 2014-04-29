//
//  World.cpp
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "World.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

void renderScene(void) {
    
    vector<glm::vec3> *verts = new vector<glm::vec3>();
    verts->push_back(glm::vec3(   0,   0, 0.1 ));
    verts->push_back(glm::vec3(   1,   0, 0.1 ));
    verts->push_back(glm::vec3( 0.5,   1, 0.1 ));
    
    Object *object = new Object::Object();
    object->Object::addVertices(verts);
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	glBegin(GL_TRIANGLES);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.5,0.0,0.0);
    glVertex3f(0.0,0.5,0.0);
	glEnd();
    
    glutSwapBuffers();
}

void World::init(int argc, char ** argv) {
    vector<glm::vec3> *verts = new vector<glm::vec3>();
    verts->push_back(glm::vec3(   0,   0, 0.1 ));
    verts->push_back(glm::vec3(   1,   0, 0.1 ));
    verts->push_back(glm::vec3( 0.5,   1, 0.1 ));
    
    Object *object = new Object::Object();
    object->Object::addVertices(verts);
    
    
    // init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutCreateWindow("MHA Engine");
    
    // print out some info about the graphics drivers
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    
	// register callbacks
	glutDisplayFunc(renderScene);
    
	// enter GLUT event processing cycle
	glutMainLoop();
	
}
//
//  ScreenSimulation.cpp
//  实验七
//
//  Created by 吴芳谷 on 2017/5/16.
//  Copyright © 2017年 Zhy. All rights reserved.
//

#include "ScreenSimulation.hpp"
int angle=0;
void Draw(int *argc,char * argv[]){
    glutInit(argc,argv);
    
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("GTMD OPENGL");
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutMainLoop();
}
void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRasterPos2f(0.8,0.8);
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 'a');
    glTranslatef(0/500, 0, 0);
    glRotatef(angle, 0.3, .5, 0.2);
    
    glBegin(GL_LINES);
    glVertex3f(-1,0,0.0);
    glVertex3f(1,0.0,0.0);
    glVertex3f(0,-1,0.0);
    glVertex3f(0, 1, 0);
    glVertex3f(0, 0, -1);
    glVertex3f(0, 0, 1);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    angle++;
    glFlush();
    
}

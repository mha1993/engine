//
//  main.cpp
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include <iostream>

#include "WindowManager.h"
#include "LevelManager.h"
#include "TestLevel.h"

using namespace std;
using namespace glm;

int main(int argv, const char** argc) {

    
    WindowManager *wm = new WindowManager;
    wm->init();
    
    Level *levelManager = new LevelManager(wm);

    levelManager->setup();
    
    levelManager->run();
    
    wm->stop();
    
    delete levelManager;
    delete wm;
    
    
}




/*


int main(int argv, const char** argc) {
    
    WindowManager *wm = new WindowManager;
    wm->init();
    
    ///////TESTING RENEREING
    
    vector<vec3> v;
    
    v.push_back(vec3(0.0,0.0,0.0));
    v.push_back(vec3(0.0,1.0,0.0));
    v.push_back(vec3(1.0,0.0,0.0));
    
    vector<vec3> n;
    
    
    vec3 nrm = calcNormaltmp(v[0],v[1],v[2]);
    
    n.push_back(nrm);
    n.push_back(nrm);
    n.push_back(nrm);
    
    Mesh *m = new Mesh("default.vs","green.fsh", &v,&n,GL_TRIANGLES);

    mat4 uMM = glm::mat4();
    //mat4 uPM = glm::perspective(50.0f, (4.0f/3.0f), 0.01f, 100.0f);
    //uVM = glm::translate(glm::mat4(), vec3(0.0,0.0,-10.0));
    
    Physics2 ps;
    //int Physics2::addObject(int physicsShape, float size, vector<vec3> vert, vec3 pos, vec3 vel, bool movable, bool collidable){

    int id = ps.addObject(Physics2::SHAPE_CONVEX_POLY, 1.0f, v, vec3(0.0,0.0,0.0), vec3(0.0,0.0,0.0), false, true);
    
    vector<vec3> v2;
    
    v2.push_back(vec3(0.0,0.0,1.0));
    v2.push_back(vec3(0.0,1.0,1.0));
    v2.push_back(vec3(1.0,0.0,0.0));
    
    nrm = calcNormaltmp(v2[0],v2[1],v2[2]);
    
    n.clear();
    
    n.push_back(nrm);
    n.push_back(nrm);
    n.push_back(nrm);
    
    int id2 = ps.addObject(Physics2::SHAPE_CONVEX_POLY, 1.0f, v2, vec3(-1.0,0.0,-0.5f), vec3(0.4,0.0,0.0), true, true);
    
    Mesh *m2 = new Mesh("default.vs","green.fsh", &v2,&n,GL_TRIANGLES);
    
    ECamera* c = new FPCamera();
    
    ///////TESTING END
    
    int loopnr = 0;
    
    while (true) {
        loopnr++;
        wm->beforRender();
        
        
        mat4 dsa = c->matrix();
        
        
        vec3 p = ps.getPos(id);
        mat4 uM = glm::translate(uMM, p);
        
        vec3 p2 = ps.getPos(id2);
        mat4 uM2 = glm::translate(uMM, p2);
        
        m->setMatrices(&uM,&dsa);
        m->draw();
        
        
        m2->setMatrices(&uM2, &dsa);
        m2->draw();
        
        string somthing = wm->readString();
        
        c->update(.01);
        ps.tick(.01);
        
        wm->afterRender();
        if (wm->quitRequest()){
            break;
        }
    }
    
    wm->stop();
    
    return 0;
}
 */

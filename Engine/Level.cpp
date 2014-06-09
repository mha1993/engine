//
//  Level.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Level.h"

#include <chrono>
#include <thread>

#include <sys/time.h>

Level::Level(WindowManager *wm): windowManager(wm){}
void Level::setup(){}
void Level::teardown(){}
void Level::tick(float deltaTime){}
void Level::render(){}


long double timemillis(){
    
    timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000.0) + (time.tv_usec / 1000.0);
}


long double clamp(long double n,long double min, long double max){
    
    return std::max(min, std::min(n, max));
    
}


void Level::sleep(long millis){

    std::this_thread::sleep_for(std::chrono::milliseconds(millis));

}

void Level::run(){
    
    shouldBeRunning = true;
    
    long double lastTime = timemillis();
    
    while (shouldBeRunning) {
        
        long double newTime = timemillis();
        
        float timeDiff = newTime - lastTime;
        
        lastTime = newTime;
        
        
        windowManager->poll();
        
        tick(timeDiff/1000.0f);
        
        long maxSleepTime = 20;
        
        long sleeptime = clamp(maxSleepTime - timeDiff , 0, maxSleepTime);
        
        sleep(sleeptime);
        
    }
}
#ifndef __SPLASH_SCREEN_H__
#define __SPLASH_SCREEN_H__
#include "cocos2d.h"
#include "HelloWorldScene.h"


class SplashScreen : public cocos2d::CCLayer


{
public:
	virtual bool init(); 
	 static cocos2d::CCScene* scene();
	 void loadSplash();
	 CREATE_FUNC(SplashScreen);

};














#endif
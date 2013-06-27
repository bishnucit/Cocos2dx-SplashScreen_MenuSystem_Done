#ifndef __SCENE_1_H__
#define __SCENE_1_H__

#include "cocos2d.h"

#include "Box2D/Box2D.h"

#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

class Scene1 : public cocos2d::CCLayer
{
public:
	void DisplayScene(CCObject* pSender);
	void MainMenu(CCObject* pSender);
	  CREATE_FUNC(Scene1);
	    virtual bool init();  
	   static cocos2d::CCScene* scene();

	
};

#endif
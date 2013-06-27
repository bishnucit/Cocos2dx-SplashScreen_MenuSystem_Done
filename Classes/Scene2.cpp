#include "Scene2.h"
#include "HelloWorldScene.h"
using namespace cocos2d;


CCScene* Scene2::scene()
{
    CCScene * scene = NULL;
    do 
    {
	
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        Scene2 *layer = Scene2::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}


bool Scene2::init()
{
    bool bRet = false;
    do 
    {
 
        CC_BREAK_IF(! CCLayer::init());

  
         CCMenuItemImage *goBack = CCMenuItemImage::create(
            "MMNormal.png",
            "MMSelected.png",
            this,
            menu_selector(Scene2::MainMenu));
        CC_BREAK_IF(! goBack);
 
        // Place the menu item bottom-right conner.
      goBack->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().height/2,100));

	  CCMenu* pMenu = CCMenu::create(goBack,NULL);
	  pMenu->setPosition(CCPointZero);
	  CC_BREAK_IF(!pMenu);
	  this->addChild(pMenu,1);


        // 3. Add add a splash screen, show the cocos2d splash image.
		CCSize size = CCDirector::sharedDirector()->getWinSize();
        CCSprite* pSprite = CCSprite::create("HelloWorld.png");
        CC_BREAK_IF(! pSprite);

        // Place the sprite on the center of the screen
        pSprite->setPosition(ccp(size.width/2, size.height/2));

        // Add the sprite to HelloWorld layer as a child layer.
        this->addChild(pSprite, 0);

        bRet = true;
    } while (0);

    return bRet;
}

void Scene2::DisplayScene(CCObject* pSender)
{
	CCDirector::sharedDirector()->pushScene(Scene2::scene());
}

void Scene2::MainMenu(CCObject* pSender)
{
	CCDirector::sharedDirector()->pushScene(HelloWorld::scene());
}
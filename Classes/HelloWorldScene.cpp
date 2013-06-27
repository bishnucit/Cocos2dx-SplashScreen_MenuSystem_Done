#include "HelloWorldScene.h"
#include "Scene1.h"
#include "Scene2.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
	
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
   
        CC_BREAK_IF(! CCLayer::init());
 
        CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        // Place the menu item bottom-right conner.
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);
		CCSize size2 = CCDirector::sharedDirector()->getWinSize();
		CCMenuItemImage *pMenu1 = CCMenuItemImage::create("But1Normal.png","But1Selected.png",this,menu_selector(Scene1::DisplayScene));
        CC_BREAK_IF(! pMenu1);
		CCMenu* pMenu11 = CCMenu::create(pMenu1,NULL);
		pMenu11 ->setPosition(ccp(size2.height/2,200));
		CC_BREAK_IF(!pMenu11);
		this->addChild(pMenu11,1);
		  CCSize size1 = CCDirector::sharedDirector()->getWinSize();
		CCMenuItemImage *pMenu2= CCMenuItemImage::create("But2Normal.png","But2Selected.png",this,menu_selector(Scene2::DisplayScene));
        CC_BREAK_IF(! pMenu2);
		CCMenu* pMenu22 = CCMenu::create(pMenu2,NULL);
		pMenu22 ->setPosition(ccp(size1.height/2,100));
		CC_BREAK_IF(!pMenu22);
		this->addChild(pMenu22,1);

	 
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

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}


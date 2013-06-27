#include "HelloWorldScene.h"
 
#include "SplashScreen.h"

USING_NS_CC;



CCScene* SplashScreen::scene()
{
	 CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SplashScreen *layer = SplashScreen::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;


}


bool SplashScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	 CCSprite* pSprite = CCSprite::create("SS.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer

	//bishnu-> you can control the time of the screen by changing 0.5s in the below to any number u wish.
	//instead directly this->runAction(CCSequence....) you can break it also into two parts.
    this->addChild(pSprite, 0);
    this->runAction( CCSequence::create(
                                 CCDelayTime::create(0.5),
                                CCCallFunc::create(this, 
                                callfunc_selector(SplashScreen::loadSplash)),
                                 NULL));
    return true;
}

void SplashScreen::loadSplash()
 {
     CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
 }
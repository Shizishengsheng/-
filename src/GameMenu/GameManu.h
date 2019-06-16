#pragma once
#include "cocos2d.h"					
using namespace cocos2d;

class GameMenu : public Layer

{
public:    static Scene* createScene();

		   virtual bool init();

		   CREATE_FUNC(GameMenu);

		   void EnterHitBrick(Ref *pSender);

		   void EnterHelp(Ref *pSender);

};


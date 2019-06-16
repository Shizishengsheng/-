#include "GameMenu.h"
#include "HitBrick.h"
#include "Help.h"

Scene* GameMenu::createScene()
{
	auto scene = Scene::create();

	auto layer = GameMenu::create();

	scene->addChild(layer);			
	
	return scene;
}

bool GameMenu::init()
{
	if (!Layer::init())

	{
		return false;
	}

	Size VisibleSize = Director::getInstance()->getVisibleSize();	//获得屏幕大小

	auto label = Label::createWithSystemFont("Play", "fonts/arial.ttf", 50);
	auto menuitem = MenuItemLabel::create(label, CC_CALLBACK_1(GameMenu::EnterHitBrick, this));
	auto menu = Menu::create(menuitem, NULL);
	menu->setPosition(VisibleSize.width / 2, VisibleSize.height / 2 + 100);
	this->addChild(menu,1);



	auto label2 = Label::createWithSystemFont("Help", "fonts/arial.ttf", 50);
	auto menu2 = MenuItemLabel::create(label2, CC_CALLBACK_1(GameMenu::EnterHelp, this));
	auto menuHelp = Menu::create(menu2, NULL);
	menuHelp->setPosition(VisibleSize.width / 2, VisibleSize.height / 2 - 100);
	this->addChild(menuHelp,1);


	auto bgSprite = Sprite::create("bg.png");

	bgSprite->setPosition(VisibleSize / 2);

	bgSprite->setScale(VisibleSize.width / bgSprite->getContentSize().width, VisibleSize.height / bgSprite->getContentSize().height);

	this->addChild(bgSprite, 0);

	return true;

}

void GameMenu::EnterHitBrick(Ref *pSender)
{
	Director::getInstance()->pushScene(HitBrick::createScene());
}

void GameMenu::EnterHelp(Ref *pSender)
{
	Director::getInstance()->pushScene(Help::createScene());
}

#include "GameMenu.h"
#include "Help.h"

Scene* Help::createScene()
{
	auto scene = Scene::create();

	auto layer = Help::create();

	scene->addChild(layer);

	return scene;
}

bool Help::init()
{
	if (!Layer::init())

	{
		return false;
	}

	Size VisibleSize = Director::getInstance()->getVisibleSize();	//获得屏幕大小


	//返回主菜单
	auto label = Label::createWithSystemFont("Back To Menu", "fonts/arial.ttf", 30);
	auto menuitem = MenuItemLabel::create(label, CC_CALLBACK_1(Help::EnterGameMenu, this));
	auto menu = Menu::create(menuitem, NULL);
	menu->setPosition(VisibleSize.width / 2, VisibleSize.height / 2 + 200);
	this->addChild(menu,1);


	auto bgSprite = Sprite::create("bg.png");

	bgSprite->setPosition(VisibleSize / 2);

	bgSprite->setScale(VisibleSize.width / bgSprite->getContentSize().width, VisibleSize.height / bgSprite->getContentSize().height);

	this->addChild(bgSprite, 0);


	addHelp();

	return true;
	
}


void Help::EnterGameMenu(Ref *pSender)
{
	Director::getInstance()->pushScene(GameMenu::createScene());
}


void Help::addHelp()
{
	Size VisibleSize = Director::getInstance()->getVisibleSize();	//获得屏幕大小


	auto Help1 = Sprite::create("Help1.png");

	Help1->setPosition(VisibleSize.width / 2 -260, VisibleSize.height / 2 );

	this->addChild(Help1,1);


	auto Help2 = Sprite::create("Help2.png");

	Help2->setPosition(VisibleSize.width / 2 + 260, VisibleSize.height / 2 );

	this->addChild(Help2,1);


	auto Help3 = Sprite::create("Help3.png");

	Help3->setPosition(VisibleSize.width / 2 , VisibleSize.height / 2);

	this->addChild(Help3, 1);

}

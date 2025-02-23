/**
* @file SettingLayer.cpp
*/
#include "SettingLayer.h"
#include "ui/UIButton.h"

#define BOARD_IMAGE_WIDTH 700
#define BOARD_IMAGE_HEIGHT 500
#define STANDARD_LEFT 125
#define CLOSE_X 10000
#define CLOSE_Y 10000

class FightScene;

SettingLayer* SettingLayer::create()
{
	auto settingLayer = new(std::nothrow) SettingLayer();

	if (settingLayer && settingLayer->init())
	{
		
		settingLayer->autorelease();

		return settingLayer;
	}
	delete settingLayer;
	settingLayer = nullptr;
	return nullptr;

}

/**
 @brief  print file loading error
 @author Cocos
 */
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
}


bool SettingLayer::init()
{
	this->setPosition(cocos2d::Vec2(CLOSE_X, CLOSE_Y));
	
	//backgroundMusicID_ = cocos2d::AudioEngine::play2d("Audio/bgm_1Low.mp3", true, .5);
	//isBackgroundMusicPlaying_ = true;

	// 设置背景框
	pauseBoardImg_ = cocos2d::ui::Scale9Sprite::create("Setting/pause_board.png");
//	pauseBoardImg_->setOpacity(96);
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	if (pauseBoardImg_ == nullptr)
	{
		problemLoading("'pause_board.png'");
		return false;
	}
	else
	{
		pauseBoardImg_->setCapInsets(cocos2d::Rect(6, 6, 79, 61));
		pauseBoardImg_->setContentSize(cocos2d::Size(BOARD_IMAGE_WIDTH, BOARD_IMAGE_HEIGHT));
		//pauseBoardImg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		pauseBoardImg_->setPosition(cocos2d::Vec2(CLOSE_X,CLOSE_Y));
		this->addChild(pauseBoardImg_, 0);
	}

	//设置关闭按钮
	closeButton_ = cocos2d::ui::Button::create("Setting/close.png", "Setting/close_pressed.png");
	auto closeButtonSize = closeButton_->getContentSize();
	closeButton_->setPosition(cocos2d::Vec2((BOARD_IMAGE_WIDTH - closeButtonSize.width / 2), (BOARD_IMAGE_HEIGHT - closeButtonSize.height / 2)));
	pauseBoardImg_->addChild(closeButton_);

	musicButton_ = settingSmallButton(5, 100, "Setting/music.png", "Music");
	shortMusicButton_ = settingSmallButton(205, 100, "Setting/short_music.png", "Sound Effect");
	superBodyButton_ = settingSmallButton(405, 100, "Setting/superBody.png", "Super Armor");
	superAccuracyButton_ = settingSmallButton(5, 350, "Setting/superAccuracy.png", "Super Accuracy");
	superBulletButton_ = settingSmallButton(205, 350, "Setting/infiniteAmmo.png", "Infinite Ammo");
	superDamageButton_ = settingSmallButton(405, 350, "Setting/superDamage.png", "Super Damage");

	return true;
}

bool SettingLayer::open()
{
	cocos2d::Director::getInstance()->getOpenGLView()->setCursorVisible(true);
	//为了在Monster类内使用外部的东西，使用以下几句
	auto runningScene = cocos2d::Director::getInstance()->getRunningScene()->getChildByTag(FIGHT_SCENE_TAG);
	auto contenteSize = runningScene->getContentSize();
	auto playerOfNode = runningScene->getChildByTag(PLAYER_TAG);
	cocos2d::Vec2 playerPositionInScene = cocos2d::Vec2::ZERO;
	//如果场景已经被释放，找不到我方player位置，直接退出
	if (playerOfNode == nullptr)
	{
		return false;
	}
	//获得当前我方player位置
	auto playerOfPlayer = dynamic_cast<Player*>(playerOfNode);
	playerPositionInScene = playerOfPlayer->getPosition();
	pauseBoardImg_->setPosition(contenteSize.width / 2, contenteSize.height / 2);
	pauseBoardImg_->setCameraMask(2, true);

	closeButton_->addClickEventListener([=](Ref*) {
		this->close();
	});

	musicButton_->addClickEventListener([&](Ref*) {
		if (!isBackgroundMusicPlaying_)
		{
			cocos2d::AudioEngine::resume(backgroundMusicID_);
			isBackgroundMusicPlaying_ = true;
		}
		else
		{
			cocos2d::AudioEngine::pause(backgroundMusicID_);
			isBackgroundMusicPlaying_ = false;
		}
	});

	shortMusicButton_->addClickEventListener([=](Ref*) {
		if (Weapon::getShootMusicStatus()||FightScene::getShootMusicStatus())
		{

			Weapon::getShootMusicStatus() = false;
			FightScene::getShootMusicStatus() = false;
		}
		else
		{
			Weapon::getShootMusicStatus() = true;
			FightScene::getShootMusicStatus() = true;
		}
	});

	superBodyButton_->addClickEventListener([=](Ref*) {
		if (!playerOfPlayer->settingSuperBody_)
		{
			playerOfPlayer->settingSuperBody_ = true;
		}
		else
		{
			playerOfPlayer->settingSuperBody_ = false;
		}
	});

	superAccuracyButton_->addClickEventListener([=](Ref*) {
		if (Weapon::isSuperAccuracy_)
		{
			Weapon::isSuperAccuracy_ = false;
		}
		else
		{
			Weapon::isSuperAccuracy_ = true;
		}
	});

	superBulletButton_->addClickEventListener([=](Ref*) {
		if (Weapon::isInfiniteBullte_)
		{
			Weapon::isInfiniteBullte_ = false;
		}
		else
		{
			Weapon::isInfiniteBullte_ = true;
		}
	});

	superDamageButton_->addClickEventListener([=](Ref*) {
		if (Monster::isPlayerSuperDamage_)
		{
			Monster::isPlayerSuperDamage_ = false;
		}
		else
		{
			Monster::isPlayerSuperDamage_ = true;
		}
	});

	isOpen = true;
	return true;
}

bool SettingLayer::close()
{
	cocos2d::Director::getInstance()->getOpenGLView()->setCursorVisible(false);
	pauseBoardImg_->setPosition(10000, 10000);
	pauseBoardImg_->setCameraMask(2, true);
	isOpen = false;
	return true;
}

//cocos2d::ui::Button* SettingLayer::settingSmallButton(float deviationX, float deviationY, std::string spriteName, std::string texts)
//{
//	cocos2d::ui::Button* smallButton = new  cocos2d::ui::Button;
//	smallButton = cocos2d::ui::Button::create("Setting/btn_default.png", "Setting/btn_default_pressed.png");
//	auto Image = cocos2d::Sprite::create(spriteName);
//	smallButton->setPosition(cocos2d::Vec2(STANDARD_LEFT + deviationX, BOARD_IMAGE_HEIGHT - deviationY));
//	Image->setPosition(cocos2d::Vec2(55, 50));
//	smallButton->setScale9Enabled(true);
//	smallButton->setContentSize(cocos2d::Size(110, 100));
//	pauseBoardImg_->addChild(smallButton, 3);
//	smallButton->addChild(Image, 2);
//	auto label = cocos2d::Label::createWithTTF(texts, "fonts/Marker Felt.ttf", 30);
//	label->setPosition(cocos2d::Vec2(55, -40));
//	smallButton->addChild(label, 2);
//
//	return smallButton;
//}
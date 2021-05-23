/**
* @file Player.cpp
*/

#include "Player.h"
#include "./Item/Weapon.h"
#include "./Scene/HelloWorldScene.h"

Player* Player::create(const std::string& filename)
{
	auto player = new(std::nothrow) Player();
	if (!player)
	{
		return nullptr;
	}
	player->bindPictureSprite(cocos2d::Sprite::create(filename));

	if (player && player->sprite_)
	{
		//���ý�ɫ��ʼλ��
		player->setPosition(cocos2d::Vec2(player->x_, player->y_));
		//��ǽ�ɫ
		player->setTag(ME);
		//��ʼ����ɫ�����͵�ҩ
		player->primaryWeapon_ = Weapon::create("default_weapon.png");
		player->secondaryWeapon_ = Weapon::create("default_sec_weapon.png");
		player->bulletFilename = "dart.png";
		player->addChild(player->primaryWeapon_);
		player->addChild(player->secondaryWeapon_);
		player->primaryWeapon_->setVisible(true);			//Ĭ����ʾ������������ʾ������
		player->secondaryWeapon_->setVisible(false);
		//Ϊ��ɫ������������
		player->bindPhysicsBody();

		player->autorelease();
		return player;
	}
	return nullptr;
}

bool Player::bindPhysicsBody()
{
	auto physicsBody = cocos2d::PhysicsBody::createBox(getContentSize(), cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody->setDynamic(false);
	//����������䣬�����Ƿ�����ײ�������Ϣ
	physicsBody->setContactTestBitmask(1);
	physicsBody->setCategoryBitmask(5);
	setPhysicsBody(physicsBody);

	return true;
}

void Player::listenToKeyPress(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unusedEvent)
{
	using K = cocos2d::EventKeyboard::KeyCode;

	//WASD����ʱ������Ķ�ӦԪ�ظ���Ϊtrue
	if (keyCode == K::KEY_W)
	{
		keyPressed_[W] = true;
	}
	if (keyCode == K::KEY_A)
	{
		keyPressed_[A] = true;
	}
	if (keyCode == K::KEY_S)
	{
		keyPressed_[S] = true;
	}
	if (keyCode == K::KEY_D)
	{
		keyPressed_[D] = true;
	}
	if (keyCode == K::KEY_Q)
	{
		switchWeapon();
	}
	if (keyCode == K::KEY_SPACE)
	{
		dodge();
	}
}

void Player::listenToKeyRelease(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unusedEvent)
{
	using K = cocos2d::EventKeyboard::KeyCode;

	//WASD����ʱ������Ķ�ӦԪ�ظ���Ϊfalse
	if (keyCode == K::KEY_W)
	{
		keyPressed_[W] = false;
	}
	if (keyCode == K::KEY_A)
	{
		keyPressed_[A] = false;
	}
	if (keyCode == K::KEY_S)
	{
		keyPressed_[S] = false;
	}
	if (keyCode == K::KEY_D)
	{
		keyPressed_[D] = false;
	}
}

void Player::dodge()
{
	if (keyPressed_[W])
	{
		y_ += dodgeLength_;
	}
	if (keyPressed_[A])
	{
		x_ -= dodgeLength_;
	}
	if (keyPressed_[S])
	{
		y_ -= dodgeLength_;
	}
	if (keyPressed_[D])
	{
		x_ += dodgeLength_;
	}
	setPosition(x_, y_);
}

void Player::switchWeapon()
{
	if (secondaryWeapon_ != nullptr)
	{
		primaryWeapon_->setVisible(false);
		secondaryWeapon_->setVisible(true);
		auto t = primaryWeapon_;
		primaryWeapon_ = secondaryWeapon_;
		secondaryWeapon_ = t;
	}
}

Weapon* Player::getPrimaryWeaponInstance()
{
	return primaryWeapon_;
}

Weapon* Player::getSecondaryWeaponInstance()
{
	return secondaryWeapon_;
}

const std::string Player::getBulletName() const
{
	return bulletFilename;
}

void Player::update(float dt)
{
	x_ = getPosition().x;
	y_ = getPosition().y;

	if (keyPressed_[W]) 
	{
		y_ += stepLength_;
	}
	if (keyPressed_[A]) 
	{
		x_ -= stepLength_;
	}
	if (keyPressed_[S]) 
	{
		y_ -= stepLength_;
	}
	if (keyPressed_[D]) 
	{
		x_ += stepLength_;
	}


	setPosition(x_, y_);
}
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
		player->setPosition(cocos2d::Vec2(50, 50));
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

void Player::getInjured(int damage)
{
	if (!superBody)
	{
		int realDamage = static_cast<int>(damage * (1 - shield));
		if (realDamage >= health_)
		{
			die();
		}
		else
		{
			health_ -= realDamage;
		}
	}	
}

bool Player::isAlive()
{
	return isAlive_;
}

void Player::die()
{
	health_ = 0;
	isAlive_ = false;
}

void Player::dodge()
{	
	auto dodgeDirection = cocos2d::Vec2::ZERO;
	if (keyPressed_[W])
	{
		dodgeDirection.y += 1;
	}
	if (keyPressed_[A])
	{
		dodgeDirection.x -= 1;
	}
	if (keyPressed_[S])
	{
		dodgeDirection.y -= 1;
	}
	if (keyPressed_[D])
	{
		dodgeDirection.x += 1;
	}
	if (dodgeDirection.x == 0 && dodgeDirection.y == 0)
	{
		dodgeDirection.y += 1;
	}
	

	dodgeDirection.normalize();
	auto delay = cocos2d::DelayTime::create(dodgeTime);
	auto start = cocos2d::CallFunc::create([=]() {
		DodgeAnimeStart();
		});
	auto act = cocos2d::CallFunc::create([=]() {
		DodgeAnime(dodgeDirection);
		});
	auto end = cocos2d::CallFunc::create([=]() {
		DodgeAnimeEnd();
		});
	this->runAction(cocos2d::Sequence::create(start, act, delay, end, nullptr));
	
	
	
}

void Player::DodgeAnimeStart()
{
	canDodge = false;
	superBody = true;
	allowMove = false;
}

void Player::DodgeAnime(cocos2d::Vec2 dir)
{
	getPhysicsBody()->setVelocity(moveSpeed_ * dodgeSpeedBoost * dir);	
}

void Player::DodgeAnimeEnd()
{
	canDodge = true;
	superBody = false;
	allowMove = true;
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
	auto velocity = cocos2d::Vec2::ZERO;
	if (allowMove)
	{
		if (keyPressed_[W])
		{
			velocity.y += moveSpeed_ * speedBoostFactor;
		}
		if (keyPressed_[A])
		{
			velocity.x -= moveSpeed_ * speedBoostFactor;
		}
		if (keyPressed_[S])
		{
			velocity.y -= moveSpeed_ * speedBoostFactor;
		}
		if (keyPressed_[D])
		{
			velocity.x += moveSpeed_ * speedBoostFactor;
		}

		//�Ƚ��б�׼�����ڳ���ģ��
		velocity.normalize();
		velocity *= moveSpeed_;
		getPhysicsBody()->setVelocity(velocity);
	}	
}
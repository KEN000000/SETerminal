/**
* @file Player.cpp
*/

#include "Player.h"
#include "Item/Medkit/Medkit.h"
#include "./Item/PlayerWeapon/Weapon.h"
#include "Const/Const.h"

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
		player->setTag(PLAYER_TAG);

		player->bindAnimate("MIKU");

		//��ʼ����ɫ�����͵�ҩ
		player->primaryWeapon_ = Weapon::create("default_weapon.png");
		player->secondaryWeapon_ = Weapon::create("default_sec_weapon.png");
		player->bulletFilename_ = "dart.png";
		player->addChild(player->primaryWeapon_);
		player->addChild(player->secondaryWeapon_);
		player->primaryWeapon_->setVisible(true);			//Ĭ����ʾ������������ʾ������
		player->secondaryWeapon_->setVisible(false);
		player->moveSpeed_ = PLAYER_DEFAULT_MOVE_SPEED;
		player->health_ = PLAYER_MAX_HEALTH;
		player->maxHealth_ = PLAYER_MAX_HEALTH;
		player->shield_ = PLAYER_DEFAULT_SHIELD;
		player->medkitMaxNum_ = MEDKIT_MAX_NUM;

		//Medkit* test = Medkit::create();
		//test->retain();
		//player->medkit_.push(test);

		//Ϊ��ɫ������������
		player->bindPhysicsBody();

		player->autorelease();

		return player;
	}
	return nullptr;
}

bool Player::bindPhysicsBody()
{
	auto physicsBody = cocos2d::PhysicsBody::createBox(sprite_->getContentSize(), cocos2d::PhysicsMaterial(0.0f, 1.0f, 0.0f));
	physicsBody->setDynamic(false);
	physicsBody->setGravityEnable(false);
	physicsBody->setRotationEnable(false);
	physicsBody->setMass(0.1);
	physicsBody->setContactTestBitmask(PLAYER_CONTACT_MASK);
	physicsBody->setCategoryBitmask(PLAYER_CATEGORY_MASK);
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
	if (keyCode == K::KEY_E)
	{
		useMedkit();
	}
	if (keyCode == K::KEY_F)
	{
		if (interactItem_ != nullptr)
		{
			interactItem_->interact();
		}
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

void Player::listenToMouseEvent(cocos2d::Vec2 facingPoint, bool isPressed)
{
	facingPoint_ = facingPoint;

	if (isPressed)
	{
		//Attack
	}
}

void Player::receiveDamage(int damage)
{
	if (!superBody_)
	{
		int realDamage = static_cast<int>(damage * (1 - shield_));
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
		auto facingDir = facingPoint_ - getPosition();
		dodgeDirection.x = -facingDir.x;
		dodgeDirection.y = -facingDir.y;
	}

	dodgeDirection.normalize();
	auto delay = cocos2d::DelayTime::create(dodgeTime_);
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

void Player::updateFacingStatus()
{
	auto direction = facingPoint_ - getPosition();
	preFacingStatus_ = curFacingStatus_;
	
	if (direction.x > 0 && abs(direction.y) <= direction.x)
	{
		curFacingStatus_ = FacingStatus::right;
	}
	else if (direction.x < 0 && abs(direction.y) <= abs(direction.x))
	{
		curFacingStatus_ = FacingStatus::left;
	}
	else if (direction.y > 0 && abs(direction.x) <= direction.y)
	{
		curFacingStatus_ = FacingStatus::up;
	}
	else if (direction.y < 0 && abs(direction.x) <= abs(direction.y))
	{
		curFacingStatus_ = FacingStatus::down;
	}

	if (preFacingStatus_ != curFacingStatus_)
	{
		statusChanged_ = true;
	}
}

void Player::updateWalkingStatus()
{
	preWalkingStatus_ = curWalkingStatus_;
	curWalkingStatus_ = WalkingStatus::idle;
	for (auto i : keyPressed_)
	{
		if (i)
			curWalkingStatus_ = WalkingStatus::walk;
	}
	if (preWalkingStatus_ != curWalkingStatus_)
	{
		statusChanged_ = true;
	}
}

void Player::DodgeAnimeStart()
{
	canDodge_ = false;
	superBody_ = true;
	allowMove_ = false;
}

void Player::DodgeAnime(cocos2d::Vec2 dir)
{
	getPhysicsBody()->setVelocity(moveSpeed_ * dodgeSpeedBoost_ * dir);	
}

void Player::DodgeAnimeEnd()
{
	canDodge_ = true;
	superBody_ = false;
	allowMove_ = true;
}

Item* Player::getInteractItem()
{
	return interactItem_;
}

void Player::setInteractItem(Item* interactItem)
{
	interactItem_ = interactItem;
}

void Player::switchWeapon()
{
	if (secondaryWeapon_ != nullptr)
	{
		primaryWeapon_->setVisible(false);
		secondaryWeapon_->setVisible(false);
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
	return bulletFilename_;
}

int Player::getMedkitNum()
{
	return medkit_.size();
}

bool Player::isMedkitFull()
{
	return medkit_.size() == medkitMaxNum_;
}

std::stack<Medkit*>* Player::getMedkitBagInstance()
{
	return &medkit_;
}

void Player::useMedkit()
{
	if (health_ != maxHealth_ && getMedkitNum() != 0)
	{
		recoverHealth(medkit_.top()->getRecovery());
		medkit_.top()->release();
		medkit_.pop();
	}
}

void Player::update(float dt)
{
	auto velocity = cocos2d::Vec2::ZERO;

	if (allowMove_)
	{
		if (keyPressed_[W])
		{
			velocity.y += moveSpeed_ * speedBoostFactor_;
		}
		if (keyPressed_[A])
		{
			velocity.x -= moveSpeed_ * speedBoostFactor_;
		}
		if (keyPressed_[S])
		{
			velocity.y -= moveSpeed_ * speedBoostFactor_;
		}
		if (keyPressed_[D])
		{
			velocity.x += moveSpeed_ * speedBoostFactor_;
		}

		//�Ƚ��б�׼�����ٳ���ģ��
		velocity.normalize();
		velocity *= moveSpeed_;
		getPhysicsBody()->setVelocity(velocity);

		updateFacingStatus();
		updateWalkingStatus();
		updateMoveAnimate();
		statusChanged_ = false;

		auto playerPos = this->getPosition();
		auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
		auto boxOfNode = runningScene->getChildByTag(133);
		//��������Ѿ����ͷţ��Ҳ����ҷ�playerλ�ã�ֱ���˳�
		if (boxOfNode != nullptr)
		{
			auto obstacle = dynamic_cast<Obstacle*>(boxOfNode);
			obstacle->collision(this);
		}
	}	
}
/**
* @file Monster.cpp
*/

#include "Monster.h"
<<<<<<< Updated upstream
#include "./Scene/HelloWorldScene.h"
=======
>>>>>>> Stashed changes

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

<<<<<<< Updated upstream
Monster* Monster::create(const std::string& filename, float sizeX, float sizeY)
=======
cocos2d::Vec2 Monster::getRandomPosition()
{
	cocos2d::Vec2 position;
	if (sprite_ == nullptr)
	{
		return cocos2d::Vec2::ZERO;
	}

	//Ϊ����Monster����ʹ���ⲿ�Ķ�����ʹ����������õ�ǰ���еĳ���
	auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
	auto runningSceneSize = runningScene->getContentSize();
	//��������Ļ�����λ�ó��֣�����������ɺͷ����ӵ��ĺϷ����귶Χ
	auto monsterHeight = sprite_->getContentSize().height;
	auto monsterWidth = sprite_->getContentSize().width;
	auto minY = monsterHeight / 2;
	auto maxY = runningSceneSize.height - monsterHeight / 2;
	auto minX = monsterWidth / 2;
	auto maxX = runningSceneSize.width - monsterWidth / 2;
	auto rangeY = maxY - minY;
	auto rangeX = maxX - minX;
	position.y = (rand() % static_cast<int>(rangeY)) + minY;
	position.x = (rand() % static_cast<int>(rangeX)) + minX;
	return position;
}

void Monster::move() {
	auto nextPosition = getRandomPosition();
	auto playerNode = cocos2d::Director::getInstance()->getRunningScene()->getChildByTag(ME);
	if (playerNode != nullptr)
	{
		nextPosition = playerNode->getPosition();
	}
	auto realDest = nextPosition - getPosition();
	realDest.normalize();
	auto moveOnce = cocos2d::MoveBy::create(2.f, realDest * 50);
	facingPoint_ = nextPosition;

	//������move1��move2�м�����λ�÷����ӵ��Ķ�����ʹ��lambda���ʽʵ��
	auto shootStar = cocos2d::CallFunc::create([=]() {
		//���ɵ����ӵ�
		Sprite* enemyBullet = Sprite::create("dart_enemy.png");
		if (enemyBullet == nullptr)
		{
			problemLoading("dart_enemy.png");
		}
		else
		{
			//setPosition��ָ���Լ��������ڵ�����λ�ã��ӵ��ĸ��ڵ���Ϊ����Helloworld
			enemyBullet->setPosition(getPosition());
			//���õз��ӵ�����������
			auto physicsBody = cocos2d::PhysicsBody::createBox(enemyBullet->getContentSize(), cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
			physicsBody->setDynamic(false);
			physicsBody->setCategoryBitmask(3);
			physicsBody->setContactTestBitmask(4);
			enemyBullet->setPhysicsBody(physicsBody);
			enemyBullet->setTag(ENEMY_BULLET);

			//Ϊ����Monster����ʹ���ⲿ�Ķ�����ʹ�����¼���
			auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
			auto playerOfNode = runningScene->getChildByTag(ME);
			cocos2d::Vec2 playerPositionInScene = cocos2d::Vec2::ZERO;
			//��������Ѿ����ͷţ��Ҳ����ҷ�playerλ�ã�ֱ���˳�
			if (playerOfNode == nullptr)
			{
				return;
			}
			//��õ�ǰ�ҷ�playerλ��
			auto playerOfPlayer = dynamic_cast<Player*>(playerOfNode);
			playerPositionInScene = playerOfPlayer->getPosition();


			runningScene->addChild(enemyBullet);
			//Ϊ�з��ӵ��󶨷��䶯�����ٶ���ʱ�ò���������1sʱ��ģ��
			float starSpeed = 1200;

			//��Monster�ӽ��µ�player�����꣨Monster����Ϊ0,0��
			auto eDartMove = cocos2d::MoveTo::create(1.0f, playerPositionInScene);
			auto eDartRemove = cocos2d::RemoveSelf::create();
			enemyBullet->runAction(cocos2d::Sequence::create(eDartMove, eDartRemove, nullptr));
		}
		});
	//���﷢���ӵ�ʱ��΢ͣ��
	auto delay = cocos2d::DelayTime::create(0.1);

	//��������ѭ���ݹ飬ֻҪ���ﻹ���ţ���һֱ��
	runAction(cocos2d::Sequence::create(moveOnce, shootStar, cocos2d::CallFunc::create([=] {move(); }), nullptr));
}

Monster* Monster::create(const std::string& filename)
>>>>>>> Stashed changes
{
	auto monster = new(std::nothrow) Monster();
	if (!monster)
	{
		return nullptr;
	}
<<<<<<< Updated upstream
	monster->bindPictureMonster(cocos2d::Sprite::create(filename));

	if (monster && monster->monster_)
	{
		//�������Ҳ����λ�ó��֣�����������ɺͷ����ӵ��ĺϷ����귶Χ
		auto minY = monster->getContentSize().height / 2;
		auto maxY = sizeY - minY;
		auto rangeY = maxY - minY;
		int randomY = (rand() % static_cast<int>(rangeY)) + minY;
		//���ù�����������
		monster->setPosition(sizeX + monster->getContentSize().width / 2, randomY);


		//��ǽ�ɫ
		monster->setTag(ENEMY);
		//Ϊ��ɫ������������
		monster->bindPhysicsBody();
=======
	monster->bindPictureSprite(cocos2d::Sprite::create(filename));
	monster->statusChanged_ = true;

	//Ϊ����Monster����ʹ���ⲿ�Ķ�����ʹ����������õ�ǰ���еĳ���
	auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
	auto runningSceneSize = runningScene->getContentSize();

	if (monster && monster->sprite_)
	{
		auto monsterPosition = monster->getRandomPosition();
		monster->bindAnimate("MONSTER2");

		//���ù�����������
		monster->setPosition(monsterPosition);

		//Ϊ��ɫ������������
		monster->bindPhysicsBody();

		//��ǽ�ɫ
		monster->setTag(ENEMY);

>>>>>>> Stashed changes

		monster->autorelease();
		return monster;
	}
	return nullptr;
}

<<<<<<< Updated upstream
void Monster::move(float sizeX, float sizeY, cocos2d::Vec2 playerPostion)
{
	auto monsterPosition = getPosition();


	//move1��������Ҳ��ƶ����м����λ�ã�����ʱ��ΪrandomDuration1
	auto move1 = cocos2d::MoveTo::create(3.5f, cocos2d::Vec2(-200, -20));
	//move1��������м����λ���ƶ�����࣬����ʱ��ΪrandomDuration2
	//auto move2 = cocos2d::MoveTo::create(2.0f, cocos2d::Vec2(200,200));
	//actionRemove���ͷŹ������
	auto actionRemove = cocos2d::RemoveSelf::create();

	////������move1��move2�м�����λ�÷����ӵ��Ķ�����ʹ��lambda���ʽʵ��
	//auto shootStar = cocos2d::CallFunc::create([=]() {
	//	//���ɵ����ӵ�
	//	Sprite* enemyBullet = Sprite::create("dart_enemy.png");
	//	if (enemyBullet == nullptr)
	//	{
	//		problemLoading("dart_enemy.png");
	//	}
	//	else
	//	{
	//		enemyBullet->setPosition(monster_->getPosition());
	//		//���õз��ӵ�����������
	//		auto physicsBody = cocos2d::PhysicsBody::createBox(enemyBullet->getContentSize(), cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
	//		physicsBody->setDynamic(false);
	//		physicsBody->setCategoryBitmask(3);
	//		physicsBody->setContactTestBitmask(4);
	//		enemyBullet->setPhysicsBody(physicsBody);
	//		enemyBullet->setTag(ENEMY_BULLET);
	//		this->addChild(enemyBullet);
	//		//Ϊ�з��ӵ��󶨷��䶯��
	//		float starSpeed = 120;
	//		float maxX = this->getContentSize().width;
	//		float starDuration = (float)randomX / starSpeed;
	//		auto eDartMove = cocos2d::MoveTo::create(starDuration, playerPostion);
	//		auto eDartRemove = cocos2d::RemoveSelf::create();
	//		enemyBullet->runAction(cocos2d::Sequence::create(eDartMove, eDartRemove, nullptr));
	//	}
	//	});
	////���﷢���ӵ�ʱ��΢ͣ��
	//auto delay = cocos2d::DelayTime::create(0.05);

	monster_->runAction(cocos2d::Sequence::create(move1, actionRemove, nullptr));

}

bool Monster::bindPhysicsBody()
{
	auto physicsBody = cocos2d::PhysicsBody::createBox(getContentSize(), cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
=======
bool Monster::bindPhysicsBody()
{
	//��ָ�룬��ʧ��
	if (sprite_ == nullptr)
	{
		return false;
	}
	auto physicsBody = cocos2d::PhysicsBody::createBox(sprite_->getContentSize(), cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
>>>>>>> Stashed changes
	physicsBody->setDynamic(false);
	physicsBody->setContactTestBitmask(1);
	physicsBody->setCategoryBitmask(3);
	setPhysicsBody(physicsBody);

	return true;
}

<<<<<<< Updated upstream
=======
void Monster::updateFacingStatus()
{
	facingPoint_ = getRandomPosition();
	auto playerNode = cocos2d::Director::getInstance()->getRunningScene()->getChildByTag(ME);
	if (playerNode != nullptr)
	{
		facingPoint_ = playerNode->getPosition();
	}
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

void Monster::updateWalkingStatus()
{
	preWalkingStatus_ = curWalkingStatus_;
	curWalkingStatus_ = WalkingStatus::walk;
	if (preFacingStatus_ != curFacingStatus_)
	{
		statusChanged_ = true;
	}
}

void Monster::update(float dt)
{
		updateFacingStatus();
		updateWalkingStatus();
		updateMoveAnimate();
		statusChanged_ = false;
	
}
>>>>>>> Stashed changes

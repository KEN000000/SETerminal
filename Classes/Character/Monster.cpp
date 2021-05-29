/**
* @file Monster.cpp
*/

#include "Monster.h"

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

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

void Monster::randomMove() {
	auto nextPosition = getRandomPosition();
	auto moveOnce = cocos2d::MoveTo::create(1.2f, nextPosition);

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
			enemyBullet->setPosition(nextPosition);
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
	runAction(cocos2d::Sequence::create(moveOnce, shootStar, cocos2d::CallFunc::create([=] {randomMove(); }), nullptr));
}

Monster* Monster::create(const std::string& filename)
{
	auto monster = new(std::nothrow) Monster();
	if (!monster)
	{
		return nullptr;
	}
	monster->bindPictureSprite(cocos2d::Sprite::create(filename));

	//Ϊ����Monster����ʹ���ⲿ�Ķ�����ʹ����������õ�ǰ���еĳ���
	auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
	auto runningSceneSize = runningScene->getContentSize();

	if (monster && monster->sprite_)
	{
		////��������Ļ�����λ�ó��֣�����������ɺͷ����ӵ��ĺϷ����귶Χ
		//auto monsterHeight = monster->sprite_->getContentSize().height;
		//auto monsterWidth = monster->sprite_->getContentSize().width;
		//auto minY = monsterHeight / 2;
		//auto maxY = runningSceneSize.height - monsterHeight / 2;
		//auto minX = monsterWidth / 2;
		//auto maxX = runningSceneSize.width - monsterWidth / 2;
		//auto rangeY = maxY - minY;
		//auto rangeX = maxX - minX;
		//auto randomY = (rand() % static_cast<int>(rangeY)) + minY;
		//auto randomX = (rand() % static_cast<int>(rangeX)) + minX;
		auto monsterPosition = monster->getRandomPosition();


		//���ù�����������
		monster->setPosition(monsterPosition);

		//Ϊ��ɫ������������
		monster->bindPhysicsBody();
		//��ǽ�ɫ
		monster->setTag(ENEMY);
		

		monster->autorelease();
		return monster;
	}
	return nullptr;
}

void Monster::move()
{
	//auto monsterPosition = getPosition();
	//����һ��0-��Ļ��ȷ�Χ֮��������������ֹͣ
	//int randomX = (rand() % static_cast<int>(monsterPosition.x));
	//float randomDuration1 = (monsterPosition.x - randomX) / monsterSpeed;
	//float randomDuration2 = randomX / monsterSpeed;

	
	//auto nextPosition = getRandomPosition();
	//auto nextPos2 = getRandomPosition();
	////move1��������Ҳ��ƶ����м����λ�ã�����ʱ��ΪrandomDuration1
	//auto move1 = cocos2d::MoveTo::create(randomDuration1, cocos2d::Vec2(randomX, monsterPosition.y));
	////move2��������м����λ���ƶ�����࣬����ʱ��ΪrandomDuration2
	//auto move2 = cocos2d::MoveTo::create(randomDuration2, cocos2d::Vec2(0, monsterPosition.y));

	//auto move1 = cocos2d::MoveTo::create(1.2f, nextPosition);
	//actionRemove���ͷŹ������
	//auto actionRemove = cocos2d::RemoveSelf::create();

	randomMove();

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
	//		//setPosition��ָ���Լ��������ڵ�����λ�ã��ӵ��ĸ��ڵ���Ϊ����Helloworld
	//		enemyBullet->setPosition(nextPosition);
	//		//���õз��ӵ�����������
	//		auto physicsBody = cocos2d::PhysicsBody::createBox(enemyBullet->getContentSize(), cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
	//		physicsBody->setDynamic(false);
	//		physicsBody->setCategoryBitmask(3);
	//		physicsBody->setContactTestBitmask(4);
	//		enemyBullet->setPhysicsBody(physicsBody);
	//		enemyBullet->setTag(ENEMY_BULLET);

	//		//Ϊ����Monster����ʹ���ⲿ�Ķ�����ʹ�����¼���
	//		auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
	//		auto playerOfNode = runningScene->getChildByTag(ME);
	//		cocos2d::Vec2 playerPositionInScene = cocos2d::Vec2::ZERO;
	//		//��õ�ǰ�ҷ�playerλ��
	//		if (playerOfNode != nullptr)
	//		{
	//			auto playerOfPlayer = dynamic_cast<Player*>(playerOfNode);
	//			playerPositionInScene = playerOfPlayer->getPosition();
	//		}

	//		runningScene->addChild(enemyBullet);
	//		//Ϊ�з��ӵ��󶨷��䶯�����ٶ���ʱ�ò���������1sʱ��ģ��
	//		float starSpeed = 1200;

	//		//��Monster�ӽ��µ�player�����꣨Monster����Ϊ0,0��
	//		auto eDartMove = cocos2d::MoveTo::create(1.0f, playerPositionInScene);
	//		auto eDartRemove = cocos2d::RemoveSelf::create();
	//		enemyBullet->runAction(cocos2d::Sequence::create(eDartMove, eDartRemove, nullptr));
	//	}
	//	});
	//���﷢���ӵ�ʱ��΢ͣ��
	//auto delay = cocos2d::DelayTime::create(0.1);

	//auto sequence = cocos2d::Sequence::create(move11, nullptr);

	//runAction(cocos2d::Sequence::create(move11, nullptr));
	
}

bool Monster::bindPhysicsBody()
{
	//��ָ�룬��ʧ��
	if (sprite_ == nullptr)
	{
		return false;
	}	
	auto physicsBody = cocos2d::PhysicsBody::createBox(sprite_->getContentSize(), cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody->setDynamic(false);
	physicsBody->setContactTestBitmask(1);
	physicsBody->setCategoryBitmask(3);
	setPhysicsBody(physicsBody);

	return true;
}


void Monster::receiveDamage(int damage)
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


bool Monster::isAlive()
{
	return isAlive_;

}

void Monster::die()
{
	health_ = 0;
	isAlive_ = false;
}



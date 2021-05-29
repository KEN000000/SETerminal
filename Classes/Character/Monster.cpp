/**
* @file Monster.cpp
*/

#include "Monster.h"
#include "./Scene/HelloWorldScene.h"

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

Monster* Monster::create(const std::string& filename)
{
	auto monster = new(std::nothrow) Monster();
	if (!monster)
	{
		return nullptr;
	}
	monster->bindPictureSprite(cocos2d::Sprite::create(filename));
	monster->moveSpeed_ = 160.f;
	monster->health_ = 3;
	monster->shield_ = 0.5f;
	
	auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
	auto runningSceneSize = runningScene->getContentSize();

	if (monster && monster->sprite_)
	{
		//�������Ҳ����λ�ó��֣�����������ɺͷ����ӵ��ĺϷ����귶Χ
		auto minY = monster->getContentSize().height / 2;
		auto maxY = runningSceneSize.height - minY;
		auto rangeY = maxY - minY;
		int randomY = (rand() % static_cast<int>(rangeY)) + minY;
		//���ù�����������
		monster->setPosition(runningSceneSize.width + monster->getContentSize().width / 2, randomY);


		//��ǽ�ɫ
		monster->setTag(ENEMY);
		//Ϊ��ɫ������������
		monster->bindPhysicsBody();

		monster->autorelease();
		return monster;
	}
	return nullptr;
}

void Monster::move()
{
	auto monsterPosition = getPosition();
	//����һ��0-��Ļ��ȷ�Χ֮��������������ֹͣ
	int randomX = (rand() % static_cast<int>(monsterPosition.x));
	float randomDuration1 = (monsterPosition.x - randomX) / moveSpeed_;
	float randomDuration2 = randomX / moveSpeed_;

	//move1��������Ҳ��ƶ����м����λ�ã�����ʱ��ΪrandomDuration1
	auto move1 = cocos2d::MoveTo::create(randomDuration1, cocos2d::Vec2(randomX, monsterPosition.y));
	//move2��������м����λ���ƶ�����࣬����ʱ��ΪrandomDuration2
	auto move2 = cocos2d::MoveTo::create(randomDuration2, cocos2d::Vec2(0, monsterPosition.y));
	//actionRemove���ͷŹ������
	auto actionRemove = cocos2d::RemoveSelf::create();

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
			//settPosition��ָ���Լ��������ڵ�����λ�ã��ӵ��ĸ��ڵ���Ϊ����Helloworld
			enemyBullet->setPosition(cocos2d::Vec2(randomX, monsterPosition.y));
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
			//��õ�ǰ�ҷ�playerλ��
			if (playerOfNode != nullptr)
			{
				auto playerOfPlayer = dynamic_cast<Player*>(playerOfNode);
				playerPositionInScene = playerOfPlayer->getPosition();
			}

			runningScene->addChild(enemyBullet);
			//Ϊ�з��ӵ��󶨷��䶯�����ٶ���ʱ�ò���������1sʱ��ģ��
			float starSpeed = 1200;

			//��Monster�ӽ��µ�player�����꣨Monster����Ϊ0,0��
			auto eDartMove = cocos2d::MoveTo::create(1.0f, playerPositionInScene);
			auto eDartRemove = cocos2d::RemoveSelf::create();
			enemyBullet->runAction(cocos2d::Sequence::create(eDartMove, eDartRemove, nullptr));
		}
		});
	////���﷢���ӵ�ʱ��΢ͣ��
	auto delay = cocos2d::DelayTime::create(0.1);

	runAction(cocos2d::Sequence::create(move1, shootStar, delay, move2, actionRemove, nullptr));

}


bool Monster::bindPhysicsBody()
{
	auto physicsBody = cocos2d::PhysicsBody::createBox(sprite_->getContentSize(), cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody->setDynamic(false);
	physicsBody->setContactTestBitmask(1);
	physicsBody->setCategoryBitmask(3);
	setPhysicsBody(physicsBody);

	return true;
}


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

Monster* Monster::create(const std::string& filename, float sizeX, float sizeY)
{
	auto monster = new(std::nothrow) Monster();
	if (!monster)
	{
		return nullptr;
	}
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

		monster->autorelease();
		return monster;
	}
	return nullptr;
}

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
	physicsBody->setDynamic(false);
	physicsBody->setContactTestBitmask(1);
	physicsBody->setCategoryBitmask(3);
	setPhysicsBody(physicsBody);

	return true;
}


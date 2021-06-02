/**
* @file HelloWorldScene.cpp
*/

#include "HelloWorldScene.h"
#include "GameOverScene.h"
#include "./Character/Player.h"
#include "./Item/Bullet/Bullet.h"
#include "./Character/Monster.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
    //���ø����ʼ��
    if (!Scene::init())
    {
        return false;
    }
    if (!Scene::initWithPhysics())
    {
        return false;
    }

    //��ȡ���ڴ�С��ԭ������
    auto winSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    //���ƻ�ɫ����
    auto background = DrawNode::create();
    background->drawSolidRect(origin, winSize, cocos2d::Color4F(0.6, 0.6, 0.6, 1));
    //�����Ϊ-2��Σ���ֹ��ס�±ߵ�tmx��ͼ�ļ�
    this->addChild(background, -2);

    //get tmx pic from files  ���ļ��и㵽tmx��ͼ�ļ�
    _tileMap = TMXTiledMap::create("myfirst.tmx");
    _tileMap->setPosition(Vec2(0, 0));
    this->addChild(_tileMap, -1);

    //������ҽ�ɫʵ��
    player_ = Player::create("MIKU/idle_down/idle_down1.png");
    this->addChild(player_, 2);

    healthBar_ = HealthBar::create(player_);
    healthBar_->setAnchorPoint(cocos2d::Point(0.f, 1.f));
    healthBar_->setPosition(cocos2d::Point(10, winSize.height));
    addChild(healthBar_, 2);

    //auto barrier = cocos2d::Sprite::create("stone.png");
    //barrier->setScale(0.3);
    //barrier->setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
    //auto physicsBody = cocos2d::PhysicsBody::createBox(barrier->getContentSize(), cocos2d::PhysicsMaterial(0, 1, 0));
    //physicsBody->setDynamic(false);
    //physicsBody->setGravityEnable(false);
    //physicsBody->setRotationEnable(false);
    //physicsBody->setContactTestBitmask(1);
    //physicsBody->setCategoryBitmask(1);
    //physicsBody->setCollisionBitmask(3);
    //physicsBody->setMass(1e10);
    //barrier->setPhysicsBody(physicsBody);
    //addChild(barrier, 1);
    //barrier->setPosition(300, 500);

    //����addMonster���������λ�����ɹ���
    srand((unsigned int)time(nullptr));
    this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::addMonster), 1.5);

    //������Ļ����������굥�����¼��ļ�����
    auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, player_);

    //����ר�õ���������
    auto mouseListener = cocos2d::EventListenerMouse::create();
    mouseListener->onMouseMove = CC_CALLBACK_1(HelloWorld::onMouseMove, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, player_);

    //���ɳ�����������ײ�¼��ļ�����
    auto contactListener = cocos2d::EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegan, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    //���ɼ��̲����¼��ļ�����
    auto keyboardListener = cocos2d::EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(Player::listenToKeyPress, player_);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(Player::listenToKeyRelease, player_);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    return true;
}


void HelloWorld::addMonster(float dt)
{
    //���ɹ���ʵ��
    auto monster = Monster::create("MONSTER2/idle_down/idle_down1.png");
    if (monster == nullptr)
    {
        problemLoading("monster.png");
    }
<<<<<<< Updated upstream
    else {
        //�������Ҳ����λ�ó��֣�����������ɺͷ����ӵ��ĺϷ����귶Χ
        auto minY = monster->getContentSize().height / 2;
        auto maxY = this->getContentSize().height - minY;
        auto rangeY = maxY - minY;
        int randomY = (rand() % static_cast<int>(rangeY)) + minY;
        int maxX = this->getContentSize().width;
        int randomX = maxX - (rand() % (int)(maxX / 2));
        float monsterSpeed = 160;
        float randomDuration2 = (float)randomX / monsterSpeed;
        float randomDuration1 = (float)(maxX - randomX) / monsterSpeed;
        //���ù�����������
        monster->setPosition(this->getContentSize().width + monster->getContentSize().width / 2, randomY);
        //move1��������Ҳ��ƶ����м����λ�ã�����ʱ��ΪrandomDuration1
        auto move1 = cocos2d::MoveTo::create(randomDuration1, cocos2d::Vec2(randomX, randomY));
        //move1��������м����λ���ƶ�����࣬����ʱ��ΪrandomDuration2
        auto move2 = cocos2d::MoveTo::create(randomDuration2, cocos2d::Vec2(-monster->getContentSize().width / 2, randomY));
        //actionRemove���ͷŹ������
        auto actionRemove = RemoveSelf::create();
        //���ù�����������
        auto physicsBody = PhysicsBody::createBox(monster->getContentSize(), cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
        physicsBody->setDynamic(false);
        physicsBody->setContactTestBitmask(1);
        physicsBody->setCategoryBitmask(3);
        monster->setPhysicsBody(physicsBody);
        monster->setTag(ENEMY);
        this->addChild(monster);

        //������move1��move2�м�����λ�÷����ӵ��Ķ�����ʹ��lambda���ʽʵ��
        auto shootStar = CallFunc::create([=]() {
            //���ɵ����ӵ�
            Sprite* enemyBullet = Sprite::create("dart_enemy.png");
            if (enemyBullet == nullptr)
            {
                problemLoading("dart_enemy.png");
            }
            else
            {
                enemyBullet->setPosition(monster->getPosition());
                //���õз��ӵ�����������
                auto physicsBody = PhysicsBody::createBox(enemyBullet->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
                physicsBody->setDynamic(false);
                physicsBody->setCategoryBitmask(3);
                physicsBody->setContactTestBitmask(4);
                enemyBullet->setPhysicsBody(physicsBody);
                enemyBullet->setTag(ENEMY_BULLET);
                this->addChild(enemyBullet);
                //Ϊ�з��ӵ��󶨷��䶯��
                float starSpeed = 600;
                float maxX = this->getContentSize().width;
                float starDuration = (float)randomX / starSpeed;
                auto eDartMove = cocos2d::MoveTo::create(starDuration, player_->getPosition());
                auto eDartRemove = cocos2d::RemoveSelf::create();
                enemyBullet->runAction(cocos2d::Sequence::create(eDartMove, eDartRemove, nullptr));
            }
            });
        //���﷢���ӵ�ʱ��΢ͣ��
        auto delay = cocos2d::DelayTime::create(0.05);
        monster->runAction(Sequence::create(move1, delay, shootStar, move2, actionRemove, nullptr));
=======
    else 
    {
        addChild(monster);
        monster->move();
>>>>>>> Stashed changes
    }
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* unusedEvent)
{
<<<<<<< Updated upstream
    //ȡ�õ����Ļλ�õ�����
    auto touchLocation = touch->getLocation();
    auto offset = touchLocation - player_->getPosition();
    player_->listenToMouseEvent(offset, true);
    //ȡ���ӵ����䷽��ĵ�λ����
    offset.normalize();
=======
    ////ȡ�õ����Ļλ�õ�����
    //auto touchLocation = touch->getLocation();
    //auto offset = touchLocation - player_->getPosition();
    ////ȡ���ӵ����䷽��ĵ�λ����
    //offset.normalize();
>>>>>>> Stashed changes
    //�ڳ����ڴ����ӵ�ʵ��
    player_->isAttacking = true;
    TouchHolding = true;      
    return true;
}

bool HelloWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* unusedEvent)
{
    player_->isAttacking = false;
    TouchHolding = false;
    return true;
}

void HelloWorld::onMouseMove(cocos2d::EventMouse* mouse)
<<<<<<< Updated upstream
{
    auto mouseLocation = convertToNodeSpace(mouse->getLocationInView());
    auto offset = mouseLocation - player_->getPosition();
    player_->listenToMouseEvent(offset, false);
=======
{   
    player_->listenToMouseEvent(convertToNodeSpace(mouse->getLocationInView()), false);
>>>>>>> Stashed changes
}

bool HelloWorld::onContactBegan(cocos2d::PhysicsContact& physicsContact)
{
    auto nodeA = physicsContact.getShapeA()->getBody()->getNode();
    auto nodeB = physicsContact.getShapeB()->getBody()->getNode();

    if (nodeA && nodeB)
    {
        auto tagA = nodeA->getTag();
        auto tagB = nodeB->getTag();

        //��һ�ɱ����������ӵ�
        if (tagA == ME_BULLET)
        {
            nodeB->removeFromParentAndCleanup(true);
            cocos2d::log("player kill");
        }
        else if (tagB == ME_BULLET)
        {
            nodeA->removeFromParentAndCleanup(true);
            cocos2d::log("player kill");
        }

        //��ұ���ɱ
        if (tagA == ME)
        {
            auto tmp = dynamic_cast<Player*>(nodeA);
<<<<<<< Updated upstream
            tmp->getInjured(6);
=======
            tmp->receiveDamage(10);
>>>>>>> Stashed changes
            if (tmp->isAlive() == false)
            {
                //�滻��Gameover����
                Director::getInstance()->replaceScene(TransitionSlideInT::create(0.2f, GameOver::create()));
            }
        }
        if (tagB == ME)
        {
            auto tmp = dynamic_cast<Player*>(nodeB);
<<<<<<< Updated upstream
            tmp->getInjured(6);
=======
            tmp->receiveDamage(10);
>>>>>>> Stashed changes
            if (tmp->isAlive() == false)
            {
                //�滻��Gameover����
                Director::getInstance()->replaceScene(TransitionSlideInT::create(0.2f, GameOver::create()));
            }
        }
    }

    return true;
}
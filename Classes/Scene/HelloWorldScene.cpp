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
    else 
    {
        addChild(monster);
        monster->move();
    }
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* unusedEvent)
{
    //ȡ�õ����Ļλ�õ�����
    auto touchLocation = touch->getLocation();
    auto offset = touchLocation - player_->getPosition();
    //ȡ���ӵ����䷽��ĵ�λ����
    offset.normalize();
    //�ڳ����ڴ����ӵ�ʵ��
    auto bullet = Bullet::create(player_->getBulletName());
    bullet->setPosition(player_->getPosition());
    this->addChild(bullet, 1);
    //Ϊ�ӵ�ʵ���󶨲��ŷ���ķ��ж���
    bullet->shoot(offset);

    return true;
}

void HelloWorld::onMouseMove(cocos2d::EventMouse* mouse)
{   
    player_->listenToMouseEvent(convertToNodeSpace(mouse->getLocationInView()), false);
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
            tmp->receiveDamage(10);
            if (tmp->isAlive() == false)
            {
                //�滻��Gameover����
                Director::getInstance()->replaceScene(TransitionSlideInT::create(0.2f, GameOver::create()));
            }
        }
        if (tagB == ME)
        {
            auto tmp = dynamic_cast<Player*>(nodeB);
            tmp->receiveDamage(10);
            if (tmp->isAlive() == false)
            {
                //�滻��Gameover����
                Director::getInstance()->replaceScene(TransitionSlideInT::create(0.2f, GameOver::create()));
            }
        }
    }

    return true;
}
/**
* @file Bullet.cpp
*/

#include "cocos2d.h"
#include "Bullet.h"
#include "././Scene/HelloWorldScene.h"

Bullet* Bullet::create(const std::string& filename)
{
    auto bullet = new(std::nothrow) Bullet();
    if (bullet == nullptr)
    {
        return nullptr;
    }
    bullet->bindPictureSprite(cocos2d::Sprite::create(filename));

    if (bullet && bullet->sprite_)
    {
        //�����ӵ�����
        bullet->bulletSpeed_ = 600.0f;
        bullet->bulletRange_ = 1500.0f;
        //�����ӵ���������
        bullet->bindPhysicsBody();
        //ʹ��tag����ҷ��ӵ�
        bullet->setTag(ME_BULLET);

        return bullet;
    }

    return nullptr;
}

bool Bullet::bindPhysicsBody()
{
    auto physicsBody = cocos2d::PhysicsBody::createBox(getContentSize(), cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody->setDynamic(false);
    physicsBody->setContactTestBitmask(2);
    physicsBody->setCategoryBitmask(5);
    setPhysicsBody(physicsBody);

    return true;
}

void Bullet::dieEffect()
{

}

bool Bullet::shoot(const cocos2d::Vec2 shootDirection)
{
    //�����ӵ������˶�����
    auto actionMove = cocos2d::MoveTo::create(bulletRange_ / bulletSpeed_, getPosition() + shootDirection * bulletRange_);
    //�ͷ��ӵ�
    auto actionRemove = cocos2d::RemoveSelf::create();
    //Ϊ�ӵ�ʵ���󶨷���-�ͷŵĶ���
    auto end = cocos2d::CallFunc::create([=]() {dieEffect(); });
    runAction(cocos2d::Sequence::create(actionMove, dieEffect, actionRemove, nullptr));

    return true;
}
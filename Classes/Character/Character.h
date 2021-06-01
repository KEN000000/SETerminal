/**
* @file Character.h
*/

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"

/**
*@brief ��ɫ�࣬Ԥ�ư�����Һ͹���
*/

class Character : public cocos2d::Sprite
{
public:

    virtual ~Character() = default;


    /**
*@brief ����ͼ����
* @param ָ�򱻰󶨸���ɫ����ľ���
* @author ����
*/
    void bindPictureSprite(cocos2d::Sprite* sprite);


	virtual void receiveDamage(int damage);


    /**
*@brief ����
* @author ����
*/
    void die();


	//��ȡ��ɫ�Ƿ�����
	bool isAlive();


	void updateMoveAnimate();


	virtual void updateFacingStatus() = 0;


	virtual void updateWalkingStatus() = 0;


    /**
*@brief ����������
* @author ����
*/
    virtual bool bindPhysicsBody() = 0;


    static cocos2d::Animate* createAnimate(const char* animateName, cocos2d::Size size, int frames = 4);


	void bindAnimate(const std::string& characterName);

protected:

	friend class HealthBar;

    cocos2d::Sprite* sprite_;

    int health_;

    float shield_;

    bool isAlive_ = true;
	
    float moveSpeed_;

	//��ɫ����ĵ������
	cocos2d::Vec2 facingPoint_;

	//�ƶ�״̬�ͳ���״̬
	enum class WalkingStatus { idle, walk };
	enum class FacingStatus { up, down, left, right };

	//�ƶ��;�ֹʱ�Ķ���
	cocos2d::Animate* walkUp_;
	cocos2d::Animate* walkDown_;
	cocos2d::Animate* walkLeft_;
	cocos2d::Animate* walkRight_;
	cocos2d::Animate* idleUp_;
	cocos2d::Animate* idleDown_;
	cocos2d::Animate* idleLeft_;
	cocos2d::Animate* idleRight_;
	cocos2d::Animate* animateBeingPlayed_;

	//��ǰ֡״̬����һ֡״̬
	WalkingStatus curWalkingStatus_ = WalkingStatus::idle;
	WalkingStatus preWalkingStatus_ = WalkingStatus::idle;
	FacingStatus curFacingStatus_ = FacingStatus::down;
	FacingStatus preFacingStatus_ = FacingStatus::down;

	//״̬�Ƿ����ı�
	bool statusChanged_ = false;

};

#endif // !__CHARACTER_H__

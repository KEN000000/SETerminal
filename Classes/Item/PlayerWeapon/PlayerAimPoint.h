/**
* @file PlayerAimPoint.h
*/

#ifndef __PLAYERAIMPOINT_H__
#define __PLAYERAIMPOINT_H__

#include "cocos2d.h"
#include "../Item.h"

/*
׼����
	@������
	*/

class PlayerAimPoint : public Item
{
public:

	virtual ~PlayerAimPoint() = default;

	/*
	����һ��׼��
	@������
	*/
	static PlayerAimPoint* create(const std::string& filename);

	virtual bool bindPhysicsBody() { return true; }

	void SetTarget(cocos2d::Vec2 Target);

	void RecoverRecoil(float RecoverSpeed);

	float RecoilStatus = 0;

protected:

	cocos2d::Vec2 TargetPos = cocos2d::Vec2::ZERO;
};

#endif // !__PLAYERAIMPOINT_H__

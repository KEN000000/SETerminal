/**
* @file CameraEffect.h
*/

#ifndef __CAMERA_EFFECT_H__
#define __CAMERA_EFFECT_H__

#include "cocos2d.h"
#include "Character/Character.h"
#include "Character/Player.h"

/*
�����Ч��
	@������
	*/

class CameraEffect :public cocos2d::Camera
{
public:

	//����һ�������
	static CameraEffect* create();

	//
	void update(float dt);

	//�����������Ŀ���ɫ����������ܹ��������ƶ�
	void LockPlayer(Player* player);

protected:

	cocos2d::Camera* CameraInstance;

	cocos2d::Vec2 Target;

	Player* TargetPlayer;
};

#endif 
#pragma once
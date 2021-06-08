/**
* @file CameraEffect.h
*/

#ifndef __CAMERA_EFFECT_H__
#define __CAMERA_EFFECT_H__

#include "cocos2d.h"
#include "Character/Character.h"
#include "Character/Player.h"

/*
���������Ч��
	@������
	*/

class CameraEffect :public cocos2d::Camera
{
public:

	//���û��߰󶨣�����У�һ�����������
	static CameraEffect* create(cocos2d::Scene* scene);

	//���������Ч��
	void Shake(float Strength, int Count);

	//
	void update(float dt);

	//�����������Ŀ���ɫ����������ܹ��������ƶ�
	void LockPlayer(Player* player);

protected:

	cocos2d::Camera* CameraInstance;

	cocos2d::Vec2 OgPos;

	Player* TargetPlayer;
};

#endif 
#pragma once
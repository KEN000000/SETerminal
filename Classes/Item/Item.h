/**
* @file Item.h
*/

#ifndef __ITEM_H__
#define __ITEM_H__

#include "cocos2d.h"

class Item : public cocos2d::Sprite
{
public:

	virtual ~Item() = default;


	/**
*@brief ����ͼ����
* @param ָ�򱻰󶨸���Ʒ����ľ���
* @author ����
*/
	void bindPictureSprite(cocos2d::Sprite* sprite);


	/**
*@brief ����
* @author ����
*/
	//void pickedUp();


		/**
*@brief ����������
* @author ����
*/
	virtual bool bindPhysicsBody() = 0;


	cocos2d::Label* getItemInfo();


protected:

	//�Ƿ񱻳���
	bool isHeld_ = false;

	cocos2d::Sprite* sprite_;

	cocos2d::Label* itemInfo_ = nullptr;
};

#endif	// !__ITEM_H__
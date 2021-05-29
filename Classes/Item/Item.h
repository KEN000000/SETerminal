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
	//virtual void interact() = 0


		/**
*@brief ����������
* @author ����
*/
	virtual bool bindPhysicsBody() = 0;

protected:

	cocos2d::Sprite* sprite_;
};

#endif	// !__ITEM_H__
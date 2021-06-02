/**
* @file Const.h
*/

#ifndef __CONST_H__
#define __CONST_H__

//masks
#define MONSTER_CONTACT_MASK 0x01
#define MONSTER_CATEGORY_MASK 0x03

#define MONSTER_BULLET_CONTACT_MASK 0x04
#define MOSNTER_BULLET_CATEGORY_MASK 0x03

#define PLAYER_CONTACT_MASK 0x01
#define PLAYER_CATEGORY_MASK 0x05

#define PLAYER_BULLET_CONTACT_MASK 0x02
#define PLAYER_BULLET_CATEGORY_MASK 0x05

#define ITEM_CONTACT_MASK 0x01
#define ITEM_CATEGORY_MASK 0x05

//tags
#define PLAYER_TAG 100
#define PLAYER_BULLET_TAG 10
#define MONSTER_TAG 200
#define MONSTER_BULLET_TAG 20
#define ITEM_TAG 50

//default values
#define PLAYER_MAX_HEALTH 100
#define MONSTER_MAX_HEALTH 10
#define PLAYER_DEFAULT_SHIELD 0.5f
#define MONSTER_DEFAULT_SHIELD 0.0f
#define PLAYER_DEFAULT_MOVE_SPEED 400.f
#define MONSTER_DEFAULT_MOVE_SPEED 2.f
#define MEDKIT_DEFAULT_RECOVERABILITY 30
#define MEDKIT_MAX_NUM 3


#endif  //!__CONST_H__
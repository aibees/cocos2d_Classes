#include "Entity.h"

USING_NS_CC;

Entity::Entity() {
	Entity(Vec2(Entity::getDefaultPosition()), 100, 100);
}

Entity::Entity(Vec2 position, long long int hp, long long int mp) {
	Position = position;
	HP = hp;
	MP = mp;
}

Vec2 Entity::getPosition() {
	return Position;
}

void Entity::setPosition(Vec2 position) {
	Position = position;
	return;
}

long long int Entity::getHP() {
	return HP;
}

void Entity::setHP(long long int hp) {
	HP = hp;
	return;
}

long long int Entity::getMP() {
	return MP;
}

void Entity::setMP(long long int mp) {
	MP = mp;
	return;
}

void Entity::setPlayerData(Rect player) {
	playerBox = player;
	return;
}

Vec2 Entity::getDefaultPosition() {
	Size visible = Director::getInstance()->getVisibleSize();
	return Vec2(visible.width / 2, visible.height / 2);
}
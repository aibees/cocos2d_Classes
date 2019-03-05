#include "Enemy.h"

USING_NS_CC;

Enemy::Enemy() {
	Enemy(Vec2(0, 0), 100, 100);
}

Enemy::Enemy(Vec2 position, long long int hp, long long int mp)
{
	Position = position;
	HP = hp;
	MP = mp;
}

Vec2 Enemy::getPosition() { return Position; }

void Enemy::setPosition(Vec2 position) {
	Position = position;
}

long long int Enemy::getHP() { return HP; }

void Enemy::setHP(long long int hp) {
	HP = hp;
}

long long int Enemy::getMP() { return MP; }

void Enemy::setMP(long long int mp) {
	MP = mp;
}
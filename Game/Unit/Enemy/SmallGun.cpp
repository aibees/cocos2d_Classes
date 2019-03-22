#include "SmallGun.h"

#define PIE 3.141592

USING_NS_CC;
using namespace std;

SmallGun::SmallGun() {

}

SmallGun::SmallGun(string spName) {
	srand((unsigned int)time(0));
	sp = Sprite::create(spName);
	setHP(100);
	setMP(100);
	auto ws = Director::getInstance()->getVisibleSize();

	setPosition(Vec2(x, y));
}

void SmallGun::setPosition(Vec2 position) { Position = position; }

long long int SmallGun::getHP() { return HP; }
void SmallGun::setHP(long long int hp) { HP = hp; }

long long int SmallGun::getMP() { return MP; }
void SmallGun::setMP(long long int mp) { MP = mp; }

void SmallGun::setPlayerData(Rect player) { playerBox = player; }

float SmallGun::calcRotation() {
	float tmp = atan2((Position.x - playerBox.getMidX()), (Position.y - playerBox.getMidY()));
	return tmp * (-180 / PIE) - 90;
}
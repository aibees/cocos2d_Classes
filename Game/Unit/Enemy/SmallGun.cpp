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
	Size ws = Director::getInstance()->getVisibleSize();
	float spSizeX = 80;
	float spSizeY = 80;
	int flag = rand() % 2;
	float x = (rand()*rand()) % ((int)ws.width);
	float y = (rand()*rand()) % ((int)ws.height);
	if(flag)
		x = (x < ws.width) ? (-1)*spSizeX : ws.width;
	else
		y = (y < ws.width) ? (-1)*spSizeY : ws.height;
	setPosition(Vec2(x, y));
}

Vec2 SmallGun::getPosition() { return Position; }
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
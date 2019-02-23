#include "CollisionData.h"

USING_NS_CC;

CollisionData* CollisionData::Instance = NULL;

CollisionData* CollisionData::getInstance() {
	if (!Instance) { Instance = new CollisionData(); }
	return Instance;
}

CollisionData::CollisionData() {

}

//player rect data set/get
Rect CollisionData::getPlayerBox() {
	return playerBox;
}

void CollisionData::setPlayerBox(Rect player) {
	playerBox = player;
}
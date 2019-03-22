#ifndef __ENEMY_FACTORY_H__
#define __ENEMY_FACTORY_H__

#include "../../Utils/Factory.h"
#include "Enemy.h"

class EnemyFactory : public Factory{
private:
	static EnemyFactory* Instance;
	EnemyFactory();
public:
	static EnemyFactory* getInstance();
	virtual Enemy* createEnemy(std::string filename);
};

#endif // !__ENEMY_FACTORY_H__
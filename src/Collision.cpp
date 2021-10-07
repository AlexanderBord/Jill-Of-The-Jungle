#include "Collision.h"



Collision::Collision()
{
	m_ObjectsMap = initializeCollisionMap();
}

HitMap Collision::initializeCollisionMap()
{
	HitMap phm; 
	phm[typesPair(typeid(Player), typeid(SpecialWall))] = &playerSpecialWall;
	phm[typesPair(typeid(Snake),    typeid(NinjaStar))] = &knifeSnake;
	phm[typesPair(typeid(Snake),    typeid(NinjaStar))] = &snakeKnife;
	phm[typesPair(typeid(NinjaStar),    typeid(Snake))] = &knifeSnake;
	phm[typesPair(typeid(Player),   typeid(Alligator))] = &playerAlligator;
	phm[typesPair(typeid(Player),     typeid(KeyGate))] = &playerKeyGate;
	phm[typesPair(typeid(Player),     typeid(GemGate))] = &playerGemGate;
	phm[typesPair(typeid(Player),     typeid(Diamond))] = &playerDiamond;
	phm[typesPair(typeid(Snake),      typeid(Diamond))] = &monsterItem;
	phm[typesPair(typeid(Snake),      typeid(GemGate))] = &monsterItem;
	phm[typesPair(typeid(Snake),      typeid(KeyGate))] = &monsterItem;
	phm[typesPair(typeid(Snake),         typeid(Vine))] = &monsterItem;
	phm[typesPair(typeid(Ant),           typeid(Vine))] = &monsterItem;
	phm[typesPair(typeid(Alligator),     typeid(Vine))] = &monsterItem;
	phm[typesPair(typeid(Bee),           typeid(Vine))] = &monsterItem;
	phm[typesPair(typeid(Bird),          typeid(Vine))] = &monsterItem;
	phm[typesPair(typeid(Frog),          typeid(Vine))] = &monsterItem;
	phm[typesPair(typeid(Ant),        typeid(Diamond))] = &monsterItem;
	phm[typesPair(typeid(Ant),        typeid(GemGate))] = &monsterItem;
	phm[typesPair(typeid(Ant),        typeid(KeyGate))] = &monsterItem;
	phm[typesPair(typeid(Alligator),  typeid(Diamond))] = &monsterItem;
	phm[typesPair(typeid(Alligator),  typeid(GemGate))] = &monsterItem;
	phm[typesPair(typeid(Alligator),  typeid(KeyGate))] = &monsterItem;
	phm[typesPair(typeid(Bee),        typeid(Diamond))] = &monsterItem;
	phm[typesPair(typeid(Bee),        typeid(GemGate))] = &monsterItem;
	phm[typesPair(typeid(Bee),        typeid(KeyGate))] = &monsterItem;
	phm[typesPair(typeid(Bird),       typeid(Diamond))] = &monsterItem;
	phm[typesPair(typeid(Bird),       typeid(GemGate))] = &monsterItem;
	phm[typesPair(typeid(Bird),       typeid(KeyGate))] = &monsterItem;
	phm[typesPair(typeid(Frog),       typeid(Diamond))] = &monsterItem;
	phm[typesPair(typeid(Frog),       typeid(GemGate))] = &monsterItem;
	phm[typesPair(typeid(Frog),       typeid(KeyGate))] = &monsterItem;	
	phm[typesPair(typeid(Player),      typeid(Spikes))] = &playerSpikes;
	phm[typesPair(typeid(Frog),        typeid(Player))] = &frogPlayer;
	phm[typesPair(typeid(Alligator),   typeid(Player))] = &alligatorPlayer;
	phm[typesPair(typeid(Ant),         typeid(Player))] = &antPlayer;
	phm[typesPair(typeid(Bird),        typeid(Player))] = &birdPlayer;
	phm[typesPair(typeid(Snake),       typeid(Player))] = &snakePlayer;	
	phm[typesPair(typeid(Bee),         typeid(Player))] = &beePlayer;
	phm[typesPair(typeid(Player),       typeid(Snake))] = &playerSnake;
	phm[typesPair(typeid(Snake),        typeid(Apple))] = &monsterItem;
	phm[typesPair(typeid(Ant),          typeid(Apple))] = &monsterItem;
	phm[typesPair(typeid(Alligator),    typeid(Apple))] = &monsterItem;
	phm[typesPair(typeid(Bird),         typeid(Apple))] = &monsterItem;
	phm[typesPair(typeid(Frog),         typeid(Apple))] = &monsterItem;	
	phm[typesPair(typeid(Bee),          typeid(Apple))] = &monsterItem;	
	phm[typesPair(typeid(Player),       typeid(Apple))] = &playerApple;
	phm[typesPair(typeid(Snake),		typeid(PresentLife))] = &monsterItem;
	phm[typesPair(typeid(Ant),			typeid(PresentLife))] = &monsterItem;
	phm[typesPair(typeid(Alligator),	typeid(PresentLife))] = &monsterItem;
	phm[typesPair(typeid(Bird),			typeid(PresentLife))] = &monsterItem;
	phm[typesPair(typeid(Frog),			typeid(PresentLife))] = &monsterItem;
	phm[typesPair(typeid(Bee),			typeid(PresentLife))] = &monsterItem;
	phm[typesPair(typeid(Snake),		typeid(PresentScore))] = &monsterItem;
	phm[typesPair(typeid(Ant),			typeid(PresentScore))] = &monsterItem;
	phm[typesPair(typeid(Alligator),	typeid(PresentScore))] = &monsterItem;
	phm[typesPair(typeid(Bird),			typeid(PresentScore))] = &monsterItem;
	phm[typesPair(typeid(Frog),			typeid(PresentScore))] = &monsterItem;
	phm[typesPair(typeid(Bee),			typeid(PresentScore))] = &monsterItem;
	phm[typesPair(typeid(Snake),		typeid(PresentTime))] = &monsterItem;
	phm[typesPair(typeid(Ant),			typeid(PresentTime))] = &monsterItem;
	phm[typesPair(typeid(Alligator),	typeid(PresentTime))] = &monsterItem;
	phm[typesPair(typeid(Bird),			typeid(PresentTime))] = &monsterItem;
	phm[typesPair(typeid(Frog),			typeid(PresentTime))] = &monsterItem;
	phm[typesPair(typeid(Bee),			typeid(PresentTime))] = &monsterItem;
	phm[typesPair(typeid(Snake),		typeid(PresentShield))] = &monsterItem;
	phm[typesPair(typeid(Ant),			typeid(PresentShield))] = &monsterItem;
	phm[typesPair(typeid(Alligator),	typeid(PresentShield))] = &monsterItem;
	phm[typesPair(typeid(Bird),			typeid(PresentShield))] = &monsterItem;
	phm[typesPair(typeid(Frog),			typeid(PresentShield))] = &monsterItem;
	phm[typesPair(typeid(Bee),			typeid(PresentShield))] = &monsterItem;
	phm[typesPair(typeid(Player),		typeid(PresentLife))] = &playerPresentLife;
	phm[typesPair(typeid(Player),		typeid(PresentScore))] = &playerPresentScore;
	phm[typesPair(typeid(Player),		typeid(PresentTime))] = &playerPresentTime;
	phm[typesPair(typeid(Player),		typeid(PresentShield))] = &playerPresentShield;
	phm[typesPair(typeid(Snake),        typeid(Knife))] = &snakeKnife;/////////////
	phm[typesPair(typeid(Knife),        typeid(Snake))] = &knifeSnake;/////////////
	phm[typesPair(typeid(Frog),          typeid(Wall))] = &frogWall;
	phm[typesPair(typeid(Ant),           typeid(Wall))] = &antWall;
	phm[typesPair(typeid(Alligator),     typeid(Wall))] = &alligatorWall;
	phm[typesPair(typeid(Bee),           typeid(Wall))] = &beeWall;
	phm[typesPair(typeid(Bird),          typeid(Wall))] = &birdWall;
	phm[typesPair(typeid(Snake),         typeid(Wall))] = &snakeWall;
	phm[typesPair(typeid(Frog),   typeid(SpecialWall))] = &frogWall;
	phm[typesPair(typeid(Ant),    typeid(SpecialWall))] = &antWall;
	phm[typesPair(typeid(Alligator),typeid(SpecialWall))] = &alligatorWall;
	phm[typesPair(typeid(Bee),    typeid(SpecialWall))] = &beeWall;
	phm[typesPair(typeid(Bird), typeid(SpecialWall))] = &birdWall;
	phm[typesPair(typeid(Snake), typeid(SpecialWall))] = &snakeWall;
	phm[typesPair(typeid(Player),        typeid(Bird))] = &playerBird;
	phm[typesPair(typeid(Player),        typeid(Vine))] = &playerVine;
	phm[typesPair(typeid(Player),        typeid(Wall))] = &playerWall;
	phm[typesPair(typeid(Player),        typeid(Frog))] = &playerFrog;	
	phm[typesPair(typeid(Player),         typeid(Ant))] = &playerAnt;
	phm[typesPair(typeid(Player),         typeid(Bee))] = &playerBee;
	phm[typesPair(typeid(Player),         typeid(Key))] = &playerKey;
	phm[typesPair(typeid(Snake),          typeid(Key))] = &monsterItem;
	phm[typesPair(typeid(Ant),            typeid(Key))] = &monsterItem;
	phm[typesPair(typeid(Alligator),      typeid(Key))] = &monsterItem;	
	phm[typesPair(typeid(Frog),           typeid(Key))] = &monsterItem;	
	phm[typesPair(typeid(Bird),		      typeid(Key))] = &monsterItem;	
	phm[typesPair(typeid(Bee),            typeid(Key))] = &monsterItem;
	phm[typesPair(typeid(Bird),         typeid(Floor))] = &birdFloor;
	phm[typesPair(typeid(Bee),          typeid(Floor))] = &beeFloor;
	phm[typesPair(typeid(Snake),        typeid(Floor))] = &snakeFloor;
	phm[typesPair(typeid(Frog),         typeid(Floor))] = &frogFloor;
	phm[typesPair(typeid(Ant),          typeid(Floor))] = &antFloor;
	phm[typesPair(typeid(Alligator),    typeid(Floor))] = &alligatorFloor;
	phm[typesPair(typeid(Bird),         typeid(Spikes))] = &birdFloor;
	phm[typesPair(typeid(Bee),          typeid(Spikes))] = &beeFloor;
	phm[typesPair(typeid(Snake),        typeid(Spikes))] = &snakeFloor;
	phm[typesPair(typeid(Frog),         typeid(Spikes))] = &frogFloor;
	phm[typesPair(typeid(Ant),          typeid(Spikes))] = &antFloor;
	phm[typesPair(typeid(Alligator),    typeid(Spikes))] = &alligatorFloor;
	phm[typesPair(typeid(Player),        typeid(Floor))] = &playerFloor;
	return phm;
}

HitFunctionPtr Collision::lookup(const std::type_index& class1, const std::type_index& class2)
{
	auto mapEntry = m_ObjectsMap.find(std::make_pair(class1, class2));
	if (mapEntry == m_ObjectsMap.end())
	{
		return nullptr;
	}
	return mapEntry->second;
}


void Collision::processCollision(Object& object1, Object& object2)
{
	auto phf = lookup(typeid(object1), typeid(object2));
	if (!phf)
	{
		std::cout << typeid(object1).name() << " " << typeid(object2).name();
		throw std::runtime_error("Collide error");	
	}
	phf(object1, object2);
}

Collision& Collision::instance()
{
	static Collision instance;
	return instance;
}

void playerApple(Object& player, Object& apple)
{
	Singleton::show().get_sound(2).play();
	Player& p = static_cast<Player&>(player);
	p.increaseScore();
}

void playerPresentLife(Object& player, Object& PresentLife)
{
	Singleton::show().get_sound(6).play();
	Player& p = static_cast<Player&>(player);
	p.addLife();
}
void playerPresentScore(Object& player, Object& presentscore)
{
	Singleton::show().get_sound(6).play();
	Player& p = static_cast<Player&>(player);
	p.addScore();
}
void playerPresentTime(Object& player, Object& presenttime)
{
	Singleton::show().get_sound(6).play();
	Player& p = static_cast<Player&>(player);
	p.addTime();
}

void playerPresentShield(Object& player, Object& presentShield)
{
	Singleton::show().get_sound(6).play();
	Player& p = static_cast<Player&>(player);
	p.setSield(true);
}

void playerKey(Object& player, Object& key)
{
	Singleton::show().get_sound(7).play();
	Player& p = static_cast<Player&>(player);
	p.addKey();
}

void playerSpikes(Object& player, Object& spikes)
{
	Player& p = static_cast<Player&>(player);
	p.decreaseLife();
	p.resetPosition();
	p.setJump(false);
}

void playerKeyGate(Object& player, Object& keyGate)
{
	Player& p = static_cast<Player&>(player);

	if (p.getKeys()>= p.getKeysGoal())
		p.setGatePassStatus(true);
}

void playerDiamond(Object& player, Object& diamond)
{
	Singleton::show().get_sound(8).play();
	Player& p = static_cast<Player&>(player);
	p.addDiamond();
}

void playerGemGate(Object& player, Object& gemgate)
{

	Player& p = static_cast<Player&>(player);
	if ( p.getDiamonds() < p.getDiamondsGoal())
	{
		p.fix_position();
		p.setJump(false);
		p.setGemGatePassStatus(false);
	}
	else
		p.setGemGatePassStatus(true);
}

void playerVine(Object& player, Object& vine)
{
	Player& p = static_cast<Player&>(player);
	bool status = p.getClimbStatus();
	if (!status)
		p.setClimb(true);
}

void playerSpecialWall(Object& player, Object& SpecialWall)
{
	Player& p = static_cast<Player&>(player);
	if (p.getClimbStatus())
		playerVine(player, SpecialWall);
	else
	{
		p.fix_position();
		p.setJump(false);
	}
}

void playerWall(Object& player, Object& wall)
{
	Player& p = static_cast<Player&>(player);
	if (p.getClimbStatus())
		playerVine(player, wall);
	else
	{
		p.fix_position();
		p.setJump(false);
	}
}

void playerFrog(Object& player, Object& monster)
{
	Player& p = static_cast<Player&>(player);
	p.decreaseLife();
	p.resetPosition();
	p.setJump(false);
}

void frogPlayer(Object& monster, Object& player)
{
	playerFrog(player, monster);
}

void playerAnt(Object& player, Object& monster)
{
	playerFrog(player, monster);
}

void antPlayer(Object& monster, Object& player)
{
	playerFrog(player, monster);
}

void playerAlligator(Object& player, Object& monster)
{
	playerFrog(player, monster);
}

void alligatorPlayer(Object& monster, Object& player)
{
	playerFrog(player, monster);
}

void playerSnake(Object& player, Object& monster)
{
	playerFrog(player, monster);
}

void snakePlayer(Object& monster, Object& player)
{
	playerFrog(player, monster);
}

void playerBee(Object& player, Object& monster)
{
	playerFrog(player, monster);
}

void beePlayer(Object& monster, Object& player)
{
	playerFrog(player, monster);
}

void playerBird(Object& player, Object& monster)
{
	playerFrog(player, monster);
}

void birdPlayer(Object& monster, Object& player)
{
	playerFrog(player, monster);
}

void monsterItem(Object& monster, Object& player)
{
}

void frogWall(Object& frog, Object& wall)
{
	Frog& f = static_cast<Frog&>(frog);
	f.fix_position();
	f.set_direction();
}

void antWall(Object& ant, Object& wall)
{
	Ant& a = static_cast<Ant&>(ant);
	a.fix_position();
	a.set_direction();
}

void alligatorWall(Object& alligator, Object& wall)
{
	Alligator& a = static_cast<Alligator&>(alligator);
	a.fix_position();
	a.set_direction();
}

void birdWall(Object& bird, Object& wall)
{
	Bird& b = static_cast<Bird&>(bird);
	b.fix_position();
}
void beeWall(Object& bee, Object& wall)
{
	Bee& b = static_cast<Bee&>(bee);
	b.fix_position();
}
void snakeWall(Object& snake, Object& wall)
{
	Snake& s = static_cast<Snake&>(snake);
	s.fix_position();
	s.set_direction();
}
void snakeKnife(Object& snake, Object& knife)
{
	Snake& s = static_cast<Snake&>(snake);
	s.setTimes();
	s.setScale();
}
void knifeSnake(Object& knife, Object& snake)
{
	snakeKnife(snake,knife);
}

void birdFloor(Object& bird, Object& floor)
{
	Bird& b = static_cast<Bird&>(bird);
	b.set_y_position(9);
}
void beeFloor(Object& bee, Object& floor)
{
	Bee& b = static_cast<Bee&>(bee);
	b.set_y_position(9);
}
void snakeFloor(Object& snake, Object& floor)
{
	Snake& b = static_cast<Snake&>(snake);
	b.set_y_position(9);
}
void alligatorFloor(Object& alligator, Object& floor)
{
	Alligator& b = static_cast<Alligator&>(alligator);
	b.set_y_position(9);
}
void frogFloor(Object& frog, Object& floor)
{
	Frog& b = static_cast<Frog&>(frog);
	b.set_y_position(9);
}
void antFloor(Object& ant, Object& floor)
{
	Ant& b = static_cast<Ant&>(ant);
	b.set_y_position(9);
}
void playerFloor(Object& player, Object& floor)
{
	Player& b = static_cast<Player&>(player);
	b.set_y_position(9);
}
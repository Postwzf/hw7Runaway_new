#ifndef PROJECTILES_HPP__
#define PROJECTILES_HPP__

#include "runaway/GameObject/GameObject.hpp"

// TODO

class Bullet : public GameObject{
public:
    Bullet(int x, int y, pGameWorld world);
    GameObject::Type GetType() const override { return GameObject::Type::ProjectilePlayer; }
    void Update() override;
    void OnCollision(std::shared_ptr<GameObject> other) override;

private:
    int speed = 10;
    int hp = 1;
};


class Axe : public GameObject{
public:
    Axe(int x, int y, pGameWorld world);
    GameObject::Type GetType() const override { return GameObject::Type::ProjectileEnemy; }
    void Update() override;
    void OnCollision(std::shared_ptr<GameObject> other) override;

private:
    int speed = 10;
    int hp = 1;
};

#endif // !PROJECTILES_HPP__

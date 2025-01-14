#ifndef PLAYER_HPP__
#define PLAYER_HPP__

#include <memory>
#include "runaway/GameObject/GameObject.hpp"

// TODO
class Player : public GameObject
// , public std::enable_shared_from_this<Player>
{
public:
    Player(pGameWorld world);
    GameObject::Type GetType() const override { return GameObject::Type::Player;}
    void Update() override;
    // void OnCollision(std::shared_ptr<GameObject> other) override;
    
private:
    int m_hp;
    int Cooldown = 10;
    bool isJumping = false;
    int jumpTime = 0;
    int initialY = GetY();
    // pGameWorld world;
    // std::shared_ptr<GameObject> world;
};

#endif // !PLAYER_HPP__

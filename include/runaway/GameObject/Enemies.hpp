#ifndef ENEMIES_HPP__

#define ENEMIES_HPP__

#include <memory>

#include "runaway/GameObject/GameObject.hpp"
#include "runaway/GameWorld/GameWorld.hpp"

// TODO
class Enemies : public GameObject {
    public:
        Enemies(int x, int y, pGameWorld world);
        void Update() override;
        // void OnCollision(std::shared_ptr<GameObject> other) override;
    private:
        int hp = 5;
        int lifetime=0;
        int waitingtime=0;
        bool wait = false;

};

#endif // !ENEMIES_HPP__
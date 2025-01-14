#include "runaway/GameObject/Enemies.hpp"
#include "runaway/GameObject/Projectiles.hpp"

// TODO
Enemies::Enemies(int x, int y, pGameWorld world)
    :GameObject(ImageID::GOBLIN, x, y, LayerID::ENEMIES, 20, 48, world, 1, 1, AnimID::IDLE)
{
}
void Enemies::Update()
{
    if (!shared_from_this()->IsAlive())
    {
        return;
    }
    MoveTo(GetX() - 3, GetY());
    if (GetX() < 0)
    {
        hp=0;
    }
    if (lifetime % 100 == 0)
    {
        PlayAnimation(AnimID::THROW);
        wait = true;
    }
    lifetime++;
    if (wait){
        waitingtime ++;
    }
    if (waitingtime == 20)
    {
        waitingtime = 0;
        wait = false;
        GetWorld()->Instantiate(std::make_shared<Axe>(GetX(), GetY(), GetWorld()));
        PlayAnimation(AnimID::IDLE);
    }

}


// Bullet::Bullet(int x, int y, pGameWorld world)
//     :GameObject(ImageID::BULLET, x, y, LayerID::PLAYER, 10, 10, world, 1, 1)
// {
// }
// void Bullet::Update()
// {
//     if (!shared_from_this()->IsAlive())
//     {
//         return;
//     }
//     MoveTo(GetX() + speed, GetY());
//     if (GetX() > WINDOW_WIDTH)
//     {
//         hp=0;
//     }
// }
// WINDOW_WIDTH-1，120
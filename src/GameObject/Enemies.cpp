#include "runaway/GameObject/Enemies.hpp"
#include "runaway/GameObject/Projectiles.hpp"

// TODO
Enemies::Enemies(int x, int y, pGameWorld world)
    :GameObject(ImageID::GOBLIN, x, y, LayerID::ENEMIES, 20, 48, world, 5, 1, AnimID::IDLE)
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

void Enemies::OnCollision(std::shared_ptr<GameObject> other)
{
    SetHP(0);
    other->TakeDamage(1);
}
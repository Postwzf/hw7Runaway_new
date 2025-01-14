#include "runaway/GameObject/Projectiles.hpp"

// TODO

Bullet::Bullet(int x, int y, pGameWorld world)
    :GameObject(ImageID::BULLET, x, y, LayerID::PROJECTILES, 10, 10, world, 1, 1)
{
}
void Bullet::Update()
{
    if (!shared_from_this()->IsAlive())
    {
        return;
    }
    MoveTo(GetX() + speed, GetY());
    if (GetX() > WINDOW_WIDTH)
    {
        SetHP(0);
    }
}
void Bullet::OnCollision(std::shared_ptr<GameObject> other)
{
    other->TakeDamage(1);
    SetHP(0);   //子弹死亡
}


Axe::Axe(int x, int y, pGameWorld world)
    :GameObject(ImageID::AXE, x, y, LayerID::PROJECTILES, 25, 25, world, 1, 1)
{
}
void Axe::Update(){
    if (!IsAlive()){
        return;
    }
    MoveTo(GetX() - speed, GetY());
    if (GetX() < 0){
       SetHP(0);
    }
}
// void Axe::OnCollision(std::shared_ptr<GameObject> other){
//     if (other->GetType() == GameObject::Type::Player){
//         other->TakeDamage(1);
//         hp--;
//     }
// }
void Axe::OnCollision(std::shared_ptr<GameObject> other)
{
    other->TakeDamage(1);
    SetHP(0);
}
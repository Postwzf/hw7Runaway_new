#include "runaway/GameWorld/GameWorld.hpp"
#include "runaway/GameObject/Player.hpp"
#include "runaway/GameObject/Projectiles.hpp"

// TODO

Player::Player(pGameWorld world)
    :GameObject(ImageID::PLAYER, 200, 120, LayerID::PLAYER, 20, 48, world, 3, 1, AnimID::IDLE)
{
}
void Player::Update()
{
    // Check if player is dead
    if (!shared_from_this()->IsAlive())
    {
        // TODO: erase text if any; 是否要设置以让gameworld可以清理？》
        // HpText.erase();
        return;
    }
    // Reduce shoot cooldown
    if (Cooldown > 0)
    {
        --Cooldown;
    }
    
    //鼠标点击怎么做？？
    //为什么WorldBase.cpp里面有跟踪鼠标位置的函数？？
    // if (GetWorld()->GetKeyDown(KeyCode::FIRE1)|| GetWorld()->GetMousePos()==(std::pair<int, int>){0,0})
    if (GetWorld()->GetKeyDown(KeyCode::FIRE1))
    {
        if (Cooldown == 0)
        {
            // TODO: Shoot
            // int bulletX = GetX() + 30;
            // int bulletY = GetY() + 20;
            // std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(bulletX, bulletY, GetWorld());
            // GetWorld()->Instantiate(bullet);
            GetWorld()->Instantiate(std::make_shared<Bullet>(GetX() + 30, GetY(), GetWorld()));
            Cooldown = 10;
        }
    }
    // Jump
    if (GetWorld()->GetKeyDown(KeyCode::JUMP) && isJumping == false){
        PlayAnimation(AnimID::JUMP);
        jumpTime = 0;
        isJumping = true;
    }
    if (isJumping){
        if (jumpTime<24){
            MoveTo(GetX(), initialY+(23*jumpTime-1*jumpTime*jumpTime));
        jumpTime++;
        }
        else{
            isJumping = false;
            PlayAnimation(AnimID::IDLE);
        }
    }    
}

// void Player::OnCollision(std::shared_ptr<GameObject> other)
// {
//     TakeDamage(1);
// }

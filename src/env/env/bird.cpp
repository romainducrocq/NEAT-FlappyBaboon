#include "env/env/bird.hpp"

Bird::Bird()
{
    this->y_lim_down = CONST::HEIGHT - (this->r + CONST::FLOOR_Y);
    this->back_x = this->pos_x - this->r;
}

void Bird::move(size_t action)
{
    if(action == CONF::Action::JUMP) {
        this->speed -= this->jump;
    }

    this->speed += this->fall;
    this->speed *= this->d_a;
    this->pos_y = math::clip(this->r, this->y_lim_down, this->pos_y + this->speed);
}

bool Bird::is_collision(const std::array<std::array<math::Vector2f, 2>, 2>& rects)
{
    for(size_t i = 0; i < this->n_collision_points; i++){
        math::point_on_circle((math::PI * 2.f * i) / this->n_collision_points, this->r, this->pos_x, this->pos_y, this->collision_point);
        for(size_t j = 0; j < 2; j++) {
            if(this->collision_point.x >= rects[j][0].x && this->collision_point.x <= rects[j][1].x
            && this->collision_point.y >= rects[j][0].y && this->collision_point.y <= rects[j][1].y) {
                return true;
            }
        }
    }
    return false;
}

void Bird::rotate_theta()
{
    this->theta = math::linterp(this->pos_y - this->y_prev, -this->jump, this->jump, -math::PI / 4, math::PI / 4);
    this->y_prev = this->pos_y;
}

void Bird::reward()
{
    this->score += 1.f;
}

float Bird::get_x() const { return this->pos_x; }

float Bird::get_y() const { return this->pos_y; }

float Bird::get_r() const { return this->r; }

float Bird::get_theta() const { return this->theta; }

float Bird::get_back_x() const { return this->back_x; }

size_t Bird::get_score() const { return this->score; }

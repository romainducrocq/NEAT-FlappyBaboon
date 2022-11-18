#ifndef _ENV_BIRD_HPP
#define _ENV_BIRD_HPP

#include <array>

#include "env/env/utils.hpp"

namespace View { class Renderer; }

class Bird
{
    private:
        friend class View::Renderer;

    private:
        float pos_x = CONST::WIDTH / 4.f;
        float r = 20.f;
        size_t n_collision_points = 10;

        float fall = 0.8f;
        float jump = 6.f; // TODO: tune params
        float d_a = 0.9f;

        float pos_y = CONST::HEIGHT / 2.f;
        float speed = 0.f;

        float score = 0.f;

        float theta = 0.f;
        float y_prev = 0.f;

        float back_x;
        float y_lim_down;

        math::Vector2f collision_point = math::Vector2f();

    public:
        Bird();

        void move(size_t action);
        bool is_collision(const std::array<std::array<math::Vector2f, 2>, 2>& rects);
        void rotate_theta();
        void reward();

        float get_x() const;
        float get_y() const;
        float get_r() const;
        float get_theta() const;
        float get_back_x() const;
        size_t get_score() const;
};

#endif
#include "env/env.hpp"

/*** DEF INIT FUNC HERE */
void MyEnv::Env::init_func()
{
}

/*** DEF OBS FUNC HERE */
void MyEnv::Env::obs_func()
{
}

/*** DEF ACT FUNC HERE */
void MyEnv::Env::act_func()
{
    if(Super::Output::activate(this->mdp.act[0])){
        this->m.bird.move(CONF::JUMP);
    }else{
        this->m.bird.move(CONF::NOOP);
    }
}

/*** DEF DONE FUNC HERE */
void MyEnv::Env::done_func()
{
    this->mdp.done = this->m.bird.is_collision(this->m.pipes.get_next_pipe().get_rects());
}

/*** DEF FITNESS FUNC HERE */
void MyEnv::Env::fitness_func()
{
}

/*** DEF INFO FUNC HERE */
void MyEnv::Env::info_func()
{
    switch(this->Super::mode){

        case CONF::Mode::TRAIN:
            break;

        case CONF::Mode::EVAL:
        case CONF::Mode::PLAY:
            std::cout << "EPOCH   : " << this->Super::epoch << " / " << this->Super::max_epoch_eval << "\n";
            std::cout << "SCORE   : " << this->m.bird.get_score()                                   << "\n";
            std::cout << "\n";
            break;

        default:
            break;
    }
}

/*** DEF NOOP FUNC HERE */
void MyEnv::Env::noop_func()
{
}

/*** DEF RESET FUNC HERE */
void MyEnv::Env::reset_func()
{
    this->m.bird = Bird();
    this->m.pipes = Pipes();
}

/*** DEF STEP FUNC HERE */
void MyEnv::Env::step_func()
{
    this->m.pipes.add_pipe();
    this->m.pipes.move_pipes();
    this->m.pipes.remove_pipe();
    this->m.pipes.next_pipe(this->m.bird.get_back_x());
    if(this->m.pipes.passed_pipe(this->m.bird.get_back_x())){
        this->m.bird.reward();
    }
}

/*** DEF RESET RENDER FUNC HERE */
void MyEnv::Env::reset_render_func()
{
}

/*** DEF STEP RENDER FUNC HERE */
void MyEnv::Env::step_render_func()
{
    this->m.bird.rotate_theta();
}
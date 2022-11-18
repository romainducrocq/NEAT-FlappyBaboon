#include "env/view.hpp"

/*** DEF EVENT SETUP HERE */
void View::EventHandler::ev_setup(sfev::EventManager& ev_manager, sf::RenderWindow& window)
{
    ev_manager.addEventCallback(sf::Event::Closed, [&](sfev::CstEv){
        window.close();
    });

    ev_manager.addKeyReleasedCallback(sf::Keyboard::Escape, [&](sfev::CstEv){
        window.close();
    });

    ev_manager.addKeyReleasedCallback(sf::Keyboard::D, [&](sfev::CstEv){
        this->ev_state.debug = ! this->ev_state.debug;
    });

    ev_manager.addKeyPressedCallback(sf::Keyboard::Up, [&](sfev::CstEv){
        ev_state.action = CONF::JUMP;
    });

    ev_manager.addKeyReleasedCallback(sf::Keyboard::Up, [&](sfev::CstEv){
        ev_state.action = CONF::NOOP;
    });
}

/*** DEF ACTION HANDLER HERE */
void View::EventHandler::get_action(std::vector<float>& act)
{
    switch(this->ev_state.action){
        case CONF::JUMP:
            act[0] = 1.f;
            break;
        case CONF::NOOP:
        default:
            act[0] = -1.f;
            break;
    }
}

/*** DEF DRAW SETUP HERE */
void View::Renderer::draw_setup(const MyEnv::Model& /*m*/, sf::RenderTarget& /*window*/)
{
}

/*** DEF DRAW LOOP HERE */
void View::Renderer::draw_loop(const MyEnv::Model& /*m*/, sf::RenderTarget& /*window*/)
{
}

/*** DEF DRAW FUNCS HERE */


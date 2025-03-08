#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Character.hpp"
void App::Start() {
    LOG_TRACE("Start");
    std::shared_ptr <Character>m_Mario;
    m_Mario->SetImage("./Resource/image/character/big/big_stand.png");
    m_Mario->SetPosition({-112.5f, -140.5f});
    m_Mario->SetZIndex(50);

    m_CurrentState = State::UPDATE;
}

void App::Update() {
    
    //TODO: do your things here and delete this line <3
    
    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */

    if(Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        m_Mario->SetPosition({m_Mario->GetPosition().x, m_Mario->GetPosition().y - 1});
    }

    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}

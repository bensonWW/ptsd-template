//
// Created by Benson on 2025/3/7.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Util/GameObject.hpp"

class Character : public Util::GameObject {
    public:

    const glm::vec2& GetPosition() const { return m_Transform.translation;}

    bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    bool IfCollides(const std::shared_ptr<Character>& other) const {
        if(other->GetPosition().x < this->GetScaledSize().x + this -> GetPosition().x &&
            other->GetPosition().x > this -> GetPosition().x - this->GetScaledSize().x&&
            other->GetPosition().y < this->GetScaledSize().y + this -> GetPosition().y&&
            other->GetPosition().y > this -> GetPosition().y - this->GetScaledSize().y ) {
            return true;
            }
        return false;
    }
    private:
      std::string way;
};

#endif //CHARACTER_HPP

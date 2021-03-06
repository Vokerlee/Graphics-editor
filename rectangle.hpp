#pragma once

#include "config.hpp"
#include "vidget.hpp"

class rectangle : public vidget
{
private:

    sf::RectangleShape rectangle_;
    sf::Color colour_;

public:

    rectangle() :
        vidget(),
        colour_(255, 255, 255),
        rectangle_(size_)
    {}

    rectangle(sf::Vector2<float>& point, sf::Vector2<float>& size, uint32_t& colour) :
        vidget(point, size),
        colour_(colour),
        rectangle_(size_)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);
    }

    rectangle(sf::Vector2<float>& point, sf::Vector2<float>& size, uint8_t red, uint8_t green, uint8_t blue) :
        vidget(point, size),
        colour_(red, green, blue),
        rectangle_(size_)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);
    }

    rectangle(float x, float y, float x_size, float y_size, uint32_t& colour) :
        vidget(x, y, x_size, y_size),
        colour_(colour),
        rectangle_(size_)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);
    }

    rectangle(float x, float y, float x_size, float y_size, uint8_t red, uint8_t green, uint8_t blue) :
        vidget(x, y, x_size, y_size),
        colour_(red, green, blue),
        rectangle_(size_)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);
    }

    ~rectangle() = default;

    rectangle(const rectangle& source)
    {
        point_     = source.point_;
        size_      = source.size_;
        colour_    = source.colour_;
        rectangle_ = source.rectangle_;
    }

    virtual void operator=(const rectangle& source)
    {
        point_     = source.point_;
        size_      = source.size_;
        colour_    = source.colour_;
        rectangle_ = source.rectangle_;
    }

    void set_colour(uint8_t red, uint8_t green, uint8_t blue)
    {
        colour_.r = red;
        colour_.g = green;
        colour_.b = blue;
    }

    virtual bool is_pressed(sf::Vector2<int> mouse_pos)
    {
        if ((mouse_pos.x > point_.x) && (mouse_pos.x < point_.x + size_.x) &&
            (mouse_pos.y > point_.y) && (mouse_pos.y < point_.y + size_.y))
            return true;

        return false;
    }

    virtual void draw(sf::RenderWindow& shell_) const
    {
        shell_.draw(rectangle_);
    }

    virtual void action(draw_state& state)
    {
        state.current_tool = RECTANGLE;
    }
};
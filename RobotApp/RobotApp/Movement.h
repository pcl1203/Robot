#pragma once
#include <functional>
#include <memory>
#include <string>
#include <map>

#include "Constants.h"
#include "Platform.h"

struct Coords
{
    std::uint8_t x;
    std::uint8_t y;

    Coords() : x(0), y(0) {}
    Coords(std::uint8_t _x, std::uint8_t _y) : x(_x), y(_y) {}
};

struct Moves
{
    std::shared_ptr<Moves> ccw;
    std::shared_ptr<Moves> cw;
    std::function<void(Coords*, Platform)> fwd;
    std::string faced;
};

class Movement
{
private:
    std::map<std::string, std::shared_ptr<Moves>> moveMap;
public:
    Movement()
    {
        moveMap[Orientation::NORTH] = std::make_shared<Moves>();
        moveMap[Orientation::EAST] = std::make_shared<Moves>();
        moveMap[Orientation::SOUTH] = std::make_shared<Moves>();
        moveMap[Orientation::WEST] = std::make_shared<Moves>();

        auto const& north = moveMap[Orientation::NORTH];
        auto const& east = moveMap[Orientation::EAST];
        auto const& south = moveMap[Orientation::SOUTH];
        auto const& west = moveMap[Orientation::WEST];

        north->ccw = west;
        east->ccw = north;
        south->ccw = east;
        west->ccw = south;

        north->cw = east;
        east->cw = south;
        south->cw = west;
        west->cw = north;

        north->faced = Orientation::NORTH;
        east->faced = Orientation::EAST;
        south->faced = Orientation::SOUTH;
        west->faced = Orientation::WEST;

        north->fwd = [this](Coords* c, Platform p)
        {
            if (c->y < p.YLimit.max) ++(c->y);
        };

        east->fwd = [this](Coords* c, Platform p)
        {
            if (c->x < p.YLimit.max) ++(c->x);
        };

        south->fwd = [this](Coords* c, Platform p)
        {
            if (c->y > p.YLimit.min) --(c->y);
        };

        west->fwd = [this](Coords* c, Platform p)
        {
            if (c->x > p.XLimit.min) --(c->x);
        };
    }

    std::shared_ptr<Moves> ExtractOrientation(std::string const& dir)
    {
        try
        {
            return moveMap.at(dir);
        }
        catch (const std::exception&)
        {
            return nullptr;
        }
    }
};
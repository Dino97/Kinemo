
-- Vec2.lua

Vec2 = {}
local metatable = {}

metatable["__add"] = function(lhs, rhs)
    return Vec2.New(lhs.x + rhs.x, lhs.y + rhs.y)
end

metatable["__sub"] = function(lhs, rhs)
    return Vec2.New(lhs.x - rhs.x, lhs.y - rhs.y)
end

function Vec2.Magnitude(vec)
    return math.sqrt(vec.x * vec.x + vec.y * vec.y)
end

function Vec2.Normalize(vec)
    local newVec = {}
    
    local len = Vec2.Magnitude(vec)
    newVec.x = vec.x / len
    newVec.y = vec.y / len

    return newVec
end

function Vec2.New(x, y)
    vec = {}
    vec.x = x or 0
    vec.y = y or 0

    setmetatable(vec, metatable)
    
    return vec
end
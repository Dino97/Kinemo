
-- Component.lua

Component = {}
local componentCnt = 0

local function DeepCopy(table)
    local copy
    if type(table) == 'table' then
        copy = {}
        for k, v in next, table, nil do
            copy[DeepCopy(k)] = DeepCopy(v)
        end
        setmetatable(copy, DeepCopy(getmetatable(table)))
    else
        copy = table
    end

    return copy
end

function Component.Create()
    local component = {}
    component._handle = componentCnt
    component.gameObject = nil

    componentCnt = componentCnt + 1

    component.Copy = DeepCopy

    --print("[Component.Create] Handle: " .. component._handle)

    return component
end

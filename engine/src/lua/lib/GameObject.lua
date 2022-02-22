
-- GameObject.lua

GameObject = {}

function GameObject:AddComponent(component)
    -- copy component
    local newComponent = component:Copy()

    -- add ref to gameobject
    self._components[#self._components + 1] = newComponent
    newComponent.gameObject = self

    if newComponent.Update ~= nil then
        RegisterComponentUpdate(newComponent)
    end
    
    --print("[GameObject:AddComponent] Handle: " .. newComponent._handle)

    -- return new copy
    return newComponent
end

function GameObject:GetComponent(component)
    for i = 1, #self._components do
        if self._components[i]._handle == component._handle then
            --print("[GameObject:GetComponent] Handle: " .. component._handle .. " Success: true")
            return self._components[i]
        end
    end

    --print("[GameObject:GetComponent] Handle: " .. component._handle .. " Success: false")

    return nil
end

function GameObject.Create()
    local gameObject = {}
    gameObject._components = {}
    gameObject.AddComponent = GameObject.AddComponent
    gameObject.GetComponent = GameObject.GetComponent

    --print("[GameObject.Create]")

    return gameObject
end

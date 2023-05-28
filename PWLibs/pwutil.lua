--[[
ProWidget Stand Library
By CubeVlmu 2023

Stand Library
]]


-- copy util

function table_copy(t)
    local new_t = {}
    for k, v in pairs(t) do
        if type(v) == "table" then
            new_t[k] = table_copy(v)
        else
            new_t[k] = v
        end
    end
    return new_t
end

function check_number(x)
	if type(x) ~= "number"
	then
		error("position should be a number")
	end
end

-- end of copy util
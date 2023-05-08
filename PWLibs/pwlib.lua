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

-- pbutton dom

local button = { 
	id = nil,
	checkInit = function(self) -- check id is init
		if self.id == nil 
		then
			error("button id is nil")
		end
	end,
	setText = function(self, text)
		self:checkInit()
		changeProp(self.id, "text", text)
	end,
	move = function(self, x, y)
		check_number(x)
		check_number(y)

		self:checkInit()
		changeProp(self.id, "pos", x..","..y) -- parse position to string
	end,
	resize = function(self, w, h)
		check_number(w)
		check_number(h)

		self:checkInit()
		changeProp(self.id, "size", w..","..h) -- parse position to string
	end,
	setStyle = function(self, style)
		self:checkInit()
		changeProp(self.id, "style", style)
	end,
	bindCallBack = function(self, funcName)
		self:checkInit()
		bindCallBack(self.id, funcName)
	end
}

function createButton(id)
	local nbtn = table_copy(button)
	nbtn.id = id
	return nbtn
end

-- end pbutton dom



--[[
ProWidget Stand Library
By CubeVlmu 2023

Stand Library
]]

require("pwutil")

-- pbutton dom object

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

function getButton(id)
	local nbtn = table_copy(button)
	nbtn.id = id
	return nbtn
end

function createButton(id, ...)
	createWidget("button", id, ...)
	local nbtn = table_copy(button)
	nbtn.id = id
	return nbtn
end

-- end pbutton dom



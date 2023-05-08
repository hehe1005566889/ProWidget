--[[
ProWidget Stand Library
By CubeVlmu 2023

MessageBox Util Lib
]]

MsgBox = {
	warning = function(self, text, title)
		if title == nil
		then
		msgbox("Warning", text, 1)
	    else
		msgbox(title, text, 1)
	    end
	end,
	info = function(self, text, title)
		if title == nil
		then
		msgbox("Info", text, 0)
	    else
		msgbox(title, text, 0)
	    end
	end,
	error = function(self, text, title)
		if title == nil
		then
		msgbox("Error", text, 2)
	    else
		msgbox(title, text, 2)
	    end
	end
}
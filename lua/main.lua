-- @Author: Sun Xiaofan <sxf>
-- @Date:   2016-09-22
-- @Email:  sunxfancy@gmail.com
-- @Last modified by:   sxf
-- @Last modified time: 2016-12-11
-- @License: MIT License

require 'lnn'

local vec = BoolVec.new(5)
vec:set(1, true):set(2, true)
print(vec:to_string())

local mat = BoolMat.new(5, 5)
print(vec:select_and(mat):to_string())

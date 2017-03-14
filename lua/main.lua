-- @Author: Sun Xiaofan <sxf>
-- @Date:   2016-09-22
-- @Email:  sunxfancy@gmail.com
-- @Last modified by:   sxf
-- @Last modified time: 2016-12-12
-- @License: MIT License

require 'lnn'

local vec = BoolVec.new(5)
vec:set(0, true):set(1, true):set(2, true)
print(vec:to_string())

local mat = BoolMat.new(5, 6)
mat:set(1, 2, true)
mat:set(2, 2, true)
-- mat:set(3, 2, true)
print(mat:to_string())
print(vec:select_and(mat):to_string())

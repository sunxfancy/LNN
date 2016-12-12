/**
* @Author: Sun Xiaofan <sxf>
* @Date:   2016-09-22
* @Email:  sunxfancy@gmail.com
* @Last modified by:   sxf
* @Last modified time: 2016-12-11
* @License: MIT License
*/



#include "oolua/oolua.h"

#include "vector.hpp"
OOLUA_PROXY(BoolVec)
    OOLUA_CTORS(
        OOLUA_CTOR(int)
    )
    OOLUA_MFUNC(add)
    OOLUA_MFUNC(set)
    OOLUA_MFUNC(select_and)
    OOLUA_MFUNC(select_or)
    OOLUA_MFUNC(select_and_ans)
    OOLUA_MFUNC(select_or_ans)
    OOLUA_MFUNC_CONST(get)
    OOLUA_MFUNC_CONST(size)
    OOLUA_MFUNC_CONST(to_string)
OOLUA_PROXY_END

OOLUA_EXPORT_FUNCTIONS_CONST(BoolVec, get, size, to_string)
OOLUA_EXPORT_FUNCTIONS(BoolVec, add, set, select_and, select_or, select_and_ans, select_or_ans)


#include "matrix.hpp"

OOLUA_PROXY(BoolMat)
    OOLUA_CTORS(
        OOLUA_CTOR(int, int)
    )
    OOLUA_MFUNC(set)
    OOLUA_MFUNC_CONST(get)
    OOLUA_MFUNC_CONST(size_x)
    OOLUA_MFUNC_CONST(size_y)
    OOLUA_MFUNC_CONST(to_string)
OOLUA_PROXY_END

OOLUA_EXPORT_FUNCTIONS_CONST(BoolMat, get, size_x, size_y, to_string)
OOLUA_EXPORT_FUNCTIONS(BoolMat, set)





extern "C" {

extern int
luaopen_lnn(lua_State* L)
{
    using namespace OOLUA;
    setup_user_lua_state(L);
    register_class<BoolVec>(L);
    register_class<BoolMat>(L);
    return 0;
}

}

//
//  Manager.cpp
//  LuaPolys
//
//  Copyright (c) 2012 Alprosys. All rights reserved.
//

#include "Manager.h"

#include <iostream>
#include <boost/foreach.hpp>
#include <boost/format.hpp>

using namespace aps::lua;

// class Manager
// public:

Manager::Manager()
: Manager(lua_open())
{
	luaL_openlibs(vm());
	
	lua_getglobal(vm(), "debug");
	
	if (!lua_isnil(vm(), -1)) {
		lua_getfield(vm(), -1, "traceback");
		debugTraceback_ = lua_tocfunction(vm(), -1);
	}
	
	uniqueVM_ = std::unique_ptr<lua_State, LuaStateDeleter>(vm_);
}

Manager::Manager(lua_State* state)
: vm_(state)
{

}

Manager::~Manager()
{
	
}

lua_State* Manager::vm()
{
	return vm_;
}

bool Manager::doFile(std::string path)
{
	int loadresult = luaL_loadfile(vm(), path.c_str());
	if (loadresult) {
		analyzeError(loadresult);
		return false;
	}
	
	return protectedCall(0, 0, 0);
}

bool Manager::doString(std::string source)
{
	int loadresult = luaL_loadstring(vm(), source.c_str());
	if (loadresult) {
		analyzeError(loadresult);
		return false;
	}
	
	return protectedCall(0, 0, 0);
}

void Manager::push(LuaValue x)
{
	switch(x.which()) {
		case 0: lua_pushnumber(vm(), boost::get<int>(x)); break;
		case 1: lua_pushnumber(vm(), boost::get<double>(x)); break;
		case 2: lua_pushboolean(vm(), boost::get<bool>(x)); break;
		case 3: lua_pushstring(vm(), boost::get<const char*>(x)); break;
		case 4: lua_pushstring(vm(), boost::get<std::string>(x).c_str()); break;
		case 5: lua_pushnil(vm()); break;
	}
}

void Manager::pushValuesToStack(LuaTuple xs)
{
	BOOST_FOREACH (LuaValue x, xs) push(x);
}

LuaValue Manager::peek(int index)
{
	int type = lua_type(vm(), index);
	switch(type) {
		case LUA_TNIL: return Nil();
		case LUA_TSTRING: return lua_tostring(vm(), index);
		case LUA_TNUMBER: return lua_tonumber(vm(), index);
		case LUA_TBOOLEAN: return lua_toboolean(vm(), index) ? true : false;
		default: return Nil();
	}
}

LuaTuple Manager::peekValuesFromStack(int count)
{
	LuaTuple result;
	for (int i = 0; i < count; i++) {
		int index = i - count;
		result.push_back(peek(index));
	}
	return result;
}

LuaTuple Manager::callFunction(std::string func, LuaTuple args)
{
	int old_top = lua_gettop(vm());
	
	lua_pushcfunction(vm(), debugTraceback_);
	
	lua_getglobal(vm(), func.c_str());
	if (!lua_isfunction(vm(), -1)) {
		std::cerr << "* Lua: Function \"" << func << "\" is not found" << std::endl;
		lua_settop(vm(), old_top);
		return LuaTuple();
	}
	
	pushValuesToStack(args);
	
	if (!protectedCall(static_cast<int>(args.size()), LUA_MULTRET, old_top)) {
		lua_settop(vm(), old_top);
		return LuaTuple();
	}
	
	int top = lua_gettop(vm());
	LuaTuple result = peekValuesFromStack(top - (old_top + 1));
	
	lua_settop(vm(), old_top);
	return result;
}

template <LuaTuple(*F)(LuaTuple), int N>
void Manager::registerFunction(std::string name)
{
	lua_CFunction func = cppFunctionToLuaCFunction<F, N>;
	lua_register(vm(), name.c_str(), func);
}

// class Manager
// private:

void Manager::dumpStack()
{
	int stackSize = lua_gettop(vm());
	for(int i = stackSize; i >= 1; i--) {
		int type = lua_type(vm(), i);
		std::cout << boost::format("Stack[%1%-%2%] : ") % i % lua_typename(vm(), type);
		
		switch(type) {
			case LUA_TNUMBER:
				std::cout << lua_tonumber(vm(), i);
				break;
			case LUA_TBOOLEAN:
				std::cout << (lua_toboolean(vm(), i) ? "true" : "false");
				break;
			case LUA_TSTRING:
				std::cout << lua_tostring(vm(), i);
				break;
			case LUA_TNIL:
				std::cout << "nil";
				break;
			default:
				std::cout << lua_typename(vm(), type);
				break;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Manager::analyzeError(int callresult)
{
	std::string reason;
	switch (callresult) {
		case LUA_ERRRUN: reason = "Runtime error"; break;
		case LUA_ERRSYNTAX: reason = "Syntax error"; break;
		case LUA_ERRMEM: reason = "Memory error"; break;
		case LUA_ERRFILE: reason = "File error"; break;
		default: break;
	}
	
	std::string mes = lua_tostring(vm(), -1);
	std::cerr << "* Lua: " << reason << std::endl << mes << std::endl;
}

bool Manager::protectedCall(int argc, int resc, int errfunc)
{
	int callresult = lua_pcall(vm(), argc, resc, errfunc);
	if (callresult != 0) {
		analyzeError(callresult);
		return false;
	}
	return true;
}

template <LuaTuple(*F)(LuaTuple), int N>
int Manager::cppFunctionToLuaCFunction(lua_State* L)
{
	Manager Manager(L);
	auto args = Manager.peekValuesFromStack(N);
	auto result = F(args);
	Manager.pushValuesToStack(result);
	return static_cast<int>(result.size());
}

// struct Manager::LuaStateDeleter
// public:

void Manager::LuaStateDeleter::operator()(lua_State* vm) const
{
	lua_close(vm);
}
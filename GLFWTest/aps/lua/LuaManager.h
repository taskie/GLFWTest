//
//  LuaManager.h
//  LuaPolys
//
//  Copyright (c) 2012 Alprosys. All rights reserved.
//

#pragma once

#include <memory>
#include <string>
#include <deque>
#include <functional>
#include <boost/variant.hpp>

#include <lua.hpp>

#include <unordered_map>

namespace aps
{
	namespace lua
	{
		class Nil {};
		
		typedef boost::variant<int, double, bool, const char*, std::string, Nil> LuaValue;
		
		typedef std::deque<LuaValue> LuaTuple;
		
		class LuaManager
		{
		public:
			LuaManager();
			LuaManager(lua_State* state);
			~LuaManager();
			
			lua_State* vm();
			
			bool doFile(std::string path);
			bool doString(std::string source);
			
			LuaTuple callFunction(std::string func, LuaTuple args);
			
			template <LuaTuple(*F)(LuaTuple), int N>
			void registerFunction(std::string name);
			
		private:
			LuaManager& operator =(const LuaManager& src);
			LuaManager(const LuaManager& src);
			
			struct LuaStateDeleter
			{
				void operator()(lua_State* vm) const;
			};
			
			std::unique_ptr<lua_State, LuaStateDeleter> uniqueVM_;
			lua_State* vm_;
			
			lua_CFunction debugTraceback_;
			
			void push(LuaValue val);
			void pushValuesToStack(LuaTuple xs);
			LuaValue peek(int index);
			LuaTuple peekValuesFromStack(int count);
			
			void dumpStack();
			
			void analyzeError(int callresult);
			bool protectedCall(int argc, int resc, int errfunc);
			
			template <LuaTuple(*F)(LuaTuple), int N>
			static int cppFunctionToLuaCFunction(lua_State* L);
		};
	}
}
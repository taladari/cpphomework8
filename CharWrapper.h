#pragma once


template<typename T> class CharWrapper
{
	
public:
	T Object;
	operator T&() { return Object; };
};
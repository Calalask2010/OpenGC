/*
	Copyright (C) ThePixelMoon 2025

	You are allowed to do ANYTHING with this code,
	as long as there is proper credit.
*/
#ifndef OPENGC_HPP
#define OPENGC_HPP

#pragma once

#include <string>

typedef std::string GCString;

#ifndef OPENGC_NO_LOGS
#include <iostream>

inline void LOG(
	GCString text
)
{
	GCString fullText = "[LOG] " + text;
	std::cout << fullText << std::endl;
}
#else
inline void LOG(
	GCString text
)
{
	/* We do not use std::cout */
}
#endif

/**
 * Region enumerations
 */
enum class Regions
{
	None = -1,
	Europe = 0,
	Asia,
	Africa,
	America,
	Last,
}; // enum class Regions

/**
 * Direction enumerations
 */
enum class Directions
{
	None = -1,
	East = 0,
	West,
	South,
	North,
	Last,
}; // enum class Directions

namespace OpenGC
{

/**
 * The game coordinator class
 */
class GC final
{
	public:
		GC();
		~GC();

		bool Initialize(
			bool isClient,
			Regions region
		);

	private:
		Regions mServerRegion;

}; // class GC

#ifdef OPENGC_IMPLEMENTATION

GC::GC()
{
	mServerRegion = Regions::None;
}; // GC::GC

GC::~GC()
{

}; // GC::~GC

bool GC::Initialize(
	bool isClient,
	Regions region
)
{
	if (region != Regions::None)
		mServerRegion = region;
	else
	{
		LOG("'None' region specified, cannot init");
		return false;
	}

	return true;
}; // bool GC::Initialize

#endif // OPENGC_IMPLEMENTATION

}; // namespace OpenGC

#endif // OPENGC_HPP
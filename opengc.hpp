/*
	Copyright (C) ThePixelMoon 2025

	You are allowed to do ANYTHING with this code,
	as long as there is proper credit.
*/
#ifndef OPENGC_HPP
#define OPENGC_HPP

#pragma once

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

		bool Initialize();
	
}; // class GC

#ifdef OPENGC_IMPLEMENTATION

GC::GC()
{

}; // GC::GC

GC::~GC()
{

}; // GC::~GC

bool GC::Initialize()
{
	
}; // bool GC::Initialize

#endif // OPENGC_IMPLEMENTATION

}; // namespace OpenGC

#endif // OPENGC_HPP
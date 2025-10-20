/*
	Copyright (C) ThePixelMoon 2025

	You are allowed to do ANYTHING with this code,
	as long as there is proper credit.
*/
#define OPENGC_IMPLEMENTATION
#include "../opengc.hpp"

using namespace OpenGC;

int main() {
	GC gc;
	gc.Initialize(
		true /* client */
	);

	return 0;
}
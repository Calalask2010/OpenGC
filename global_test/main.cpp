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
		true, /* client */
		Regions::Europe /* region */
	);

	gc.AddServer(
		{
			"EU-Server-1", /* name */
			"192.168.1.5:7777",  /* address */
			Regions::Europe,  /* region */
			true  /* online? */
		}
	);

	auto servers = gc.ListServers();
	for (auto& s : servers)
		std::cout << s.name << " (" << static_cast<int>(s.region) << ")\n";

	auto srv = gc.FindServer("EU-Server-1");
	if (srv)
		std::cout << "[LOG] Found server: " << srv->address << "\n";

	return 0;
}
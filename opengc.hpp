/*
	Copyright (C) ThePixelMoon 2025

	You are allowed to do ANYTHING with this code,
	as long as there is proper credit.
*/
#ifndef OPENGC_HPP
#define OPENGC_HPP

#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

typedef std::string GCString;

template <typename T>
using GCVector = std::vector<T>;

template <typename K, typename V>
using GCMap = std::unordered_map<K, V>;

/* the current version. why? idk */
constexpr const char* OPENGC_VERSION = "0.0.5";

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

/**
 * Server info structure
 */
struct ServerInfo
{
	GCString name;
	GCString address;
	Regions region;
	bool isOnline;
}; // struct ServerInfo

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
		bool AddServer(
			const ServerInfo& server
		);
		bool RemoveServer(
			const GCString& name
		);
		ServerInfo* FindServer(
			const GCString& name
		);

		GCVector<ServerInfo> ListServers() const;
		GCVector<ServerInfo> ListServers(Regions filterRegion, bool onlyOnline = false) const;

		/* Server info stuff */
		bool SetServerStatus(const GCString& name, bool isOnline);
		bool HasServer(const GCString& name) const;

		/* since server region member is private */
		Regions GetRegion() const { return mServerRegion; }

		/* ..and the version */
		inline GCString GetVersion() const
		{
			return OPENGC_VERSION;
		}

	private:
		GCMap<GCString, ServerInfo> mServers;
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

	GCString fullText = "GC initialized for region: " + std::to_string(static_cast<int>(region));
	LOG(fullText);

	/* ..and the version! */
	LOG("OpenGC version: " + GetVersion());

	return true;
}; // bool GC::Initialize

bool GC::AddServer(
	const ServerInfo& server
)
{
	if (server.region == Regions::None)
	{
		LOG("Cannot add server with region 'None'\n");
		return false;
	}

	mServers[server.name] = server;
	LOG("Added server: " + server.name);
	return true;
} // bool GC::AddServer


bool GC::RemoveServer(
	const GCString& name
)
{
	auto it = mServers.find(name);
	if (it == mServers.end())
		return false;
	mServers.erase(it);
	std::cout << "[LOG] Removed server: " << name << "\n";
	return true;
} // bool GC::RemoveServer

ServerInfo* GC::FindServer(
	const GCString& name
)
{
	auto it = mServers.find(name);
	if (it != mServers.end())
		return &it->second;
	return nullptr;
} // ServerInfo *GC::FindServer

GCVector<ServerInfo> GC::ListServers() const
{
	GCVector<ServerInfo> list;
	for (const auto& kv : mServers)
		list.push_back(kv.second);
	return list;
} // GCVector<ServerInfo> GC::ListServers

bool GC::SetServerStatus(const GCString& name, bool isOnline)
{
	auto it = mServers.find(name);
	if (it == mServers.end())
		return false;

	it->second.isOnline = isOnline;

	LOG("Updated server status for: " + name);
	return true;
} // bool GC::SetServerStatus

GCVector<ServerInfo> GC::ListServers(Regions filterRegion, bool onlyOnline) const
{
	GCVector<ServerInfo> list;
	for (const auto& kv : mServers)
	{
		const auto& s = kv.second;
		if ((filterRegion == Regions::None || s.region == filterRegion) &&
			(!onlyOnline || s.isOnline))
			list.push_back(s);
	}

	return list;
} // GCVector<ServerInfo> GC::ListServers

bool GC::HasServer(const GCString& name) const
{
	return mServers.find(name) != mServers.end();
} // bool GC::HasServer

#endif // OPENGC_IMPLEMENTATION

}; // namespace OpenGC

#endif // OPENGC_HPP
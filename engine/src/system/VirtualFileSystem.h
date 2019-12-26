#pragma once

#include <string>
#include <unordered_map>

#include <iostream>

namespace Kinemo
{
	class VFS
	{
	public:
		static void Mount(const std::string& path,const std::string& name);

		static std::string ReadTextFile(const std::string& path);

	private:
		static std::unordered_map<std::string, std::string> m_MountPoints;
	};
}